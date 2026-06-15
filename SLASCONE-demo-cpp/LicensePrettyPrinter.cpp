#include <iostream>
#include <string>
#include "LicensePrettyPrinter.h"

using namespace std;
using namespace org::openapitools::client::model;
using namespace utility::conversions;
using namespace SLASCONE_demo_cpp;

int LicensePrettyPrinter::print_license(shared_ptr<LicenseDto> licenseDto)
{
    if (licenseDto == nullptr)
    {
        return -1;
    }

    cout << "License infos (Retrieved " << to_utf8string(licenseDto->getCreatedDateUtc().to_string()) << "):" << endl;

    // Display the main properties of the license
    cout << "\nLicense Information:" << endl;
    cout << "-------------------" << endl;
    cout << "License Name: " << to_utf8string(licenseDto->getName()) << endl;
    cout << "License Key: " << to_utf8string(licenseDto->getId()) << endl;

    if (!licenseDto->getLegacyLicenseKey().empty())
    {
        cout << "Legacy License Key: " << to_utf8string(licenseDto->getLegacyLicenseKey()) << endl;
    }

    cout << "License key: " << to_utf8string(licenseDto->getId()) << endl;
    cout << "Legacy license key: " << to_utf8string(licenseDto->getLegacyLicenseKey()) << endl;
    cout << "License name: " << to_utf8string(licenseDto->getName()) << endl;
    cout << "Product name: " << to_utf8string(licenseDto->getProductId()) << endl;
    cout << "License valid: " << licenseDto->isIsValid() << endl;
    cout << "Expiration date: " << to_utf8string(licenseDto->getExpirationDateUtc().to_string()) << endl;
    cout << "Customer company name: " << to_utf8string(licenseDto->getCustomer()->getCompanyName()) << endl;
    cout << "Customer number: " << to_utf8string(licenseDto->getCustomer()->getCustomerNumber()) << endl;

    auto features = licenseDto->getLicenseFeatures();
    for (auto feature : features)
    {
        cout << " - Feature name: " << to_utf8string(feature->getFeatureName()) << endl;
        cout << "   Feature description: " << to_utf8string(feature->getFeatureDescription()) << endl;
    }

    auto limitations = licenseDto->getLicenseLimitations();
    for (auto limitation : limitations)
    {
        cout << " - Limitation name: " << to_utf8string(limitation->getLimitationName()) << endl;
        cout << "   Limitation description: " << to_utf8string(limitation->getLimitationDescription()) << endl;
        cout << "   Limitation value: " << limitation->getLimit() << endl;
    }

    auto constrainedVariables = licenseDto->getLicenseConstrainedVariables();
    for (auto constrainedVariable : constrainedVariables)
    {
        cout << " - Constrained variable name: " << to_utf8string(constrainedVariable->getVariableName()) << endl;
        cout << "   Constrained variable description: " << to_utf8string(constrainedVariable->getVariableDescription()) << endl;
        cout << "   Constrained variable value: ";            
        for (auto value : constrainedVariable->getValues())
        {
            cout << to_utf8string(value);
        }
        cout << endl;
    }

    auto variables = licenseDto->getLicenseVariables();
    for (auto variable : variables)
    {
        cout << " - Variable name: " << to_utf8string(variable->getVariableName()) << endl;
        cout << "   Variable description: " << to_utf8string(variable->getVariableDescription()) << endl;
        cout << "   Variable value: " << to_utf8string(variable->getValue()) << endl;
    }

    cout << endl;

    if (licenseDto->isIsValid() && licenseDto->isIsSoftwareReleaseValid())
    {
        cout << "This license is valid." << endl;
        return 0;
    }

    if (licenseDto->dateValidityIsSet())
    {
        auto dateValidityPtr = licenseDto->getDateValidity();
        auto dateValidity = dateValidityPtr->getValue();

        if (DateValidity::eDateValidity::_1 == dateValidity)
        {
            cout << "This license is not yet valid. Valid from " << licenseDto->getStartDateUtc().to_string() << endl;
            return -1;
        }
        else if (DateValidity::eDateValidity::_2 == dateValidity)
        {
            cout << "This license is expired. Expired at " << licenseDto->getExpirationDateUtc().to_string() << endl;
            return -1;
        }
    }

    if (!licenseDto->isIsActive())
    {
        cout << "This license is deactivated." << endl;
        return -1;
    }

    if (!licenseDto->isIsSoftwareReleaseValid())
    {
        cout << "This license is not valid for this software release." << endl;
        return -1;
    }

    return 0;
}

