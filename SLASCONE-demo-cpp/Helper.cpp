#include "Helper.h"
#include <fstream>
#include <future>
#include <string>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <openssl/err.h>
#include <openssl/rsa.h>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <xmlsec/xmlsec.h>
#include <xmlsec/xmltree.h>
#include <xmlsec/xmldsig.h>
#include <xmlsec/app.h>
#include <xmlsec/openssl/app.h>
#include <xmlsec/crypto.h>
#include <xmlsec/errors.h>
#include <SlasconeOpenApiClient/ApiClient.h>
#include <SlasconeOpenApiClient/api/ProvisioningApi.h>
#include "LicenseXmlValidator/LicenseXmlValidator.h"

using namespace std;
using namespace web::http::client;
using namespace org::openapitools::client::api;
using namespace utility::conversions;
using namespace SLASCONE_demo_cpp;

// Base URL
const string baseUrl = "https://api.slascone.com";

// ISV ID
const string isvId = "2af5fe02-6207-4214-946e-b00ac5309f53";

// Product ID
const string productId = "b18657cc-1f7c-43fa-e3a4-08da6fa41ad3";

// Provisioning key header
const string provisioningKeyHeader = "ProvisioningKey";

// Provisioning key
const string provisioningKey = "NfEpJ2DFfgczdYqOjvmlgP2O/4VlqmRHXNE9xDXbqZcOwXTbH3TFeBAKKbEzga7D7ashHxFtZOR142LYgKWdNocibDgN75/P58YNvUZafLdaie7eGwI/2gX/XuDPtqDW";

// Example PEM public key (replace this with your actual key)
    const string pemKey =
R"(-----BEGIN PUBLIC KEY-----
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAwpigzm+cZIyw6x253YRD
mroGQyo0rO9qpOdbNAkE/FMSX+At5CQT/Cyr0eZTo2h+MO5gn5a6dwg2SYB/K1Yt
yuiKqnaEUfoPnG51KLrj8hi9LoZyIenfsQnxPz+r8XGCUPeS9MhBEVvT4ba0x9Ew
R+krU87VqfI3KNpFQVdLPaZxN4STTEZaet7nReeNtnnZFYaUt5XeNPB0b0rGfrps
y7drmZz81dlWoRcLrBRpkf6XrOTX4yFxe/3HJ8mpukuvdweUBFoQ0xOHmG9pNQ31
AHGtgLYGjbKcW4xYmpDGl0txfcipAr1zMj7X3oCO9lHcFRnXdzx+TTeJYxQX2XVb
hQIDAQAB
-----END PUBLIC KEY-----)";

/**
 * Helper:
 * 
 */
Helper::Helper(/* args */)
{
	shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration);
	shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));

	apiConfig->setBaseUrl(baseUrl);

    shared_ptr<http_client_config> httpConfig(new http_client_config);
    httpConfig->set_timeout(chrono::seconds(15));

	apiConfig->setHttpConfig(*httpConfig);
	apiConfig->setApiKey(provisioningKeyHeader, provisioningKey);

	apiClient->setConfiguration(apiConfig);

    // Create a provisioning API instance
    provisioningApi = make_unique<ProvisioningApi>(apiClient);
}

Helper::~Helper()
{
    // Free the provisioning API instance
    provisioningApi.reset();

    // Clean up the OpenSSL library
    ERR_free_strings();
}

/**
 * activate_license:
 * 
 * Activate a license
 * 
 * @return 0 on success or a negative value if an error occurs.
 */
int
Helper::activate_license()
{
    shared_ptr<ActivateClientDto> activateLicense = make_shared<ActivateClientDto>();
    activateLicense->setProductId(productId);
    activateLicense->setLicenseKey("27180460-29df-4a5a-a0a1-78c85ab6cee0");
    activateLicense->setClientId(get_device_id());
    activateLicense->setSoftwareVersion("24.11");    
    activateLicense->setClientDescription(get_os_name());

    // Create a promise and future
    auto promise = make_shared<std::promise<shared_ptr<LicenseInfoDto>>>();
    future<shared_ptr<LicenseInfoDto>> future = promise->get_future();

    provisioningApi->activateLicense(isvId, activateLicense)
        .then([promise](pplx::task<shared_ptr<LicenseInfoDto>> licenseInfo) mutable
              {
                try {
                    auto licenseInfoDto = licenseInfo.get();
                    promise->set_value(licenseInfoDto);
                }
                catch (...) {
                    auto ex = current_exception();
                    promise->set_exception(ex);
                } });

    shared_ptr<LicenseInfoDto> licenseInfoDto;

    try
    {
        licenseInfoDto = future.get();
    }
    catch (const ApiException &e)
    {
        shared_ptr<istream> content = e.getContent();
        ErrorResultObjects errorResultObjects;
        string jsonStr((istreambuf_iterator<char>(*content)), istreambuf_iterator<char>());
        errorResultObjects.fromJson(web::json::value::parse(jsonStr));

        cout << "activateLicense() error ID: " << errorResultObjects.getId() << endl;
        cout << "activateLicense() error message: " << errorResultObjects.getMessage() << endl;
    }
    catch (const exception &e)
    {
        cout << "activateLicense() exception: " << e.what() << '\n';
    }

    if (licenseInfoDto != nullptr)
    {
        Helper::print_license(licenseInfoDto);
    }
    else
    {
        cout << "Error: licenseInfoDto is null." << '\n';
    }

    return 0;
}

