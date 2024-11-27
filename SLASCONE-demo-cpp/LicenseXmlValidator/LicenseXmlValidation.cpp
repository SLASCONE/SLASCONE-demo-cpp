#include "LicenseXmlValidation.h"

using namespace SLASCONE_demo_cpp::LicenseXmlValidator;

LicenseXmlValidation::LicenseXmlValidation()
{
}

LicenseXmlValidation::~LicenseXmlValidation()
{
    /* cleanup */
    if (dsigCtx != NULL) {
        xmlSecDSigCtxDestroy(dsigCtx);
    }

    if (doc != NULL) {
        xmlFreeDoc(doc);
    }
}
