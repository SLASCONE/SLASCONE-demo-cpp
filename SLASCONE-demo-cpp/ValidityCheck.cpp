#include <fstream>
#include <future>
#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <cpprest/asyncrt_utils.h>
#include "ValidityCheck.h"

using namespace std;
using namespace org::openapitools::client::model;
using namespace utility::conversions;
using namespace SLASCONE_demo_cpp;

std::tm datetime_to_tm(const utility::datetime& dt)
{
    int64_t ticks = dt.to_interval();  // 100-ns ticks since 1601
    int64_t total_seconds = ticks / 10'000'000;  // convert to seconds
    std::time_t tt = static_cast<std::time_t>(total_seconds - 11644473600LL);
    std::tm tm{};    
    gmtime_r(&tt, &tm); // or gmtime_s on Windows
    return tm;
}

bool ValidityCheck::check_license_validity(shared_ptr<LicenseDto> licenseDto)
{
    if (licenseDto == nullptr)
    {
        cout << "Error: No license information available." << endl;
        return false;
    }

    // License validity status
    cout << endl << "License Validity Status:" << endl;
    cout << "-----------------------" << endl;
    cout << endl << "===> License is " << (licenseDto->isIsValid() ? "valid" : "not valid") << " <===" << endl << endl;

    // Date information and license validity
    if (licenseDto->isIsValid() && licenseDto->dateValidityIsSet() && DateValidity::eDateValidity::_0 == licenseDto->getDateValidity()->getValue())
    {
        if (licenseDto->expirationDateUtcIsSet())
        {
            // Check if it's a "9999" perpetual license
            std::tm expirationTm = datetime_to_tm(licenseDto->getExpirationDateUtc());
            if (expirationTm.tm_year + 1900 >= 9999) // tm_year is years since 1900
            {
                cout << "This is a perpetual license." << endl;
            }
            else
            {
                long valid = licenseDto->getExpirationDateUtc() - utility::datetime::utc_now(); // in seconds
                valid /= 86400; // convert to days
                cout << "License is valid for another " << valid << " day(s) until " << licenseDto->getExpirationDateUtc().to_string(utility::datetime::ISO_8601) << "." << endl;
            }
        }
    }
    else if (licenseDto->dateValidityIsSet())
    {
        switch (licenseDto->getDateValidity()->getValue())
        {
            case DateValidity::eDateValidity::_1:
                cout << "License is not valid yet." << (licenseDto->startDateUtcIsSet() ? " (Start Date: " + licenseDto->getStartDateUtc().to_string(datetime::ISO_8601) + ")" : "") << endl;
                break;

            case DateValidity::eDateValidity::_2:
                cout << (licenseDto->expirationDateUtcIsSet() ? "License has expired.since " + licenseDto->getExpirationDateUtc().to_string(datetime::ISO_8601) + "." : "License has expired.") << endl;
                break;

            default:
                break;
        }
    }

    if (!licenseDto->isIsValid() && !licenseDto->isIsActive())
    {
        cout << "License is deactivated." << endl;
    }

    if (licenseDto->dateValidityIsSet())
    {
        auto dateValidityPtr = licenseDto->getDateValidity();
        auto dateValidity = dateValidityPtr->getValue();

        if (DateValidity::eDateValidity::_1 == dateValidity)
        {
            cout << "This license is not yet valid. Valid from " << licenseDto->getStartDateUtc().to_string(datetime::ISO_8601) << endl;
            return -1;
        }
        else if (DateValidity::eDateValidity::_2 == dateValidity)
        {
            cout << "This license is expired. Expired at " << licenseDto->getExpirationDateUtc().to_string(datetime::ISO_8601) << endl;
            return -1;
        }
    }

    if (!licenseDto->isIsActive())
    {
        cout << "This license is deactivated." << endl;
        return -1;
    }

    // Software version information
    auto swLimitation = licenseDto->getSoftwareReleaseLimitation();
    if (swLimitation != nullptr)
    {
        cout << endl << "Software Version Information:" << endl;
        cout << "----------------------------" << endl;
        if (licenseDto->isIsSoftwareReleaseValid())
        {
            cout << "Software version is valid" << endl;
        }
        else
        {
            cout << "\n===> Software version is not valid <===\n" << endl;
        }

        if (!swLimitation->getSoftwareRelease().empty())
        {
            cout << "Software Release: " << swLimitation->getSoftwareRelease() << endl;
        }

        if (swLimitation->descriptionIsSet() && !swLimitation->getDescription().empty())
        {
            cout << "Description: " << swLimitation->getDescription() << endl;
        }
    }

    if (!licenseDto->isIsSoftwareReleaseValid())
    {
        return -1;
    }

    return 0;
}

