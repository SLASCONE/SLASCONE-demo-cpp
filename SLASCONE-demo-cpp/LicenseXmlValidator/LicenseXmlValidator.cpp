#include <openssl/pem.h>
#include <iostream>
#include <openssl/x509.h>
#include <openssl/err.h>
#include <openssl/rsa.h>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <xmlsec/xmlsec.h>
#include <xmlsec/xmltree.h>
#include <xmlsec/xmldsig.h>
#include <xmlsec/app.h>
#include <xmlsec/openssl/app.h>
#include <xmlsec/crypto.h>
#include <xmlsec/errors.h>
#include "LicenseXmlValidator.h"
#include "LicenseXmlValidation.h"

using namespace std;
using namespace SLASCONE_demo_cpp::LicenseXmlValidator;

// Constructor
LicenseXmlValidator::LicenseXmlValidator()
{
    /* Init libxml libraries */
    xmlInitParser();
    LIBXML_TEST_VERSION xmlLoadExtDtdDefaultValue = XML_DETECT_IDS | XML_COMPLETE_ATTRS;
    xmlSubstituteEntitiesDefault(1);

    /* Init xmlsec library */
    if (xmlSecInit() < 0)
    {
        throw runtime_error("Error: xmlsec initialization failed.");
    }

    /* Check loaded library version */
    if (xmlSecCheckVersion() != 1)
    {
        throw runtime_error("Error: loaded xmlsec library version is not compatible.\n");
    }

    /* Init crypto library */
    if (xmlSecCryptoAppInit(NULL) < 0)
    {
        throw runtime_error("Error: crypto initialization failed.\n");
    }

    /* Init xmlsec-crypto library */
    if (xmlSecCryptoInit() < 0)
    {
        throw runtime_error("Error: xmlsec-crypto initialization failed.\n");
    }
}

// Destructor
LicenseXmlValidator::~LicenseXmlValidator()
{
    /* Shutdown xmlsec-crypto library */
    xmlSecCryptoShutdown();

    /* Shutdown crypto library */
    xmlSecShutdown();

    xmlCleanupParser();
}

/**
 * verify_file:
 * @xml_file:           the signed XML file name.
 * @pemKey:             the PEM public key.
 * @pemKeyLength:       the length of the PEM public key.
 *
 * Verifies XML signature in #xml_file using public key from #key_file.
 *
 * Returns 0 on success or a negative value if an error occurs.
 */
int LicenseXmlValidator::verify_file(const char *xml_file, const char *pemKey, size_t pemKeyLength)
{
    LicenseXmlValidation licenseXmlValidation;
    xmlNodePtr node = NULL;

    try
    {
        /* load file */
        licenseXmlValidation.setDoc(xmlReadFile(xml_file, NULL, XML_PARSE_PEDANTIC | XML_PARSE_NONET));
        if ((licenseXmlValidation.getDoc() == NULL) || (xmlDocGetRootElement(licenseXmlValidation.getDoc()) == NULL))
        {
            throw runtime_error(string("Error: unable to parse file \"") + string(xml_file) + string("\""));
        }

        /* find start node */
        node = xmlSecFindNode(xmlDocGetRootElement(licenseXmlValidation.getDoc()), xmlSecNodeSignature, xmlSecDSigNs);
        if (node == NULL)
        {
            throw runtime_error(string("Error: start node not found in \"") + string(xml_file) + string("\""));
        }

        /* create signature context, we don't need keys manager in this example */
        licenseXmlValidation.setDsigCtx(xmlSecDSigCtxCreate(NULL));
        if (licenseXmlValidation.getDsigCtx() == NULL)
        {
            throw runtime_error("Error: failed to create signature context\n");
        }

        /* load public key */
        licenseXmlValidation.getDsigCtx()->signKey = xmlSecCryptoAppKeyLoadMemory((xmlSecByte *)pemKey, pemKeyLength, xmlSecKeyDataFormatPem, NULL, NULL, NULL);
        if (licenseXmlValidation.getDsigCtx()->signKey == NULL)
        {
            throw runtime_error("Error: failed to load public pem key.\n");
        }

        /* Verify signature */
        if (xmlSecDSigCtxVerify(licenseXmlValidation.getDsigCtx(), node) < 0)
        {
            throw runtime_error("Error: signature verify\n");
        }

        /* print verification result to stdout */
        if (licenseXmlValidation.getDsigCtx()->status == xmlSecDSigStatusSucceeded)
        {
            cout << "Signature is OK" << endl;
            return 0;
        }
        else
        {
            cout << "Signature is INVALID" << endl;
            return -1;
        }
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
        return -1;
    }
}