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



#include "SlasconeOpenApiClient/model/ActivateClientDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



ActivateClientDto::ActivateClientDto()
{
    m_Product_id = utility::conversions::to_string_t("");
    m_Product_idIsSet = false;
    m_License_key = utility::conversions::to_string_t("");
    m_License_keyIsSet = false;
    m_Client_id = utility::conversions::to_string_t("");
    m_Client_idIsSet = false;
    m_Client_name = utility::conversions::to_string_t("");
    m_Client_nameIsSet = false;
    m_Client_description = utility::conversions::to_string_t("");
    m_Client_descriptionIsSet = false;
    m_Software_version = utility::conversions::to_string_t("");
    m_Software_versionIsSet = false;
    m_Timestamp_utc = utility::datetime();
    m_Timestamp_utcIsSet = false;
    m_TagsIsSet = false;
}

ActivateClientDto::~ActivateClientDto()
{
}

void ActivateClientDto::validate()
{
    // TODO: implement validation
}

web::json::value ActivateClientDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_Product_idIsSet)
    {
        val[utility::conversions::to_string_t(U("product_id"))] = ModelBase::toJson(m_Product_id);
    }
    if(m_License_keyIsSet)
    {
        val[utility::conversions::to_string_t(U("license_key"))] = ModelBase::toJson(m_License_key);
    }
    if(m_Client_idIsSet)
    {
        val[utility::conversions::to_string_t(U("client_id"))] = ModelBase::toJson(m_Client_id);
    }
    if(m_Client_nameIsSet)
    {
        val[utility::conversions::to_string_t(U("client_name"))] = ModelBase::toJson(m_Client_name);
    }
    if(m_Client_descriptionIsSet)
    {
        val[utility::conversions::to_string_t(U("client_description"))] = ModelBase::toJson(m_Client_description);
    }
    if(m_Software_versionIsSet)
    {
        val[utility::conversions::to_string_t(U("software_version"))] = ModelBase::toJson(m_Software_version);
    }
    if(m_Timestamp_utcIsSet)
    {
        val[utility::conversions::to_string_t(U("timestamp_utc"))] = ModelBase::toJson(m_Timestamp_utc);
    }
    if(m_TagsIsSet)
    {
        val[utility::conversions::to_string_t(U("tags"))] = ModelBase::toJson(m_Tags);
    }

    return val;
}

bool ActivateClientDto::fromJson(const web::json::value& val)
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
    if(val.has_field(utility::conversions::to_string_t(U("license_key"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("license_key")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setLicenseKey;
            ok &= ModelBase::fromJson(fieldValue, refVal_setLicenseKey);
            setLicenseKey(refVal_setLicenseKey);
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
    if(val.has_field(utility::conversions::to_string_t(U("client_name"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("client_name")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setClientName;
            ok &= ModelBase::fromJson(fieldValue, refVal_setClientName);
            setClientName(refVal_setClientName);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("client_description"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("client_description")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setClientDescription;
            ok &= ModelBase::fromJson(fieldValue, refVal_setClientDescription);
            setClientDescription(refVal_setClientDescription);
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
    if(val.has_field(utility::conversions::to_string_t(U("timestamp_utc"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("timestamp_utc")));
        if(!fieldValue.is_null())
        {
            utility::datetime refVal_setTimestampUtc;
            ok &= ModelBase::fromJson(fieldValue, refVal_setTimestampUtc);
            setTimestampUtc(refVal_setTimestampUtc);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("tags"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("tags")));
        if(!fieldValue.is_null())
        {
            std::vector<utility::string_t> refVal_setTags;
            ok &= ModelBase::fromJson(fieldValue, refVal_setTags);
            setTags(refVal_setTags);
        }
    }
    return ok;
}

void ActivateClientDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_License_keyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("license_key")), m_License_key));
    }
    if(m_Client_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("client_id")), m_Client_id));
    }
    if(m_Client_nameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("client_name")), m_Client_name));
    }
    if(m_Client_descriptionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("client_description")), m_Client_description));
    }
    if(m_Software_versionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("software_version")), m_Software_version));
    }
    if(m_Timestamp_utcIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("timestamp_utc")), m_Timestamp_utc));
    }
    if(m_TagsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("tags")), m_Tags));
    }
}

