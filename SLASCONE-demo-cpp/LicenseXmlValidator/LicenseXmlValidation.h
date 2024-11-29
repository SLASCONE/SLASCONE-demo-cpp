#include <xmlsec/xmltree.h>
#include <xmlsec/xmldsig.h>

namespace SLASCONE_demo_cpp::LicenseXmlValidator
{
    class LicenseXmlValidation
    {
    private:
        xmlDocPtr doc = NULL;
        xmlSecDSigCtxPtr dsigCtx = NULL;

    public:
        LicenseXmlValidation();
        virtual ~LicenseXmlValidation();

        xmlDocPtr getDoc() const { return doc; }
        void setDoc(xmlDocPtr doc) { this->doc = doc; }

        xmlSecDSigCtxPtr getDsigCtx() const { return dsigCtx; }
        void setDsigCtx(xmlSecDSigCtxPtr dsigCtx) { this->dsigCtx = dsigCtx; }
    };

} // namespace SLASCONE_demo_cpp::LicenseXmlValidator
