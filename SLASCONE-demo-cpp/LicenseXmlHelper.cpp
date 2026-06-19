#include "LicenseXmlHelper.h"
#include "ValidityCheck.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace utility::conversions;
using namespace SLASCONE_demo_cpp;

namespace
{
    std::string get_node_text(xmlNodePtr node)
    {
        xmlChar* content = xmlNodeGetContent(node);
        if (content == nullptr)
        {
            return "";
        }

        std::string text(reinterpret_cast<const char*>(content));
        xmlFree(content);
        return text;
    }
}

int LicenseXmlHelper::print_license_infos(const XmlDocument* xml_license)
{
        // Display the main properties of the license
    cout << "\nLicense Information:" << endl;
    cout << "-------------------" << endl;
    cout << "License Name: " << xml_license->get_first_text(BAD_CAST "/slascone_license_file/license_name") << endl;
    cout << "License Key: " << xml_license->get_first_text(BAD_CAST "/slascone_license_file/license_key") << endl;

    string legacyLicenseKey = xml_license->get_first_text(BAD_CAST "/slascone_license_file/legacy_license_key");
    if (!legacyLicenseKey.empty())
    {
        cout << "Legacy License Key: " << legacyLicenseKey << endl;
    }

    string clientId = xml_license->get_first_text(BAD_CAST "/slascone_license_file/client_id");
    if (!clientId.empty())
    {
        cout << "Client ID: " << clientId << endl;
    }

    // Customer information
    string companyName = xml_license->get_first_text(BAD_CAST "/slascone_license_file/customer/company_name");
    string customerNumber = xml_license->get_first_text(BAD_CAST "/slascone_license_file/customer/customer_number");
    string customerId = xml_license->get_first_text(BAD_CAST "/slascone_license_file/customer_id");
    if (!companyName.empty() || !customerNumber.empty() || !customerId.empty())
    {
        cout << endl << "Customer Information:" << endl;
        cout << "---------------------" << endl;
        if (!customerId.empty())
        {
            cout << "Customer ID: " << customerId << endl;
        }
        cout << "Company Name: " << companyName << endl;
        cout << "Customer Number: " << customerNumber << endl;
    }

    // Product information
    cout << endl << "Product Information:" << endl;
    cout << "--------------------" << endl;
    cout << "Product ID: " << xml_license->get_first_text(BAD_CAST "/slascone_license_file/product_id") << endl;
    string productName = xml_license->get_first_text(BAD_CAST "/slascone_license_file/product_name");
    if (!productName.empty())
    {
        cout << "Product Name: " << productName << endl;
    }
    cout << "Template ID: " << xml_license->get_first_text(BAD_CAST "/slascone_license_file/template_id") << endl;
    string templateName = xml_license->get_first_text(BAD_CAST "/slascone_license_file/template_name");
    if (!templateName.empty())
    {
        cout << "Template Name: " << templateName << endl;
    }
    string provisioningMode = xml_license->get_first_text(BAD_CAST "/slascone_license_file/provisioning_mode");
    string clientType = xml_license->get_first_text(BAD_CAST "/slascone_license_file/client_type");
    if (!provisioningMode.empty() && !clientType.empty())
    {
        cout << "Provisioning mode / client type: " << provisioningMode << " / " << clientType << endl;
    }

    // License details
    cout << endl << "License Details:" << endl;
    cout << "----------------" << endl;
    string isTemporary = xml_license->get_first_text(BAD_CAST "/slascone_license_file/is_temporary");
    cout << "Is Temporary: " << (!isTemporary.empty() ? isTemporary : "false") << endl;

    string licenseTypeId = xml_license->get_first_text(BAD_CAST "/slascone_license_file/license_type_id");
    string licenseTypeName = xml_license->get_first_text(BAD_CAST "/slascone_license_file/license_type/name");
    if (!licenseTypeId.empty() && !licenseTypeName.empty())
    {
        cout << "License Type ID: " << licenseTypeId << endl;
        cout << "License Type: " << licenseTypeName << endl;
    }

    string createdDate = xml_license->get_first_text(BAD_CAST "/slascone_license_file/created_date_utc");
    string modifiedDate = xml_license->get_first_text(BAD_CAST "/slascone_license_file/modified_date_utc");
    string lastModifiedBy = xml_license->get_first_text(BAD_CAST "/slascone_license_file/last_modified_by");
    if (!createdDate.empty() && !modifiedDate.empty() && !lastModifiedBy.empty())
    {
        cout << endl << "License Dates:" << endl;
        cout << "--------------" << endl;
        cout << "Created Date: " << createdDate << endl;
        cout << "Modified Date: " << modifiedDate << endl;
        cout << "Last Modified By: " << lastModifiedBy << endl;
    }

    // Enumerate features
    xmlXPathObjectPtr featuresObj = xmlXPathEvalExpression(BAD_CAST "/slascone_license_file/features", xml_license->get_xpath_context());
    xmlNodeSetPtr featureNodes = (featuresObj != nullptr) ? featuresObj->nodesetval : nullptr;
    int featureCount = (featureNodes != nullptr) ? featureNodes->nodeNr : 0;
    if (featureCount == 0)
    {
        cout << endl << "No features available in this license." << endl;
    }
    else
    {
        cout << endl << "Features:" << endl;
        for (int i = 0; i < featureCount; ++i)
        {
            shared_ptr<ProvisioningFeatureDto> feature = make_shared<ProvisioningFeatureDto>();
            fromXml(feature, featureNodes->nodeTab[i]);

            cout << "- " << to_utf8string(feature->getName());
            if (!feature->isIsActive())
            {
                cout << " (not active)";
            }
            cout << endl;

            if (feature->descriptionIsSet() && !feature->getDescription().empty())
            {
                cout << "   Description: " << to_utf8string(feature->getDescription()) << endl;
            }
        }
    }
    if (featuresObj != nullptr)
    {
        xmlXPathFreeObject(featuresObj);
    }

    // Enumerate limitations
    xmlXPathObjectPtr limitationsObj = xmlXPathEvalExpression(BAD_CAST "/slascone_license_file/limitations", xml_license->get_xpath_context());
    xmlNodeSetPtr limitationNodes = (limitationsObj != nullptr) ? limitationsObj->nodesetval : nullptr;
    int limitationCount = (limitationNodes != nullptr) ? limitationNodes->nodeNr : 0;
    if (limitationCount == 0)
    {
        cout << endl << "No limitations available in this license." << endl;
    }
    else
    {
        cout << endl << "Limitations:" << endl;
        for (int i = 0; i < limitationCount; ++i)
        {
            shared_ptr<ProvisioningLimitationDto> limitation = make_shared<ProvisioningLimitationDto>();
            fromXml(limitation, limitationNodes->nodeTab[i]);

            cout << " - " << to_utf8string(limitation->getName());
            if (limitation->valueIsSet())
            {
                cout << " (Limit: " << limitation->getValue() << ")" << endl;
            }
            else
            {
                cout << " (unlimited)" << endl;
            }

            if (limitation->descriptionIsSet() && !limitation->getDescription().empty())
            {
                cout << "   Description: " << to_utf8string(limitation->getDescription()) << endl;
            }
        }
    }
    if (limitationsObj != nullptr)
    {
        xmlXPathFreeObject(limitationsObj);
    }

    // Enumerate constrained variables
    xmlXPathObjectPtr constrainedObj = xmlXPathEvalExpression(BAD_CAST "/slascone_license_file/constrained_variables", xml_license->get_xpath_context());
    xmlNodeSetPtr constrainedNodes = (constrainedObj != nullptr) ? constrainedObj->nodesetval : nullptr;
    int constrainedCount = (constrainedNodes != nullptr) ? constrainedNodes->nodeNr : 0;
    if (constrainedCount == 0)
    {
        cout << endl << "No constrained variables available in this license." << endl;
    }
    else
    {
        cout << endl << "Constrained Variables:" << endl;
        for (int i = 0; i < constrainedCount; ++i)
        {
            shared_ptr<ProvisioningConstrainedVariableDto> variable = make_shared<ProvisioningConstrainedVariableDto>();
            fromXml(variable, constrainedNodes->nodeTab[i]);

            cout << " - " << to_utf8string(variable->getName()) << endl;
            if (variable->descriptionIsSet() && !variable->getDescription().empty())
            {
                cout << "   Description: " << to_utf8string(variable->getDescription()) << endl;
            }
            cout << "   Value: ";
            for (auto value : variable->getValue())
            {
                cout << to_utf8string(value);
            }
            cout << endl;
        }
    }
    if (constrainedObj != nullptr)
    {
        xmlXPathFreeObject(constrainedObj);
    }

    // Enumerate variables
    xmlXPathObjectPtr variablesObj = xmlXPathEvalExpression(BAD_CAST "/slascone_license_file/variables", xml_license->get_xpath_context());
    xmlNodeSetPtr variableNodes = (variablesObj != nullptr) ? variablesObj->nodesetval : nullptr;
    int variableCount = (variableNodes != nullptr) ? variableNodes->nodeNr : 0;
    if (variableCount == 0)
    {
        cout << endl << "No variables available in this license." << endl;
    }
    else
    {
        cout << endl << "Variables:" << endl;
        for (int i = 0; i < variableCount; ++i)
        {
            shared_ptr<ProvisioningVariableDto> variable = make_shared<ProvisioningVariableDto>();
            fromXml(variable, variableNodes->nodeTab[i]);

            cout << " - " << to_utf8string(variable->getName()) << endl;
            cout << "   Description: " << to_utf8string(variable->getDescription()) << endl;
            cout << "   Value: " << to_utf8string(variable->getValue()) << endl;
        }
    }
    if (variablesObj != nullptr)
    {
        xmlXPathFreeObject(variablesObj);
    }

    // User information if present
    xmlXPathObjectPtr usersObj = xmlXPathEvalExpression(BAD_CAST "/slascone_license_file/license_users", xml_license->get_xpath_context());
    int userCount = (usersObj != nullptr && usersObj->nodesetval != nullptr) ? usersObj->nodesetval->nodeNr : 0;
    if (userCount > 0)
    {
        cout << endl << "License Users:" << endl;
        cout << "Number of users: " << userCount << endl;
    }
    if (usersObj != nullptr)
    {
        xmlXPathFreeObject(usersObj);
    }

    return 0;   
}

