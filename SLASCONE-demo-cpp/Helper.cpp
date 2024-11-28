#include "Helper.h"
#include <openssl/pem.h>
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

#include "LicenseXmlValidator/LicenseXmlValidator.h"

using namespace std;
using namespace SLASCONE_demo_cpp;

    // Example PEM public key (replace this with your actual key)
    const std::string pemKey = R"(-----BEGIN PUBLIC KEY-----
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAwpigzm+cZIyw6x253YRD
mroGQyo0rO9qpOdbNAkE/FMSX+At5CQT/Cyr0eZTo2h+MO5gn5a6dwg2SYB/K1Yt
yuiKqnaEUfoPnG51KLrj8hi9LoZyIenfsQnxPz+r8XGCUPeS9MhBEVvT4ba0x9Ew
R+krU87VqfI3KNpFQVdLPaZxN4STTEZaet7nReeNtnnZFYaUt5XeNPB0b0rGfrps
y7drmZz81dlWoRcLrBRpkf6XrOTX4yFxe/3HJ8mpukuvdweUBFoQ0xOHmG9pNQ31
AHGtgLYGjbKcW4xYmpDGl0txfcipAr1zMj7X3oCO9lHcFRnXdzx+TTeJYxQX2XVb
hQIDAQAB
-----END PUBLIC KEY-----)";

/**
 * Helper:
 * 
 */
Helper::Helper(/* args */)
{
}

Helper::~Helper()
{
}

/**
 * verify_file:
 * @xml_file:           the signed XML file name.
 *
 * Verifies XML signature in #xml_file using public key from #key_file.
 *
 * Returns 0 on success or a negative value if an error occurs.
 */
int
Helper::verify_file(const char* xml_file) {
    LicenseXmlValidator::LicenseXmlValidator validator;
    return validator.verify_file(xml_file, pemKey.c_str(), pemKey.length());
}

int Helper::print_license_infos(const char* xml_file)
{
    // Read and deserialize the license XML file using libxml2
        
    return 0;
}