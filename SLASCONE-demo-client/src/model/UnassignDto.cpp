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



#include "SlasconeOpenApiClient/model/UnassignDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



UnassignDto::UnassignDto()
{
    m_Token_key = utility::conversions::to_string_t("");
    m_Token_keyIsSet = false;
}

UnassignDto::~UnassignDto()
{
}

void UnassignDto::validate()
{
    // TODO: implement validation
}

web::json::value UnassignDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_Token_keyIsSet)
    {
        val[utility::conversions::to_string_t(U("token_key"))] = ModelBase::toJson(m_Token_key);
    }

    return val;
}

bool UnassignDto::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("token_key"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("token_key")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setTokenKey;
            ok &= ModelBase::fromJson(fieldValue, refVal_setTokenKey);
            setTokenKey(refVal_setTokenKey);
        }
    }
    return ok;
}

void UnassignDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_Token_keyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("token_key")), m_Token_key));
    }
}

bool UnassignDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("token_key"))))
    {
        utility::string_t refVal_setTokenKey;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("token_key"))), refVal_setTokenKey );
        setTokenKey(refVal_setTokenKey);
    }
    return ok;
}

utility::string_t UnassignDto::getTokenKey() const
{
    return m_Token_key;
}

void UnassignDto::setTokenKey(const utility::string_t& value)
{
    m_Token_key = value;
    m_Token_keyIsSet = true;
}

bool UnassignDto::tokenKeyIsSet() const
{
    return m_Token_keyIsSet;
}

void UnassignDto::unsetToken_key()
{
    m_Token_keyIsSet = false;
}
}
}
}
}


