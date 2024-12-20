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



#include "SlasconeOpenApiClient/model/LicenseImportConstrainedVariableDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



LicenseImportConstrainedVariableDto::LicenseImportConstrainedVariableDto()
{
    m_Variable = utility::conversions::to_string_t("");
    m_VariableIsSet = false;
    m_ValuesIsSet = false;
}

LicenseImportConstrainedVariableDto::~LicenseImportConstrainedVariableDto()
{
}

void LicenseImportConstrainedVariableDto::validate()
{
    // TODO: implement validation
}

web::json::value LicenseImportConstrainedVariableDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_VariableIsSet)
    {
        val[utility::conversions::to_string_t(U("variable"))] = ModelBase::toJson(m_Variable);
    }
    if(m_ValuesIsSet)
    {
        val[utility::conversions::to_string_t(U("values"))] = ModelBase::toJson(m_Values);
    }

    return val;
}

bool LicenseImportConstrainedVariableDto::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("variable"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("variable")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setVariable;
            ok &= ModelBase::fromJson(fieldValue, refVal_setVariable);
            setVariable(refVal_setVariable);
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

void LicenseImportConstrainedVariableDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_VariableIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("variable")), m_Variable));
    }
    if(m_ValuesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("values")), m_Values));
    }
}

bool LicenseImportConstrainedVariableDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("variable"))))
    {
        utility::string_t refVal_setVariable;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("variable"))), refVal_setVariable );
        setVariable(refVal_setVariable);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("values"))))
    {
        std::vector<utility::string_t> refVal_setValues;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("values"))), refVal_setValues );
        setValues(refVal_setValues);
    }
    return ok;
}

utility::string_t LicenseImportConstrainedVariableDto::getVariable() const
{
    return m_Variable;
}

void LicenseImportConstrainedVariableDto::setVariable(const utility::string_t& value)
{
    m_Variable = value;
    m_VariableIsSet = true;
}

bool LicenseImportConstrainedVariableDto::variableIsSet() const
{
    return m_VariableIsSet;
}

void LicenseImportConstrainedVariableDto::unsetVariable()
{
    m_VariableIsSet = false;
}
std::vector<utility::string_t>& LicenseImportConstrainedVariableDto::getValues()
{
    return m_Values;
}

void LicenseImportConstrainedVariableDto::setValues(const std::vector<utility::string_t>& value)
{
    m_Values = value;
    m_ValuesIsSet = true;
}

bool LicenseImportConstrainedVariableDto::valuesIsSet() const
{
    return m_ValuesIsSet;
}

void LicenseImportConstrainedVariableDto::unsetValues()
{
    m_ValuesIsSet = false;
}
}
}
}
}