bool ValidityCheck::check_license_validity(shared_ptr<LicenseInfoDto> licenseInfoDto)
{
    if (licenseInfoDto == nullptr)
    {
        cout << "Error: No license information available." << endl;
        return false;
    }

    // License validity status
    cout << endl << "License Validity Status:" << endl;
    cout << "-----------------------" << endl;
    cout << endl << "===> License is " << (licenseInfoDto->isIsLicenseValid() ? "valid" : "not valid") << " <===" << endl << endl;

    // Date information and license validity
    if (licenseInfoDto->isIsLicenseValid() && DateValidity::eDateValidity::_0 == licenseInfoDto->getDateValidity()->getValue())
    {
        // Check if it's a "9999" perpetual license
        std::tm expirationTm = datetime_to_tm(licenseInfoDto->getExpirationDateUtc());
        if (expirationTm.tm_year +1900 >= 9999) // tm_year is years since 1900
        {
            cout << "This is a perpetual license." << endl;
        }
        else
        {
            long valid = licenseInfoDto->getExpirationDateUtc() - utility::datetime::utc_now(); // in seconds
            valid /= 86400; // convert to days
            cout << "License is valid for another " << valid << " day(s) until " << licenseInfoDto->getExpirationDateUtc().to_string(utility::datetime::ISO_8601) << "." << endl;
        }
    }
    else
    {
        switch (licenseInfoDto->getDateValidity()->getValue())
        {
            case DateValidity::eDateValidity::_1:
                cout << "License is not valid yet." << (licenseInfoDto->startDateUtcIsSet() ? " (Start Date: " + licenseInfoDto->getStartDateUtc().to_string(datetime::ISO_8601) + ")" : "") << endl;
                break;

            case DateValidity::eDateValidity::_2:
                cout << (licenseInfoDto->expirationDateUtcIsSet() ? "License has expired.since " + licenseInfoDto->getExpirationDateUtc().to_string(datetime::ISO_8601) + "." : "License has expired.") << endl;
                break;
        }
    }

    if (!licenseInfoDto->isIsLicenseValid() && !licenseInfoDto->isIsLicenseActive())
    {
        cout << "License is deactivated." << endl;
    }

    if (licenseInfoDto->dateValidityIsSet())
    {
        auto dateValidityPtr = licenseInfoDto->getDateValidity();
        auto dateValidity = dateValidityPtr->getValue();

        if (DateValidity::eDateValidity::_1 == dateValidity)
        {
            cout << "This license is not yet valid. Valid from " << licenseInfoDto->getStartDateUtc().to_string(datetime::ISO_8601) << endl;
            return -1;
        }
        else if (DateValidity::eDateValidity::_2 == dateValidity)
        {
            cout << "This license is expired. Expired at " << licenseInfoDto->getExpirationDateUtc().to_string(datetime::ISO_8601) << endl;
            return -1;
        } 
    }

    if (!licenseInfoDto->isIsLicenseActive())
    {
        cout << "This license is deactivated." << endl;
        return -1;
    }

    // Software version information
    auto swLimitation = licenseInfoDto->getSoftwareReleaseLimitation();
    if (swLimitation != nullptr)
    {
        cout << endl << "Software Version Information:" << endl;
        cout << "----------------------------" << endl;
        if (licenseInfoDto->isIsSoftwareVersionValid())
        {
            cout << "Software version is valid" << endl;
        }
        else
        {
            cout << "\n===> Software version is not valid <===\n" << endl;
        }
        cout << "Enforce Software Upgrade: " << licenseInfoDto->isEnforceSoftwareVersionUpgrade() << endl;

        if (!swLimitation->getSoftwareRelease().empty())
        {
            cout << "Software Release: " << swLimitation->getSoftwareRelease() << endl;
        }

        if (swLimitation->descriptionIsSet() && !swLimitation->getDescription().empty())
        {
            cout << "Description: " << swLimitation->getDescription() << endl;
        }
    }
    
    if (!licenseInfoDto->isIsSoftwareVersionValid())
    {
        return -1;
    }

    return 0;
}

bool ValidityCheck::check_license_validity(shared_ptr<SoftwareReleaseLimitationDto> releaseLimitationDto)
{
    if (releaseLimitationDto == nullptr)
    {
        cout << "Error: No software release limitation information available." << endl;
        return false;
    }

    if (releaseLimitationDto != nullptr)
    {

        if (!swLimitation->getSoftwareRelease().empty())
        {
            cout << "Software Release: " << swLimitation->getSoftwareRelease() << endl;
        }

        if (swLimitation->descriptionIsSet() && !swLimitation->getDescription().empty())
        {
            cout << "Description: " << swLimitation->getDescription() << endl;
        }
    }

    return true;
}
