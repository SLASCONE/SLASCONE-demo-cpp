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



#include "SlasconeOpenApiClient/model/FullUsageHeartbeatByNameDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



FullUsageHeartbeatByNameDto::FullUsageHeartbeatByNameDto()
{
    m_Product_id = utility::conversions::to_string_t("");
    m_Product_idIsSet = false;
    m_Client_id = utility::conversions::to_string_t("");
    m_Client_idIsSet = false;
    m_Usage_heartbeatIsSet = false;
    m_Token_key = utility::conversions::to_string_t("");
    m_Token_keyIsSet = false;
    m_Create_usage_feature_if_not_exists = false;
    m_Create_usage_feature_if_not_existsIsSet = false;
    m_Create_usage_module_if_not_exists = false;
    m_Create_usage_module_if_not_existsIsSet = false;
}

FullUsageHeartbeatByNameDto::~FullUsageHeartbeatByNameDto()
{
}

void FullUsageHeartbeatByNameDto::validate()
{
    // TODO: implement validation
}

web::json::value FullUsageHeartbeatByNameDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_Product_idIsSet)
    {
        val[utility::conversions::to_string_t(U("product_id"))] = ModelBase::toJson(m_Product_id);
    }
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
    if(m_Create_usage_feature_if_not_existsIsSet)
    {
        val[utility::conversions::to_string_t(U("create_usage_feature_if_not_exists"))] = ModelBase::toJson(m_Create_usage_feature_if_not_exists);
    }
    if(m_Create_usage_module_if_not_existsIsSet)
    {
        val[utility::conversions::to_string_t(U("create_usage_module_if_not_exists"))] = ModelBase::toJson(m_Create_usage_module_if_not_exists);
    }

    return val;
}

bool FullUsageHeartbeatByNameDto::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("product_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("product_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setProductId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setProductId);
            setProductId(refVal_setProductId);
        }
    }
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
            std::vector<std::shared_ptr<UsageFeatureNameDto>> refVal_setUsageHeartbeat;
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
    if(val.has_field(utility::conversions::to_string_t(U("create_usage_feature_if_not_exists"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("create_usage_feature_if_not_exists")));
        if(!fieldValue.is_null())
        {
            bool refVal_setCreateUsageFeatureIfNotExists;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCreateUsageFeatureIfNotExists);
            setCreateUsageFeatureIfNotExists(refVal_setCreateUsageFeatureIfNotExists);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("create_usage_module_if_not_exists"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("create_usage_module_if_not_exists")));
        if(!fieldValue.is_null())
        {
            bool refVal_setCreateUsageModuleIfNotExists;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCreateUsageModuleIfNotExists);
            setCreateUsageModuleIfNotExists(refVal_setCreateUsageModuleIfNotExists);
        }
    }
    return ok;
}

void FullUsageHeartbeatByNameDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_Product_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("product_id")), m_Product_id));
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
    if(m_Create_usage_feature_if_not_existsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("create_usage_feature_if_not_exists")), m_Create_usage_feature_if_not_exists));
    }
    if(m_Create_usage_module_if_not_existsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("create_usage_module_if_not_exists")), m_Create_usage_module_if_not_exists));
    }
}

bool FullUsageHeartbeatByNameDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("product_id"))))
    {
        utility::string_t refVal_setProductId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("product_id"))), refVal_setProductId );
        setProductId(refVal_setProductId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("client_id"))))
    {
        utility::string_t refVal_setClientId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("client_id"))), refVal_setClientId );
        setClientId(refVal_setClientId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("usage_heartbeat"))))
    {
        std::vector<std::shared_ptr<UsageFeatureNameDto>> refVal_setUsageHeartbeat;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("usage_heartbeat"))), refVal_setUsageHeartbeat );
        setUsageHeartbeat(refVal_setUsageHeartbeat);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("token_key"))))
    {
        utility::string_t refVal_setTokenKey;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("token_key"))), refVal_setTokenKey );
        setTokenKey(refVal_setTokenKey);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("create_usage_feature_if_not_exists"))))
    {
        bool refVal_setCreateUsageFeatureIfNotExists;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("create_usage_feature_if_not_exists"))), refVal_setCreateUsageFeatureIfNotExists );
        setCreateUsageFeatureIfNotExists(refVal_setCreateUsageFeatureIfNotExists);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("create_usage_module_if_not_exists"))))
    {
        bool refVal_setCreateUsageModuleIfNotExists;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("create_usage_module_if_not_exists"))), refVal_setCreateUsageModuleIfNotExists );
        setCreateUsageModuleIfNotExists(refVal_setCreateUsageModuleIfNotExists);
    }
    return ok;
}

