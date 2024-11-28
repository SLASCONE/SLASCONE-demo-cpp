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



#include "SlasconeOpenApiClient/model/ResellerLightDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



ResellerLightDto::ResellerLightDto()
{
    m_Id = utility::conversions::to_string_t("");
    m_IdIsSet = false;
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
    m_Reseller_number = utility::conversions::to_string_t("");
    m_Reseller_numberIsSet = false;
    m_Email = utility::conversions::to_string_t("");
    m_EmailIsSet = false;
}

ResellerLightDto::~ResellerLightDto()
{
}

void ResellerLightDto::validate()
{
    // TODO: implement validation
}

web::json::value ResellerLightDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_IdIsSet)
    {
        val[utility::conversions::to_string_t(U("id"))] = ModelBase::toJson(m_Id);
    }
    if(m_NameIsSet)
    {
        val[utility::conversions::to_string_t(U("name"))] = ModelBase::toJson(m_Name);
    }
    if(m_Reseller_numberIsSet)
    {
        val[utility::conversions::to_string_t(U("reseller_number"))] = ModelBase::toJson(m_Reseller_number);
    }
    if(m_EmailIsSet)
    {
        val[utility::conversions::to_string_t(U("email"))] = ModelBase::toJson(m_Email);
    }

    return val;
}

bool ResellerLightDto::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setId);
            setId(refVal_setId);
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
    if(val.has_field(utility::conversions::to_string_t(U("reseller_number"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("reseller_number")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setResellerNumber;
            ok &= ModelBase::fromJson(fieldValue, refVal_setResellerNumber);
            setResellerNumber(refVal_setResellerNumber);
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
    return ok;
}

void ResellerLightDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_IdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("id")), m_Id));
    }
    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("name")), m_Name));
    }
    if(m_Reseller_numberIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("reseller_number")), m_Reseller_number));
    }
    if(m_EmailIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("email")), m_Email));
    }
}

bool ResellerLightDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("id"))))
    {
        utility::string_t refVal_setId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("id"))), refVal_setId );
        setId(refVal_setId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("name"))))
    {
        utility::string_t refVal_setName;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("name"))), refVal_setName );
        setName(refVal_setName);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("reseller_number"))))
    {
        utility::string_t refVal_setResellerNumber;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("reseller_number"))), refVal_setResellerNumber );
        setResellerNumber(refVal_setResellerNumber);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("email"))))
    {
        utility::string_t refVal_setEmail;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("email"))), refVal_setEmail );
        setEmail(refVal_setEmail);
    }
    return ok;
}

utility::string_t ResellerLightDto::getId() const
{
    return m_Id;
}

void ResellerLightDto::setId(const utility::string_t& value)
{
    m_Id = value;
    m_IdIsSet = true;
}

bool ResellerLightDto::idIsSet() const
{
    return m_IdIsSet;
}

void ResellerLightDto::unsetId()
{
    m_IdIsSet = false;
}
utility::string_t ResellerLightDto::getName() const
{
    return m_Name;
}

void ResellerLightDto::setName(const utility::string_t& value)
{
    m_Name = value;
    m_NameIsSet = true;
}

bool ResellerLightDto::nameIsSet() const
{
    return m_NameIsSet;
}

void ResellerLightDto::unsetName()
{
    m_NameIsSet = false;
}
utility::string_t ResellerLightDto::getResellerNumber() const
{
    return m_Reseller_number;
}

void ResellerLightDto::setResellerNumber(const utility::string_t& value)
{
    m_Reseller_number = value;
    m_Reseller_numberIsSet = true;
}

bool ResellerLightDto::resellerNumberIsSet() const
{
    return m_Reseller_numberIsSet;
}

void ResellerLightDto::unsetReseller_number()
{
    m_Reseller_numberIsSet = false;
}
utility::string_t ResellerLightDto::getEmail() const
{
    return m_Email;
}

void ResellerLightDto::setEmail(const utility::string_t& value)
{
    m_Email = value;
    m_EmailIsSet = true;
}

bool ResellerLightDto::emailIsSet() const
{
    return m_EmailIsSet;
}

void ResellerLightDto::unsetEmail()
{
    m_EmailIsSet = false;
}
}
}
}
}


