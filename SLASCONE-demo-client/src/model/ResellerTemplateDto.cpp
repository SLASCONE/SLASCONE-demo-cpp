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



#include "SlasconeOpenApiClient/model/ResellerTemplateDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



ResellerTemplateDto::ResellerTemplateDto()
{
    m_Reseller_id = utility::conversions::to_string_t("");
    m_Reseller_idIsSet = false;
    m_Template_id = utility::conversions::to_string_t("");
    m_Template_idIsSet = false;
}

ResellerTemplateDto::~ResellerTemplateDto()
{
}

void ResellerTemplateDto::validate()
{
    // TODO: implement validation
}

web::json::value ResellerTemplateDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_Reseller_idIsSet)
    {
        val[utility::conversions::to_string_t(U("reseller_id"))] = ModelBase::toJson(m_Reseller_id);
    }
    if(m_Template_idIsSet)
    {
        val[utility::conversions::to_string_t(U("template_id"))] = ModelBase::toJson(m_Template_id);
    }

    return val;
}

bool ResellerTemplateDto::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("reseller_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("reseller_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setResellerId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setResellerId);
            setResellerId(refVal_setResellerId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("template_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("template_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setTemplateId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setTemplateId);
            setTemplateId(refVal_setTemplateId);
        }
    }
    return ok;
}

void ResellerTemplateDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_Reseller_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("reseller_id")), m_Reseller_id));
    }
    if(m_Template_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("template_id")), m_Template_id));
    }
}

bool ResellerTemplateDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("reseller_id"))))
    {
        utility::string_t refVal_setResellerId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("reseller_id"))), refVal_setResellerId );
        setResellerId(refVal_setResellerId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("template_id"))))
    {
        utility::string_t refVal_setTemplateId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("template_id"))), refVal_setTemplateId );
        setTemplateId(refVal_setTemplateId);
    }
    return ok;
}

utility::string_t ResellerTemplateDto::getResellerId() const
{
    return m_Reseller_id;
}

void ResellerTemplateDto::setResellerId(const utility::string_t& value)
{
    m_Reseller_id = value;
    m_Reseller_idIsSet = true;
}

bool ResellerTemplateDto::resellerIdIsSet() const
{
    return m_Reseller_idIsSet;
}

void ResellerTemplateDto::unsetReseller_id()
{
    m_Reseller_idIsSet = false;
}
utility::string_t ResellerTemplateDto::getTemplateId() const
{
    return m_Template_id;
}

void ResellerTemplateDto::setTemplateId(const utility::string_t& value)
{
    m_Template_id = value;
    m_Template_idIsSet = true;
}

bool ResellerTemplateDto::templateIdIsSet() const
{
    return m_Template_idIsSet;
}

void ResellerTemplateDto::unsetTemplate_id()
{
    m_Template_idIsSet = false;
}
}
}
}
}


