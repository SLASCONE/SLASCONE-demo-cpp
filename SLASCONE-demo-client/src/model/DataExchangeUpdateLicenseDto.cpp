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



#include "SlasconeOpenApiClient/model/DataExchangeUpdateLicenseDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



DataExchangeUpdateLicenseDto::DataExchangeUpdateLicenseDto()
{
    m_Product_id = utility::conversions::to_string_t("");
    m_Product_idIsSet = false;
    m_Customer_number = utility::conversions::to_string_t("");
    m_Customer_numberIsSet = false;
    m_Legacy_license_key = utility::conversions::to_string_t("");
    m_Legacy_license_keyIsSet = false;
    m_r_template = utility::conversions::to_string_t("");
    m_r_templateIsSet = false;
    m_Token_limit = 0;
    m_Token_limitIsSet = false;
    m_Goodwill_token_limit = 0;
    m_Goodwill_token_limitIsSet = false;
    m_Floating_token_limit = 0;
    m_Floating_token_limitIsSet = false;
    m_User_limit = 0;
    m_User_limitIsSet = false;
    m_Expiration_date = utility::conversions::to_string_t("");
    m_Expiration_dateIsSet = false;
    m_Software_release_limitation = utility::conversions::to_string_t("");
    m_Software_release_limitationIsSet = false;
    m_License_type = utility::conversions::to_string_t("");
    m_License_typeIsSet = false;
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
    m_Description = utility::conversions::to_string_t("");
    m_DescriptionIsSet = false;
    m_Is_active = false;
    m_Is_activeIsSet = false;
}

DataExchangeUpdateLicenseDto::~DataExchangeUpdateLicenseDto()
{
}

void DataExchangeUpdateLicenseDto::validate()
{
    // TODO: implement validation
}

web::json::value DataExchangeUpdateLicenseDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_Product_idIsSet)
    {
        val[utility::conversions::to_string_t(U("product_id"))] = ModelBase::toJson(m_Product_id);
    }
    if(m_Customer_numberIsSet)
    {
        val[utility::conversions::to_string_t(U("customer_number"))] = ModelBase::toJson(m_Customer_number);
    }
    if(m_Legacy_license_keyIsSet)
    {
        val[utility::conversions::to_string_t(U("legacy_license_key"))] = ModelBase::toJson(m_Legacy_license_key);
    }
    if(m_r_templateIsSet)
    {
        val[utility::conversions::to_string_t(U("template"))] = ModelBase::toJson(m_r_template);
    }
    if(m_Token_limitIsSet)
    {
        val[utility::conversions::to_string_t(U("token_limit"))] = ModelBase::toJson(m_Token_limit);
    }
    if(m_Goodwill_token_limitIsSet)
    {
        val[utility::conversions::to_string_t(U("goodwill_token_limit"))] = ModelBase::toJson(m_Goodwill_token_limit);
    }
    if(m_Floating_token_limitIsSet)
    {
        val[utility::conversions::to_string_t(U("floating_token_limit"))] = ModelBase::toJson(m_Floating_token_limit);
    }
    if(m_User_limitIsSet)
    {
        val[utility::conversions::to_string_t(U("user_limit"))] = ModelBase::toJson(m_User_limit);
    }
    if(m_Expiration_dateIsSet)
    {
        val[utility::conversions::to_string_t(U("expiration_date"))] = ModelBase::toJson(m_Expiration_date);
    }
    if(m_Software_release_limitationIsSet)
    {
        val[utility::conversions::to_string_t(U("software_release_limitation"))] = ModelBase::toJson(m_Software_release_limitation);
    }
    if(m_License_typeIsSet)
    {
        val[utility::conversions::to_string_t(U("license_type"))] = ModelBase::toJson(m_License_type);
    }
    if(m_NameIsSet)
    {
        val[utility::conversions::to_string_t(U("name"))] = ModelBase::toJson(m_Name);
    }
    if(m_DescriptionIsSet)
    {
        val[utility::conversions::to_string_t(U("description"))] = ModelBase::toJson(m_Description);
    }
    if(m_Is_activeIsSet)
    {
        val[utility::conversions::to_string_t(U("is_active"))] = ModelBase::toJson(m_Is_active);
    }

    return val;
}