/**
 * send_license_heartbeat:
 * 
 * Send a license heartbeat
 * 
 * @return 0 on success or a negative value if an error occurs.
 */
int 
Helper::send_license_heartbeat()
{
	shared_ptr<AddHeartbeatDto> addHeartbeat = make_shared<AddHeartbeatDto>();
    addHeartbeat->setProductId(productId);
    addHeartbeat->setClientId(get_device_id());
	addHeartbeat->setSoftwareVersion("24.11");
	addHeartbeat->setOperatingSystem("C++ sample");

    // Create a promise and future
    auto promise = make_shared<std::promise<shared_ptr<LicenseInfoDto>>>();
    future<shared_ptr<LicenseInfoDto>> future = promise->get_future();

    provisioningApi->addHeartbeat(isvId, addHeartbeat)
        .then([promise](pplx::task<shared_ptr<LicenseInfoDto>> licenseInfo) mutable
              {
				try {
					auto licenseInfoDto = licenseInfo.get();
					promise->set_value(licenseInfoDto);
				}
				catch (...) {
                    auto ex = current_exception();
					promise->set_exception(ex);
				} });

    shared_ptr<LicenseInfoDto> licenseInfoDto;

    try
    {
        licenseInfoDto = future.get();
    }
    catch (const ApiException &e)
    {
        shared_ptr<istream> content = e.getContent();
        ErrorResultObjects errorResultObjects;
        string jsonStr((istreambuf_iterator<char>(*content)), istreambuf_iterator<char>());
        errorResultObjects.fromJson(web::json::value::parse(jsonStr));

        cout << "addHeartbeat() error ID: " << errorResultObjects.getId() << endl;
        cout << "addHeartbeat() error message: " << errorResultObjects.getMessage() << endl;
    }
    catch (const exception &e)
    {
        cout << "addHeartbeat() exception: " << e.what() << '\n';
    }

    if (licenseInfoDto != nullptr)
	{
		Helper::print_license(licenseInfoDto);
	}
	else
	{
		cout << "Error: licenseInfoDto is null." << '\n';
	}

	if (licenseInfoDto != nullptr) {
	}

    return 0;
}

/**
 * get_license_by_id:
 * 
 * Get a license by ID
 * 
 * @return 0 on success or a negative value if an error occurs.
 */
int Helper::get_license_by_id()
{
    shared_ptr<GetLicensesByLicenseKeyDto> getLicenses = make_shared<GetLicensesByLicenseKeyDto>();
    getLicenses->setLicenseKey("27180460-29df-4a5a-a0a1-78c85ab6cee0");
    getLicenses->setProductId(productId);

    provisioningApi->getLicensesByLicenseKeyAsync(isvId, getLicenses)
        .then([this](pplx::task<vector<shared_ptr<LicenseDto>>> licenses)
              {
					try {
						auto licenseDtos = licenses.get();

						for (auto licenseDto : licenseDtos)
						{
							Helper::print_license(licenseDto);
						}
					}
					catch (const exception& e) {
						cout << "getLicensesByLicenseKeyAsync() exception: " << e.what() << '\n';
					} })
        .wait();

    return 0;
}

/**
 * verify_file:
 * @xml_file:           the signed XML file name.
 *
 * Verifies XML signature in #xml_file using public key from #key_file.
 *
 * Returns 0 on success or a negative value if an error occurs.
 */
int
Helper::verify_file(const char* xml_file) {
    LicenseXmlValidator::LicenseXmlValidator validator;
    return validator.verify_file(xml_file, pemKey.c_str(), pemKey.length());
}

int Helper::print_license_infos(const char* xml_file)
{
    // Read and deserialize the license XML file using libxml2
        
    return 0;
}

/**
 * get_os_name:
 * 
 * Get the operating system name
 * 
 * @return the operating system name or an empty string if an error occurs.
 */
string
Helper::get_os_name()
{
    #if defined(_WIN32) || defined(_WIN64)
        return "Windows";
    #elif defined(__linux__)
        // Use the output of the command 'uname -sr' to get the Linux distribution name and version
        string command = "uname -sr";
        char buffer[128];
        FILE* pipe = popen(command.c_str(), "r");
        if (pipe == nullptr)
        {
            cout << "Error: popen() failed." << '\n';
            return "";
        }
        string os_name = fgets(buffer, 128, pipe);
        // Trim ending line feed/carriage return
        os_name.erase(os_name.find_last_not_of("\n\r") + 1);
        return os_name;
    #elif defined(__APPLE__) || defined(__MACH__)
        return "macOS";
    #elif defined(__unix__)
        return "Unix";
    #else
        return "Unknown operating system";
    #endif
}

