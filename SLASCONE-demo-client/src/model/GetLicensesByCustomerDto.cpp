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



#include "SlasconeOpenApiClient/model/GetLicensesByCustomerDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



GetLicensesByCustomerDto::GetLicensesByCustomerDto()
{
    m_Product_id = utility::conversions::to_string_t("");
    m_Product_idIsSet = false;
    m_Customer_number = utility::conversions::to_string_t("");
    m_Customer_numberIsSet = false;
    m_Active_licenses_only = false;
    m_Active_licenses_onlyIsSet = false;
}

GetLicensesByCustomerDto::~GetLicensesByCustomerDto()
{
}

void GetLicensesByCustomerDto::validate()
{
    // TODO: implement validation
}

web::json::value GetLicensesByCustomerDto::toJson() const
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
    if(m_Active_licenses_onlyIsSet)
    {
        val[utility::conversions::to_string_t(U("active_licenses_only"))] = ModelBase::toJson(m_Active_licenses_only);
    }

    return val;
}

bool GetLicensesByCustomerDto::fromJson(const web::json::value& val)
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
    if(val.has_field(utility::conversions::to_string_t(U("active_licenses_only"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("active_licenses_only")));
        if(!fieldValue.is_null())
        {
            bool refVal_setActiveLicensesOnly;
            ok &= ModelBase::fromJson(fieldValue, refVal_setActiveLicensesOnly);
            setActiveLicensesOnly(refVal_setActiveLicensesOnly);
        }
    }
    return ok;
}

void GetLicensesByCustomerDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_Active_licenses_onlyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("active_licenses_only")), m_Active_licenses_only));
    }
}

bool GetLicensesByCustomerDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t(U("active_licenses_only"))))
    {
        bool refVal_setActiveLicensesOnly;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("active_licenses_only"))), refVal_setActiveLicensesOnly );
        setActiveLicensesOnly(refVal_setActiveLicensesOnly);
    }
    return ok;
}

utility::string_t GetLicensesByCustomerDto::getProductId() const
{
    return m_Product_id;
}

void GetLicensesByCustomerDto::setProductId(const utility::string_t& value)
{
    m_Product_id = value;
    m_Product_idIsSet = true;
}

bool GetLicensesByCustomerDto::productIdIsSet() const
{
    return m_Product_idIsSet;
}

void GetLicensesByCustomerDto::unsetProduct_id()
{
    m_Product_idIsSet = false;
}
utility::string_t GetLicensesByCustomerDto::getCustomerNumber() const
{
    return m_Customer_number;
}

void GetLicensesByCustomerDto::setCustomerNumber(const utility::string_t& value)
{
    m_Customer_number = value;
    m_Customer_numberIsSet = true;
}

bool GetLicensesByCustomerDto::customerNumberIsSet() const
{
    return m_Customer_numberIsSet;
}

void GetLicensesByCustomerDto::unsetCustomer_number()
{
    m_Customer_numberIsSet = false;
}
bool GetLicensesByCustomerDto::isActiveLicensesOnly() const
{
    return m_Active_licenses_only;
}

void GetLicensesByCustomerDto::setActiveLicensesOnly(bool value)
{
    m_Active_licenses_only = value;
    m_Active_licenses_onlyIsSet = true;
}

bool GetLicensesByCustomerDto::activeLicensesOnlyIsSet() const
{
    return m_Active_licenses_onlyIsSet;
}

void GetLicensesByCustomerDto::unsetActive_licenses_only()
{
    m_Active_licenses_onlyIsSet = false;
}
}
}
}
}


