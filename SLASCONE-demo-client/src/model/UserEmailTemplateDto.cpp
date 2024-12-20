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



#include "SlasconeOpenApiClient/model/UserEmailTemplateDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



UserEmailTemplateDto::UserEmailTemplateDto()
{
    m_Id = utility::conversions::to_string_t("");
    m_IdIsSet = false;
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
    m_Language = utility::conversions::to_string_t("");
    m_LanguageIsSet = false;
    m_Subject = utility::conversions::to_string_t("");
    m_SubjectIsSet = false;
    m_Body = utility::conversions::to_string_t("");
    m_BodyIsSet = false;
    m_Parent_id = utility::conversions::to_string_t("");
    m_Parent_idIsSet = false;
    m_Sub_email_templatesIsSet = false;
    m_Created_date_utc = utility::datetime();
    m_Created_date_utcIsSet = false;
    m_Modified_date_utc = utility::datetime();
    m_Modified_date_utcIsSet = false;
    m_Last_modified_by = utility::conversions::to_string_t("");
    m_Last_modified_byIsSet = false;
    m_Purpose = utility::conversions::to_string_t("");
    m_PurposeIsSet = false;
}

UserEmailTemplateDto::~UserEmailTemplateDto()
{
}

void UserEmailTemplateDto::validate()
{
    // TODO: implement validation
}

web::json::value UserEmailTemplateDto::toJson() const
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
    if(m_LanguageIsSet)
    {
        val[utility::conversions::to_string_t(U("language"))] = ModelBase::toJson(m_Language);
    }
    if(m_SubjectIsSet)
    {
        val[utility::conversions::to_string_t(U("subject"))] = ModelBase::toJson(m_Subject);
    }
    if(m_BodyIsSet)
    {
        val[utility::conversions::to_string_t(U("body"))] = ModelBase::toJson(m_Body);
    }
    if(m_Parent_idIsSet)
    {
        val[utility::conversions::to_string_t(U("parent_id"))] = ModelBase::toJson(m_Parent_id);
    }
    if(m_Sub_email_templatesIsSet)
    {
        val[utility::conversions::to_string_t(U("sub_email_templates"))] = ModelBase::toJson(m_Sub_email_templates);
    }
    if(m_Created_date_utcIsSet)
    {
        val[utility::conversions::to_string_t(U("created_date_utc"))] = ModelBase::toJson(m_Created_date_utc);
    }
    if(m_Modified_date_utcIsSet)
    {
        val[utility::conversions::to_string_t(U("modified_date_utc"))] = ModelBase::toJson(m_Modified_date_utc);
    }
    if(m_Last_modified_byIsSet)
    {
        val[utility::conversions::to_string_t(U("last_modified_by"))] = ModelBase::toJson(m_Last_modified_by);
    }
    if(m_PurposeIsSet)
    {
        val[utility::conversions::to_string_t(U("purpose"))] = ModelBase::toJson(m_Purpose);
    }

    return val;
}

