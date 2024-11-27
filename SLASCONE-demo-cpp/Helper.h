// Helper class for SLASCONE

#include <iostream>
#include <fstream>
#include <string>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <openssl/err.h>

namespace SLASCONE_demo_cpp
{
    class Helper
    {
    private:
        /* data */
    public:
        Helper(/* args */);
        ~Helper();

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
        int verify_file(const char *xml_file);
    };

} // namespace SLASCONE_demo_