/**
 * get_device_id:
 * 
 * Get the device ID
 * 
 * @return the device ID or an empty string if an error occurs.
 * 
 * Note: The device ID is the HOSTNAME environment variable.
 */
string 
Helper::get_device_id()
{
    // Read HOSTNAME environment variable
    const char* hostname = getenv("HOSTNAME");
    if (hostname == nullptr)
    {
        cout << "Error: HOSTNAME environment variable not set." << '\n';
        return "";
    }

    return hostname;
}

int 
Helper::print_license(shared_ptr<LicenseDto> licenseDto)
{
    if (licenseDto != nullptr)
    {
        cout << "License key: " << to_utf8string(licenseDto->getId()) << '\n';
        cout << "Legacy license key: " << to_utf8string(licenseDto->getLegacyLicenseKey()) << '\n';
        cout << "License name: " << to_utf8string(licenseDto->getName()) << '\n';
        cout << "Product name: " << to_utf8string(licenseDto->getProductId()) << '\n';
        cout << "License valid: " << licenseDto->isIsValid() << '\n';
        cout << "Expiration date: " << to_utf8string(licenseDto->getExpirationDateUtc().to_string()) << '\n';

        auto features = licenseDto->getLicenseFeatures();
        for (auto feature : features)
        {
            cout << " - Feature name: " << to_utf8string(feature->getFeatureName()) << '\n';
            cout << "   Feature description: " << to_utf8string(feature->getFeatureDescription()) << '\n';
        }

        auto limitations = licenseDto->getLicenseLimitations();
        for (auto limitation : limitations)
        {
            cout << " - Limitation name: " << to_utf8string(limitation->getLimitationName()) << '\n';
            cout << "   Limitation description: " << to_utf8string(limitation->getLimitationDescription()) << '\n';
            cout << "   Limitation value: " << limitation->getLimit() << '\n';
        }

        auto variables = licenseDto->getLicenseVariables();
        for (auto variable : variables)
        {
            cout << " - Variable name: " << to_utf8string(variable->getVariableName()) << '\n';
            cout << "   Variable description: " << to_utf8string(variable->getVariableDescription()) << '\n';
            cout << "   Variable value: " << to_utf8string(variable->getValue()) << '\n';
        }
        return 0;
    }

    return -1;
}

int 
Helper::print_license(shared_ptr<LicenseInfoDto> licenseInfoDto)
{
    if (licenseInfoDto != nullptr)
    {
        cout << "License key: " << to_utf8string(licenseInfoDto->getLicenseKey()) << '\n';
        cout << "Legacy license key: " << to_utf8string(licenseInfoDto->getLegacyLicenseKey()) << '\n';
        cout << "Token key: " << to_utf8string(licenseInfoDto->getTokenKey()) << '\n';
        cout << "License name: " << to_utf8string(licenseInfoDto->getLicenseName()) << '\n';
        cout << "Product name: " << to_utf8string(licenseInfoDto->getProductName()) << '\n';
        cout << "Template name: " << to_utf8string(licenseInfoDto->getTemplateName()) << '\n';
        cout << "License valid: " << licenseInfoDto->isIsLicenseValid() << '\n';
        cout << "Expiration date: " << to_utf8string(licenseInfoDto->getExpirationDateUtc().to_string()) << '\n';


        auto customer = licenseInfoDto->getCustomer();
        cout << "Customer company name: " << to_utf8string(customer->getCompanyName()) << '\n';
        cout << "Customer number: " << to_utf8string(customer->getCustomerNumber()) << '\n';

        auto features = licenseInfoDto->getFeatures();
        for (auto feature : features)
        {
            cout << " - Feature name: " << to_utf8string(feature->getName()) << '\n';
            cout << "   Feature description: " << to_utf8string(feature->getDescription()) << '\n';
        }

        auto limitations = licenseInfoDto->getLimitations();
        for (auto limitation : limitations)
        {
            cout << " - Limitation name: " << to_utf8string(limitation->getName()) << '\n';
            cout << "   Limitation description: " << to_utf8string(limitation->getDescription()) << '\n';
            cout << "   Limitation value: " << limitation->getValue() << '\n';
        }

        auto variables = licenseInfoDto->getVariables();
        for (auto variable : variables)
        {
            cout << " - Variable name: " << to_utf8string(variable->getName()) << '\n';
            cout << "   Variable description: " << to_utf8string(variable->getDescription()) << '\n';
            cout << "   Variable value: " << to_utf8string(variable->getValue()) << '\n';
        }

        return 0;
    }

    return -1;
}
