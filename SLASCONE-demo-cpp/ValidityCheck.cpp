#include <fstream>
#include <future>
#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <cpprest/asyncrt_utils.h>
#include "ValidityCheck.h"
#include "ReleaseCheck.h"

using namespace std;
using namespace org::openapitools::client::model;
using namespace utility;
using namespace utility::conversions;
using namespace SLASCONE_demo_cpp;

const string softwareRelease = "26.3";

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
    auto dateValidityPtr = licenseDto->dateValidityIsSet() ? licenseDto->getDateValidity() : nullptr;
    if (licenseDto->isIsValid()
        && dateValidityPtr != nullptr
        && DateValidity::eDateValidity::_0 == dateValidityPtr->getValue())
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
                cout << "License is valid until " << licenseDto->getExpirationDateUtc().to_string(utility::datetime::ISO_8601) << "." << endl;
            }
        }
    }
    else if (dateValidityPtr != nullptr)
    {
        switch (dateValidityPtr->getValue())
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

    if (dateValidityPtr != nullptr)
    {
        auto dateValidity = dateValidityPtr->getValue();

        if (DateValidity::eDateValidity::_1 == dateValidity)
        {
            cout << "This license is not yet valid. Valid from " << licenseDto->getStartDateUtc().to_string(datetime::ISO_8601) << endl;
            return false;
        }
        else if (DateValidity::eDateValidity::_2 == dateValidity)
        {
            cout << "This license is expired. Expired at " << licenseDto->getExpirationDateUtc().to_string(datetime::ISO_8601) << endl;
            return false;
        }
    }

    if (!licenseDto->isIsActive())
    {
        cout << "This license is deactivated." << endl;
        return false;
    }

    // Software version information
    auto swLimitation = licenseDto->getSoftwareReleaseLimitation();
    if (swLimitation == nullptr)
    {
        return true;
    }

    auto limit = swLimitation->getSoftwareRelease();
    if (limit.empty())
    {
        return true;
    }

    cout << endl << "Software Version Information:" << endl;
    cout << "----------------------------" << endl;
    cout << "Software Release Limit: " << swLimitation->getSoftwareRelease() << endl;

    if (swLimitation->descriptionIsSet() && !swLimitation->getDescription().empty())
    {
        cout << "Description: " << swLimitation->getDescription() << endl;
    }

    if (ReleaseCheck::Compare(limit, softwareRelease) < 0)
    {
        cout << "\n===> Software version " << softwareRelease << " is not compliant <===\n" << endl;
        return false;
    }
    else
    {
        cout << "Software version is compliant." << endl;
    }

    return true;
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
    auto dateValidityPtr = licenseInfoDto->dateValidityIsSet() ? licenseInfoDto->getDateValidity() : nullptr;
    if (licenseInfoDto->isIsLicenseValid()
        && dateValidityPtr != nullptr
        && DateValidity::eDateValidity::_0 == dateValidityPtr->getValue())
    {
        // Check if it's a "9999" perpetual license
        std::tm expirationTm = datetime_to_tm(licenseInfoDto->getExpirationDateUtc());
        if (expirationTm.tm_year +1900 >= 9999) // tm_year is years since 1900
        {
            cout << "This is a perpetual license." << endl;
        }
        else
        {
            cout << "License is valid until " << licenseInfoDto->getExpirationDateUtc().to_string(utility::datetime::ISO_8601) << "." << endl;
        }
    }
    else if (dateValidityPtr != nullptr)
    {
        switch (dateValidityPtr->getValue())
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

    if (dateValidityPtr != nullptr)
    {
        auto dateValidity = dateValidityPtr->getValue();

        if (DateValidity::eDateValidity::_1 == dateValidity)
        {
            cout << "This license is not yet valid. Valid from " << licenseInfoDto->getStartDateUtc().to_string(datetime::ISO_8601) << endl;
            return false;
        }
        else if (DateValidity::eDateValidity::_2 == dateValidity)
        {
            cout << "This license is expired. Expired at " << licenseInfoDto->getExpirationDateUtc().to_string(datetime::ISO_8601) << endl;
            return false;
        } 
    }

    if (!licenseInfoDto->isIsLicenseActive())
    {
        cout << "This license is deactivated." << endl;
        return false;
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
        return false;
    }

    return true;
}

bool ValidityCheck::check_license_validity(shared_ptr<SoftwareReleaseLimitationDto> releaseLimitationDto)
{
    if (releaseLimitationDto == nullptr)
    {
        // No software release limitation, consider it as valid
        return true;
    }

    if (releaseLimitationDto == nullptr)
    {
        return true;
    }

    auto limit = releaseLimitationDto->getSoftwareRelease();
    if (limit.empty())
    {
        return true;
    }

    cout << endl << "Software Version Information:" << endl;
    cout << "----------------------------" << endl;
    cout << "Software Release Limit: " << releaseLimitationDto->getSoftwareRelease() << endl;

    if (releaseLimitationDto->descriptionIsSet() && !releaseLimitationDto->getDescription().empty())
    {
        cout << "Description: " << releaseLimitationDto->getDescription() << endl;
    }

    if (ReleaseCheck::Compare(limit, softwareRelease) < 0)
    {
        cout << "\n===> Software version " << softwareRelease << " is not compliant <===\n" << endl;
        return false;
    }
    else
    {
        cout << "Software version is compliant." << endl;
    }

    return true;
}
