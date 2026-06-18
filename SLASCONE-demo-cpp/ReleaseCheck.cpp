#include <string>
#include <vector>
#include <sstream>
#include <regex>
#include <stdexcept>
#include "ReleaseCheck.h"

using namespace std;
using namespace SLASCONE_demo_cpp;

// Helper: split string by delimiter
std::vector<std::string> ReleaseCheck::split(const std::string& s, char delimiter)
{
    std::vector<std::string> parts;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delimiter))
    {
        parts.push_back(item);
    }
    return parts;
}

int ReleaseCheck::Compare(const std::string& releaseLimitation, const std::string& softwareVersion)
{
    // Split releaseLimitation
    auto releaseLimitationParts = ReleaseCheck::split(releaseLimitation, '.');

    // Remove letters from softwareVersion
    std::regex letters("[a-zA-Z]");
    std::string cleanedVersion = std::regex_replace(softwareVersion, letters, "");

    // Split cleaned software version
    auto softwareVersionParts = ReleaseCheck::split(cleanedVersion, '.');

    if (softwareVersionParts.size() < releaseLimitationParts.size())
    {
        throw std::invalid_argument("Release has too few parts.");
    }

    for (size_t i = 0; i < releaseLimitationParts.size(); i++)
    {
        try
        {
            int limitationPartInt = std::stoi(releaseLimitationParts[i]);
            int versionPartInt = std::stoi(softwareVersionParts[i]);

            if (limitationPartInt < versionPartInt)
            {
                return -1;
            }

            if (limitationPartInt > versionPartInt)
            {
                return 1;
            }
        }
        catch (...)
        {
            throw std::invalid_argument("Version format error.");
        }
    }

    // Extra parts in softwareVersion are ignored
    return 0;
}