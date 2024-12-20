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



#include "SlasconeOpenApiClient/model/LicenseLazyLoadDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



LicenseLazyLoadDto::LicenseLazyLoadDto()
{
    m_LicensesIsSet = false;
    m_Max_count = 0;
    m_Max_countIsSet = false;
    m_Customer_count = 0;
    m_Customer_countIsSet = false;
}

LicenseLazyLoadDto::~LicenseLazyLoadDto()
{
}

void LicenseLazyLoadDto::validate()
{
    // TODO: implement validation
}

web::json::value LicenseLazyLoadDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_LicensesIsSet)
    {
        val[utility::conversions::to_string_t(U("licenses"))] = ModelBase::toJson(m_Licenses);
    }
    if(m_Max_countIsSet)
    {
        val[utility::conversions::to_string_t(U("max_count"))] = ModelBase::toJson(m_Max_count);
    }
    if(m_Customer_countIsSet)
    {
        val[utility::conversions::to_string_t(U("customer_count"))] = ModelBase::toJson(m_Customer_count);
    }

    return val;
}

bool LicenseLazyLoadDto::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("licenses"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("licenses")));
        if(!fieldValue.is_null())
        {
            std::vector<std::shared_ptr<LicenseTreeDto>> refVal_setLicenses;
            ok &= ModelBase::fromJson(fieldValue, refVal_setLicenses);
            setLicenses(refVal_setLicenses);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("max_count"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("max_count")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setMaxCount;
            ok &= ModelBase::fromJson(fieldValue, refVal_setMaxCount);
            setMaxCount(refVal_setMaxCount);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("customer_count"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("customer_count")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setCustomerCount;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCustomerCount);
            setCustomerCount(refVal_setCustomerCount);
        }
    }
    return ok;
}

void LicenseLazyLoadDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_LicensesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("licenses")), m_Licenses));
    }
    if(m_Max_countIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("max_count")), m_Max_count));
    }
    if(m_Customer_countIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("customer_count")), m_Customer_count));
    }
}

bool LicenseLazyLoadDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("licenses"))))
    {
        std::vector<std::shared_ptr<LicenseTreeDto>> refVal_setLicenses;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("licenses"))), refVal_setLicenses );
        setLicenses(refVal_setLicenses);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("max_count"))))
    {
        int32_t refVal_setMaxCount;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("max_count"))), refVal_setMaxCount );
        setMaxCount(refVal_setMaxCount);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("customer_count"))))
    {
        int32_t refVal_setCustomerCount;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("customer_count"))), refVal_setCustomerCount );
        setCustomerCount(refVal_setCustomerCount);
    }
    return ok;
}

std::vector<std::shared_ptr<LicenseTreeDto>>& LicenseLazyLoadDto::getLicenses()
{
    return m_Licenses;
}

void LicenseLazyLoadDto::setLicenses(const std::vector<std::shared_ptr<LicenseTreeDto>>& value)
{
    m_Licenses = value;
    m_LicensesIsSet = true;
}

bool LicenseLazyLoadDto::licensesIsSet() const
{
    return m_LicensesIsSet;
}

void LicenseLazyLoadDto::unsetLicenses()
{
    m_LicensesIsSet = false;
}
int32_t LicenseLazyLoadDto::getMaxCount() const
{
    return m_Max_count;
}

void LicenseLazyLoadDto::setMaxCount(int32_t value)
{
    m_Max_count = value;
    m_Max_countIsSet = true;
}

bool LicenseLazyLoadDto::maxCountIsSet() const
{
    return m_Max_countIsSet;
}

void LicenseLazyLoadDto::unsetMax_count()
{
    m_Max_countIsSet = false;
}
int32_t LicenseLazyLoadDto::getCustomerCount() const
{
    return m_Customer_count;
}

void LicenseLazyLoadDto::setCustomerCount(int32_t value)
{
    m_Customer_count = value;
    m_Customer_countIsSet = true;
}

bool LicenseLazyLoadDto::customerCountIsSet() const
{
    return m_Customer_countIsSet;
}

void LicenseLazyLoadDto::unsetCustomer_count()
{
    m_Customer_countIsSet = false;
}
}
}
}
}