bool UserEmailTemplateDto::fromJson(const web::json::value& val)
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
    if(val.has_field(utility::conversions::to_string_t(U("subject"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("subject")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setSubject;
            ok &= ModelBase::fromJson(fieldValue, refVal_setSubject);
            setSubject(refVal_setSubject);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("body"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("body")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setBody;
            ok &= ModelBase::fromJson(fieldValue, refVal_setBody);
            setBody(refVal_setBody);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("parent_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("parent_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setParentId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setParentId);
            setParentId(refVal_setParentId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("sub_email_templates"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("sub_email_templates")));
        if(!fieldValue.is_null())
        {
            std::vector<std::shared_ptr<UserEmailTemplateDto>> refVal_setSubEmailTemplates;
            ok &= ModelBase::fromJson(fieldValue, refVal_setSubEmailTemplates);
            setSubEmailTemplates(refVal_setSubEmailTemplates);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("created_date_utc"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("created_date_utc")));
        if(!fieldValue.is_null())
        {
            utility::datetime refVal_setCreatedDateUtc;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCreatedDateUtc);
            setCreatedDateUtc(refVal_setCreatedDateUtc);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("modified_date_utc"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("modified_date_utc")));
        if(!fieldValue.is_null())
        {
            utility::datetime refVal_setModifiedDateUtc;
            ok &= ModelBase::fromJson(fieldValue, refVal_setModifiedDateUtc);
            setModifiedDateUtc(refVal_setModifiedDateUtc);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("last_modified_by"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("last_modified_by")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setLastModifiedBy;
            ok &= ModelBase::fromJson(fieldValue, refVal_setLastModifiedBy);
            setLastModifiedBy(refVal_setLastModifiedBy);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("purpose"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("purpose")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setPurpose;
            ok &= ModelBase::fromJson(fieldValue, refVal_setPurpose);
            setPurpose(refVal_setPurpose);
        }
    }
    return ok;
}

void UserEmailTemplateDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_LanguageIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("language")), m_Language));
    }
    if(m_SubjectIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("subject")), m_Subject));
    }
    if(m_BodyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("body")), m_Body));
    }
    if(m_Parent_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("parent_id")), m_Parent_id));
    }
    if(m_Sub_email_templatesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("sub_email_templates")), m_Sub_email_templates));
    }
    if(m_Created_date_utcIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("created_date_utc")), m_Created_date_utc));
    }
    if(m_Modified_date_utcIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("modified_date_utc")), m_Modified_date_utc));
    }
    if(m_Last_modified_byIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("last_modified_by")), m_Last_modified_by));
    }
    if(m_PurposeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("purpose")), m_Purpose));
    }
}

bool UserEmailTemplateDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t(U("language"))))
    {
        utility::string_t refVal_setLanguage;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("language"))), refVal_setLanguage );
        setLanguage(refVal_setLanguage);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("subject"))))
    {
        utility::string_t refVal_setSubject;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("subject"))), refVal_setSubject );
        setSubject(refVal_setSubject);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("body"))))
    {
        utility::string_t refVal_setBody;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("body"))), refVal_setBody );
        setBody(refVal_setBody);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("parent_id"))))
    {
        utility::string_t refVal_setParentId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("parent_id"))), refVal_setParentId );
        setParentId(refVal_setParentId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("sub_email_templates"))))
    {
        std::vector<std::shared_ptr<UserEmailTemplateDto>> refVal_setSubEmailTemplates;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("sub_email_templates"))), refVal_setSubEmailTemplates );
        setSubEmailTemplates(refVal_setSubEmailTemplates);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("created_date_utc"))))
    {
        utility::datetime refVal_setCreatedDateUtc;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("created_date_utc"))), refVal_setCreatedDateUtc );
        setCreatedDateUtc(refVal_setCreatedDateUtc);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("modified_date_utc"))))
    {
        utility::datetime refVal_setModifiedDateUtc;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("modified_date_utc"))), refVal_setModifiedDateUtc );
        setModifiedDateUtc(refVal_setModifiedDateUtc);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("last_modified_by"))))
    {
        utility::string_t refVal_setLastModifiedBy;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("last_modified_by"))), refVal_setLastModifiedBy );
        setLastModifiedBy(refVal_setLastModifiedBy);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("purpose"))))
    {
        utility::string_t refVal_setPurpose;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("purpose"))), refVal_setPurpose );
        setPurpose(refVal_setPurpose);
    }
    return ok;
}

utility::string_t UserEmailTemplateDto::getId() const
{
    return m_Id;
}

void UserEmailTemplateDto::setId(const utility::string_t& value)
{
    m_Id = value;
    m_IdIsSet = true;
}

bool UserEmailTemplateDto::idIsSet() const
{
    return m_IdIsSet;
}

void UserEmailTemplateDto::unsetId()
{
    m_IdIsSet = false;
}
utility::string_t UserEmailTemplateDto::getName() const
{
    return m_Name;
}

void UserEmailTemplateDto::setName(const utility::string_t& value)
{
    m_Name = value;
    m_NameIsSet = true;
}

bool UserEmailTemplateDto::nameIsSet() const
{
    return m_NameIsSet;
}

void UserEmailTemplateDto::unsetName()
{
    m_NameIsSet = false;
}
utility::string_t UserEmailTemplateDto::getLanguage() const
{
    return m_Language;
}

void UserEmailTemplateDto::setLanguage(const utility::string_t& value)
{
    m_Language = value;
    m_LanguageIsSet = true;
}

bool UserEmailTemplateDto::languageIsSet() const
{
    return m_LanguageIsSet;
}