int LicensePrettyPrinter::print_license(shared_ptr<LicenseInfoDto> licenseInfoDto)
{
    if (licenseInfoDto == nullptr)    
    {
        return -1;
    }
    
    cout << "License key: " << to_utf8string(licenseInfoDto->getLicenseKey()) << endl;
    licenseInfoDto->legacyLicenseKeyIsSet() ? cout << "Legacy license key: " << to_utf8string(licenseInfoDto->getLegacyLicenseKey()) << endl : cout << "Legacy license key: not set" << endl;
    cout << "Token key: " << to_utf8string(licenseInfoDto->getTokenKey()) << endl;
    licenseInfoDto->licenseNameIsSet() ? cout << "License name: " << to_utf8string(licenseInfoDto->getLicenseName()) << endl : cout << "License name: not set" << endl;
    cout << "Product name: " << to_utf8string(licenseInfoDto->getProductName()) << endl;
    cout << "Template name: " << to_utf8string(licenseInfoDto->getTemplateName()) << endl;
    cout << "License valid: " << licenseInfoDto->isIsLicenseValid() << endl;
    cout << "Expiration date: " << to_utf8string(licenseInfoDto->getExpirationDateUtc().to_string()) << endl;

    auto customer = licenseInfoDto->getCustomer();
    cout << "Customer company name: " << to_utf8string(customer->getCompanyName()) << endl;
    cout << "Customer number: " << to_utf8string(customer->getCustomerNumber()) << endl;

    cout << "Session period: " << licenseInfoDto->getSessionPeriod() << endl;
    cout << "Heartbeat period: " << licenseInfoDto->getHeartbeatPeriod() << endl;
    cout << "Freeride: " << licenseInfoDto->getFreeride() << endl;

    auto features = licenseInfoDto->getFeatures();
    for (auto feature : features)
    {
        cout << " - Feature name: " << to_utf8string(feature->getName());
        feature->isIsActive() ? cout << endl : cout << " (not active)" << endl;
        feature->descriptionIsSet() 
            ? cout << "   Feature description: " << to_utf8string(feature->getDescription()) << endl
            : cout << "   Feature description: not set" << endl;
    }

    auto limitations = licenseInfoDto->getLimitations();
    for (auto limitation : limitations)
    {
        cout << " - Limitation name: " << to_utf8string(limitation->getName()) << endl;
        limitation->descriptionIsSet() 
            ? cout << "   Limitation description: " << to_utf8string(limitation->getDescription()) << endl 
            : cout << "   Limitation description: not set" << endl;
        limitation->valueIsSet() 
            ? cout << "   Limitation value: " << limitation->getValue() << endl
            : cout << "   Unlimited limitation" << endl;
        limitation->remainingIsSet() 
            ? cout << "   Limitation remaining: " << limitation->getRemaining() << endl
            : cout << "   Limitation remaining: not set" << endl;
        limitation->balanceIsSet() 
            ? cout << "   Limitation balance: " << limitation->getBalance() << endl
            : cout << "   Limitation balance: not set" << endl;
    }

    auto constrainedVariables = licenseInfoDto->getConstrainedVariables();
    for (auto constrainedVariable : constrainedVariables)
    {
        cout << " - Constrained variable name: " << to_utf8string(constrainedVariable->getName()) << endl;
        constrainedVariable->descriptionIsSet() 
            ? cout << "   Constrained variable description: " << to_utf8string(constrainedVariable->getDescription()) << endl 
            : cout << "   Constrained variable description: not set" << endl;
        cout << "   Constrained variable value: ";            
        for (auto value : constrainedVariable->getValue())
        {
            cout << to_utf8string(value);
        }
        cout << endl;
    }

    auto variables = licenseInfoDto->getVariables();
    for (auto variable : variables)
    {
        cout << " - Variable name: " << to_utf8string(variable->getName()) << endl;
        variable->descriptionIsSet() 
                ? cout << "   Variable description: " << to_utf8string(variable->getDescription()) << endl
                : cout << "   Variable description: not set" << endl;
        cout << "   Variable value: " << to_utf8string(variable->getValue()) << endl;
    }

    cout << endl;

    if (licenseInfoDto->isIsLicenseValid() && licenseInfoDto->isIsSoftwareVersionValid())
    {
        cout << "This license is valid." << endl;
        return 0;
    }

    if (licenseInfoDto->dateValidityIsSet())
    {
        auto dateValidityPtr = licenseInfoDto->getDateValidity();
        auto dateValidity = dateValidityPtr->getValue();

        if (DateValidity::eDateValidity::_1 == dateValidity)
        {
            cout << "This license is not yet valid. Valid from " << licenseInfoDto->getStartDateUtc().to_string() << endl;
            return -1;
        }
        else if (DateValidity::eDateValidity::_2 == dateValidity)
        {
            cout << "This license is expired. Expired at " << licenseInfoDto->getExpirationDateUtc().to_string() << endl;
            return -1;
        } 
    }

    if (!licenseInfoDto->isIsLicenseActive())
    {
        cout << "This license is deactivated." << endl;
        return -1;
    }

    if (!licenseInfoDto->isIsSoftwareVersionValid())
    {
        cout << "This license is not valid for this software release." << endl;
        return -1;
    }

    return 0;
}
