#include "SlasconeOpenApiClient/SlasconeApiClient.h"

#include <iostream>
#include <regex>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

namespace org {
namespace openapitools {
namespace client {
namespace api {

const char* slasconeSignatureHeader = "x-slascone-signature";
const char* offlineLicenseFileName = "license.json";
const char* offlineLicenseSignatureFileName = "license_signature.txt";
const char* offlineSessionFileName = "session.token";

SlasconeApiClient::SlasconeApiClient(const char* rsaPublicKey, std::shared_ptr<const ApiConfiguration> configuration)
	: ApiClient(configuration),
	  evpPublicKey(buildRsaPublicKey(rsaPublicKey), &EVP_PKEY_free)
{
}

SlasconeApiClient::SlasconeApiClient(std::shared_ptr<const ApiConfiguration> configuration)
	: ApiClient(configuration),
	  evpPublicKey(nullptr, &EVP_PKEY_free)
{
}

SlasconeApiClient::~SlasconeApiClient()
{
}

// Build a RSA public key with OpenSSL
EVP_PKEY* SlasconeApiClient::buildRsaPublicKey(const char* rsaPublicKey) const
{
	BIO *bio = BIO_new_mem_buf((void *)rsaPublicKey, -1);
	if (bio == nullptr)
	{
		return nullptr;
	}

	EVP_PKEY *evp_pkey = PEM_read_bio_PUBKEY(bio, nullptr, nullptr, nullptr);
	BIO_free(bio);

	return evp_pkey;
}

pplx::task<web::http::http_response> SlasconeApiClient::callApi(
	const utility::string_t &path,
	const utility::string_t &method,
	const std::map<utility::string_t, utility::string_t> &queryParams,
	const std::shared_ptr<org::openapitools::client::api::IHttpBody> postBody,
	const std::map<utility::string_t, utility::string_t> &headerParams,
	const std::map<utility::string_t, utility::string_t> &formParams,
	const std::map<utility::string_t, std::shared_ptr<org::openapitools::client::api::HttpContent>> &fileParams,
	const utility::string_t &contentType) const
{
	return ApiClient::callApi(path, method, queryParams, postBody, headerParams, formParams, fileParams, contentType)
		.then([this, method, path, postBody](web::http::http_response response) -> web::http::http_response 
			{
				if (response.status_code() != web::http::status_codes::OK)
				{
					return response;
				}

				// The response body is needed if
				//  - the signature header has to be validated (a public key is specified)
				//  - license info or session status has to be stored in a file for 'temporary offline' fallback
				//    Endpoints:
				//      o /api/v2/isv/{isv_id}/provisioning/activations
				//      o /api/v2/isv/{isv_id}/provisioning/heartbeats
				//      o /api/v2/isv/{isv_id}/provisioning/session/open

				auto signatureHeaderMustBeValidated = evpPublicKey != nullptr;

				// Check using a regular expression to accept arbitrary isv_id
				auto utf8Path = utility::conversions::to_utf8string(path);
				auto licenseInfoMustBeStored = method == U("POST") && std::regex_match(utf8Path, std::regex("/api/v2/isv/[^/]+/provisioning/(activations|heartbeats)"));
				auto sessionStatusMustBeStored = method == U("POST") && std::regex_match(utf8Path, std::regex("/api/v2/isv/[^/]+/provisioning/session/open"));
				
				// Delete session status file if the session is closed
				auto sessionStatusMustBeDeleted = method == U("POST") && std::regex_match(utf8Path, std::regex("/api/v2/isv/[^/]+/provisioning/session/close"));
				if (sessionStatusMustBeDeleted)
				{
					std::filesystem::path slasconeDir;
					if (0 == findOrCreateSlasconeFolder(slasconeDir))
					{
						std::filesystem::remove(slasconeDir / offlineSessionFileName);
					}
				}				

				if (!signatureHeaderMustBeValidated && !licenseInfoMustBeStored && !sessionStatusMustBeStored)
				{
					return response;
				}

				// Get the response body
				std::vector<unsigned char> body = response.extract_vector().get();

				// Get the x-slascone-signature header
				std::string signature;
				auto signature_iterator = response.headers().find(slasconeSignatureHeader);
				if (signature_iterator != response.headers().end())
				{
					signature = utility::conversions::to_utf8string(signature_iterator->second);
				}

				// Validate the response body with the x-slascone-signature header
				if (evpPublicKey != nullptr)
				{
					validateSignature(body, signature);
				}

				if (licenseInfoMustBeStored)
				{
					// Store the license info and the signature header in files
					std::filesystem::path slasconeDir;
					if (0 == findOrCreateSlasconeFolder(slasconeDir))
					{
						std::ofstream file(slasconeDir / offlineLicenseFileName);
						file.write(reinterpret_cast<const char*>(body.data()), body.size());
						file.close();

						std::ofstream signatureFile(slasconeDir / offlineLicenseSignatureFileName);
						signatureFile << signature;
						signatureFile.close();
					}					
				}

				if (sessionStatusMustBeStored)
				{
					// Since the session status doesn't contain the session id the request body has to be stored too.
					// The request body and the response body are base64 encoded and stored in one file together with
					// the signature header (already base64 encoded), separated by dots.
					std::string base64Body = utility::conversions::to_base64(body);
					// Create a memory stream and write the request body to it
					std::ostringstream stream;
					postBody->writeTo(stream);
					// Get the request body
					std::string requestBody = stream.str();
					std::vector<unsigned char> requestBodyVec(requestBody.begin(), requestBody.end());
					std::string base64RequestBody = utility::conversions::to_base64(requestBodyVec);

					std::filesystem::path slasconeDir;
					if (0 == findOrCreateSlasconeFolder(slasconeDir))
					{
						std::ofstream file(slasconeDir / offlineSessionFileName);
						file << base64RequestBody << "." << base64Body << "." << signature;
						file.close();
					}
				}

				// Put the body back to the response so it can be processed by the caller
				response.set_body(body);

				return response;
			});
}

/**
 * Validate the signature of the response body using the RSA public key
 * 
 * @param body The response body
 * @param signature The x-slascone-signature header
 * @return 0 on success or a negative value if an error occurs.
 */
int SlasconeApiClient::validateSignature(std::vector<unsigned char> body, std::string signature) const
{
	if (signature == "")
	{
		std::cerr << "Signature header not found" << std::endl;
		return -1;
	}

	// Decode the base64 encoded signature
	std::vector<unsigned char> signatureVec = utility::conversions::from_base64(signature);

	// Verify the signature
	EVP_MD_CTX *md_ctx = EVP_MD_CTX_new();
	EVP_DigestVerifyInit(md_ctx, nullptr, EVP_sha256(), nullptr, evpPublicKey.get());

	int result = EVP_DigestVerify(md_ctx, signatureVec.data(), signatureVec.size(), body.data(), body.size());
	if (result != 1)
	{
		std::cerr << "Signature verification failed" << std::endl;
		EVP_MD_CTX_free(md_ctx);
		return -1;
	}

	EVP_MD_CTX_free(md_ctx);

	return 0;
}

/**
 * Try to get the license info from the file
 * 
 * @param licenseInfo The license info DTO
 * @return 0 on success or a negative value if an error occurs.
 */
int SlasconeApiClient::TryGetLicenseInfo(const std::shared_ptr<LicenseInfoDto>& licenseInfo) const
{
	std::filesystem::path slasconeDir;
	if (findOrCreateSlasconeFolder(slasconeDir) < 0)
	{
		std::cerr << "Error: Unable to find or create Slascone directory." << std::endl;
		return -1;
	}

	// Try to read the license info from the file
	std::ifstream file(slasconeDir / offlineLicenseFileName);
	if (file.is_open())
	{
		// Read the file as std::vector<unsigned char> and check the signature
		std::vector<unsigned char> body((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
		if (nullptr != evpPublicKey)
		{
			// Read the signature from the file
			std::string signature;
			std::ifstream signatureFile(slasconeDir / offlineLicenseSignatureFileName);
			if (signatureFile.is_open())
			{
				std::string signature((std::istreambuf_iterator<char>(signatureFile)), std::istreambuf_iterator<char>());
				if (0 != validateSignature(body, signature))
				{
					std::cerr << "Error: License file signature verification failed." << std::endl;
					return -1;
				}
				signatureFile.close();
			}
			else
			{
				std::cerr << "Error: Unable to open license_signature.txt file." << std::endl;
				return -1;
			}
		}

		// Create a utility::string_t from the std::vector<unsigned char>
		utility::string_t bodyStr = utility::conversions::to_string_t(std::string(body.begin(), body.end()));		

		// Parse the Json content
		licenseInfo->fromJson(web::json::value::parse(bodyStr));
	}
	else
	{
		std::cerr << "Error: Unable to open license.json file." << std::endl;
		return -1;
	}

	return 0;
}

int SlasconeApiClient::TryGetOpenSession(const std::shared_ptr<SessionRequestDto>& sessionRequest, const std::shared_ptr<SessionStatusDto>& sessionStatus) const
{
	std::filesystem::path slasconeDir;
	if (findOrCreateSlasconeFolder(slasconeDir) < 0)
	{
		std::cerr << "Error: Unable to find or create Slascone directory." << std::endl;
		return -1;
	}

	// Try to read the session status from the file
	std::ifstream file(slasconeDir / offlineSessionFileName);
	if (file.is_open())
	{
		// Read the file as std::vector<unsigned char> and check the signature
		// The request body and the response body are base64 encoded and stored in one file together with
		// the signature header (already base64 encoded), separated by dots.
		std::string base64RequestBody;
		std::string base64Body;
		std::string signature;
		std::string line;
		if (std::getline(file, line))
		{
			std::istringstream iss(line);
			std::getline(iss, base64RequestBody, '.');
			std::getline(iss, base64Body, '.');
			std::getline(iss, signature);
		}

		// Decode the base64 encoded request body and body
		std::vector<unsigned char> requestBody = utility::conversions::from_base64(utility::conversions::to_string_t(base64RequestBody));
		std::vector<unsigned char> body = utility::conversions::from_base64(utility::conversions::to_string_t(base64Body));

		// Validate the signature
		if (nullptr != evpPublicKey)
		{
			if (0 != validateSignature(body, signature))
			{
				std::cerr << "Error: Session file signature verification failed." << std::endl;
				return -1;
			}
		}

		// Create a utility::string_t from the std::vector<unsigned char>
		utility::string_t bodyStr = utility::conversions::to_string_t(std::string(body.begin(), body.end()));

		// Parse the Json content
		sessionStatus->fromJson(web::json::value::parse(bodyStr));
		sessionRequest->fromJson(web::json::value::parse(utility::conversions::to_string_t(std::string(requestBody.begin(), requestBody.end()))));
	}
	else
	{
		std::cerr << "Error: Unable to open session.token file." << std::endl;
		return -1;
	}

	return 0;
}

/**
 * Find or create a 'Slascone' directory in the home directory of the user
 * 
 * @param slasconeDir The path to the 'Slascone' directory
 */
int SlasconeApiClient::findOrCreateSlasconeFolder(std::filesystem::path& slasconeDir) const
{
    // Find or create a 'Slascone' directory in the home directory of the user
	slasconeDir = getenv("HOME");
    slasconeDir /= "Slascone";
    if (mkdir(slasconeDir.c_str(), 0777) == -1)
    {
        if (errno != EEXIST)
        {
            std::cerr << "Error: Unable to create Slascone directory." << std::endl;
            return -1;
        }
    }

	return 0;	
}

}
}
}
}
