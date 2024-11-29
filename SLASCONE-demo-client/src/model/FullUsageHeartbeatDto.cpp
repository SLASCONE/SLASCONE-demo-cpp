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



#include "SlasconeOpenApiClient/model/FullUsageHeartbeatDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



FullUsageHeartbeatDto::FullUsageHeartbeatDto()
{
    m_Client_id = utility::conversions::to_string_t("");
    m_Client_idIsSet = false;
    m_Usage_heartbeatIsSet = false;
    m_Token_key = utility::conversions::to_string_t("");
    m_Token_keyIsSet = false;
}

FullUsageHeartbeatDto::~FullUsageHeartbeatDto()
{
}

void FullUsageHeartbeatDto::validate()
{
    // TODO: implement validation
}

web::json::value FullUsageHeartbeatDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_Client_idIsSet)
    {
        val[utility::conversions::to_string_t(U("client_id"))] = ModelBase::toJson(m_Client_id);
    }
    if(m_Usage_heartbeatIsSet)
    {
        val[utility::conversions::to_string_t(U("usage_heartbeat"))] = ModelBase::toJson(m_Usage_heartbeat);
    }
    if(m_Token_keyIsSet)
    {
        val[utility::conversions::to_string_t(U("token_key"))] = ModelBase::toJson(m_Token_key);
    }

    return val;
}

bool FullUsageHeartbeatDto::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("client_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("client_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setClientId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setClientId);
            setClientId(refVal_setClientId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("usage_heartbeat"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("usage_heartbeat")));
        if(!fieldValue.is_null())
        {
            std::vector<std::shared_ptr<UsageHeartbeatValueDto>> refVal_setUsageHeartbeat;
            ok &= ModelBase::fromJson(fieldValue, refVal_setUsageHeartbeat);
            setUsageHeartbeat(refVal_setUsageHeartbeat);
        }
    }
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

void FullUsageHeartbeatDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_Client_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("client_id")), m_Client_id));
    }
    if(m_Usage_heartbeatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("usage_heartbeat")), m_Usage_heartbeat));
    }
    if(m_Token_keyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("token_key")), m_Token_key));
    }
}

bool FullUsageHeartbeatDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("client_id"))))
    {
        utility::string_t refVal_setClientId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("client_id"))), refVal_setClientId );
        setClientId(refVal_setClientId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("usage_heartbeat"))))
    {
        std::vector<std::shared_ptr<UsageHeartbeatValueDto>> refVal_setUsageHeartbeat;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("usage_heartbeat"))), refVal_setUsageHeartbeat );
        setUsageHeartbeat(refVal_setUsageHeartbeat);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("token_key"))))
    {
        utility::string_t refVal_setTokenKey;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("token_key"))), refVal_setTokenKey );
        setTokenKey(refVal_setTokenKey);
    }
    return ok;
}

utility::string_t FullUsageHeartbeatDto::getClientId() const
{
    return m_Client_id;
}

void FullUsageHeartbeatDto::setClientId(const utility::string_t& value)
{
    m_Client_id = value;
    m_Client_idIsSet = true;
}

bool FullUsageHeartbeatDto::clientIdIsSet() const
{
    return m_Client_idIsSet;
}

void FullUsageHeartbeatDto::unsetClient_id()
{
    m_Client_idIsSet = false;
}
std::vector<std::shared_ptr<UsageHeartbeatValueDto>>& FullUsageHeartbeatDto::getUsageHeartbeat()
{
    return m_Usage_heartbeat;
}

void FullUsageHeartbeatDto::setUsageHeartbeat(const std::vector<std::shared_ptr<UsageHeartbeatValueDto>>& value)
{
    m_Usage_heartbeat = value;
    m_Usage_heartbeatIsSet = true;
}

bool FullUsageHeartbeatDto::usageHeartbeatIsSet() const
{
    return m_Usage_heartbeatIsSet;
}

void FullUsageHeartbeatDto::unsetUsage_heartbeat()
{
    m_Usage_heartbeatIsSet = false;
}
utility::string_t FullUsageHeartbeatDto::getTokenKey() const
{
    return m_Token_key;
}

void FullUsageHeartbeatDto::setTokenKey(const utility::string_t& value)
{
    m_Token_key = value;
    m_Token_keyIsSet = true;
}

bool FullUsageHeartbeatDto::tokenKeyIsSet() const
{
    return m_Token_keyIsSet;
}

void FullUsageHeartbeatDto::unsetToken_key()
{
    m_Token_keyIsSet = false;
}
}
}
}
}

