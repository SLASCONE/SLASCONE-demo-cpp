#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xpath.h>
#include <SlasconeOpenApiClient/api/ProvisioningApi.h>

using namespace std;
using namespace org::openapitools::client::model;

namespace SLASCONE_demo_cpp
{
    class LicenseXmlHelper
    {
    public:
        static int print_license_infos(const char* xml_file);

        protected:
        static int eval_xpath_expression(const xmlChar *xpathExpr, xmlXPathContextPtr xpathCtx, void (*print_func)(xmlNodeSetPtr));

        static void print_xpath_nodes(xmlNodeSetPtr nodes);
        static void print_element_names(xmlNode *node);

        static void print_features(xmlNodeSetPtr nodes);
        static void print_limitations(xmlNodeSetPtr nodes);
        static void print_constrained_variables(xmlNodeSetPtr nodes);
        static void print_variable(xmlNodeSetPtr nodes);

        static int fromXml(shared_ptr<ProvisioningFeatureDto> &feature, xmlNodePtr rootNode);
        static int fromXml(shared_ptr<ProvisioningLimitationDto> &limitation, xmlNodePtr rootNode);
        static int fromXml(shared_ptr<ProvisioningConstrainedVariableDto> &variable, xmlNodePtr rootNode);
        static int fromXml(shared_ptr<ProvisioningVariableDto> &variable, xmlNodePtr rootNode);
    };
}