bool LicenseXmlHelper::check_license_validity(const XmlDocument* xml_license)
{
    // License validity status
    cout << endl << "License Validity Status:" << endl;
    cout << "-----------------------" << endl;

    // Since a license file is created once but read many times the validity status has to be checked every time 
    // separately from the start date and the expiration date, to make sure the license is valid at the moment of reading it.

    time_t now = time(nullptr);

    bool isNotYetValid = true;
    string startDateUtc = xml_license->get_first_text(BAD_CAST "/slascone_license_file/start_date_utc");
    if (!startDateUtc.empty())
    {
        std::tm startTm = {};
        bool startDateValid = !startDateUtc.empty() && strptime(startDateUtc.c_str(), "%Y-%m-%dT%H:%M:%SZ", &startTm) != nullptr;

        isNotYetValid = startDateValid && 0 < difftime(timegm(&startTm), now);
    }

    bool isExpired = true;
    bool isPerpetualLicense = false;
    string expirationDateUtc = xml_license->get_first_text(BAD_CAST "/slascone_license_file/expiration_date_utc");
    if (!expirationDateUtc.empty())
    {
        std::tm expirationTm = {};
        bool expirationDateValid = !expirationDateUtc.empty() && strptime(expirationDateUtc.c_str(), "%Y-%m-%dT%H:%M:%SZ", &expirationTm) != nullptr;

        isExpired = expirationDateValid && difftime(timegm(&expirationTm), now) < 0;

        expirationTm.tm_year += 1900; // Adjust year since tm_year is years since 1900
        isPerpetualLicense = (9999 == expirationTm.tm_year);
    }

    bool valid = !(isNotYetValid || isExpired);

    cout << endl << "===> License is " << (valid ? "valid" : "not valid") << " <===" << endl << endl;

    if (isNotYetValid)
    {
        cout << "License is valid from " << startDateUtc << "." << endl;
    }

    if (isExpired)    
    {
        cout << "The license is expired since " << expirationDateUtc << "." << endl;
    }
    else
    {
        if (isPerpetualLicense)
        {
            cout << "This is a perpetual license." << endl;
        }
        else
        {
            cout << "License is valid until " << expirationDateUtc << "." << endl;
        }
    }

    return valid;
}

