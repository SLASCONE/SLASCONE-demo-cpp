#include "ApiClient.h"

#include <filesystem>

#include "SlasconeOpenApiClient/model/LicenseInfoDto.h"
#include <SlasconeOpenApiClient/model/SessionRequestDto.h>
#include <SlasconeOpenApiClient/model/SessionStatusDto.h>

namespace org {
namespace openapitools {
namespace client {
namespace api {

class SlasconeApiClient : public ApiClient
{
    private:
        std::unique_ptr<EVP_PKEY, decltype(&EVP_PKEY_free)> evpPublicKey;

    public:
        SlasconeApiClient(const char* rsaPublicKey, std::shared_ptr<const ApiConfiguration> configuration = nullptr);
        SlasconeApiClient(std::shared_ptr<const ApiConfiguration> configuration = nullptr);
        virtual ~SlasconeApiClient();

        virtual pplx::task<web::http::http_response> callApi(
            const utility::string_t& path,
            const utility::string_t& method,
            const std::map<utility::string_t, utility::string_t>& queryParams,
            const std::shared_ptr<IHttpBody> postBody,
            const std::map<utility::string_t, utility::string_t>& headerParams,
            const std::map<utility::string_t, utility::string_t>& formParams,
            const std::map<utility::string_t, std::shared_ptr<HttpContent>>& fileParams,
            const utility::string_t& contentType
        ) const;

        int TryGetLicenseInfo(const std::shared_ptr<LicenseInfoDto>& licenseInfo) const;
        int TryGetOpenSession(const std::shared_ptr<SessionRequestDto>& sessionRequest, const std::shared_ptr<SessionStatusDto>& sessionStatus) const;

    protected:
        EVP_PKEY* buildRsaPublicKey(const char* rsaPublicKey) const;
        int validateSignature(std::vector<unsigned char> body, std::string signature) const;
        int findOrCreateSlasconeFolder(std::filesystem::path& slasconeDir) const;
};
}
}
}
}
