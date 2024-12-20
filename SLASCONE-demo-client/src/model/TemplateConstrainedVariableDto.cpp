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



#include "SlasconeOpenApiClient/model/TemplateConstrainedVariableDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



TemplateConstrainedVariableDto::TemplateConstrainedVariableDto()
{
    m_Template_id = utility::conversions::to_string_t("");
    m_Template_idIsSet = false;
    m_Variable_id = utility::conversions::to_string_t("");
    m_Variable_idIsSet = false;
    m_Variable_name = utility::conversions::to_string_t("");
    m_Variable_nameIsSet = false;
    m_Is_adjustable = false;
    m_Is_adjustableIsSet = false;
    m_ValuesIsSet = false;
}

TemplateConstrainedVariableDto::~TemplateConstrainedVariableDto()
{
}

void TemplateConstrainedVariableDto::validate()
{
    // TODO: implement validation
}

web::json::value TemplateConstrainedVariableDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_Template_idIsSet)
    {
        val[utility::conversions::to_string_t(U("template_id"))] = ModelBase::toJson(m_Template_id);
    }
    if(m_Variable_idIsSet)
    {
        val[utility::conversions::to_string_t(U("variable_id"))] = ModelBase::toJson(m_Variable_id);
    }
    if(m_Variable_nameIsSet)
    {
        val[utility::conversions::to_string_t(U("variable_name"))] = ModelBase::toJson(m_Variable_name);
    }
    if(m_Is_adjustableIsSet)
    {
        val[utility::conversions::to_string_t(U("is_adjustable"))] = ModelBase::toJson(m_Is_adjustable);
    }
    if(m_ValuesIsSet)
    {
        val[utility::conversions::to_string_t(U("values"))] = ModelBase::toJson(m_Values);
    }

    return val;
}

bool TemplateConstrainedVariableDto::fromJson(const web::json::value& val)
{
    bool ok = true;
    
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
    if(val.has_field(utility::conversions::to_string_t(U("variable_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("variable_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setVariableId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setVariableId);
            setVariableId(refVal_setVariableId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("variable_name"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("variable_name")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setVariableName;
            ok &= ModelBase::fromJson(fieldValue, refVal_setVariableName);
            setVariableName(refVal_setVariableName);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("is_adjustable"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("is_adjustable")));
        if(!fieldValue.is_null())
        {
            bool refVal_setIsAdjustable;
            ok &= ModelBase::fromJson(fieldValue, refVal_setIsAdjustable);
            setIsAdjustable(refVal_setIsAdjustable);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("values"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("values")));
        if(!fieldValue.is_null())
        {
            std::vector<utility::string_t> refVal_setValues;
            ok &= ModelBase::fromJson(fieldValue, refVal_setValues);
            setValues(refVal_setValues);
        }
    }
    return ok;
}

void TemplateConstrainedVariableDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_Template_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("template_id")), m_Template_id));
    }
    if(m_Variable_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("variable_id")), m_Variable_id));
    }
    if(m_Variable_nameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("variable_name")), m_Variable_name));
    }
    if(m_Is_adjustableIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("is_adjustable")), m_Is_adjustable));
    }
    if(m_ValuesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("values")), m_Values));
    }
}

bool TemplateConstrainedVariableDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("template_id"))))
    {
        utility::string_t refVal_setTemplateId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("template_id"))), refVal_setTemplateId );
        setTemplateId(refVal_setTemplateId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("variable_id"))))
    {
        utility::string_t refVal_setVariableId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("variable_id"))), refVal_setVariableId );
        setVariableId(refVal_setVariableId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("variable_name"))))
    {
        utility::string_t refVal_setVariableName;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("variable_name"))), refVal_setVariableName );
        setVariableName(refVal_setVariableName);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("is_adjustable"))))
    {
        bool refVal_setIsAdjustable;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("is_adjustable"))), refVal_setIsAdjustable );
        setIsAdjustable(refVal_setIsAdjustable);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("values"))))
    {
        std::vector<utility::string_t> refVal_setValues;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("values"))), refVal_setValues );
        setValues(refVal_setValues);
    }
    return ok;
}

utility::string_t TemplateConstrainedVariableDto::getTemplateId() const
{
    return m_Template_id;
}

void TemplateConstrainedVariableDto::setTemplateId(const utility::string_t& value)
{
    m_Template_id = value;
    m_Template_idIsSet = true;
}

bool TemplateConstrainedVariableDto::templateIdIsSet() const
{
    return m_Template_idIsSet;
}

void TemplateConstrainedVariableDto::unsetTemplate_id()
{
    m_Template_idIsSet = false;
}
utility::string_t TemplateConstrainedVariableDto::getVariableId() const
{
    return m_Variable_id;
}

void TemplateConstrainedVariableDto::setVariableId(const utility::string_t& value)
{
    m_Variable_id = value;
    m_Variable_idIsSet = true;
}

bool TemplateConstrainedVariableDto::variableIdIsSet() const
{
    return m_Variable_idIsSet;
}

void TemplateConstrainedVariableDto::unsetVariable_id()
{
    m_Variable_idIsSet = false;
}
utility::string_t TemplateConstrainedVariableDto::getVariableName() const
{
    return m_Variable_name;
}

void TemplateConstrainedVariableDto::setVariableName(const utility::string_t& value)
{
    m_Variable_name = value;
    m_Variable_nameIsSet = true;
}

bool TemplateConstrainedVariableDto::variableNameIsSet() const
{
    return m_Variable_nameIsSet;
}

void TemplateConstrainedVariableDto::unsetVariable_name()
{
    m_Variable_nameIsSet = false;
}
bool TemplateConstrainedVariableDto::isIsAdjustable() const
{
    return m_Is_adjustable;
}

void TemplateConstrainedVariableDto::setIsAdjustable(bool value)
{
    m_Is_adjustable = value;
    m_Is_adjustableIsSet = true;
}

bool TemplateConstrainedVariableDto::isAdjustableIsSet() const
{
    return m_Is_adjustableIsSet;
}

void TemplateConstrainedVariableDto::unsetIs_adjustable()
{
    m_Is_adjustableIsSet = false;
}
std::vector<utility::string_t>& TemplateConstrainedVariableDto::getValues()
{
    return m_Values;
}

void TemplateConstrainedVariableDto::setValues(const std::vector<utility::string_t>& value)
{
    m_Values = value;
    m_ValuesIsSet = true;
}

bool TemplateConstrainedVariableDto::valuesIsSet() const
{
    return m_ValuesIsSet;
}

void TemplateConstrainedVariableDto::unsetValues()
{
    m_ValuesIsSet = false;
}
}
}
}
}