bool DataExchangeUpdateLicenseDto::fromJson(const web::json::value& val)
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
    if(val.has_field(utility::conversions::to_string_t(U("customer_number"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("customer_number")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setCustomerNumber;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCustomerNumber);
            setCustomerNumber(refVal_setCustomerNumber);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("legacy_license_key"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("legacy_license_key")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setLegacyLicenseKey;
            ok &= ModelBase::fromJson(fieldValue, refVal_setLegacyLicenseKey);
            setLegacyLicenseKey(refVal_setLegacyLicenseKey);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("template"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("template")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setRTemplate;
            ok &= ModelBase::fromJson(fieldValue, refVal_setRTemplate);
            setRTemplate(refVal_setRTemplate);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("token_limit"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("token_limit")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setTokenLimit;
            ok &= ModelBase::fromJson(fieldValue, refVal_setTokenLimit);
            setTokenLimit(refVal_setTokenLimit);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("goodwill_token_limit"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("goodwill_token_limit")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setGoodwillTokenLimit;
            ok &= ModelBase::fromJson(fieldValue, refVal_setGoodwillTokenLimit);
            setGoodwillTokenLimit(refVal_setGoodwillTokenLimit);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("floating_token_limit"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("floating_token_limit")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setFloatingTokenLimit;
            ok &= ModelBase::fromJson(fieldValue, refVal_setFloatingTokenLimit);
            setFloatingTokenLimit(refVal_setFloatingTokenLimit);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("user_limit"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("user_limit")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setUserLimit;
            ok &= ModelBase::fromJson(fieldValue, refVal_setUserLimit);
            setUserLimit(refVal_setUserLimit);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("expiration_date"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("expiration_date")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setExpirationDate;
            ok &= ModelBase::fromJson(fieldValue, refVal_setExpirationDate);
            setExpirationDate(refVal_setExpirationDate);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("software_release_limitation"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("software_release_limitation")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setSoftwareReleaseLimitation;
            ok &= ModelBase::fromJson(fieldValue, refVal_setSoftwareReleaseLimitation);
            setSoftwareReleaseLimitation(refVal_setSoftwareReleaseLimitation);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("license_type"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("license_type")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setLicenseType;
            ok &= ModelBase::fromJson(fieldValue, refVal_setLicenseType);
            setLicenseType(refVal_setLicenseType);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("name"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("name")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setName;
            ok &= ModelBase::fromJson(fieldValue, refVal_setName);
            setName(refVal_setName);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("description"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("description")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setDescription;
            ok &= ModelBase::fromJson(fieldValue, refVal_setDescription);
            setDescription(refVal_setDescription);
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

void DataExchangeUpdateLicenseDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_Customer_numberIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("customer_number")), m_Customer_number));
    }
    if(m_Legacy_license_keyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("legacy_license_key")), m_Legacy_license_key));
    }
    if(m_r_templateIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("template")), m_r_template));
    }
    if(m_Token_limitIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("token_limit")), m_Token_limit));
    }
    if(m_Goodwill_token_limitIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("goodwill_token_limit")), m_Goodwill_token_limit));
    }
    if(m_Floating_token_limitIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("floating_token_limit")), m_Floating_token_limit));
    }
    if(m_User_limitIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("user_limit")), m_User_limit));
    }
    if(m_Expiration_dateIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("expiration_date")), m_Expiration_date));
    }
    if(m_Software_release_limitationIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("software_release_limitation")), m_Software_release_limitation));
    }
    if(m_License_typeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("license_type")), m_License_type));
    }
    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("name")), m_Name));
    }
    if(m_DescriptionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("description")), m_Description));
    }
    if(m_Is_activeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("is_active")), m_Is_active));
    }
}

bool DataExchangeUpdateLicenseDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t(U("customer_number"))))
    {
        utility::string_t refVal_setCustomerNumber;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("customer_number"))), refVal_setCustomerNumber );
        setCustomerNumber(refVal_setCustomerNumber);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("legacy_license_key"))))
    {
        utility::string_t refVal_setLegacyLicenseKey;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("legacy_license_key"))), refVal_setLegacyLicenseKey );
        setLegacyLicenseKey(refVal_setLegacyLicenseKey);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("template"))))
    {
        utility::string_t refVal_setRTemplate;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("template"))), refVal_setRTemplate );
        setRTemplate(refVal_setRTemplate);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("token_limit"))))
    {
        int32_t refVal_setTokenLimit;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("token_limit"))), refVal_setTokenLimit );
        setTokenLimit(refVal_setTokenLimit);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("goodwill_token_limit"))))
    {
        int32_t refVal_setGoodwillTokenLimit;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("goodwill_token_limit"))), refVal_setGoodwillTokenLimit );
        setGoodwillTokenLimit(refVal_setGoodwillTokenLimit);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("floating_token_limit"))))
    {
        int32_t refVal_setFloatingTokenLimit;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("floating_token_limit"))), refVal_setFloatingTokenLimit );
        setFloatingTokenLimit(refVal_setFloatingTokenLimit);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("user_limit"))))
    {
        int32_t refVal_setUserLimit;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("user_limit"))), refVal_setUserLimit );
        setUserLimit(refVal_setUserLimit);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("expiration_date"))))
    {
        utility::string_t refVal_setExpirationDate;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("expiration_date"))), refVal_setExpirationDate );
        setExpirationDate(refVal_setExpirationDate);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("software_release_limitation"))))
    {
        utility::string_t refVal_setSoftwareReleaseLimitation;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("software_release_limitation"))), refVal_setSoftwareReleaseLimitation );
        setSoftwareReleaseLimitation(refVal_setSoftwareReleaseLimitation);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("license_type"))))
    {
        utility::string_t refVal_setLicenseType;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("license_type"))), refVal_setLicenseType );
        setLicenseType(refVal_setLicenseType);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("name"))))
    {
        utility::string_t refVal_setName;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("name"))), refVal_setName );
        setName(refVal_setName);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("description"))))
    {
        utility::string_t refVal_setDescription;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("description"))), refVal_setDescription );
        setDescription(refVal_setDescription);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("is_active"))))
    {
        bool refVal_setIsActive;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("is_active"))), refVal_setIsActive );
        setIsActive(refVal_setIsActive);
    }
    return ok;
}

utility::string_t DataExchangeUpdateLicenseDto::getProductId() const
{
    return m_Product_id;
}

void DataExchangeUpdateLicenseDto::setProductId(const utility::string_t& value)
{
    m_Product_id = value;
    m_Product_idIsSet = true;
}

bool DataExchangeUpdateLicenseDto::productIdIsSet() const
{
    return m_Product_idIsSet;
}

void DataExchangeUpdateLicenseDto::unsetProduct_id()
{
    m_Product_idIsSet = false;
}
utility::string_t DataExchangeUpdateLicenseDto::getCustomerNumber() const
{
    return m_Customer_number;
}

void DataExchangeUpdateLicenseDto::setCustomerNumber(const utility::string_t& value)
{
    m_Customer_number = value;
    m_Customer_numberIsSet = true;
}

bool DataExchangeUpdateLicenseDto::customerNumberIsSet() const
{
    return m_Customer_numberIsSet;
}

void DataExchangeUpdateLicenseDto::unsetCustomer_number()
{
    m_Customer_numberIsSet = false;
}
utility::string_t DataExchangeUpdateLicenseDto::getLegacyLicenseKey() const
{
    return m_Legacy_license_key;
}

void DataExchangeUpdateLicenseDto::setLegacyLicenseKey(const utility::string_t& value)
{
    m_Legacy_license_key = value;
    m_Legacy_license_keyIsSet = true;
}

bool DataExchangeUpdateLicenseDto::legacyLicenseKeyIsSet() const
{
    return m_Legacy_license_keyIsSet;
}

void DataExchangeUpdateLicenseDto::unsetLegacy_license_key()
{
    m_Legacy_license_keyIsSet = false;
}
utility::string_t DataExchangeUpdateLicenseDto::getRTemplate() const
{
    return m_r_template;
}

void DataExchangeUpdateLicenseDto::setRTemplate(const utility::string_t& value)
{
    m_r_template = value;
    m_r_templateIsSet = true;
}

bool DataExchangeUpdateLicenseDto::rTemplateIsSet() const
{
    return m_r_templateIsSet;
}

void DataExchangeUpdateLicenseDto::unsetr_template()
{
    m_r_templateIsSet = false;
}
int32_t DataExchangeUpdateLicenseDto::getTokenLimit() const
{
    return m_Token_limit;
}

void DataExchangeUpdateLicenseDto::setTokenLimit(int32_t value)
{
    m_Token_limit = value;
    m_Token_limitIsSet = true;
}

bool DataExchangeUpdateLicenseDto::tokenLimitIsSet() const
{
    return m_Token_limitIsSet;
}

void DataExchangeUpdateLicenseDto::unsetToken_limit()
{
    m_Token_limitIsSet = false;
}
int32_t DataExchangeUpdateLicenseDto::getGoodwillTokenLimit() const
{
    return m_Goodwill_token_limit;
}

void DataExchangeUpdateLicenseDto::setGoodwillTokenLimit(int32_t value)
{
    m_Goodwill_token_limit = value;
    m_Goodwill_token_limitIsSet = true;
}

