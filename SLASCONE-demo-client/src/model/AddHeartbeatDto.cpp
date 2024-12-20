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



#include "SlasconeOpenApiClient/model/AddHeartbeatDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



AddHeartbeatDto::AddHeartbeatDto()
{
    m_Product_id = utility::conversions::to_string_t("");
    m_Product_idIsSet = false;
    m_Client_id = utility::conversions::to_string_t("");
    m_Client_idIsSet = false;
    m_Software_version = utility::conversions::to_string_t("");
    m_Software_versionIsSet = false;
    m_Operating_system = utility::conversions::to_string_t("");
    m_Operating_systemIsSet = false;
    m_Token_key = utility::conversions::to_string_t("");
    m_Token_keyIsSet = false;
    m_Group_id = utility::conversions::to_string_t("");
    m_Group_idIsSet = false;
    m_Heartbeat_type_id = utility::conversions::to_string_t("");
    m_Heartbeat_type_idIsSet = false;
}

AddHeartbeatDto::~AddHeartbeatDto()
{
}

void AddHeartbeatDto::validate()
{
    // TODO: implement validation
}

web::json::value AddHeartbeatDto::toJson() const
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
    if(m_Software_versionIsSet)
    {
        val[utility::conversions::to_string_t(U("software_version"))] = ModelBase::toJson(m_Software_version);
    }
    if(m_Operating_systemIsSet)
    {
        val[utility::conversions::to_string_t(U("operating_system"))] = ModelBase::toJson(m_Operating_system);
    }
    if(m_Token_keyIsSet)
    {
        val[utility::conversions::to_string_t(U("token_key"))] = ModelBase::toJson(m_Token_key);
    }
    if(m_Group_idIsSet)
    {
        val[utility::conversions::to_string_t(U("group_id"))] = ModelBase::toJson(m_Group_id);
    }
    if(m_Heartbeat_type_idIsSet)
    {
        val[utility::conversions::to_string_t(U("heartbeat_type_id"))] = ModelBase::toJson(m_Heartbeat_type_id);
    }

    return val;
}

bool AddHeartbeatDto::fromJson(const web::json::value& val)
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
    if(val.has_field(utility::conversions::to_string_t(U("software_version"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("software_version")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setSoftwareVersion;
            ok &= ModelBase::fromJson(fieldValue, refVal_setSoftwareVersion);
            setSoftwareVersion(refVal_setSoftwareVersion);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("operating_system"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("operating_system")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setOperatingSystem;
            ok &= ModelBase::fromJson(fieldValue, refVal_setOperatingSystem);
            setOperatingSystem(refVal_setOperatingSystem);
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
    if(val.has_field(utility::conversions::to_string_t(U("group_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("group_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setGroupId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setGroupId);
            setGroupId(refVal_setGroupId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("heartbeat_type_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("heartbeat_type_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setHeartbeatTypeId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setHeartbeatTypeId);
            setHeartbeatTypeId(refVal_setHeartbeatTypeId);
        }
    }
    return ok;
}

void AddHeartbeatDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_Software_versionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("software_version")), m_Software_version));
    }
    if(m_Operating_systemIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("operating_system")), m_Operating_system));
    }
    if(m_Token_keyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("token_key")), m_Token_key));
    }
    if(m_Group_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("group_id")), m_Group_id));
    }
    if(m_Heartbeat_type_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("heartbeat_type_id")), m_Heartbeat_type_id));
    }
}

