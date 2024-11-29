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



#include "SlasconeOpenApiClient/model/DataExchangeAddCustomerDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



DataExchangeAddCustomerDto::DataExchangeAddCustomerDto()
{
    m_Customer_number = utility::conversions::to_string_t("");
    m_Customer_numberIsSet = false;
    m_Customer_name = utility::conversions::to_string_t("");
    m_Customer_nameIsSet = false;
    m_Customer_type = utility::conversions::to_string_t("");
    m_Customer_typeIsSet = false;
    m_Country = utility::conversions::to_string_t("");
    m_CountryIsSet = false;
    m_Street = utility::conversions::to_string_t("");
    m_StreetIsSet = false;
    m_Zip = utility::conversions::to_string_t("");
    m_ZipIsSet = false;
    m_City = utility::conversions::to_string_t("");
    m_CityIsSet = false;
    m_Phone = utility::conversions::to_string_t("");
    m_PhoneIsSet = false;
    m_Email = utility::conversions::to_string_t("");
    m_EmailIsSet = false;
    m_Prospect_number = utility::conversions::to_string_t("");
    m_Prospect_numberIsSet = false;
    m_TagsIsSet = false;
}

DataExchangeAddCustomerDto::~DataExchangeAddCustomerDto()
{
}

void DataExchangeAddCustomerDto::validate()
{
    // TODO: implement validation
}

web::json::value DataExchangeAddCustomerDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_Customer_numberIsSet)
    {
        val[utility::conversions::to_string_t(U("customer_number"))] = ModelBase::toJson(m_Customer_number);
    }
    if(m_Customer_nameIsSet)
    {
        val[utility::conversions::to_string_t(U("customer_name"))] = ModelBase::toJson(m_Customer_name);
    }
    if(m_Customer_typeIsSet)
    {
        val[utility::conversions::to_string_t(U("customer_type"))] = ModelBase::toJson(m_Customer_type);
    }
    if(m_CountryIsSet)
    {
        val[utility::conversions::to_string_t(U("country"))] = ModelBase::toJson(m_Country);
    }
    if(m_StreetIsSet)
    {
        val[utility::conversions::to_string_t(U("street"))] = ModelBase::toJson(m_Street);
    }
    if(m_ZipIsSet)
    {
        val[utility::conversions::to_string_t(U("zip"))] = ModelBase::toJson(m_Zip);
    }
    if(m_CityIsSet)
    {
        val[utility::conversions::to_string_t(U("city"))] = ModelBase::toJson(m_City);
    }
    if(m_PhoneIsSet)
    {
        val[utility::conversions::to_string_t(U("phone"))] = ModelBase::toJson(m_Phone);
    }
    if(m_EmailIsSet)
    {
        val[utility::conversions::to_string_t(U("email"))] = ModelBase::toJson(m_Email);
    }
    if(m_Prospect_numberIsSet)
    {
        val[utility::conversions::to_string_t(U("prospect_number"))] = ModelBase::toJson(m_Prospect_number);
    }
    if(m_TagsIsSet)
    {
        val[utility::conversions::to_string_t(U("tags"))] = ModelBase::toJson(m_Tags);
    }

    return val;
}

