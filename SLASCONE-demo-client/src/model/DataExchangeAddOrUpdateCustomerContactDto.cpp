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



#include "SlasconeOpenApiClient/model/DataExchangeAddOrUpdateCustomerContactDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



DataExchangeAddOrUpdateCustomerContactDto::DataExchangeAddOrUpdateCustomerContactDto()
{
    m_Customer_number = utility::conversions::to_string_t("");
    m_Customer_numberIsSet = false;
    m_Contact_name = utility::conversions::to_string_t("");
    m_Contact_nameIsSet = false;
    m_Contact_surname = utility::conversions::to_string_t("");
    m_Contact_surnameIsSet = false;
    m_Email = utility::conversions::to_string_t("");
    m_EmailIsSet = false;
    m_Phone = utility::conversions::to_string_t("");
    m_PhoneIsSet = false;
    m_Mobil = utility::conversions::to_string_t("");
    m_MobilIsSet = false;
    m_Language = utility::conversions::to_string_t("");
    m_LanguageIsSet = false;
    m_Is_customer_portal_user = false;
    m_Is_customer_portal_userIsSet = false;
}

DataExchangeAddOrUpdateCustomerContactDto::~DataExchangeAddOrUpdateCustomerContactDto()
{
}

void DataExchangeAddOrUpdateCustomerContactDto::validate()
{
    // TODO: implement validation
}

web::json::value DataExchangeAddOrUpdateCustomerContactDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_Customer_numberIsSet)
    {
        val[utility::conversions::to_string_t(U("customer_number"))] = ModelBase::toJson(m_Customer_number);
    }
    if(m_Contact_nameIsSet)
    {
        val[utility::conversions::to_string_t(U("contact_name"))] = ModelBase::toJson(m_Contact_name);
    }
    if(m_Contact_surnameIsSet)
    {
        val[utility::conversions::to_string_t(U("contact_surname"))] = ModelBase::toJson(m_Contact_surname);
    }
    if(m_EmailIsSet)
    {
        val[utility::conversions::to_string_t(U("email"))] = ModelBase::toJson(m_Email);
    }
    if(m_PhoneIsSet)
    {
        val[utility::conversions::to_string_t(U("phone"))] = ModelBase::toJson(m_Phone);
    }
    if(m_MobilIsSet)
    {
        val[utility::conversions::to_string_t(U("mobil"))] = ModelBase::toJson(m_Mobil);
    }
    if(m_LanguageIsSet)
    {
        val[utility::conversions::to_string_t(U("language"))] = ModelBase::toJson(m_Language);
    }
    if(m_Is_customer_portal_userIsSet)
    {
        val[utility::conversions::to_string_t(U("is_customer_portal_user"))] = ModelBase::toJson(m_Is_customer_portal_user);
    }

    return val;
}

bool DataExchangeAddOrUpdateCustomerContactDto::fromJson(const web::json::value& val)
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
    if(val.has_field(utility::conversions::to_string_t(U("contact_name"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("contact_name")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setContactName;
            ok &= ModelBase::fromJson(fieldValue, refVal_setContactName);
            setContactName(refVal_setContactName);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("contact_surname"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("contact_surname")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setContactSurname;
            ok &= ModelBase::fromJson(fieldValue, refVal_setContactSurname);
            setContactSurname(refVal_setContactSurname);
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
    if(val.has_field(utility::conversions::to_string_t(U("mobil"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("mobil")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setMobil;
            ok &= ModelBase::fromJson(fieldValue, refVal_setMobil);
            setMobil(refVal_setMobil);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("language"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("language")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setLanguage;
            ok &= ModelBase::fromJson(fieldValue, refVal_setLanguage);
            setLanguage(refVal_setLanguage);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("is_customer_portal_user"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("is_customer_portal_user")));
        if(!fieldValue.is_null())
        {
            bool refVal_setIsCustomerPortalUser;
            ok &= ModelBase::fromJson(fieldValue, refVal_setIsCustomerPortalUser);
            setIsCustomerPortalUser(refVal_setIsCustomerPortalUser);
        }
    }
    return ok;
}

void DataExchangeAddOrUpdateCustomerContactDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_Contact_nameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("contact_name")), m_Contact_name));
    }
    if(m_Contact_surnameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("contact_surname")), m_Contact_surname));
    }
    if(m_EmailIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("email")), m_Email));
    }
    if(m_PhoneIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("phone")), m_Phone));
    }
    if(m_MobilIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("mobil")), m_Mobil));
    }
    if(m_LanguageIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("language")), m_Language));
    }
    if(m_Is_customer_portal_userIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("is_customer_portal_user")), m_Is_customer_portal_user));
    }
}

bool DataExchangeAddOrUpdateCustomerContactDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t(U("contact_name"))))
    {
        utility::string_t refVal_setContactName;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("contact_name"))), refVal_setContactName );
        setContactName(refVal_setContactName);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("contact_surname"))))
    {
        utility::string_t refVal_setContactSurname;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("contact_surname"))), refVal_setContactSurname );
        setContactSurname(refVal_setContactSurname);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("email"))))
    {
        utility::string_t refVal_setEmail;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("email"))), refVal_setEmail );
        setEmail(refVal_setEmail);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("phone"))))
    {
        utility::string_t refVal_setPhone;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("phone"))), refVal_setPhone );
        setPhone(refVal_setPhone);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("mobil"))))
    {
        utility::string_t refVal_setMobil;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("mobil"))), refVal_setMobil );
        setMobil(refVal_setMobil);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("language"))))
    {
        utility::string_t refVal_setLanguage;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("language"))), refVal_setLanguage );
        setLanguage(refVal_setLanguage);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("is_customer_portal_user"))))
    {
        bool refVal_setIsCustomerPortalUser;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("is_customer_portal_user"))), refVal_setIsCustomerPortalUser );
        setIsCustomerPortalUser(refVal_setIsCustomerPortalUser);
    }
    return ok;
}

