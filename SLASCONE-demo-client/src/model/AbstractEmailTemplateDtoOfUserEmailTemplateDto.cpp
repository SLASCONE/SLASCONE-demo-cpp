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



#include "SlasconeOpenApiClient/model/AbstractEmailTemplateDtoOfUserEmailTemplateDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



AbstractEmailTemplateDtoOfUserEmailTemplateDto::AbstractEmailTemplateDtoOfUserEmailTemplateDto()
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
}

AbstractEmailTemplateDtoOfUserEmailTemplateDto::~AbstractEmailTemplateDtoOfUserEmailTemplateDto()
{
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::validate()
{
    // TODO: implement validation
}

web::json::value AbstractEmailTemplateDtoOfUserEmailTemplateDto::toJson() const
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

    return val;
}

bool AbstractEmailTemplateDtoOfUserEmailTemplateDto::fromJson(const web::json::value& val)
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
    return ok;
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
}

bool AbstractEmailTemplateDtoOfUserEmailTemplateDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    return ok;
}

utility::string_t AbstractEmailTemplateDtoOfUserEmailTemplateDto::getId() const
{
    return m_Id;
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::setId(const utility::string_t& value)
{
    m_Id = value;
    m_IdIsSet = true;
}

bool AbstractEmailTemplateDtoOfUserEmailTemplateDto::idIsSet() const
{
    return m_IdIsSet;
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::unsetId()
{
    m_IdIsSet = false;
}
utility::string_t AbstractEmailTemplateDtoOfUserEmailTemplateDto::getName() const
{
    return m_Name;
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::setName(const utility::string_t& value)
{
    m_Name = value;
    m_NameIsSet = true;
}

bool AbstractEmailTemplateDtoOfUserEmailTemplateDto::nameIsSet() const
{
    return m_NameIsSet;
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::unsetName()
{
    m_NameIsSet = false;
}
utility::string_t AbstractEmailTemplateDtoOfUserEmailTemplateDto::getLanguage() const
{
    return m_Language;
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::setLanguage(const utility::string_t& value)
{
    m_Language = value;
    m_LanguageIsSet = true;
}

bool AbstractEmailTemplateDtoOfUserEmailTemplateDto::languageIsSet() const
{
    return m_LanguageIsSet;
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::unsetLanguage()
{
    m_LanguageIsSet = false;
}
utility::string_t AbstractEmailTemplateDtoOfUserEmailTemplateDto::getSubject() const
{
    return m_Subject;
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::setSubject(const utility::string_t& value)
{
    m_Subject = value;
    m_SubjectIsSet = true;
}

bool AbstractEmailTemplateDtoOfUserEmailTemplateDto::subjectIsSet() const
{
    return m_SubjectIsSet;
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::unsetSubject()
{
    m_SubjectIsSet = false;
}
utility::string_t AbstractEmailTemplateDtoOfUserEmailTemplateDto::getBody() const
{
    return m_Body;
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::setBody(const utility::string_t& value)
{
    m_Body = value;
    m_BodyIsSet = true;
}

bool AbstractEmailTemplateDtoOfUserEmailTemplateDto::bodyIsSet() const
{
    return m_BodyIsSet;
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::unsetBody()
{
    m_BodyIsSet = false;
}
utility::string_t AbstractEmailTemplateDtoOfUserEmailTemplateDto::getParentId() const
{
    return m_Parent_id;
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::setParentId(const utility::string_t& value)
{
    m_Parent_id = value;
    m_Parent_idIsSet = true;
}

bool AbstractEmailTemplateDtoOfUserEmailTemplateDto::parentIdIsSet() const
{
    return m_Parent_idIsSet;
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::unsetParent_id()
{
    m_Parent_idIsSet = false;
}
std::vector<std::shared_ptr<UserEmailTemplateDto>>& AbstractEmailTemplateDtoOfUserEmailTemplateDto::getSubEmailTemplates()
{
    return m_Sub_email_templates;
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::setSubEmailTemplates(const std::vector<std::shared_ptr<UserEmailTemplateDto>>& value)
{
    m_Sub_email_templates = value;
    m_Sub_email_templatesIsSet = true;
}

bool AbstractEmailTemplateDtoOfUserEmailTemplateDto::subEmailTemplatesIsSet() const
{
    return m_Sub_email_templatesIsSet;
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::unsetSub_email_templates()
{
    m_Sub_email_templatesIsSet = false;
}
utility::datetime AbstractEmailTemplateDtoOfUserEmailTemplateDto::getCreatedDateUtc() const
{
    return m_Created_date_utc;
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::setCreatedDateUtc(const utility::datetime& value)
{
    m_Created_date_utc = value;
    m_Created_date_utcIsSet = true;
}

bool AbstractEmailTemplateDtoOfUserEmailTemplateDto::createdDateUtcIsSet() const
{
    return m_Created_date_utcIsSet;
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::unsetCreated_date_utc()
{
    m_Created_date_utcIsSet = false;
}
utility::datetime AbstractEmailTemplateDtoOfUserEmailTemplateDto::getModifiedDateUtc() const
{
    return m_Modified_date_utc;
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::setModifiedDateUtc(const utility::datetime& value)
{
    m_Modified_date_utc = value;
    m_Modified_date_utcIsSet = true;
}

bool AbstractEmailTemplateDtoOfUserEmailTemplateDto::modifiedDateUtcIsSet() const
{
    return m_Modified_date_utcIsSet;
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::unsetModified_date_utc()
{
    m_Modified_date_utcIsSet = false;
}
utility::string_t AbstractEmailTemplateDtoOfUserEmailTemplateDto::getLastModifiedBy() const
{
    return m_Last_modified_by;
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::setLastModifiedBy(const utility::string_t& value)
{
    m_Last_modified_by = value;
    m_Last_modified_byIsSet = true;
}

bool AbstractEmailTemplateDtoOfUserEmailTemplateDto::lastModifiedByIsSet() const
{
    return m_Last_modified_byIsSet;
}

void AbstractEmailTemplateDtoOfUserEmailTemplateDto::unsetLast_modified_by()
{
    m_Last_modified_byIsSet = false;
}
}
}
}
}


