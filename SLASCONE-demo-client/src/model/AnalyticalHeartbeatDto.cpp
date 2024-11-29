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



#include "SlasconeOpenApiClient/model/AnalyticalHeartbeatDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



AnalyticalHeartbeatDto::AnalyticalHeartbeatDto()
{
    m_Client_id = utility::conversions::to_string_t("");
    m_Client_idIsSet = false;
    m_Analytical_heartbeatIsSet = false;
    m_Token_key = utility::conversions::to_string_t("");
    m_Token_keyIsSet = false;
}

AnalyticalHeartbeatDto::~AnalyticalHeartbeatDto()
{
}

void AnalyticalHeartbeatDto::validate()
{
    // TODO: implement validation
}

web::json::value AnalyticalHeartbeatDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_Client_idIsSet)
    {
        val[utility::conversions::to_string_t(U("client_id"))] = ModelBase::toJson(m_Client_id);
    }
    if(m_Analytical_heartbeatIsSet)
    {
        val[utility::conversions::to_string_t(U("analytical_heartbeat"))] = ModelBase::toJson(m_Analytical_heartbeat);
    }
    if(m_Token_keyIsSet)
    {
        val[utility::conversions::to_string_t(U("token_key"))] = ModelBase::toJson(m_Token_key);
    }

    return val;
}

bool AnalyticalHeartbeatDto::fromJson(const web::json::value& val)
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
    if(val.has_field(utility::conversions::to_string_t(U("analytical_heartbeat"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("analytical_heartbeat")));
        if(!fieldValue.is_null())
        {
            std::vector<std::shared_ptr<AnalyticalFieldValueDto>> refVal_setAnalyticalHeartbeat;
            ok &= ModelBase::fromJson(fieldValue, refVal_setAnalyticalHeartbeat);
            setAnalyticalHeartbeat(refVal_setAnalyticalHeartbeat);
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

void AnalyticalHeartbeatDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_Analytical_heartbeatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("analytical_heartbeat")), m_Analytical_heartbeat));
    }
    if(m_Token_keyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("token_key")), m_Token_key));
    }
}

bool AnalyticalHeartbeatDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t(U("analytical_heartbeat"))))
    {
        std::vector<std::shared_ptr<AnalyticalFieldValueDto>> refVal_setAnalyticalHeartbeat;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("analytical_heartbeat"))), refVal_setAnalyticalHeartbeat );
        setAnalyticalHeartbeat(refVal_setAnalyticalHeartbeat);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("token_key"))))
    {
        utility::string_t refVal_setTokenKey;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("token_key"))), refVal_setTokenKey );
        setTokenKey(refVal_setTokenKey);
    }
    return ok;
}

utility::string_t AnalyticalHeartbeatDto::getClientId() const
{
    return m_Client_id;
}

void AnalyticalHeartbeatDto::setClientId(const utility::string_t& value)
{
    m_Client_id = value;
    m_Client_idIsSet = true;
}

bool AnalyticalHeartbeatDto::clientIdIsSet() const
{
    return m_Client_idIsSet;
}

void AnalyticalHeartbeatDto::unsetClient_id()
{
    m_Client_idIsSet = false;
}
std::vector<std::shared_ptr<AnalyticalFieldValueDto>>& AnalyticalHeartbeatDto::getAnalyticalHeartbeat()
{
    return m_Analytical_heartbeat;
}

void AnalyticalHeartbeatDto::setAnalyticalHeartbeat(const std::vector<std::shared_ptr<AnalyticalFieldValueDto>>& value)
{
    m_Analytical_heartbeat = value;
    m_Analytical_heartbeatIsSet = true;
}

bool AnalyticalHeartbeatDto::analyticalHeartbeatIsSet() const
{
    return m_Analytical_heartbeatIsSet;
}

void AnalyticalHeartbeatDto::unsetAnalytical_heartbeat()
{
    m_Analytical_heartbeatIsSet = false;
}
utility::string_t AnalyticalHeartbeatDto::getTokenKey() const
{
    return m_Token_key;
}

void AnalyticalHeartbeatDto::setTokenKey(const utility::string_t& value)
{
    m_Token_key = value;
    m_Token_keyIsSet = true;
}

bool AnalyticalHeartbeatDto::tokenKeyIsSet() const
{
    return m_Token_keyIsSet;
}

void AnalyticalHeartbeatDto::unsetToken_key()
{
    m_Token_keyIsSet = false;
}
}
}
}
}

