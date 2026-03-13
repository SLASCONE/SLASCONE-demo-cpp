// Helper class for SLASCONE

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <SlasconeOpenApiClient/SlasconeApiClient.h>
#include <SlasconeOpenApiClient/api/DataGatheringApi.h>
#include <SlasconeOpenApiClient/api/ProvisioningApi.h>
#include "ErrorHandlingHelper.h"

using namespace std;
using namespace org::openapitools::client::api;

namespace SLASCONE_demo_cpp
{
    class Helper
    {
    private:
        // Reference to an ApiClient instance
        shared_ptr<SlasconeApiClient> apiClient;

        // Reference to a DataGatheringApi instance
        unique_ptr<DataGatheringApi> dataGatheringApi;

        // Reference to a ProvisioningApi instance
        unique_ptr<ProvisioningApi> provisioningApi;

        // License DTO
        shared_ptr<LicenseInfoDto> licenseInfoDto;

        // A stack of session IDs
        stack<string> sessionIds;

    public:
        Helper(/* args */);
        ~Helper();

        int activate_license();
        int send_license_heartbeat();
        int find_temp_offline_license();
        int unassign_token();
        int send_analytical_heartbeat();
        int send_usage_heartbeat();
        int send_consumption_heartbeat();
        int open_session();
        int find_open_session();
        int close_session();

        int get_license_by_id();
        int verify_file(const char *xml_file);
        string get_os_name();
        string get_device_id();

    protected:
        void response_handler(web::http::status_code, const web::http::http_headers&);
        void print_api_error(const std::string& errorMessage, int32_t errorId);
        int print_license(shared_ptr<LicenseDto> licenseDto);
        int print_license(shared_ptr<LicenseInfoDto> licenseInfoDto);
    };
}