bool LicenseXmlHelper::check_software_release_limitation_validity(const XmlDocument* xml_license)
{
    auto softwareReleaseLimitation = make_shared<SoftwareReleaseLimitationDto>();
    int ret = fromXml(softwareReleaseLimitation, xml_license);
    if (ret != 0)    {
        cerr << "Error while reading software release limitation from license file." << endl;
        return false;
    }

    return ValidityCheck::check_license_validity(softwareReleaseLimitation);
}

int LicenseXmlHelper::eval_xpath_expression(const xmlChar *xpathExpr, xmlXPathContextPtr xpathCtx, void (*print_func)(xmlNodeSetPtr))
{
    xmlXPathObjectPtr xpathObj;

    /* Evaluate xpath expression */
    xpathObj = xmlXPathEvalExpression(xpathExpr, xpathCtx);
    if (xpathObj == NULL)
    {
        cerr << "Error: unable to evaluate xpath expression \"" << xpathExpr << "\"" << endl;
        return (-1);
    }

    /* Print results */
    print_func(xpathObj->nodesetval);

    /* Cleanup */
    xmlXPathFreeObject(xpathObj);
    
    return(0);
}

void LicenseXmlHelper::print_xpath_nodes(xmlNodeSetPtr nodes)
{
    xmlNodePtr cur;
    int size;
    int i;

    size = (nodes) ? nodes->nodeNr : 0;

    for (i = 0; i < size; ++i)
    {
        assert(nodes->nodeTab[i]);

        if (nodes->nodeTab[i]->type == XML_ELEMENT_NODE)
        {
            cur = nodes->nodeTab[i];
            cout << cur->name << ": ";
            print_element_names(cur->children);
        }
    }
}