bool DataExchangeUpdateLicenseDto::goodwillTokenLimitIsSet() const
{
    return m_Goodwill_token_limitIsSet;
}

void DataExchangeUpdateLicenseDto::unsetGoodwill_token_limit()
{
    m_Goodwill_token_limitIsSet = false;
}
int32_t DataExchangeUpdateLicenseDto::getFloatingTokenLimit() const
{
    return m_Floating_token_limit;
}

void DataExchangeUpdateLicenseDto::setFloatingTokenLimit(int32_t value)
{
    m_Floating_token_limit = value;
    m_Floating_token_limitIsSet = true;
}

bool DataExchangeUpdateLicenseDto::floatingTokenLimitIsSet() const
{
    return m_Floating_token_limitIsSet;
}

void DataExchangeUpdateLicenseDto::unsetFloating_token_limit()
{
    m_Floating_token_limitIsSet = false;
}
int32_t DataExchangeUpdateLicenseDto::getUserLimit() const
{
    return m_User_limit;
}

void DataExchangeUpdateLicenseDto::setUserLimit(int32_t value)
{
    m_User_limit = value;
    m_User_limitIsSet = true;
}

bool DataExchangeUpdateLicenseDto::userLimitIsSet() const
{
    return m_User_limitIsSet;
}

void DataExchangeUpdateLicenseDto::unsetUser_limit()
{
    m_User_limitIsSet = false;
}
utility::string_t DataExchangeUpdateLicenseDto::getExpirationDate() const
{
    return m_Expiration_date;
}

void DataExchangeUpdateLicenseDto::setExpirationDate(const utility::string_t& value)
{
    m_Expiration_date = value;
    m_Expiration_dateIsSet = true;
}

bool DataExchangeUpdateLicenseDto::expirationDateIsSet() const
{
    return m_Expiration_dateIsSet;
}

void DataExchangeUpdateLicenseDto::unsetExpiration_date()
{
    m_Expiration_dateIsSet = false;
}
utility::string_t DataExchangeUpdateLicenseDto::getSoftwareReleaseLimitation() const
{
    return m_Software_release_limitation;
}

void DataExchangeUpdateLicenseDto::setSoftwareReleaseLimitation(const utility::string_t& value)
{
    m_Software_release_limitation = value;
    m_Software_release_limitationIsSet = true;
}

bool DataExchangeUpdateLicenseDto::softwareReleaseLimitationIsSet() const
{
    return m_Software_release_limitationIsSet;
}

void DataExchangeUpdateLicenseDto::unsetSoftware_release_limitation()
{
    m_Software_release_limitationIsSet = false;
}
utility::string_t DataExchangeUpdateLicenseDto::getLicenseType() const
{
    return m_License_type;
}

void DataExchangeUpdateLicenseDto::setLicenseType(const utility::string_t& value)
{
    m_License_type = value;
    m_License_typeIsSet = true;
}

bool DataExchangeUpdateLicenseDto::licenseTypeIsSet() const
{
    return m_License_typeIsSet;
}

void DataExchangeUpdateLicenseDto::unsetLicense_type()
{
    m_License_typeIsSet = false;
}
utility::string_t DataExchangeUpdateLicenseDto::getName() const
{
    return m_Name;
}

void DataExchangeUpdateLicenseDto::setName(const utility::string_t& value)
{
    m_Name = value;
    m_NameIsSet = true;
}

bool DataExchangeUpdateLicenseDto::nameIsSet() const
{
    return m_NameIsSet;
}

void DataExchangeUpdateLicenseDto::unsetName()
{
    m_NameIsSet = false;
}
utility::string_t DataExchangeUpdateLicenseDto::getDescription() const
{
    return m_Description;
}

void DataExchangeUpdateLicenseDto::setDescription(const utility::string_t& value)
{
    m_Description = value;
    m_DescriptionIsSet = true;
}

bool DataExchangeUpdateLicenseDto::descriptionIsSet() const
{
    return m_DescriptionIsSet;
}

void DataExchangeUpdateLicenseDto::unsetDescription()
{
    m_DescriptionIsSet = false;
}
bool DataExchangeUpdateLicenseDto::isIsActive() const
{
    return m_Is_active;
}

void DataExchangeUpdateLicenseDto::setIsActive(bool value)
{
    m_Is_active = value;
    m_Is_activeIsSet = true;
}

bool DataExchangeUpdateLicenseDto::isActiveIsSet() const
{
    return m_Is_activeIsSet;
}

void DataExchangeUpdateLicenseDto::unsetIs_active()
{
    m_Is_activeIsSet = false;
}
}
}
}
}

