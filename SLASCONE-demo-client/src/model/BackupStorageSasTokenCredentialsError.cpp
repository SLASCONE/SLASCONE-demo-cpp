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



#include "SlasconeOpenApiClient/model/BackupStorageSasTokenCredentialsError.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



BackupStorageSasTokenCredentialsError::BackupStorageSasTokenCredentialsError()
{
    m_Id = 0;
    m_IdIsSet = false;
    m_Message = utility::conversions::to_string_t("");
    m_MessageIsSet = false;
    m_Help = utility::conversions::to_string_t("");
    m_HelpIsSet = false;
}

BackupStorageSasTokenCredentialsError::~BackupStorageSasTokenCredentialsError()
{
}

void BackupStorageSasTokenCredentialsError::validate()
{
    // TODO: implement validation
}

web::json::value BackupStorageSasTokenCredentialsError::toJson() const
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

    return val;
}

bool BackupStorageSasTokenCredentialsError::fromJson(const web::json::value& val)
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
    return ok;
}

void BackupStorageSasTokenCredentialsError::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
}

bool BackupStorageSasTokenCredentialsError::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    return ok;
}

int32_t BackupStorageSasTokenCredentialsError::getId() const
{
    return m_Id;
}

void BackupStorageSasTokenCredentialsError::setId(int32_t value)
{
    m_Id = value;
    m_IdIsSet = true;
}

bool BackupStorageSasTokenCredentialsError::idIsSet() const
{
    return m_IdIsSet;
}

void BackupStorageSasTokenCredentialsError::unsetId()
{
    m_IdIsSet = false;
}
utility::string_t BackupStorageSasTokenCredentialsError::getMessage() const
{
    return m_Message;
}

void BackupStorageSasTokenCredentialsError::setMessage(const utility::string_t& value)
{
    m_Message = value;
    m_MessageIsSet = true;
}

bool BackupStorageSasTokenCredentialsError::messageIsSet() const
{
    return m_MessageIsSet;
}

void BackupStorageSasTokenCredentialsError::unsetMessage()
{
    m_MessageIsSet = false;
}
utility::string_t BackupStorageSasTokenCredentialsError::getHelp() const
{
    return m_Help;
}

void BackupStorageSasTokenCredentialsError::setHelp(const utility::string_t& value)
{
    m_Help = value;
    m_HelpIsSet = true;
}

bool BackupStorageSasTokenCredentialsError::helpIsSet() const
{
    return m_HelpIsSet;
}

void BackupStorageSasTokenCredentialsError::unsetHelp()
{
    m_HelpIsSet = false;
}
}
}
}
}