void LicenseXmlHelper::print_element_names(xmlNode *node)
{
    xmlNode *cur_node = NULL;

    for (cur_node = node; cur_node; cur_node = cur_node->next)
    {
        switch (cur_node->type)
        {
        case XML_ELEMENT_NODE:
            cout << cur_node->name << ": ";
            break;

        case XML_TEXT_NODE:
            cout << cur_node->content << endl;
            break;
        
        default:
            break;
        }

        print_element_names(cur_node->children);
    }
}

void LicenseXmlHelper::print_features(xmlNodeSetPtr nodes)
{
    xmlNodePtr cur;
    int size;
    int i;

    size = (nodes) ? nodes->nodeNr : 0;

    for (i = 0; i < size; ++i)
    {
        assert(nodes->nodeTab[i]);

        shared_ptr<ProvisioningFeatureDto> feature = make_shared<ProvisioningFeatureDto>();
        fromXml(feature, nodes->nodeTab[i]);
        cout << " - Feature name: " << to_utf8string(feature->getName());
        feature->isIsActive() ? cout << endl : cout << " (not active)" << endl;
        cout << "   Feature description: " << (feature->descriptionIsSet() ? to_utf8string(feature->getDescription()) : "not set") << endl;
    }
}

void LicenseXmlHelper::print_limitations(xmlNodeSetPtr nodes)
{
    xmlNodePtr cur;
    int size;
    int i;

    size = (nodes) ? nodes->nodeNr : 0;

    for (i = 0; i < size; ++i)
    {
        assert(nodes->nodeTab[i]);

        shared_ptr<ProvisioningLimitationDto> limitation = make_shared<ProvisioningLimitationDto>();
        fromXml(limitation, nodes->nodeTab[i]);
        cout << " - Limitation name: " << to_utf8string(limitation->getName()) << endl;
        cout << "   Limitation description: " << (limitation->descriptionIsSet() ? to_utf8string(limitation->getDescription()) : "not set") << endl;
        limitation->valueIsSet() 
            ? cout << "   Limitation value: " << limitation->getValue() << endl
            : cout << "   Unlimited limitation" << endl;
    }
}