utility::string_t FullUsageHeartbeatByNameDto::getProductId() const
{
    return m_Product_id;
}

void FullUsageHeartbeatByNameDto::setProductId(const utility::string_t& value)
{
    m_Product_id = value;
    m_Product_idIsSet = true;
}

bool FullUsageHeartbeatByNameDto::productIdIsSet() const
{
    return m_Product_idIsSet;
}

void FullUsageHeartbeatByNameDto::unsetProduct_id()
{
    m_Product_idIsSet = false;
}
utility::string_t FullUsageHeartbeatByNameDto::getClientId() const
{
    return m_Client_id;
}

void FullUsageHeartbeatByNameDto::setClientId(const utility::string_t& value)
{
    m_Client_id = value;
    m_Client_idIsSet = true;
}

bool FullUsageHeartbeatByNameDto::clientIdIsSet() const
{
    return m_Client_idIsSet;
}

void FullUsageHeartbeatByNameDto::unsetClient_id()
{
    m_Client_idIsSet = false;
}
std::vector<std::shared_ptr<UsageFeatureNameDto>>& FullUsageHeartbeatByNameDto::getUsageHeartbeat()
{
    return m_Usage_heartbeat;
}

void FullUsageHeartbeatByNameDto::setUsageHeartbeat(const std::vector<std::shared_ptr<UsageFeatureNameDto>>& value)
{
    m_Usage_heartbeat = value;
    m_Usage_heartbeatIsSet = true;
}

bool FullUsageHeartbeatByNameDto::usageHeartbeatIsSet() const
{
    return m_Usage_heartbeatIsSet;
}

void FullUsageHeartbeatByNameDto::unsetUsage_heartbeat()
{
    m_Usage_heartbeatIsSet = false;
}
utility::string_t FullUsageHeartbeatByNameDto::getTokenKey() const
{
    return m_Token_key;
}

void FullUsageHeartbeatByNameDto::setTokenKey(const utility::string_t& value)
{
    m_Token_key = value;
    m_Token_keyIsSet = true;
}

bool FullUsageHeartbeatByNameDto::tokenKeyIsSet() const
{
    return m_Token_keyIsSet;
}

void FullUsageHeartbeatByNameDto::unsetToken_key()
{
    m_Token_keyIsSet = false;
}
bool FullUsageHeartbeatByNameDto::isCreateUsageFeatureIfNotExists() const
{
    return m_Create_usage_feature_if_not_exists;
}

void FullUsageHeartbeatByNameDto::setCreateUsageFeatureIfNotExists(bool value)
{
    m_Create_usage_feature_if_not_exists = value;
    m_Create_usage_feature_if_not_existsIsSet = true;
}

bool FullUsageHeartbeatByNameDto::createUsageFeatureIfNotExistsIsSet() const
{
    return m_Create_usage_feature_if_not_existsIsSet;
}

void FullUsageHeartbeatByNameDto::unsetCreate_usage_feature_if_not_exists()
{
    m_Create_usage_feature_if_not_existsIsSet = false;
}
bool FullUsageHeartbeatByNameDto::isCreateUsageModuleIfNotExists() const
{
    return m_Create_usage_module_if_not_exists;
}

void FullUsageHeartbeatByNameDto::setCreateUsageModuleIfNotExists(bool value)
{
    m_Create_usage_module_if_not_exists = value;
    m_Create_usage_module_if_not_existsIsSet = true;
}

bool FullUsageHeartbeatByNameDto::createUsageModuleIfNotExistsIsSet() const
{
    return m_Create_usage_module_if_not_existsIsSet;
}

void FullUsageHeartbeatByNameDto::unsetCreate_usage_module_if_not_exists()
{
    m_Create_usage_module_if_not_existsIsSet = false;
}
}
}
}
}


