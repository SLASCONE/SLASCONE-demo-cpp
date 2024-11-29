/**
 * SLASCONE API
 * Please visit our official [Documentation](https://support.slascone.com/hc/en-us/sections/360004685737-API) and/or our [GitHub repository](https://github.com/slascone/) and/or our [NuGet package](https://www.nuget.org/packages/Slascone.Client/). Always use Version 2 of this API (Version 1.3 is deprecated).
 *
 * The version of the OpenAPI document: v2
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 7.11.0-SNAPSHOT.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */



#include "SlasconeOpenApiClient/model/ActivationUponLicenseCreation.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {


namespace
{
using EnumUnderlyingType = int64_t;

ActivationUponLicenseCreation::eActivationUponLicenseCreation toEnum(const EnumUnderlyingType& val)
{
    switch (val)
    {
    case 0:
        return ActivationUponLicenseCreation::eActivationUponLicenseCreation::ActivationUponLicenseCreation__0;
    case 1:
        return ActivationUponLicenseCreation::eActivationUponLicenseCreation::ActivationUponLicenseCreation__1;
    case 2:
        return ActivationUponLicenseCreation::eActivationUponLicenseCreation::ActivationUponLicenseCreation__2;
    case 3:
        return ActivationUponLicenseCreation::eActivationUponLicenseCreation::ActivationUponLicenseCreation__3;
    case 4:
        return ActivationUponLicenseCreation::eActivationUponLicenseCreation::ActivationUponLicenseCreation__4;
    case 5:
        return ActivationUponLicenseCreation::eActivationUponLicenseCreation::ActivationUponLicenseCreation__5;
    default:
        break;
    }
    return {};
}

EnumUnderlyingType fromEnum(ActivationUponLicenseCreation::eActivationUponLicenseCreation e)
{
    switch (e)
    {
    case ActivationUponLicenseCreation::eActivationUponLicenseCreation::ActivationUponLicenseCreation__0:
        return 0;
    case ActivationUponLicenseCreation::eActivationUponLicenseCreation::ActivationUponLicenseCreation__1:
        return 1;
    case ActivationUponLicenseCreation::eActivationUponLicenseCreation::ActivationUponLicenseCreation__2:
        return 2;
    case ActivationUponLicenseCreation::eActivationUponLicenseCreation::ActivationUponLicenseCreation__3:
        return 3;
    case ActivationUponLicenseCreation::eActivationUponLicenseCreation::ActivationUponLicenseCreation__4:
        return 4;
    case ActivationUponLicenseCreation::eActivationUponLicenseCreation::ActivationUponLicenseCreation__5:
        return 5;
    default:
        break;
    }
    return {};
}
}

ActivationUponLicenseCreation::ActivationUponLicenseCreation()
{
}

ActivationUponLicenseCreation::~ActivationUponLicenseCreation()
{
}

void ActivationUponLicenseCreation::validate()
{
    // TODO: implement validation
}

web::json::value ActivationUponLicenseCreation::toJson() const
{
    auto val = fromEnum(m_value);
    return web::json::value(val);
}

bool ActivationUponLicenseCreation::fromJson(const web::json::value& val)
{
    m_value = toEnum(val.as_number().to_int64());
    return true;
}

void ActivationUponLicenseCreation::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if (!namePrefix.empty() && namePrefix.back() != U('.'))
    {
        namePrefix.push_back(U('.'));
    }

    auto e = fromEnum(m_value);
    multipart->add(ModelBase::toHttpContent(namePrefix, e));
}

bool ActivationUponLicenseCreation::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if (!namePrefix.empty() && namePrefix.back() != U('.'))
    {
        namePrefix.push_back(U('.'));
    }
    {
        EnumUnderlyingType e;
        ok = ModelBase::fromHttpContent(multipart->getContent(namePrefix), e);
        if (ok)
        {
            auto v = toEnum(e);
            setValue(v);
        }
    }
    return ok;
}

ActivationUponLicenseCreation::eActivationUponLicenseCreation ActivationUponLicenseCreation::getValue() const
{
   return m_value;
}

void ActivationUponLicenseCreation::setValue(ActivationUponLicenseCreation::eActivationUponLicenseCreation const value)
{
   m_value = value;
}


}
}
}
}

