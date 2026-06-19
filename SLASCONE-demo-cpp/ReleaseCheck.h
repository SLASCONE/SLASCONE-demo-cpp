#include <string>
#include <vector>
#include <sstream>
#include <regex>
#include <stdexcept>

using namespace std;

namespace SLASCONE_demo_cpp
{
    class ReleaseCheck
    {
    public:
        // Compare function returns:
        // -1 if softwareVersion is higher than releaseLimitation
        // 0 if softwareVersion is equal to releaseLimitation
        // 1 if softwareVersion is lower than releaseLimitation
        // Throws invalid_argument exception if the format of releaseLimitation or softwareVersion is wrong
        static int Compare(const std::string& releaseLimitation, const std::string& softwareVersion);
    private:
        static std::vector<std::string> split(const std::string& s, char delimiter);
    };
}
