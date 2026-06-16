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

    // Display the main properties of the license
    cout << "\nLicense Information:" << endl;
    cout << "-------------------" << endl;
    cout << "License Name: " << (licenseInfoDto->licenseNameIsSet() ? to_utf8string(licenseInfoDto->getLicenseName()) : "") << endl;
    cout << "License Key: " << (licenseInfoDto->licenseKeyIsSet() ? to_utf8string(licenseInfoDto->getLicenseKey()) : "") << endl;

    if (licenseInfoDto->legacyLicenseKeyIsSet())
    {
        cout << "Legacy License Key: " << to_utf8string(licenseInfoDto->getLegacyLicenseKey()) << endl;
    }

    if (licenseInfoDto->tokenKeyIsSet())
    {
        cout << "Token Key: " << to_utf8string(licenseInfoDto->getTokenKey()) << endl;
    }

    cout << "License key: " << to_utf8string(licenseInfoDto->getLicenseKey()) << endl;
    licenseInfoDto->legacyLicenseKeyIsSet() ? cout << "Legacy license key: " << to_utf8string(licenseInfoDto->getLegacyLicenseKey()) << endl : cout << "Legacy license key: not set" << endl;
    cout << "Token key: " << to_utf8string(licenseInfoDto->getTokenKey()) << endl;
    licenseInfoDto->licenseNameIsSet() ? cout << "License name: " << to_utf8string(licenseInfoDto->getLicenseName()) << endl : cout << "License name: not set" << endl;
    cout << "Product name: " << to_utf8string(licenseInfoDto->getProductName()) << endl;
    cout << "Template name: " << to_utf8string(licenseInfoDto->getTemplateName()) << endl;
    cout << "License valid: " << licenseInfoDto->isIsLicenseValid() << endl;
    cout << "Expiration date: " << to_utf8string(licenseInfoDto->getExpirationDateUtc().to_string()) << endl;

    // Customer information
    auto customer = licenseInfoDto->getCustomer();
    if (customer != nullptr)
    {
        cout << "\nCustomer Information:" << endl;
        cout << "---------------------" << endl;
        cout << "Customer ID: " << to_utf8string(customer->getCustomerId()) << endl;
        cout << "Company Name: " << to_utf8string(customer->getCompanyName()) << endl;

        if (customer->customerNumberIsSet())
        {
            cout << "Customer Number: " << to_utf8string(customer->getCustomerNumber()) << endl;
        }
    }

    // Product information
    cout << "\nProduct Information:" << endl;
    cout << "--------------------" << endl;
    cout << "Product Name: " << to_utf8string(licenseInfoDto->getProductName()) << endl;
    cout << "Template Name: " << to_utf8string(licenseInfoDto->getTemplateName()) << endl;
    ProvisioningMode::eProvisioningMode provisioningMode = licenseInfoDto->getProvisioningMode()->getValue();
    ClientType::eClientType clientType = licenseInfoDto->getClientType()->getValue();
    cout << "Provisioning mode / client type: " << static_cast<int>(provisioningMode) << " / " << static_cast<int>(clientType) << endl;

    cout << "Session period: " << licenseInfoDto->getSessionPeriod() << endl;
    cout << "Heartbeat period: " << licenseInfoDto->getHeartbeatPeriod() << endl;
    cout << "Freeride: " << licenseInfoDto->getFreeride() << endl;

    /*
    // License details
    Console.WriteLine("\nLicense Details:");
    Console.WriteLine("----------------");
    Console.WriteLine($"Provisioning Mode: {licenseInfo.Provisioning_mode}");
    Console.WriteLine($"Is Temporary: {licenseInfo.Is_temporary}");
    Console.WriteLine($"Heartbeat Period: {licenseInfo.Heartbeat_period ?? 0} days");

    // Date information and license validity
    string dateFormat = "yyyy-MM-dd HH:mm";
    if (licenseInfo.Created_date_utc.HasValue)
    {
        Console.WriteLine($"Created Date: {licenseInfo.Created_date_utc.Value.ToString(dateFormat)}");
    }

    if (licenseInfo.Session_period is > 0)
    {
        Console.WriteLine($"Session Period: {licenseInfo.Session_period.Value} days");
    }

    if (licenseInfo.Freeride is > 0)
    {
        Console.WriteLine($"Freeride granted for {licenseInfo.Freeride.Value} day(s).");
    }

    // Enumerate features
    if (licenseInfo.Features != null && licenseInfo.Features.Count > 0)
    {
        Console.WriteLine("\nFeatures:");
        foreach (var feature in licenseInfo.Features)
        {
            Console.WriteLine($"- {feature.Name ?? ""} (Active: {feature.Is_active})");

            if (feature.Expiration_date_utc.HasValue)
            {
                Console.WriteLine($"  Expires: {feature.Expiration_date_utc.Value.ToString(dateFormat)}");
            }
        }
    }
    else
    {
        Console.WriteLine("\nNo features available in this license.");
    }

    // Enumerate limitations
    Dictionary<Guid, (string, bool)> limitationMap;
    if (licenseInfo.Limitations != null && licenseInfo.Limitations.Count > 0)
    {
        Console.WriteLine("\nLimitations:");
        foreach (var limitation in licenseInfo.Limitations)
        {
            Console.WriteLine($"- {limitation.Name ?? ""}: {(limitation.Value.HasValue ? limitation.Value.Value.ToString() : "unlimited")}");
        }

        // Create a dictionary of limitations
        limitationMap = licenseInfo.Limitations?.ToDictionary(
                            l => l.Id,
                            l => ($"{l.Name} (max: {l.Value})", ConsumptionResetPeriod.Disabled != l.Consumption_reset_mode));
    }
    else
    {
        Console.WriteLine("\nNo limitations available in this license.");
        limitationMap = new Dictionary<Guid, (string Description, bool CanConsume)>();
    }

    // Enumerate variables if present
    if (licenseInfo.Variables != null && licenseInfo.Variables.Count > 0)
    {
        Console.WriteLine("\nVariables:");
        foreach (var variable in licenseInfo.Variables)
        {
            Console.WriteLine($"- {variable.Name ?? ""}: {variable.Value ?? ""}");
        }
    }
    else
    {
        Console.WriteLine("\nNo variables available in this license.");
    }

    // User information if present
    if (licenseInfo.License_users != null && licenseInfo.License_users.Count > 0)
    {
        Console.WriteLine("\nLicense Users:");
        Console.WriteLine($"Number of users: {licenseInfo.License_users.Count}");
    }

    // License validity status
    Console.WriteLine("\nLicense Validity Status:");
    Console.WriteLine("-----------------------");
    Console.WriteLine($"\n===> License is {(licenseInfo.Is_license_valid ? "valid" : "not valid")} <===\n");

    // Date information and license validity
    if (licenseInfo.Is_license_valid && DateValidity.IsValid == licenseInfo.Date_validity)
    {
        // Check if it's a "9999" perpetual license
        if (licenseInfo.Expiration_date_utc.Value.Year >= 9999)
        {
            Console.WriteLine("This is a perpetual license.");
        }
        else
        {
            long valid = (licenseInfo.Expiration_date_utc.Value - DateTime.UtcNow).Days;
            Console.WriteLine($"License is valid for another {valid} day(s) until {licenseInfo.Expiration_date_utc.Value.ToString(dateFormat)}.");
        }
    }
    else
    {
        switch (licenseInfo.Date_validity)
        {
            case DateValidity.IsNotValidYet:
                Console.WriteLine(
                    $"License is not valid yet.{(licenseInfo.Start_date_utc.HasValue ? $" (Start Date: {licenseInfo.Start_date_utc.Value.ToString(dateFormat)}" : "")}");
                break;

            case DateValidity.IsExpired:
                Console.WriteLine(licenseInfo.Expiration_date_utc.HasValue
                    ? $"License has expired.since {licenseInfo.Expiration_date_utc.Value.ToString(dateFormat)}."
                    : "License has expired.");
                break;
        }
    }

    if (!licenseInfo.Is_license_valid && !licenseInfo.Is_license_active)
    {
        Console.WriteLine("License is deactivated.");
    }

    // Software version information
    var swLimitation = licenseInfo.Software_release_limitation;
    if (swLimitation != null)
    {
        Console.WriteLine("\nSoftware Version Information:");
        Console.WriteLine("----------------------------");
        if (licenseInfo.Is_software_version_valid)
            Console.WriteLine("Software version is valid");
        else
            Console.WriteLine("\n===> Software version is not valid <===\n");
        Console.WriteLine($"Enforce Software Upgrade: {licenseInfo.Enforce_software_version_upgrade}");

        if (!string.IsNullOrEmpty(swLimitation.Software_release))
        {
            Console.WriteLine($"Software Release: {swLimitation.Software_release}");
        }

        if (!string.IsNullOrEmpty(swLimitation.Description))
        {
            Console.WriteLine($"Description: {swLimitation.Description}");
        }
    }
    */
    
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
