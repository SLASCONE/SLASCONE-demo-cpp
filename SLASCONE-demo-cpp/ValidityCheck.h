// 

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <SlasconeOpenApiClient/model/LicenseDto.h>
#include <SlasconeOpenApiClient/model/LicenseInfoDto.h>

using namespace std;
using namespace org::openapitools::client::model;


namespace SLASCONE_demo_cpp
{
    class ValidityCheck
    {
    public:
        static bool check_license_validity(shared_ptr<LicenseDto> licenseDto);
        static bool check_license_validity(shared_ptr<LicenseInfoDto> licenseInfoDto);
        static bool check_license_validity(shared_ptr<SoftwareReleaseLimitationDto> releaseLimitationDto);
   };
}
