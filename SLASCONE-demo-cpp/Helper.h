// Helper class for SLASCONE

#include <iostream>
#include <fstream>
#include <string>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <openssl/err.h>
#include <SlasconeOpenApiClient/ApiClient.h>
#include <SlasconeOpenApiClient/api/ProvisioningApi.h>

using namespace std;
using namespace org::openapitools::client::api;

namespace SLASCONE_demo_cpp
{
    class Helper
    {
    private:
        // Reference to a ProvisioningApi instance
        unique_ptr<ProvisioningApi> provisioningApi;

    public:
        Helper(/* args */);
        ~Helper();

        int send_heartbeat();
        int get_license_by_id();
        int verify_file(const char *xml_file);
		int print_license_infos(const char* xml_file);

    protected:
        int print_license(shared_ptr<LicenseDto> licenseDto);
        int print_license(shared_ptr<LicenseInfoDto> licenseInfoDto);
    };
}
