#include "LicenseXmlHelper.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace utility::conversions;
using namespace SLASCONE_demo_cpp;

int LicenseXmlHelper::print_license_infos(const char* xml_file)
{
    xmlDocPtr doc;
    xmlXPathContextPtr xpathCtx; 

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
        return(-1);
    }

    /* Create xpath evaluation context */
    xpathCtx = xmlXPathNewContext(doc);
    if(xpathCtx == NULL) {
        cerr << "Error: unable to create new XPath context" << endl;
        xmlFreeDoc(doc); 
        return(-1);
    }
    
    /* Evaluate xpath expressions */
    const xmlChar* xpathExprs[] = {
        BAD_CAST "/slascone_license_file/license_key",
        BAD_CAST "/slascone_license_file/legacy_license_key",
        BAD_CAST "/slascone_license_file/license_name",
        BAD_CAST "/slascone_license_file/product_id",
        BAD_CAST "/slascone_license_file/expiration_date_utc",
        BAD_CAST "/slascone_license_file/customer/company_name",
	    BAD_CAST "/slascone_license_file/session_period",
	    BAD_CAST "/slascone_license_file/heartbeat_period",
	    BAD_CAST "/slascone_license_file/freeride",
        nullptr
    };

    for (int i = 0; xpathExprs[i] != nullptr; i++)
    {
        if (eval_xpath_expression(xpathExprs[i], xpathCtx, print_xpath_nodes) < 0) {
            fprintf(stderr,"Error: unable to evaluate xpath expression \"%s\"\n", xpathExprs[i]);
        }
    }

    const xmlChar* xpathExpr = BAD_CAST "/slascone_license_file/features";
    if (eval_xpath_expression(xpathExpr, xpathCtx, print_features) < 0) {
        fprintf(stderr,"Error: unable to evaluate xpath expression \"%s\"\n", xpathExpr);
    }

    xpathExpr = BAD_CAST "/slascone_license_file/limitations";
    if (eval_xpath_expression(xpathExpr, xpathCtx, print_limitations) < 0) {
        fprintf(stderr,"Error: unable to evaluate xpath expression \"%s\"\n", xpathExpr);
    }

    xpathExpr = BAD_CAST "/slascone_license_file/constrained_variables";
    if (eval_xpath_expression(xpathExpr, xpathCtx, print_constrained_variables) < 0) {
        fprintf(stderr,"Error: unable to evaluate xpath expression \"%s\"\n", xpathExpr);
    }

    xpathExpr = BAD_CAST "/slascone_license_file/variables";
    if (eval_xpath_expression(xpathExpr, xpathCtx, print_variable) < 0) {
        fprintf(stderr,"Error: unable to evaluate xpath expression \"%s\"\n", xpathExpr);
    }

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

    return 0;   
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
        cout << " - Feature name: " << to_utf8string(feature->getName()) << endl;
        cout << "   Feature description: " << to_utf8string(feature->getDescription()) << endl;
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
        cout << "   Limitation description: " << to_utf8string(limitation->getDescription()) << endl;
        cout << "   Limitation value: " << limitation->getValue() << endl;
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
        cout << "   Constrained variable description: " << to_utf8string(variable->getDescription()) << endl;
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
        cout << "   Variable description: " << to_utf8string(variable->getDescription()) << endl;
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
                feature->setId(reinterpret_cast<const char *>(xmlNodeGetContent(curNode)));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "name") == 0)
            {
                feature->setName(reinterpret_cast<const char *>(xmlNodeGetContent(curNode)));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "description") == 0)
            {
                feature->setDescription(reinterpret_cast<const char *>(xmlNodeGetContent(curNode)));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "is_active") == 0)
            {
                std::string isActiveStr(reinterpret_cast<const char *>(xmlNodeGetContent(curNode)));
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
                limitation->setId(reinterpret_cast<const char *>(xmlNodeGetContent(curNode)));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "name") == 0)
            {
                limitation->setName(reinterpret_cast<const char *>(xmlNodeGetContent(curNode)));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "description") == 0)
            {
                limitation->setDescription(reinterpret_cast<const char *>(xmlNodeGetContent(curNode)));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "value") == 0)
            {
                limitation->setValue(strtol(reinterpret_cast<const char *>(xmlNodeGetContent(curNode)), nullptr, 10));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "consumption_reset_mode") == 0)
            {
                auto resetPeriod = strtol(reinterpret_cast<const char *>(xmlNodeGetContent(curNode)), nullptr, 10);
                auto resetMode = make_shared<ConsumptionResetPeriod>();
                resetMode->setValue(static_cast<ConsumptionResetPeriod::eConsumptionResetPeriod>(resetPeriod));
                limitation->setConsumptionResetMode(resetMode);
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "consumption_reset_period_days") == 0)
            {
                limitation->setConsumptionResetPeriodDays(strtol(reinterpret_cast<const char *>(xmlNodeGetContent(curNode)), nullptr, 10));
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
                variable->setId(reinterpret_cast<const char *>(xmlNodeGetContent(curNode)));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "name") == 0)
            {
                variable->setName(reinterpret_cast<const char *>(xmlNodeGetContent(curNode)));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "description") == 0)
            {
                variable->setDescription(reinterpret_cast<const char *>(xmlNodeGetContent(curNode)));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "custom_list_id") == 0)
            {
                variable->setCustomListId(reinterpret_cast<const char *>(xmlNodeGetContent(curNode)));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "values") == 0)
            {
                values->push_back(reinterpret_cast<const char *>(xmlNodeGetContent(curNode)));
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
                variable->setId(reinterpret_cast<const char *>(xmlNodeGetContent(curNode)));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "name") == 0)
            {
                variable->setName(reinterpret_cast<const char *>(xmlNodeGetContent(curNode)));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "description") == 0)
            {
                variable->setDescription(reinterpret_cast<const char *>(xmlNodeGetContent(curNode)));
            }
            else if (xmlStrcmp(curNode->name, BAD_CAST "value") == 0)
            {
                variable->setValue(reinterpret_cast<const char *>(xmlNodeGetContent(curNode)));
            }
        }
    }
    return 0;
}
