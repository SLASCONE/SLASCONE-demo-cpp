#include <iostream>
#include <string>
#include <ctime>
#include <cstdint>
#include <cpprest/asyncrt_utils.h>
#include "LicensePrettyPrinter.h"

using namespace std;
using namespace org::openapitools::client::model;
using namespace utility;
using namespace utility::conversions;
using namespace SLASCONE_demo_cpp;

int LicensePrettyPrinter::print_license(shared_ptr<LicenseDto> licenseDto)
{
    if (licenseDto == nullptr)
    {
        return -1;
    }

    // Display the main properties of the license
    cout << "\nLicense Information:" << endl;
    cout << "-------------------" << endl;
    cout << "License Name: " << (licenseDto->nameIsSet() ? to_utf8string(licenseDto->getName()) : "") << endl;
    cout << "License Key: " << (licenseDto->idIsSet() ? to_utf8string(licenseDto->getId()) : "") << endl;

    if (licenseDto->legacyLicenseKeyIsSet() && !licenseDto->getLegacyLicenseKey().empty())
    {
        cout << "Legacy License Key: " << to_utf8string(licenseDto->getLegacyLicenseKey()) << endl;
    }

    if (licenseDto->clientIdIsSet() && !licenseDto->getClientId().empty())
    {
        cout << "Client ID: " << to_utf8string(licenseDto->getClientId()) << endl;
    }

    // Customer information
    auto customer = licenseDto->getCustomer();
    if (customer != nullptr)
    {
        cout << endl << "Customer Information:" << endl;
        cout << "---------------------" << endl;
        if (licenseDto->customerIdIsSet())
        {
            cout << "Customer ID: " << to_utf8string(licenseDto->getCustomerId()) << endl;
        }
        cout << "Company Name: " << to_utf8string(customer->getCompanyName()) << endl;
        cout << "Customer Number: " << to_utf8string(customer->getCustomerNumber()) << endl;
    }

    // Product information
    cout << endl << "Product Information:" << endl;
    cout << "--------------------" << endl;
    cout << "Product ID: " << (licenseDto->productIdIsSet() ? to_utf8string(licenseDto->getProductId()) : "") << endl;
    auto product = licenseDto->getProduct();
    if (product != nullptr)
    {
        cout << "Product Name: " << to_utf8string(product->getName()) << endl;
    }
    cout << "Template ID: " << (licenseDto->templateIdIsSet() ? to_utf8string(licenseDto->getTemplateId()) : "") << endl;
    auto rtemplate = licenseDto->getRTemplate();
    if (rtemplate != nullptr)
    {
        cout << "Template Name: " << to_utf8string(rtemplate->getName()) << endl;
        if (rtemplate->provisioningModeIsSet() && rtemplate->clientTypeIsSet())
        {
            shared_ptr<ProvisioningMode> provisioningMode = rtemplate->getProvisioningMode();
            shared_ptr<ClientType> clientType = rtemplate->getClientType();
            cout << "Provisioning mode / client type: " << static_cast<utility::string_t>(*provisioningMode) << " / " << static_cast<utility::string_t>(*clientType) << endl;
        }
    }

    // License details
    cout << endl << "License Details:" << endl;
    cout << "----------------" << endl;
    cout << "Is Temporary: " << licenseDto->isIsTemporary() << endl;

    if (licenseDto->licenseTypeIdIsSet() && licenseDto->licenseTypeIsSet()) 
    {
        cout << "License Type ID: " << to_utf8string(licenseDto->getLicenseTypeId()) << endl;
        cout << "License Type: " << to_utf8string(licenseDto->getLicenseType()->getName()) << endl;
    }

    if (licenseDto->createdDateUtcIsSet() && licenseDto->modifiedDateUtcIsSet() && licenseDto->lastModifiedByIsSet())
    {
        cout << endl << "License Dates:" << endl;
        cout << "--------------" << endl;
        cout << "Created Date: " << licenseDto->getCreatedDateUtc().to_string() << endl;
        cout << "Modified Date: " << licenseDto->getModifiedDateUtc().to_string() << endl;
        cout << "Last Modified By: " << to_utf8string(licenseDto->getLastModifiedBy()) << endl;
    }

    // Enumerate features
    auto features = licenseDto->getLicenseFeatures();
    if (features.empty())
    {
        cout << endl << "No features available in this license." << endl;
    }
    else
    {
        cout << endl << "Features:" << endl;
        for (auto feature : features)
        {
            cout << "- " << to_utf8string(feature->getFeatureName());
            if (feature->isActiveIsSet() && !feature->isIsActive())
            {
                cout << " (not active)";
            }   
            cout << endl;
            if (feature->featureDescriptionIsSet() && !feature->getFeatureDescription().empty())
            {
                cout << "   Description: " << to_utf8string(feature->getFeatureDescription()) << endl;
            }
            if (feature->featureExceptionsIsSet() && feature->getFeatureExceptions()->exceptionsIsSet() && !feature->getFeatureExceptions()->getExceptions().empty())
            {
                auto exceptions = feature->getFeatureExceptions();
                cout << "   Exceptions:" << endl;
                for (const auto& exception : exceptions->getExceptions())
                {
                    cout << "     - From " << exception->getStartDateUtc().to_string() << " to " << exception->getEndDateUtc().to_string() << (exception->temporaryIsActiveIsSet() && exception->isTemporaryIsActive() ? " (temporary active)" : "") << endl;
                }
            }
        }
    }

    // Enumerate limitations
    auto limitations = licenseDto->getLicenseLimitations();
    if (limitations.empty())
    {
        cout << endl << "No limitations available in this license." << endl;
    }
    else
    {
        cout << endl << "Limitations:" << endl;
        for (auto limitation : limitations)
        {
            cout << " - " << to_utf8string(limitation->getLimitationName());
            if (limitation->limitIsSet())
            {
                cout << " (Limit: " << limitation->getLimit() << ")" << endl;
            }
            else
            {
                cout << " (unlimited)" << endl;
            }
            
            cout << "   Description: " << to_utf8string(limitation->getLimitationDescription()) << endl;
        }
    }

    auto constrainedVariables = licenseDto->getLicenseConstrainedVariables();
    if (constrainedVariables.empty())
    {
        cout << endl << "No constrained variables available in this license." << endl;
    }
    else
    {
        cout << endl << "Constrained Variables:" << endl;
        for (auto constrainedVariable : constrainedVariables)
        {
            cout << " - " << to_utf8string(constrainedVariable->getVariableName()) << endl;
            if (constrainedVariable->variableDescriptionIsSet() && !constrainedVariable->getVariableDescription().empty())
            {
                cout << "   Description: " << to_utf8string(constrainedVariable->getVariableDescription()) << endl;
            }
            cout << "   Value: ";
            for (auto value : constrainedVariable->getValues())
            {
                cout << to_utf8string(value);
            }
            cout << endl;
        }
    }

    auto variables = licenseDto->getLicenseVariables();
    if (variables.empty())
    {
        cout << endl << "No variables available in this license." << endl;
    }
    else
    {
        cout << endl << "Variables:" << endl;
        for (auto variable : variables)
        {
            cout << " - " << to_utf8string(variable->getVariableName()) << endl;
            cout << "   Description: " << to_utf8string(variable->getVariableDescription()) << endl;
            cout << "   Value: " << to_utf8string(variable->getValue()) << endl;
        }
    }

    // User information if present
    auto licenseUsers = licenseDto->getLicenseUsers();
    if (!licenseUsers.empty())
    {
        cout << endl << "License Users:" << endl;
        cout << "Number of users: " << licenseUsers.size() << endl;
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

    // Customer information
    auto customer = licenseInfoDto->getCustomer();
    if (customer != nullptr)
    {
        cout << endl << "Customer Information:" << endl;
        cout << "---------------------" << endl;
        cout << "Customer ID: " << to_utf8string(customer->getCustomerId()) << endl;
        cout << "Company Name: " << to_utf8string(customer->getCompanyName()) << endl;

        if (customer->customerNumberIsSet())
        {
            cout << "Customer Number: " << to_utf8string(customer->getCustomerNumber()) << endl;
        }
    }

    // Product information
    cout << endl << "Product Information:" << endl;
    cout << "--------------------" << endl;
    cout << "Product Name: " << to_utf8string(licenseInfoDto->getProductName()) << endl;
    cout << "Template Name: " << to_utf8string(licenseInfoDto->getTemplateName()) << endl;
    shared_ptr<ProvisioningMode> provisioningMode = licenseInfoDto->getProvisioningMode();
    shared_ptr<ClientType> clientType = licenseInfoDto->getClientType();
    cout << "Provisioning mode / client type: " << static_cast<utility::string_t>(*provisioningMode) << " / " << static_cast<utility::string_t>(*clientType) << endl;

    // License details
    cout << endl << "License Details:" << endl;
    cout << "----------------" << endl;
    cout << "Is Temporary: " << licenseInfoDto->isIsTemporary() << endl;
    if (licenseInfoDto->heartbeatPeriodIsSet())
    {
        cout << "Heartbeat Period: " << licenseInfoDto->getHeartbeatPeriod() << " days" << endl;
    }

    // Date information and license validity
    if (licenseInfoDto->createdDateUtcIsSet())
    {
        cout << "Created Date: " << licenseInfoDto->getCreatedDateUtc().to_string() << endl;
    }

    if (licenseInfoDto->getSessionPeriod() > 0)
    {
        cout << "Session Period: " << licenseInfoDto->getSessionPeriod() << " days" << endl;
    }

    if (licenseInfoDto->getFreeride() > 0)
    {
        cout << "Freeride granted for " << licenseInfoDto->getFreeride() << " day(s)." << endl;
    }

    // Enumerate features
    auto features = licenseInfoDto->getFeatures();
    if (features.empty())
    {
        cout << endl << "No features available in this license." << endl;
    }
    else
    {
        cout << endl << "Features:" << endl;
        for (auto feature : features)
        {
            cout << "- " << to_utf8string(feature->getName());
            feature->isIsActive() ? cout << endl : cout << " (not active)" << endl;
            if (feature->descriptionIsSet() && !feature->getDescription().empty())
            {
                cout << "   Description: " << to_utf8string(feature->getDescription()) << endl;
            }
            if (feature->expirationDateUtcIsSet())
            {
                cout << "   Expires: " << feature->getExpirationDateUtc().to_string() << endl;
            }
        }
    }

    // Enumerate limitations
    auto limitations = licenseInfoDto->getLimitations();
    if (limitations.empty())
    {
        cout << endl << "No limitations available in this license." << endl;
    }
    else
    {
        cout << endl << "Limitations:" << endl;
        for (auto limitation : limitations)
        {
            cout << " - " << to_utf8string(limitation->getName());
             if (limitation->valueIsSet())
             {
                 cout << " (" << to_string(limitation->getValue()) << ")" << endl;
             }
             else
             {
                 cout << " (Unlimited)" << endl;
             }

            if (limitation->descriptionIsSet() && !limitation->getDescription().empty())
            {
                cout << "   Description: " << to_utf8string(limitation->getDescription()) << endl;
            }

            if (limitation->remainingIsSet())
            {
                cout << "   remaining: " << limitation->getRemaining() << endl;
            }

            if (limitation->balanceIsSet())
            {
                cout << "   balance: " << limitation->getBalance() << endl;
            }
        }
    }

    auto constrainedVariables = licenseInfoDto->getConstrainedVariables();
    if (constrainedVariables.empty())
    {
        cout << endl << "No constrained variables available in this license." << endl;
    }
    else
    {
        cout << endl << "Constrained Variables:" << endl;
        for (auto constrainedVariable : constrainedVariables)
        {
            cout << " - " << to_utf8string(constrainedVariable->getName()) << endl;
            if (constrainedVariable->descriptionIsSet() && !constrainedVariable->getDescription().empty()) 
            {
                cout << "   Description: " << to_utf8string(constrainedVariable->getDescription()) << endl;
            }
            cout << "   Value: ";            
            for (auto value : constrainedVariable->getValue())
            {
                cout << to_utf8string(value);
            }
            cout << endl;
        }
    }

    auto variables = licenseInfoDto->getVariables();
    if (variables.empty())
    {
        cout << endl << "No variables available in this license." << endl;
    }
    else
    {
        cout << endl << "Variables:" << endl;
        for (auto variable : variables)
        {
            cout << " - " << to_utf8string(variable->getName()) << endl;
            if (variable->descriptionIsSet() && !variable->getDescription().empty())
            {
                cout << "   Description: " << to_utf8string(variable->getDescription()) << endl;
            }
            cout << "   Value: " << to_utf8string(variable->getValue()) << endl;
        }
    }

    // User information if present
    auto licenseUsers = licenseInfoDto->getLicenseUsers();
    if (!licenseUsers.empty())
    {
        cout << endl << "License Users:" << endl;
        cout << "Number of users: " << licenseUsers.size() << endl;
    }

    return 0;
}