bool DataExchangeAddCustomerDto::fromJson(const web::json::value& val)
{
    bool ok = true;
    
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
    if(val.has_field(utility::conversions::to_string_t(U("customer_name"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("customer_name")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setCustomerName;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCustomerName);
            setCustomerName(refVal_setCustomerName);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("customer_type"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("customer_type")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setCustomerType;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCustomerType);
            setCustomerType(refVal_setCustomerType);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("country"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("country")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setCountry;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCountry);
            setCountry(refVal_setCountry);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("street"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("street")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setStreet;
            ok &= ModelBase::fromJson(fieldValue, refVal_setStreet);
            setStreet(refVal_setStreet);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("zip"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("zip")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setZip;
            ok &= ModelBase::fromJson(fieldValue, refVal_setZip);
            setZip(refVal_setZip);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("city"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("city")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setCity;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCity);
            setCity(refVal_setCity);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("phone"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("phone")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setPhone;
            ok &= ModelBase::fromJson(fieldValue, refVal_setPhone);
            setPhone(refVal_setPhone);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("email"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("email")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setEmail;
            ok &= ModelBase::fromJson(fieldValue, refVal_setEmail);
            setEmail(refVal_setEmail);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("prospect_number"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("prospect_number")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setProspectNumber;
            ok &= ModelBase::fromJson(fieldValue, refVal_setProspectNumber);
            setProspectNumber(refVal_setProspectNumber);
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

void DataExchangeAddCustomerDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_Customer_numberIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("customer_number")), m_Customer_number));
    }
    if(m_Customer_nameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("customer_name")), m_Customer_name));
    }
    if(m_Customer_typeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("customer_type")), m_Customer_type));
    }
    if(m_CountryIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("country")), m_Country));
    }
    if(m_StreetIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("street")), m_Street));
    }
    if(m_ZipIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("zip")), m_Zip));
    }
    if(m_CityIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("city")), m_City));
    }
    if(m_PhoneIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("phone")), m_Phone));
    }
    if(m_EmailIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("email")), m_Email));
    }
    if(m_Prospect_numberIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("prospect_number")), m_Prospect_number));
    }
    if(m_TagsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("tags")), m_Tags));
    }
}

bool DataExchangeAddCustomerDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("customer_number"))))
    {
        utility::string_t refVal_setCustomerNumber;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("customer_number"))), refVal_setCustomerNumber );
        setCustomerNumber(refVal_setCustomerNumber);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("customer_name"))))
    {
        utility::string_t refVal_setCustomerName;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("customer_name"))), refVal_setCustomerName );
        setCustomerName(refVal_setCustomerName);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("customer_type"))))
    {
        utility::string_t refVal_setCustomerType;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("customer_type"))), refVal_setCustomerType );
        setCustomerType(refVal_setCustomerType);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("country"))))
    {
        utility::string_t refVal_setCountry;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("country"))), refVal_setCountry );
        setCountry(refVal_setCountry);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("street"))))
    {
        utility::string_t refVal_setStreet;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("street"))), refVal_setStreet );
        setStreet(refVal_setStreet);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("zip"))))
    {
        utility::string_t refVal_setZip;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("zip"))), refVal_setZip );
        setZip(refVal_setZip);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("city"))))
    {
        utility::string_t refVal_setCity;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("city"))), refVal_setCity );
        setCity(refVal_setCity);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("phone"))))
    {
        utility::string_t refVal_setPhone;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("phone"))), refVal_setPhone );
        setPhone(refVal_setPhone);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("email"))))
    {
        utility::string_t refVal_setEmail;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("email"))), refVal_setEmail );
        setEmail(refVal_setEmail);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("prospect_number"))))
    {
        utility::string_t refVal_setProspectNumber;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("prospect_number"))), refVal_setProspectNumber );
        setProspectNumber(refVal_setProspectNumber);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("tags"))))
    {
        std::vector<utility::string_t> refVal_setTags;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("tags"))), refVal_setTags );
        setTags(refVal_setTags);
    }
    return ok;
}

utility::string_t DataExchangeAddCustomerDto::getCustomerNumber() const
{
    return m_Customer_number;
}

void DataExchangeAddCustomerDto::setCustomerNumber(const utility::string_t& value)
{
    m_Customer_number = value;
    m_Customer_numberIsSet = true;
}

bool DataExchangeAddCustomerDto::customerNumberIsSet() const
{
    return m_Customer_numberIsSet;
}

void DataExchangeAddCustomerDto::unsetCustomer_number()
{
    m_Customer_numberIsSet = false;
}
utility::string_t DataExchangeAddCustomerDto::getCustomerName() const
{
    return m_Customer_name;
}

void DataExchangeAddCustomerDto::setCustomerName(const utility::string_t& value)
{
    m_Customer_name = value;
    m_Customer_nameIsSet = true;
}

bool DataExchangeAddCustomerDto::customerNameIsSet() const
{
    return m_Customer_nameIsSet;
}

void DataExchangeAddCustomerDto::unsetCustomer_name()
{
    m_Customer_nameIsSet = false;
}
utility::string_t DataExchangeAddCustomerDto::getCustomerType() const
{
    return m_Customer_type;
}

