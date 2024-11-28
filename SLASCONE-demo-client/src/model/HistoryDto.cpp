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



#include "SlasconeOpenApiClient/model/HistoryDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



HistoryDto::HistoryDto()
{
    m_Id = utility::conversions::to_string_t("");
    m_IdIsSet = false;
    m_New_value = utility::conversions::to_string_t("");
    m_New_valueIsSet = false;
    m_Last_modified_by = utility::conversions::to_string_t("");
    m_Last_modified_byIsSet = false;
    m_Modified_date_utc = utility::datetime();
    m_Modified_date_utcIsSet = false;
    m_Created_date_utc = utility::datetime();
    m_Created_date_utcIsSet = false;
}

HistoryDto::~HistoryDto()
{
}

void HistoryDto::validate()
{
    // TODO: implement validation
}

web::json::value HistoryDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_IdIsSet)
    {
        val[utility::conversions::to_string_t(U("id"))] = ModelBase::toJson(m_Id);
    }
    if(m_New_valueIsSet)
    {
        val[utility::conversions::to_string_t(U("new_value"))] = ModelBase::toJson(m_New_value);
    }
    if(m_Last_modified_byIsSet)
    {
        val[utility::conversions::to_string_t(U("last_modified_by"))] = ModelBase::toJson(m_Last_modified_by);
    }
    if(m_Modified_date_utcIsSet)
    {
        val[utility::conversions::to_string_t(U("modified_date_utc"))] = ModelBase::toJson(m_Modified_date_utc);
    }
    if(m_Created_date_utcIsSet)
    {
        val[utility::conversions::to_string_t(U("created_date_utc"))] = ModelBase::toJson(m_Created_date_utc);
    }

    return val;
}

bool HistoryDto::fromJson(const web::json::value& val)
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
    if(val.has_field(utility::conversions::to_string_t(U("new_value"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("new_value")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setNewValue;
            ok &= ModelBase::fromJson(fieldValue, refVal_setNewValue);
            setNewValue(refVal_setNewValue);
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
    return ok;
}

void HistoryDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_New_valueIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("new_value")), m_New_value));
    }
    if(m_Last_modified_byIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("last_modified_by")), m_Last_modified_by));
    }
    if(m_Modified_date_utcIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("modified_date_utc")), m_Modified_date_utc));
    }
    if(m_Created_date_utcIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("created_date_utc")), m_Created_date_utc));
    }
}

bool HistoryDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t(U("new_value"))))
    {
        utility::string_t refVal_setNewValue;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("new_value"))), refVal_setNewValue );
        setNewValue(refVal_setNewValue);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("last_modified_by"))))
    {
        utility::string_t refVal_setLastModifiedBy;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("last_modified_by"))), refVal_setLastModifiedBy );
        setLastModifiedBy(refVal_setLastModifiedBy);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("modified_date_utc"))))
    {
        utility::datetime refVal_setModifiedDateUtc;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("modified_date_utc"))), refVal_setModifiedDateUtc );
        setModifiedDateUtc(refVal_setModifiedDateUtc);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("created_date_utc"))))
    {
        utility::datetime refVal_setCreatedDateUtc;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("created_date_utc"))), refVal_setCreatedDateUtc );
        setCreatedDateUtc(refVal_setCreatedDateUtc);
    }
    return ok;
}

utility::string_t HistoryDto::getId() const
{
    return m_Id;
}

void HistoryDto::setId(const utility::string_t& value)
{
    m_Id = value;
    m_IdIsSet = true;
}

bool HistoryDto::idIsSet() const
{
    return m_IdIsSet;
}

void HistoryDto::unsetId()
{
    m_IdIsSet = false;
}
utility::string_t HistoryDto::getNewValue() const
{
    return m_New_value;
}

void HistoryDto::setNewValue(const utility::string_t& value)
{
    m_New_value = value;
    m_New_valueIsSet = true;
}

bool HistoryDto::newValueIsSet() const
{
    return m_New_valueIsSet;
}

void HistoryDto::unsetNew_value()
{
    m_New_valueIsSet = false;
}
utility::string_t HistoryDto::getLastModifiedBy() const
{
    return m_Last_modified_by;
}

void HistoryDto::setLastModifiedBy(const utility::string_t& value)
{
    m_Last_modified_by = value;
    m_Last_modified_byIsSet = true;
}

bool HistoryDto::lastModifiedByIsSet() const
{
    return m_Last_modified_byIsSet;
}

void HistoryDto::unsetLast_modified_by()
{
    m_Last_modified_byIsSet = false;
}
utility::datetime HistoryDto::getModifiedDateUtc() const
{
    return m_Modified_date_utc;
}

void HistoryDto::setModifiedDateUtc(const utility::datetime& value)
{
    m_Modified_date_utc = value;
    m_Modified_date_utcIsSet = true;
}

bool HistoryDto::modifiedDateUtcIsSet() const
{
    return m_Modified_date_utcIsSet;
}

void HistoryDto::unsetModified_date_utc()
{
    m_Modified_date_utcIsSet = false;
}
utility::datetime HistoryDto::getCreatedDateUtc() const
{
    return m_Created_date_utc;
}

void HistoryDto::setCreatedDateUtc(const utility::datetime& value)
{
    m_Created_date_utc = value;
    m_Created_date_utcIsSet = true;
}

bool HistoryDto::createdDateUtcIsSet() const
{
    return m_Created_date_utcIsSet;
}

void HistoryDto::unsetCreated_date_utc()
{
    m_Created_date_utcIsSet = false;
}
}
}
}
}


