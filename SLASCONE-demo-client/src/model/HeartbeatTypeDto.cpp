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



#include "SlasconeOpenApiClient/model/HeartbeatTypeDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



HeartbeatTypeDto::HeartbeatTypeDto()
{
    m_Id = utility::conversions::to_string_t("");
    m_IdIsSet = false;
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
    m_Created_date_utc = utility::datetime();
    m_Created_date_utcIsSet = false;
    m_Modified_date_utc = utility::datetime();
    m_Modified_date_utcIsSet = false;
    m_Last_modified_by = utility::conversions::to_string_t("");
    m_Last_modified_byIsSet = false;
}

HeartbeatTypeDto::~HeartbeatTypeDto()
{
}

void HeartbeatTypeDto::validate()
{
    // TODO: implement validation
}

web::json::value HeartbeatTypeDto::toJson() const
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

bool HeartbeatTypeDto::fromJson(const web::json::value& val)
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

void HeartbeatTypeDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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

bool HeartbeatTypeDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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

utility::string_t HeartbeatTypeDto::getId() const
{
    return m_Id;
}

void HeartbeatTypeDto::setId(const utility::string_t& value)
{
    m_Id = value;
    m_IdIsSet = true;
}

bool HeartbeatTypeDto::idIsSet() const
{
    return m_IdIsSet;
}

void HeartbeatTypeDto::unsetId()
{
    m_IdIsSet = false;
}
utility::string_t HeartbeatTypeDto::getName() const
{
    return m_Name;
}

void HeartbeatTypeDto::setName(const utility::string_t& value)
{
    m_Name = value;
    m_NameIsSet = true;
}

bool HeartbeatTypeDto::nameIsSet() const
{
    return m_NameIsSet;
}

void HeartbeatTypeDto::unsetName()
{
    m_NameIsSet = false;
}
utility::datetime HeartbeatTypeDto::getCreatedDateUtc() const
{
    return m_Created_date_utc;
}

void HeartbeatTypeDto::setCreatedDateUtc(const utility::datetime& value)
{
    m_Created_date_utc = value;
    m_Created_date_utcIsSet = true;
}

bool HeartbeatTypeDto::createdDateUtcIsSet() const
{
    return m_Created_date_utcIsSet;
}

void HeartbeatTypeDto::unsetCreated_date_utc()
{
    m_Created_date_utcIsSet = false;
}
utility::datetime HeartbeatTypeDto::getModifiedDateUtc() const
{
    return m_Modified_date_utc;
}

void HeartbeatTypeDto::setModifiedDateUtc(const utility::datetime& value)
{
    m_Modified_date_utc = value;
    m_Modified_date_utcIsSet = true;
}

bool HeartbeatTypeDto::modifiedDateUtcIsSet() const
{
    return m_Modified_date_utcIsSet;
}

void HeartbeatTypeDto::unsetModified_date_utc()
{
    m_Modified_date_utcIsSet = false;
}
utility::string_t HeartbeatTypeDto::getLastModifiedBy() const
{
    return m_Last_modified_by;
}

void HeartbeatTypeDto::setLastModifiedBy(const utility::string_t& value)
{
    m_Last_modified_by = value;
    m_Last_modified_byIsSet = true;
}

bool HeartbeatTypeDto::lastModifiedByIsSet() const
{
    return m_Last_modified_byIsSet;
}

void HeartbeatTypeDto::unsetLast_modified_by()
{
    m_Last_modified_byIsSet = false;
}
}
}
}
}


