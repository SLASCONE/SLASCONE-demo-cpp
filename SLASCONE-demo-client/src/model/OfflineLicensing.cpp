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



#include "SlasconeOpenApiClient/model/OfflineLicensing.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {


namespace
{
using EnumUnderlyingType = int64_t;

OfflineLicensing::eOfflineLicensing toEnum(const EnumUnderlyingType& val)
{
    switch (val)
    {
    case 0:
        return OfflineLicensing::eOfflineLicensing::OfflineLicensing__0;
    case 1:
        return OfflineLicensing::eOfflineLicensing::OfflineLicensing__1;
    case 2:
        return OfflineLicensing::eOfflineLicensing::OfflineLicensing__2;
    default:
        break;
    }
    return {};
}

EnumUnderlyingType fromEnum(OfflineLicensing::eOfflineLicensing e)
{
    switch (e)
    {
    case OfflineLicensing::eOfflineLicensing::OfflineLicensing__0:
        return 0;
    case OfflineLicensing::eOfflineLicensing::OfflineLicensing__1:
        return 1;
    case OfflineLicensing::eOfflineLicensing::OfflineLicensing__2:
        return 2;
    default:
        break;
    }
    return {};
}
}

OfflineLicensing::OfflineLicensing()
{
}

OfflineLicensing::~OfflineLicensing()
{
}

void OfflineLicensing::validate()
{
    // TODO: implement validation
}

web::json::value OfflineLicensing::toJson() const
{
    auto val = fromEnum(m_value);
    return web::json::value(val);
}

bool OfflineLicensing::fromJson(const web::json::value& val)
{
    m_value = toEnum(val.as_number().to_int64());
    return true;
}

void OfflineLicensing::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if (!namePrefix.empty() && namePrefix.back() != U('.'))
    {
        namePrefix.push_back(U('.'));
    }

    auto e = fromEnum(m_value);
    multipart->add(ModelBase::toHttpContent(namePrefix, e));
}

bool OfflineLicensing::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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

OfflineLicensing::eOfflineLicensing OfflineLicensing::getValue() const
{
   return m_value;
}

void OfflineLicensing::setValue(OfflineLicensing::eOfflineLicensing const value)
{
   m_value = value;
}


}
}
}
}