void DataExchangeAddCustomerDto::setCustomerType(const utility::string_t& value)
{
    m_Customer_type = value;
    m_Customer_typeIsSet = true;
}

bool DataExchangeAddCustomerDto::customerTypeIsSet() const
{
    return m_Customer_typeIsSet;
}

void DataExchangeAddCustomerDto::unsetCustomer_type()
{
    m_Customer_typeIsSet = false;
}
utility::string_t DataExchangeAddCustomerDto::getCountry() const
{
    return m_Country;
}

void DataExchangeAddCustomerDto::setCountry(const utility::string_t& value)
{
    m_Country = value;
    m_CountryIsSet = true;
}

bool DataExchangeAddCustomerDto::countryIsSet() const
{
    return m_CountryIsSet;
}

void DataExchangeAddCustomerDto::unsetCountry()
{
    m_CountryIsSet = false;
}
utility::string_t DataExchangeAddCustomerDto::getStreet() const
{
    return m_Street;
}

void DataExchangeAddCustomerDto::setStreet(const utility::string_t& value)
{
    m_Street = value;
    m_StreetIsSet = true;
}

bool DataExchangeAddCustomerDto::streetIsSet() const
{
    return m_StreetIsSet;
}

void DataExchangeAddCustomerDto::unsetStreet()
{
    m_StreetIsSet = false;
}
utility::string_t DataExchangeAddCustomerDto::getZip() const
{
    return m_Zip;
}

void DataExchangeAddCustomerDto::setZip(const utility::string_t& value)
{
    m_Zip = value;
    m_ZipIsSet = true;
}

bool DataExchangeAddCustomerDto::zipIsSet() const
{
    return m_ZipIsSet;
}

void DataExchangeAddCustomerDto::unsetZip()
{
    m_ZipIsSet = false;
}
utility::string_t DataExchangeAddCustomerDto::getCity() const
{
    return m_City;
}

void DataExchangeAddCustomerDto::setCity(const utility::string_t& value)
{
    m_City = value;
    m_CityIsSet = true;
}

bool DataExchangeAddCustomerDto::cityIsSet() const
{
    return m_CityIsSet;
}

void DataExchangeAddCustomerDto::unsetCity()
{
    m_CityIsSet = false;
}
utility::string_t DataExchangeAddCustomerDto::getPhone() const
{
    return m_Phone;
}

void DataExchangeAddCustomerDto::setPhone(const utility::string_t& value)
{
    m_Phone = value;
    m_PhoneIsSet = true;
}

bool DataExchangeAddCustomerDto::phoneIsSet() const
{
    return m_PhoneIsSet;
}

void DataExchangeAddCustomerDto::unsetPhone()
{
    m_PhoneIsSet = false;
}
utility::string_t DataExchangeAddCustomerDto::getEmail() const
{
    return m_Email;
}

void DataExchangeAddCustomerDto::setEmail(const utility::string_t& value)
{
    m_Email = value;
    m_EmailIsSet = true;
}

bool DataExchangeAddCustomerDto::emailIsSet() const
{
    return m_EmailIsSet;
}

void DataExchangeAddCustomerDto::unsetEmail()
{
    m_EmailIsSet = false;
}
utility::string_t DataExchangeAddCustomerDto::getProspectNumber() const
{
    return m_Prospect_number;
}

void DataExchangeAddCustomerDto::setProspectNumber(const utility::string_t& value)
{
    m_Prospect_number = value;
    m_Prospect_numberIsSet = true;
}

bool DataExchangeAddCustomerDto::prospectNumberIsSet() const
{
    return m_Prospect_numberIsSet;
}

void DataExchangeAddCustomerDto::unsetProspect_number()
{
    m_Prospect_numberIsSet = false;
}
std::vector<utility::string_t>& DataExchangeAddCustomerDto::getTags()
{
    return m_Tags;
}

void DataExchangeAddCustomerDto::setTags(const std::vector<utility::string_t>& value)
{
    m_Tags = value;
    m_TagsIsSet = true;
}

bool DataExchangeAddCustomerDto::tagsIsSet() const
{
    return m_TagsIsSet;
}

void DataExchangeAddCustomerDto::unsetTags()
{
    m_TagsIsSet = false;
}
}
}
}
}