void LicenseXmlHelper::print_constrained_variables(xmlNodeSetPtr nodes)
{
    xmlNodePtr cur;
    int size;
    int i;

    size = (nodes) ? nodes->nodeNr : 0;

    for (i = 0; i < size; ++i)
    {
        assert(nodes->nodeTab[i]);

        shared_ptr<ProvisioningConstrainedVariableDto> variable = make_shared<ProvisioningConstrainedVariableDto>();
        fromXml(variable, nodes->nodeTab[i]);
        cout << " - Constrained variable name: " << to_utf8string(variable->getName()) << endl;
        variable->descriptionIsSet() 
            ? cout << "   Constrained variable description: " << to_utf8string(variable->getDescription()) << endl
            : cout << "   Constrained variable description: not set" << endl;
        cout << "   Constrained variable values: ";
        for (auto value : variable->getValue())
        {
            cout << to_utf8string(value) << ", ";
        }
        cout << endl;
    }
}

void LicenseXmlHelper::print_variable(xmlNodeSetPtr nodes)
{
    xmlNodePtr cur;
    int size;
    int i;

    size = (nodes) ? nodes->nodeNr : 0;

    for (i = 0; i < size; ++i)
    {
        assert(nodes->nodeTab[i]);

        shared_ptr<ProvisioningVariableDto> variable = make_shared<ProvisioningVariableDto>();
        fromXml(variable, nodes->nodeTab[i]);
        cout << " - Variable name: " << to_utf8string(variable->getName()) << endl;
        variable->descriptionIsSet() 
             ? cout << "   Variable description: " << to_utf8string(variable->getDescription()) << endl
             : cout << "   Variable description: not set" << endl;
        cout << "   Variable value: " << to_utf8string(variable->getValue()) << endl;
    }
}

int LicenseXmlHelper::fromXml(shared_ptr<ProvisioningFeatureDto> &feature, xmlNodePtr rootNode)
{
    for (xmlNodePtr curNode = rootNode->children; curNode != nullptr; curNode = curNode->next)
    {
        if (curNode->type == XML_ELEMENT_NODE)
        {
            if (xmlStrcmp(curNode->name, BAD_CAST "id") == 0)
            {
                feature->setId(get_node_text(curNode));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "name") == 0)
            {
                feature->setName(get_node_text(curNode));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "description") == 0)
            {
                feature->setDescription(get_node_text(curNode));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "is_active") == 0)
            {
                std::string isActiveStr = get_node_text(curNode);
                feature->setIsActive(isActiveStr == "true");
            }
        }
    }
    return 0;
}

int LicenseXmlHelper::fromXml(shared_ptr<ProvisioningLimitationDto> &limitation, xmlNodePtr rootNode)
{
    for (xmlNodePtr curNode = rootNode->children; curNode != nullptr; curNode = curNode->next)
    {
        if (curNode->type == XML_ELEMENT_NODE)
        {
            if (xmlStrcmp(curNode->name, BAD_CAST "id") == 0)
            {
                limitation->setId(get_node_text(curNode));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "name") == 0)
            {
                limitation->setName(get_node_text(curNode));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "description") == 0)
            {
                limitation->setDescription(get_node_text(curNode));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "value") == 0)
            {
                auto valueStr = get_node_text(curNode);
                if (!valueStr.empty())
                {
                    limitation->setValue(strtol(valueStr.c_str(), nullptr, 10));
                }
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "consumption_reset_mode") == 0)
            {
                auto resetModeStr = get_node_text(curNode);
                auto resetPeriod = strtol(resetModeStr.c_str(), nullptr, 10);
                auto resetMode = make_shared<ConsumptionResetPeriod>();
                resetMode->setValue(static_cast<ConsumptionResetPeriod::eConsumptionResetPeriod>(resetPeriod));
                limitation->setConsumptionResetMode(resetMode);
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "consumption_reset_period_days") == 0)
            {
                auto periodDaysStr = get_node_text(curNode);
                limitation->setConsumptionResetPeriodDays(strtol(periodDaysStr.c_str(), nullptr, 10));
            }
        }
    }
    return 0;
}

int LicenseXmlHelper::fromXml(shared_ptr<ProvisioningConstrainedVariableDto> &variable, xmlNodePtr rootNode)
{
    auto values = make_shared<vector<utility::string_t>>();

    for (xmlNodePtr curNode = rootNode->children; curNode != nullptr; curNode = curNode->next)
    {
        if (curNode->type == XML_ELEMENT_NODE)
        {
            if (xmlStrcmp(curNode->name, BAD_CAST "id") == 0)
            {
                variable->setId(get_node_text(curNode));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "name") == 0)
            {
                variable->setName(get_node_text(curNode));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "description") == 0)
            {
                variable->setDescription(get_node_text(curNode));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "custom_list_id") == 0)
            {
                variable->setCustomListId(get_node_text(curNode));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "values") == 0)
            {
                values->push_back(get_node_text(curNode));
            }
        }
    }

    variable->setValue(*values);

    return 0;
}