bool ActivateClientDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t(U("license_key"))))
    {
        utility::string_t refVal_setLicenseKey;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("license_key"))), refVal_setLicenseKey );
        setLicenseKey(refVal_setLicenseKey);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("client_id"))))
    {
        utility::string_t refVal_setClientId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("client_id"))), refVal_setClientId );
        setClientId(refVal_setClientId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("client_name"))))
    {
        utility::string_t refVal_setClientName;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("client_name"))), refVal_setClientName );
        setClientName(refVal_setClientName);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("client_description"))))
    {
        utility::string_t refVal_setClientDescription;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("client_description"))), refVal_setClientDescription );
        setClientDescription(refVal_setClientDescription);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("software_version"))))
    {
        utility::string_t refVal_setSoftwareVersion;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("software_version"))), refVal_setSoftwareVersion );
        setSoftwareVersion(refVal_setSoftwareVersion);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("timestamp_utc"))))
    {
        utility::datetime refVal_setTimestampUtc;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("timestamp_utc"))), refVal_setTimestampUtc );
        setTimestampUtc(refVal_setTimestampUtc);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("tags"))))
    {
        std::vector<utility::string_t> refVal_setTags;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("tags"))), refVal_setTags );
        setTags(refVal_setTags);
    }
    return ok;
}

utility::string_t ActivateClientDto::getProductId() const
{
    return m_Product_id;
}

void ActivateClientDto::setProductId(const utility::string_t& value)
{
    m_Product_id = value;
    m_Product_idIsSet = true;
}

bool ActivateClientDto::productIdIsSet() const
{
    return m_Product_idIsSet;
}

void ActivateClientDto::unsetProduct_id()
{
    m_Product_idIsSet = false;
}
utility::string_t ActivateClientDto::getLicenseKey() const
{
    return m_License_key;
}

void ActivateClientDto::setLicenseKey(const utility::string_t& value)
{
    m_License_key = value;
    m_License_keyIsSet = true;
}

bool ActivateClientDto::licenseKeyIsSet() const
{
    return m_License_keyIsSet;
}

void ActivateClientDto::unsetLicense_key()
{
    m_License_keyIsSet = false;
}
utility::string_t ActivateClientDto::getClientId() const
{
    return m_Client_id;
}

void ActivateClientDto::setClientId(const utility::string_t& value)
{
    m_Client_id = value;
    m_Client_idIsSet = true;
}

bool ActivateClientDto::clientIdIsSet() const
{
    return m_Client_idIsSet;
}

void ActivateClientDto::unsetClient_id()
{
    m_Client_idIsSet = false;
}
utility::string_t ActivateClientDto::getClientName() const
{
    return m_Client_name;
}

void ActivateClientDto::setClientName(const utility::string_t& value)
{
    m_Client_name = value;
    m_Client_nameIsSet = true;
}

bool ActivateClientDto::clientNameIsSet() const
{
    return m_Client_nameIsSet;
}

void ActivateClientDto::unsetClient_name()
{
    m_Client_nameIsSet = false;
}
utility::string_t ActivateClientDto::getClientDescription() const
{
    return m_Client_description;
}

void ActivateClientDto::setClientDescription(const utility::string_t& value)
{
    m_Client_description = value;
    m_Client_descriptionIsSet = true;
}

bool ActivateClientDto::clientDescriptionIsSet() const
{
    return m_Client_descriptionIsSet;
}

void ActivateClientDto::unsetClient_description()
{
    m_Client_descriptionIsSet = false;
}
utility::string_t ActivateClientDto::getSoftwareVersion() const
{
    return m_Software_version;
}

void ActivateClientDto::setSoftwareVersion(const utility::string_t& value)
{
    m_Software_version = value;
    m_Software_versionIsSet = true;
}

bool ActivateClientDto::softwareVersionIsSet() const
{
    return m_Software_versionIsSet;
}

void ActivateClientDto::unsetSoftware_version()
{
    m_Software_versionIsSet = false;
}
utility::datetime ActivateClientDto::getTimestampUtc() const
{
    return m_Timestamp_utc;
}

void ActivateClientDto::setTimestampUtc(const utility::datetime& value)
{
    m_Timestamp_utc = value;
    m_Timestamp_utcIsSet = true;
}

bool ActivateClientDto::timestampUtcIsSet() const
{
    return m_Timestamp_utcIsSet;
}

void ActivateClientDto::unsetTimestamp_utc()
{
    m_Timestamp_utcIsSet = false;
}
std::vector<utility::string_t>& ActivateClientDto::getTags()
{
    return m_Tags;
}

void ActivateClientDto::setTags(const std::vector<utility::string_t>& value)
{
    m_Tags = value;
    m_TagsIsSet = true;
}

bool ActivateClientDto::tagsIsSet() const
{
    return m_TagsIsSet;
}

void ActivateClientDto::unsetTags()
{
    m_TagsIsSet = false;
}
}
}
}
}