void UserEmailTemplateDto::unsetLanguage()
{
    m_LanguageIsSet = false;
}
utility::string_t UserEmailTemplateDto::getSubject() const
{
    return m_Subject;
}

void UserEmailTemplateDto::setSubject(const utility::string_t& value)
{
    m_Subject = value;
    m_SubjectIsSet = true;
}

bool UserEmailTemplateDto::subjectIsSet() const
{
    return m_SubjectIsSet;
}

void UserEmailTemplateDto::unsetSubject()
{
    m_SubjectIsSet = false;
}
utility::string_t UserEmailTemplateDto::getBody() const
{
    return m_Body;
}

void UserEmailTemplateDto::setBody(const utility::string_t& value)
{
    m_Body = value;
    m_BodyIsSet = true;
}

bool UserEmailTemplateDto::bodyIsSet() const
{
    return m_BodyIsSet;
}

void UserEmailTemplateDto::unsetBody()
{
    m_BodyIsSet = false;
}
utility::string_t UserEmailTemplateDto::getParentId() const
{
    return m_Parent_id;
}

void UserEmailTemplateDto::setParentId(const utility::string_t& value)
{
    m_Parent_id = value;
    m_Parent_idIsSet = true;
}

bool UserEmailTemplateDto::parentIdIsSet() const
{
    return m_Parent_idIsSet;
}

void UserEmailTemplateDto::unsetParent_id()
{
    m_Parent_idIsSet = false;
}
std::vector<std::shared_ptr<UserEmailTemplateDto>>& UserEmailTemplateDto::getSubEmailTemplates()
{
    return m_Sub_email_templates;
}

void UserEmailTemplateDto::setSubEmailTemplates(const std::vector<std::shared_ptr<UserEmailTemplateDto>>& value)
{
    m_Sub_email_templates = value;
    m_Sub_email_templatesIsSet = true;
}

bool UserEmailTemplateDto::subEmailTemplatesIsSet() const
{
    return m_Sub_email_templatesIsSet;
}

void UserEmailTemplateDto::unsetSub_email_templates()
{
    m_Sub_email_templatesIsSet = false;
}
utility::datetime UserEmailTemplateDto::getCreatedDateUtc() const
{
    return m_Created_date_utc;
}

void UserEmailTemplateDto::setCreatedDateUtc(const utility::datetime& value)
{
    m_Created_date_utc = value;
    m_Created_date_utcIsSet = true;
}

bool UserEmailTemplateDto::createdDateUtcIsSet() const
{
    return m_Created_date_utcIsSet;
}

void UserEmailTemplateDto::unsetCreated_date_utc()
{
    m_Created_date_utcIsSet = false;
}
utility::datetime UserEmailTemplateDto::getModifiedDateUtc() const
{
    return m_Modified_date_utc;
}

void UserEmailTemplateDto::setModifiedDateUtc(const utility::datetime& value)
{
    m_Modified_date_utc = value;
    m_Modified_date_utcIsSet = true;
}

bool UserEmailTemplateDto::modifiedDateUtcIsSet() const
{
    return m_Modified_date_utcIsSet;
}

void UserEmailTemplateDto::unsetModified_date_utc()
{
    m_Modified_date_utcIsSet = false;
}
utility::string_t UserEmailTemplateDto::getLastModifiedBy() const
{
    return m_Last_modified_by;
}

void UserEmailTemplateDto::setLastModifiedBy(const utility::string_t& value)
{
    m_Last_modified_by = value;
    m_Last_modified_byIsSet = true;
}

bool UserEmailTemplateDto::lastModifiedByIsSet() const
{
    return m_Last_modified_byIsSet;
}

void UserEmailTemplateDto::unsetLast_modified_by()
{
    m_Last_modified_byIsSet = false;
}
utility::string_t UserEmailTemplateDto::getPurpose() const
{
    return m_Purpose;
}

void UserEmailTemplateDto::setPurpose(const utility::string_t& value)
{
    m_Purpose = value;
    m_PurposeIsSet = true;
}

bool UserEmailTemplateDto::purposeIsSet() const
{
    return m_PurposeIsSet;
}

void UserEmailTemplateDto::unsetPurpose()
{
    m_PurposeIsSet = false;
}
}
}
}
}


