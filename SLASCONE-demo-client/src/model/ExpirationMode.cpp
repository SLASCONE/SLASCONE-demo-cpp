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



#include "SlasconeOpenApiClient/model/ExpirationMode.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {


namespace
{
using EnumUnderlyingType = int64_t;

ExpirationMode::eExpirationMode toEnum(const EnumUnderlyingType& val)
{
    switch (val)
    {
    case 1:
        return ExpirationMode::eExpirationMode::ExpirationMode__1;
    case 2:
        return ExpirationMode::eExpirationMode::ExpirationMode__2;
    case 3:
        return ExpirationMode::eExpirationMode::ExpirationMode__3;
    default:
        break;
    }
    return {};
}

EnumUnderlyingType fromEnum(ExpirationMode::eExpirationMode e)
{
    switch (e)
    {
    case ExpirationMode::eExpirationMode::ExpirationMode__1:
        return 1;
    case ExpirationMode::eExpirationMode::ExpirationMode__2:
        return 2;
    case ExpirationMode::eExpirationMode::ExpirationMode__3:
        return 3;
    default:
        break;
    }
    return {};
}
}

ExpirationMode::ExpirationMode()
{
}

ExpirationMode::~ExpirationMode()
{
}

void ExpirationMode::validate()
{
    // TODO: implement validation
}

web::json::value ExpirationMode::toJson() const
{
    auto val = fromEnum(m_value);
    return web::json::value(val);
}

bool ExpirationMode::fromJson(const web::json::value& val)
{
    m_value = toEnum(val.as_number().to_int64());
    return true;
}

void ExpirationMode::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if (!namePrefix.empty() && namePrefix.back() != U('.'))
    {
        namePrefix.push_back(U('.'));
    }

    auto e = fromEnum(m_value);
    multipart->add(ModelBase::toHttpContent(namePrefix, e));
}

bool ExpirationMode::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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

ExpirationMode::eExpirationMode ExpirationMode::getValue() const
{
   return m_value;
}

void ExpirationMode::setValue(ExpirationMode::eExpirationMode const value)
{
   m_value = value;
}


}
}
}
}


