#include <stddef.h>

namespace SLASCONE_demo_cpp::LicenseXmlValidator
{
    class LicenseXmlValidator
    {
        public:
            LicenseXmlValidator();
            virtual ~LicenseXmlValidator();
            
            int verify_file(const char *xml_file, const char *pemKey, size_t pemKeyLength);
    };

} // namespace SLASCONE_demo_cpp::LicenseXmlValidator
