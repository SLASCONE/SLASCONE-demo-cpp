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



#include "SlasconeOpenApiClient/model/CustomListDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



CustomListDto::CustomListDto()
{
    m_Id = utility::conversions::to_string_t("");
    m_IdIsSet = false;
    m_Custom_list_name = utility::conversions::to_string_t("");
    m_Custom_list_nameIsSet = false;
    m_ElementsIsSet = false;
    m_Created_date_utc = utility::datetime();
    m_Created_date_utcIsSet = false;
    m_Modified_date_utc = utility::datetime();
    m_Modified_date_utcIsSet = false;
    m_Last_modified_by = utility::conversions::to_string_t("");
    m_Last_modified_byIsSet = false;
}

CustomListDto::~CustomListDto()
{
}

void CustomListDto::validate()
{
    // TODO: implement validation
}

web::json::value CustomListDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_IdIsSet)
    {
        val[utility::conversions::to_string_t(U("id"))] = ModelBase::toJson(m_Id);
    }
    if(m_Custom_list_nameIsSet)
    {
        val[utility::conversions::to_string_t(U("custom_list_name"))] = ModelBase::toJson(m_Custom_list_name);
    }
    if(m_ElementsIsSet)
    {
        val[utility::conversions::to_string_t(U("elements"))] = ModelBase::toJson(m_Elements);
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

bool CustomListDto::fromJson(const web::json::value& val)
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
    if(val.has_field(utility::conversions::to_string_t(U("custom_list_name"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("custom_list_name")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setCustomListName;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCustomListName);
            setCustomListName(refVal_setCustomListName);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("elements"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("elements")));
        if(!fieldValue.is_null())
        {
            std::vector<std::shared_ptr<CustomListElementDto>> refVal_setElements;
            ok &= ModelBase::fromJson(fieldValue, refVal_setElements);
            setElements(refVal_setElements);
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

void CustomListDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_Custom_list_nameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("custom_list_name")), m_Custom_list_name));
    }
    if(m_ElementsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("elements")), m_Elements));
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

bool CustomListDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t(U("custom_list_name"))))
    {
        utility::string_t refVal_setCustomListName;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("custom_list_name"))), refVal_setCustomListName );
        setCustomListName(refVal_setCustomListName);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("elements"))))
    {
        std::vector<std::shared_ptr<CustomListElementDto>> refVal_setElements;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("elements"))), refVal_setElements );
        setElements(refVal_setElements);
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

utility::string_t CustomListDto::getId() const
{
    return m_Id;
}

void CustomListDto::setId(const utility::string_t& value)
{
    m_Id = value;
    m_IdIsSet = true;
}

bool CustomListDto::idIsSet() const
{
    return m_IdIsSet;
}

void CustomListDto::unsetId()
{
    m_IdIsSet = false;
}
utility::string_t CustomListDto::getCustomListName() const
{
    return m_Custom_list_name;
}

void CustomListDto::setCustomListName(const utility::string_t& value)
{
    m_Custom_list_name = value;
    m_Custom_list_nameIsSet = true;
}

bool CustomListDto::customListNameIsSet() const
{
    return m_Custom_list_nameIsSet;
}

void CustomListDto::unsetCustom_list_name()
{
    m_Custom_list_nameIsSet = false;
}
std::vector<std::shared_ptr<CustomListElementDto>>& CustomListDto::getElements()
{
    return m_Elements;
}

void CustomListDto::setElements(const std::vector<std::shared_ptr<CustomListElementDto>>& value)
{
    m_Elements = value;
    m_ElementsIsSet = true;
}

bool CustomListDto::elementsIsSet() const
{
    return m_ElementsIsSet;
}

void CustomListDto::unsetElements()
{
    m_ElementsIsSet = false;
}
utility::datetime CustomListDto::getCreatedDateUtc() const
{
    return m_Created_date_utc;
}

void CustomListDto::setCreatedDateUtc(const utility::datetime& value)
{
    m_Created_date_utc = value;
    m_Created_date_utcIsSet = true;
}

bool CustomListDto::createdDateUtcIsSet() const
{
    return m_Created_date_utcIsSet;
}

void CustomListDto::unsetCreated_date_utc()
{
    m_Created_date_utcIsSet = false;
}
utility::datetime CustomListDto::getModifiedDateUtc() const
{
    return m_Modified_date_utc;
}

void CustomListDto::setModifiedDateUtc(const utility::datetime& value)
{
    m_Modified_date_utc = value;
    m_Modified_date_utcIsSet = true;
}

bool CustomListDto::modifiedDateUtcIsSet() const
{
    return m_Modified_date_utcIsSet;
}

void CustomListDto::unsetModified_date_utc()
{
    m_Modified_date_utcIsSet = false;
}
utility::string_t CustomListDto::getLastModifiedBy() const
{
    return m_Last_modified_by;
}

void CustomListDto::setLastModifiedBy(const utility::string_t& value)
{
    m_Last_modified_by = value;
    m_Last_modified_byIsSet = true;
}

bool CustomListDto::lastModifiedByIsSet() const
{
    return m_Last_modified_byIsSet;
}

void CustomListDto::unsetLast_modified_by()
{
    m_Last_modified_byIsSet = false;
}
}
}
}
}

