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



#include "SlasconeOpenApiClient/model/CustomerLazyLoadDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



CustomerLazyLoadDto::CustomerLazyLoadDto()
{
    m_CustomersIsSet = false;
    m_Max_count = 0;
    m_Max_countIsSet = false;
    m_Customer_charactersIsSet = false;
}

CustomerLazyLoadDto::~CustomerLazyLoadDto()
{
}

void CustomerLazyLoadDto::validate()
{
    // TODO: implement validation
}

web::json::value CustomerLazyLoadDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_CustomersIsSet)
    {
        val[utility::conversions::to_string_t(U("customers"))] = ModelBase::toJson(m_Customers);
    }
    if(m_Max_countIsSet)
    {
        val[utility::conversions::to_string_t(U("max_count"))] = ModelBase::toJson(m_Max_count);
    }
    if(m_Customer_charactersIsSet)
    {
        val[utility::conversions::to_string_t(U("customer_characters"))] = ModelBase::toJson(m_Customer_characters);
    }

    return val;
}

bool CustomerLazyLoadDto::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("customers"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("customers")));
        if(!fieldValue.is_null())
        {
            std::vector<std::shared_ptr<CustomerDto>> refVal_setCustomers;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCustomers);
            setCustomers(refVal_setCustomers);
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
    if(val.has_field(utility::conversions::to_string_t(U("customer_characters"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("customer_characters")));
        if(!fieldValue.is_null())
        {
            std::vector<utility::string_t> refVal_setCustomerCharacters;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCustomerCharacters);
            setCustomerCharacters(refVal_setCustomerCharacters);
        }
    }
    return ok;
}

void CustomerLazyLoadDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_CustomersIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("customers")), m_Customers));
    }
    if(m_Max_countIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("max_count")), m_Max_count));
    }
    if(m_Customer_charactersIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("customer_characters")), m_Customer_characters));
    }
}

bool CustomerLazyLoadDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("customers"))))
    {
        std::vector<std::shared_ptr<CustomerDto>> refVal_setCustomers;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("customers"))), refVal_setCustomers );
        setCustomers(refVal_setCustomers);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("max_count"))))
    {
        int32_t refVal_setMaxCount;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("max_count"))), refVal_setMaxCount );
        setMaxCount(refVal_setMaxCount);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("customer_characters"))))
    {
        std::vector<utility::string_t> refVal_setCustomerCharacters;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("customer_characters"))), refVal_setCustomerCharacters );
        setCustomerCharacters(refVal_setCustomerCharacters);
    }
    return ok;
}

std::vector<std::shared_ptr<CustomerDto>>& CustomerLazyLoadDto::getCustomers()
{
    return m_Customers;
}

void CustomerLazyLoadDto::setCustomers(const std::vector<std::shared_ptr<CustomerDto>>& value)
{
    m_Customers = value;
    m_CustomersIsSet = true;
}

bool CustomerLazyLoadDto::customersIsSet() const
{
    return m_CustomersIsSet;
}

void CustomerLazyLoadDto::unsetCustomers()
{
    m_CustomersIsSet = false;
}
int32_t CustomerLazyLoadDto::getMaxCount() const
{
    return m_Max_count;
}

void CustomerLazyLoadDto::setMaxCount(int32_t value)
{
    m_Max_count = value;
    m_Max_countIsSet = true;
}

bool CustomerLazyLoadDto::maxCountIsSet() const
{
    return m_Max_countIsSet;
}

void CustomerLazyLoadDto::unsetMax_count()
{
    m_Max_countIsSet = false;
}
std::vector<utility::string_t>& CustomerLazyLoadDto::getCustomerCharacters()
{
    return m_Customer_characters;
}

void CustomerLazyLoadDto::setCustomerCharacters(const std::vector<utility::string_t>& value)
{
    m_Customer_characters = value;
    m_Customer_charactersIsSet = true;
}

bool CustomerLazyLoadDto::customerCharactersIsSet() const
{
    return m_Customer_charactersIsSet;
}

void CustomerLazyLoadDto::unsetCustomer_characters()
{
    m_Customer_charactersIsSet = false;
}
}
}
}
}


