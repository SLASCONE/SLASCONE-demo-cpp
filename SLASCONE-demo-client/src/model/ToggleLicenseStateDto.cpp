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



#include "SlasconeOpenApiClient/model/ToggleLicenseStateDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



ToggleLicenseStateDto::ToggleLicenseStateDto()
{
    m_Product_id = utility::conversions::to_string_t("");
    m_Product_idIsSet = false;
    m_License_key = utility::conversions::to_string_t("");
    m_License_keyIsSet = false;
    m_Is_active = false;
    m_Is_activeIsSet = false;
}

ToggleLicenseStateDto::~ToggleLicenseStateDto()
{
}

void ToggleLicenseStateDto::validate()
{
    // TODO: implement validation
}

web::json::value ToggleLicenseStateDto::toJson() const
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
    if(m_Is_activeIsSet)
    {
        val[utility::conversions::to_string_t(U("is_active"))] = ModelBase::toJson(m_Is_active);
    }

    return val;
}

bool ToggleLicenseStateDto::fromJson(const web::json::value& val)
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
    if(val.has_field(utility::conversions::to_string_t(U("is_active"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("is_active")));
        if(!fieldValue.is_null())
        {
            bool refVal_setIsActive;
            ok &= ModelBase::fromJson(fieldValue, refVal_setIsActive);
            setIsActive(refVal_setIsActive);
        }
    }
    return ok;
}

void ToggleLicenseStateDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_Is_activeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("is_active")), m_Is_active));
    }
}

bool ToggleLicenseStateDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t(U("is_active"))))
    {
        bool refVal_setIsActive;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("is_active"))), refVal_setIsActive );
        setIsActive(refVal_setIsActive);
    }
    return ok;
}

utility::string_t ToggleLicenseStateDto::getProductId() const
{
    return m_Product_id;
}

void ToggleLicenseStateDto::setProductId(const utility::string_t& value)
{
    m_Product_id = value;
    m_Product_idIsSet = true;
}

bool ToggleLicenseStateDto::productIdIsSet() const
{
    return m_Product_idIsSet;
}

void ToggleLicenseStateDto::unsetProduct_id()
{
    m_Product_idIsSet = false;
}
utility::string_t ToggleLicenseStateDto::getLicenseKey() const
{
    return m_License_key;
}

void ToggleLicenseStateDto::setLicenseKey(const utility::string_t& value)
{
    m_License_key = value;
    m_License_keyIsSet = true;
}

bool ToggleLicenseStateDto::licenseKeyIsSet() const
{
    return m_License_keyIsSet;
}

void ToggleLicenseStateDto::unsetLicense_key()
{
    m_License_keyIsSet = false;
}
bool ToggleLicenseStateDto::isIsActive() const
{
    return m_Is_active;
}

void ToggleLicenseStateDto::setIsActive(bool value)
{
    m_Is_active = value;
    m_Is_activeIsSet = true;
}

bool ToggleLicenseStateDto::isActiveIsSet() const
{
    return m_Is_activeIsSet;
}

void ToggleLicenseStateDto::unsetIs_active()
{
    m_Is_activeIsSet = false;
}
}
}
}
}