utility::string_t DataExchangeAddOrUpdateCustomerContactDto::getCustomerNumber() const
{
    return m_Customer_number;
}

void DataExchangeAddOrUpdateCustomerContactDto::setCustomerNumber(const utility::string_t& value)
{
    m_Customer_number = value;
    m_Customer_numberIsSet = true;
}

bool DataExchangeAddOrUpdateCustomerContactDto::customerNumberIsSet() const
{
    return m_Customer_numberIsSet;
}

void DataExchangeAddOrUpdateCustomerContactDto::unsetCustomer_number()
{
    m_Customer_numberIsSet = false;
}
utility::string_t DataExchangeAddOrUpdateCustomerContactDto::getContactName() const
{
    return m_Contact_name;
}

void DataExchangeAddOrUpdateCustomerContactDto::setContactName(const utility::string_t& value)
{
    m_Contact_name = value;
    m_Contact_nameIsSet = true;
}

bool DataExchangeAddOrUpdateCustomerContactDto::contactNameIsSet() const
{
    return m_Contact_nameIsSet;
}

void DataExchangeAddOrUpdateCustomerContactDto::unsetContact_name()
{
    m_Contact_nameIsSet = false;
}
utility::string_t DataExchangeAddOrUpdateCustomerContactDto::getContactSurname() const
{
    return m_Contact_surname;
}

void DataExchangeAddOrUpdateCustomerContactDto::setContactSurname(const utility::string_t& value)
{
    m_Contact_surname = value;
    m_Contact_surnameIsSet = true;
}

bool DataExchangeAddOrUpdateCustomerContactDto::contactSurnameIsSet() const
{
    return m_Contact_surnameIsSet;
}

void DataExchangeAddOrUpdateCustomerContactDto::unsetContact_surname()
{
    m_Contact_surnameIsSet = false;
}
utility::string_t DataExchangeAddOrUpdateCustomerContactDto::getEmail() const
{
    return m_Email;
}

void DataExchangeAddOrUpdateCustomerContactDto::setEmail(const utility::string_t& value)
{
    m_Email = value;
    m_EmailIsSet = true;
}

bool DataExchangeAddOrUpdateCustomerContactDto::emailIsSet() const
{
    return m_EmailIsSet;
}

void DataExchangeAddOrUpdateCustomerContactDto::unsetEmail()
{
    m_EmailIsSet = false;
}
utility::string_t DataExchangeAddOrUpdateCustomerContactDto::getPhone() const
{
    return m_Phone;
}

void DataExchangeAddOrUpdateCustomerContactDto::setPhone(const utility::string_t& value)
{
    m_Phone = value;
    m_PhoneIsSet = true;
}

bool DataExchangeAddOrUpdateCustomerContactDto::phoneIsSet() const
{
    return m_PhoneIsSet;
}

void DataExchangeAddOrUpdateCustomerContactDto::unsetPhone()
{
    m_PhoneIsSet = false;
}
utility::string_t DataExchangeAddOrUpdateCustomerContactDto::getMobil() const
{
    return m_Mobil;
}

void DataExchangeAddOrUpdateCustomerContactDto::setMobil(const utility::string_t& value)
{
    m_Mobil = value;
    m_MobilIsSet = true;
}

bool DataExchangeAddOrUpdateCustomerContactDto::mobilIsSet() const
{
    return m_MobilIsSet;
}

void DataExchangeAddOrUpdateCustomerContactDto::unsetMobil()
{
    m_MobilIsSet = false;
}
utility::string_t DataExchangeAddOrUpdateCustomerContactDto::getLanguage() const
{
    return m_Language;
}

void DataExchangeAddOrUpdateCustomerContactDto::setLanguage(const utility::string_t& value)
{
    m_Language = value;
    m_LanguageIsSet = true;
}

bool DataExchangeAddOrUpdateCustomerContactDto::languageIsSet() const
{
    return m_LanguageIsSet;
}

void DataExchangeAddOrUpdateCustomerContactDto::unsetLanguage()
{
    m_LanguageIsSet = false;
}
bool DataExchangeAddOrUpdateCustomerContactDto::isIsCustomerPortalUser() const
{
    return m_Is_customer_portal_user;
}

void DataExchangeAddOrUpdateCustomerContactDto::setIsCustomerPortalUser(bool value)
{
    m_Is_customer_portal_user = value;
    m_Is_customer_portal_userIsSet = true;
}

bool DataExchangeAddOrUpdateCustomerContactDto::isCustomerPortalUserIsSet() const
{
    return m_Is_customer_portal_userIsSet;
}

void DataExchangeAddOrUpdateCustomerContactDto::unsetIs_customer_portal_user()
{
    m_Is_customer_portal_userIsSet = false;
}
}
}
}
}


