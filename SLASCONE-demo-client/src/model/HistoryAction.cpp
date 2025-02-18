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



#include "SlasconeOpenApiClient/model/HistoryAction.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {


namespace
{
using EnumUnderlyingType = int64_t;

HistoryAction::eHistoryAction toEnum(const EnumUnderlyingType& val)
{
    switch (val)
    {
    case 0:
        return HistoryAction::eHistoryAction::HistoryAction__0;
    case 1:
        return HistoryAction::eHistoryAction::HistoryAction__1;
    case 2:
        return HistoryAction::eHistoryAction::HistoryAction__2;
    case 3:
        return HistoryAction::eHistoryAction::HistoryAction__3;
    case 4:
        return HistoryAction::eHistoryAction::HistoryAction__4;
    default:
        break;
    }
    return {};
}

EnumUnderlyingType fromEnum(HistoryAction::eHistoryAction e)
{
    switch (e)
    {
    case HistoryAction::eHistoryAction::HistoryAction__0:
        return 0;
    case HistoryAction::eHistoryAction::HistoryAction__1:
        return 1;
    case HistoryAction::eHistoryAction::HistoryAction__2:
        return 2;
    case HistoryAction::eHistoryAction::HistoryAction__3:
        return 3;
    case HistoryAction::eHistoryAction::HistoryAction__4:
        return 4;
    default:
        break;
    }
    return {};
}
}

HistoryAction::HistoryAction()
{
}

HistoryAction::~HistoryAction()
{
}

void HistoryAction::validate()
{
    // TODO: implement validation
}

web::json::value HistoryAction::toJson() const
{
    auto val = fromEnum(m_value);
    return web::json::value(val);
}

bool HistoryAction::fromJson(const web::json::value& val)
{
    m_value = toEnum(val.as_number().to_int64());
    return true;
}

void HistoryAction::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if (!namePrefix.empty() && namePrefix.back() != U('.'))
    {
        namePrefix.push_back(U('.'));
    }

    auto e = fromEnum(m_value);
    multipart->add(ModelBase::toHttpContent(namePrefix, e));
}

bool HistoryAction::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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

HistoryAction::eHistoryAction HistoryAction::getValue() const
{
   return m_value;
}

void HistoryAction::setValue(HistoryAction::eHistoryAction const value)
{
   m_value = value;
}


}
}
}
}


