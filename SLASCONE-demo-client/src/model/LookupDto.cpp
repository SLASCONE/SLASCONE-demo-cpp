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



#include "SlasconeOpenApiClient/model/LookupDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



LookupDto::LookupDto()
{
    m_Product_id = utility::conversions::to_string_t("");
    m_Product_idIsSet = false;
    m_Customer_number = utility::conversions::to_string_t("");
    m_Customer_numberIsSet = false;
    m_Client_id = utility::conversions::to_string_t("");
    m_Client_idIsSet = false;
    m_Legacy_key = utility::conversions::to_string_t("");
    m_Legacy_keyIsSet = false;
}

LookupDto::~LookupDto()
{
}

void LookupDto::validate()
{
    // TODO: implement validation
}

web::json::value LookupDto::toJson() const
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
    if(m_Client_idIsSet)
    {
        val[utility::conversions::to_string_t(U("client_id"))] = ModelBase::toJson(m_Client_id);
    }
    if(m_Legacy_keyIsSet)
    {
        val[utility::conversions::to_string_t(U("legacy_key"))] = ModelBase::toJson(m_Legacy_key);
    }

    return val;
}

bool LookupDto::fromJson(const web::json::value& val)
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
    if(val.has_field(utility::conversions::to_string_t(U("legacy_key"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("legacy_key")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setLegacyKey;
            ok &= ModelBase::fromJson(fieldValue, refVal_setLegacyKey);
            setLegacyKey(refVal_setLegacyKey);
        }
    }
    return ok;
}

void LookupDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_Client_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("client_id")), m_Client_id));
    }
    if(m_Legacy_keyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("legacy_key")), m_Legacy_key));
    }
}

bool LookupDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t(U("client_id"))))
    {
        utility::string_t refVal_setClientId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("client_id"))), refVal_setClientId );
        setClientId(refVal_setClientId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("legacy_key"))))
    {
        utility::string_t refVal_setLegacyKey;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("legacy_key"))), refVal_setLegacyKey );
        setLegacyKey(refVal_setLegacyKey);
    }
    return ok;
}

utility::string_t LookupDto::getProductId() const
{
    return m_Product_id;
}

void LookupDto::setProductId(const utility::string_t& value)
{
    m_Product_id = value;
    m_Product_idIsSet = true;
}

bool LookupDto::productIdIsSet() const
{
    return m_Product_idIsSet;
}

void LookupDto::unsetProduct_id()
{
    m_Product_idIsSet = false;
}
utility::string_t LookupDto::getCustomerNumber() const
{
    return m_Customer_number;
}

void LookupDto::setCustomerNumber(const utility::string_t& value)
{
    m_Customer_number = value;
    m_Customer_numberIsSet = true;
}

bool LookupDto::customerNumberIsSet() const
{
    return m_Customer_numberIsSet;
}

void LookupDto::unsetCustomer_number()
{
    m_Customer_numberIsSet = false;
}
utility::string_t LookupDto::getClientId() const
{
    return m_Client_id;
}

void LookupDto::setClientId(const utility::string_t& value)
{
    m_Client_id = value;
    m_Client_idIsSet = true;
}

bool LookupDto::clientIdIsSet() const
{
    return m_Client_idIsSet;
}

void LookupDto::unsetClient_id()
{
    m_Client_idIsSet = false;
}
utility::string_t LookupDto::getLegacyKey() const
{
    return m_Legacy_key;
}

void LookupDto::setLegacyKey(const utility::string_t& value)
{
    m_Legacy_key = value;
    m_Legacy_keyIsSet = true;
}

bool LookupDto::legacyKeyIsSet() const
{
    return m_Legacy_keyIsSet;
}

void LookupDto::unsetLegacy_key()
{
    m_Legacy_keyIsSet = false;
}
}
}
}
}