int LicenseXmlHelper::fromXml(shared_ptr<ProvisioningVariableDto> &variable, xmlNodePtr rootNode)
{
    for (xmlNodePtr curNode = rootNode->children; curNode != nullptr; curNode = curNode->next)
    {
        if (curNode->type == XML_ELEMENT_NODE)
        {
            if (xmlStrcmp(curNode->name, BAD_CAST "id") == 0)
            {
                variable->setId(get_node_text(curNode));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "name") == 0)
            {
                variable->setName(get_node_text(curNode));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "description") == 0)
            {
                variable->setDescription(get_node_text(curNode));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "value") == 0)
            {
                variable->setValue(get_node_text(curNode));
            }
        }
    }
    return 0;
}

int LicenseXmlHelper::fromXml(shared_ptr<SoftwareReleaseLimitationDto> &releaseLimitation, const XmlDocument* xml_license)
{
    // Software version information
    bool hasSwSection = xml_license->node_exists(BAD_CAST "/slascone_license_file/software_release_limitation");
    if (!hasSwSection)
    {
        return -1; // No software release limitation section, so nothing to populate
    }

    string softwareRelease = xml_license->get_first_text(BAD_CAST "/slascone_license_file/software_release_limitation/software_release");
    if (!softwareRelease.empty())
    {
        releaseLimitation->setSoftwareRelease(softwareRelease);
    }

    string swDescription = xml_license->get_first_text(BAD_CAST "/slascone_license_file/software_release_limitation/description");
    if (!swDescription.empty())
    {
        releaseLimitation->setDescription(swDescription);
    }

    return 0;
}

XmlDocument::XmlDocument(const char* xml_file)
{
    assert(xml_file);

    /*
     * this initialize the library and check potential ABI mismatches
     * between the version it was compiled for and the actual shared
     * library used.
     */
    xmlInitParser();
    LIBXML_TEST_VERSION

    /* Load XML document */
    doc = xmlParseFile(xml_file);
    if (doc == NULL) {
        cerr << "Error: unable to parse file \"" << xml_file << "\"" << endl;
    }

    /* Create xpath evaluation context */
    xpathCtx = xmlXPathNewContext(doc);
    if(xpathCtx == NULL) {
        cerr << "Error: unable to create new XPath context" << endl;
        xmlFreeDoc(doc); 
    }
}

XmlDocument::~XmlDocument()
{    
    /* Cleanup */
    xmlXPathFreeContext(xpathCtx); 
    xmlFreeDoc(doc); 

    /*
     *Free the global variables that may
     *have been allocated by the parser.
     */
    xmlCleanupParser();

    /*
     * this is to debug memory for regression tests
     */
    xmlMemoryDump();    
}

string XmlDocument::get_first_text(const xmlChar* xpathExpr) const
{
    xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression(xpathExpr, xpathCtx);
    if (xpathObj == nullptr || xpathObj->nodesetval == nullptr || xpathObj->nodesetval->nodeNr == 0)
    {
        if (xpathObj != nullptr)
        {
            xmlXPathFreeObject(xpathObj);
        }
        return "";
    }

    xmlNodePtr node = xpathObj->nodesetval->nodeTab[0];
    xmlChar* content = xmlNodeGetContent(node);
    string result = (content != nullptr) ? reinterpret_cast<const char*>(content) : "";
    if (content != nullptr)
    {
        xmlFree(content);
    }
    xmlXPathFreeObject(xpathObj);
    return result;
}

bool XmlDocument::node_exists(const xmlChar* xpathExpr) const
{
    xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression(xpathExpr, xpathCtx);
    bool exists = xpathObj != nullptr && xpathObj->nodesetval != nullptr && xpathObj->nodesetval->nodeNr > 0;
    if (xpathObj != nullptr)
    {
        xmlXPathFreeObject(xpathObj);
    }
    return exists;
}

xmlXPathContextPtr XmlDocument::get_xpath_context() const
{
    return xpathCtx;
}