bool AddHeartbeatDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t(U("software_version"))))
    {
        utility::string_t refVal_setSoftwareVersion;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("software_version"))), refVal_setSoftwareVersion );
        setSoftwareVersion(refVal_setSoftwareVersion);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("operating_system"))))
    {
        utility::string_t refVal_setOperatingSystem;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("operating_system"))), refVal_setOperatingSystem );
        setOperatingSystem(refVal_setOperatingSystem);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("token_key"))))
    {
        utility::string_t refVal_setTokenKey;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("token_key"))), refVal_setTokenKey );
        setTokenKey(refVal_setTokenKey);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("group_id"))))
    {
        utility::string_t refVal_setGroupId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("group_id"))), refVal_setGroupId );
        setGroupId(refVal_setGroupId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("heartbeat_type_id"))))
    {
        utility::string_t refVal_setHeartbeatTypeId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("heartbeat_type_id"))), refVal_setHeartbeatTypeId );
        setHeartbeatTypeId(refVal_setHeartbeatTypeId);
    }
    return ok;
}

utility::string_t AddHeartbeatDto::getProductId() const
{
    return m_Product_id;
}

void AddHeartbeatDto::setProductId(const utility::string_t& value)
{
    m_Product_id = value;
    m_Product_idIsSet = true;
}

bool AddHeartbeatDto::productIdIsSet() const
{
    return m_Product_idIsSet;
}

void AddHeartbeatDto::unsetProduct_id()
{
    m_Product_idIsSet = false;
}
utility::string_t AddHeartbeatDto::getClientId() const
{
    return m_Client_id;
}

void AddHeartbeatDto::setClientId(const utility::string_t& value)
{
    m_Client_id = value;
    m_Client_idIsSet = true;
}

bool AddHeartbeatDto::clientIdIsSet() const
{
    return m_Client_idIsSet;
}

void AddHeartbeatDto::unsetClient_id()
{
    m_Client_idIsSet = false;
}
utility::string_t AddHeartbeatDto::getSoftwareVersion() const
{
    return m_Software_version;
}

void AddHeartbeatDto::setSoftwareVersion(const utility::string_t& value)
{
    m_Software_version = value;
    m_Software_versionIsSet = true;
}

bool AddHeartbeatDto::softwareVersionIsSet() const
{
    return m_Software_versionIsSet;
}

void AddHeartbeatDto::unsetSoftware_version()
{
    m_Software_versionIsSet = false;
}
utility::string_t AddHeartbeatDto::getOperatingSystem() const
{
    return m_Operating_system;
}

void AddHeartbeatDto::setOperatingSystem(const utility::string_t& value)
{
    m_Operating_system = value;
    m_Operating_systemIsSet = true;
}

bool AddHeartbeatDto::operatingSystemIsSet() const
{
    return m_Operating_systemIsSet;
}

void AddHeartbeatDto::unsetOperating_system()
{
    m_Operating_systemIsSet = false;
}
utility::string_t AddHeartbeatDto::getTokenKey() const
{
    return m_Token_key;
}

void AddHeartbeatDto::setTokenKey(const utility::string_t& value)
{
    m_Token_key = value;
    m_Token_keyIsSet = true;
}

bool AddHeartbeatDto::tokenKeyIsSet() const
{
    return m_Token_keyIsSet;
}

void AddHeartbeatDto::unsetToken_key()
{
    m_Token_keyIsSet = false;
}
utility::string_t AddHeartbeatDto::getGroupId() const
{
    return m_Group_id;
}

void AddHeartbeatDto::setGroupId(const utility::string_t& value)
{
    m_Group_id = value;
    m_Group_idIsSet = true;
}

bool AddHeartbeatDto::groupIdIsSet() const
{
    return m_Group_idIsSet;
}

void AddHeartbeatDto::unsetGroup_id()
{
    m_Group_idIsSet = false;
}
utility::string_t AddHeartbeatDto::getHeartbeatTypeId() const
{
    return m_Heartbeat_type_id;
}

void AddHeartbeatDto::setHeartbeatTypeId(const utility::string_t& value)
{
    m_Heartbeat_type_id = value;
    m_Heartbeat_type_idIsSet = true;
}

bool AddHeartbeatDto::heartbeatTypeIdIsSet() const
{
    return m_Heartbeat_type_idIsSet;
}

void AddHeartbeatDto::unsetHeartbeat_type_id()
{
    m_Heartbeat_type_idIsSet = false;
}
}
}
}
}


