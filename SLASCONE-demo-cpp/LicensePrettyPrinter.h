// License pretty printer for SLASCONE

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
    class LicensePrettyPrinter
    {
    public:
        static int print_license(shared_ptr<LicenseDto> licenseDto);
        static int print_license(shared_ptr<LicenseInfoDto> licenseInfoDto);
    };
}
