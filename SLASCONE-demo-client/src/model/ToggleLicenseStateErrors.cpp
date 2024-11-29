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



#include "SlasconeOpenApiClient/model/ToggleLicenseStateErrors.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



ToggleLicenseStateErrors::ToggleLicenseStateErrors()
{
    m_Id = 0;
    m_IdIsSet = false;
    m_Message = utility::conversions::to_string_t("");
    m_MessageIsSet = false;
    m_Help = utility::conversions::to_string_t("");
    m_HelpIsSet = false;
    m_ExpectedErrorsIsSet = false;
}

ToggleLicenseStateErrors::~ToggleLicenseStateErrors()
{
}

void ToggleLicenseStateErrors::validate()
{
    // TODO: implement validation
}

web::json::value ToggleLicenseStateErrors::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_IdIsSet)
    {
        val[utility::conversions::to_string_t(U("id"))] = ModelBase::toJson(m_Id);
    }
    if(m_MessageIsSet)
    {
        val[utility::conversions::to_string_t(U("message"))] = ModelBase::toJson(m_Message);
    }
    if(m_HelpIsSet)
    {
        val[utility::conversions::to_string_t(U("help"))] = ModelBase::toJson(m_Help);
    }
    if(m_ExpectedErrorsIsSet)
    {
        val[utility::conversions::to_string_t(U("expectedErrors"))] = ModelBase::toJson(m_ExpectedErrors);
    }

    return val;
}

bool ToggleLicenseStateErrors::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("id")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setId);
            setId(refVal_setId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("message"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("message")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setMessage;
            ok &= ModelBase::fromJson(fieldValue, refVal_setMessage);
            setMessage(refVal_setMessage);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("help"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("help")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setHelp;
            ok &= ModelBase::fromJson(fieldValue, refVal_setHelp);
            setHelp(refVal_setHelp);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("expectedErrors"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("expectedErrors")));
        if(!fieldValue.is_null())
        {
            std::vector<std::shared_ptr<ErrorResultObjects>> refVal_setExpectedErrors;
            ok &= ModelBase::fromJson(fieldValue, refVal_setExpectedErrors);
            setExpectedErrors(refVal_setExpectedErrors);
        }
    }
    return ok;
}

void ToggleLicenseStateErrors::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_MessageIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("message")), m_Message));
    }
    if(m_HelpIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("help")), m_Help));
    }
    if(m_ExpectedErrorsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("expectedErrors")), m_ExpectedErrors));
    }
}

bool ToggleLicenseStateErrors::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("id"))))
    {
        int32_t refVal_setId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("id"))), refVal_setId );
        setId(refVal_setId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("message"))))
    {
        utility::string_t refVal_setMessage;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("message"))), refVal_setMessage );
        setMessage(refVal_setMessage);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("help"))))
    {
        utility::string_t refVal_setHelp;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("help"))), refVal_setHelp );
        setHelp(refVal_setHelp);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("expectedErrors"))))
    {
        std::vector<std::shared_ptr<ErrorResultObjects>> refVal_setExpectedErrors;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("expectedErrors"))), refVal_setExpectedErrors );
        setExpectedErrors(refVal_setExpectedErrors);
    }
    return ok;
}

int32_t ToggleLicenseStateErrors::getId() const
{
    return m_Id;
}

void ToggleLicenseStateErrors::setId(int32_t value)
{
    m_Id = value;
    m_IdIsSet = true;
}

bool ToggleLicenseStateErrors::idIsSet() const
{
    return m_IdIsSet;
}

void ToggleLicenseStateErrors::unsetId()
{
    m_IdIsSet = false;
}
utility::string_t ToggleLicenseStateErrors::getMessage() const
{
    return m_Message;
}

void ToggleLicenseStateErrors::setMessage(const utility::string_t& value)
{
    m_Message = value;
    m_MessageIsSet = true;
}

bool ToggleLicenseStateErrors::messageIsSet() const
{
    return m_MessageIsSet;
}

void ToggleLicenseStateErrors::unsetMessage()
{
    m_MessageIsSet = false;
}
utility::string_t ToggleLicenseStateErrors::getHelp() const
{
    return m_Help;
}

void ToggleLicenseStateErrors::setHelp(const utility::string_t& value)
{
    m_Help = value;
    m_HelpIsSet = true;
}

bool ToggleLicenseStateErrors::helpIsSet() const
{
    return m_HelpIsSet;
}

void ToggleLicenseStateErrors::unsetHelp()
{
    m_HelpIsSet = false;
}
std::vector<std::shared_ptr<ErrorResultObjects>>& ToggleLicenseStateErrors::getExpectedErrors()
{
    return m_ExpectedErrors;
}

void ToggleLicenseStateErrors::setExpectedErrors(const std::vector<std::shared_ptr<ErrorResultObjects>>& value)
{
    m_ExpectedErrors = value;
    m_ExpectedErrorsIsSet = true;
}

bool ToggleLicenseStateErrors::expectedErrorsIsSet() const
{
    return m_ExpectedErrorsIsSet;
}

void ToggleLicenseStateErrors::unsetExpectedErrors()
{
    m_ExpectedErrorsIsSet = false;
}
}
}
}
}


