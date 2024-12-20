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



#include "SlasconeOpenApiClient/model/OmittedDataSet.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



OmittedDataSet::OmittedDataSet()
{
    m_RecordLine = 0;
    m_RecordLineIsSet = false;
    m_ErrorsIsSet = false;
}

OmittedDataSet::~OmittedDataSet()
{
}

void OmittedDataSet::validate()
{
    // TODO: implement validation
}

web::json::value OmittedDataSet::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_RecordLineIsSet)
    {
        val[utility::conversions::to_string_t(U("recordLine"))] = ModelBase::toJson(m_RecordLine);
    }
    if(m_ErrorsIsSet)
    {
        val[utility::conversions::to_string_t(U("errors"))] = ModelBase::toJson(m_Errors);
    }

    return val;
}

bool OmittedDataSet::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("recordLine"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("recordLine")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setRecordLine;
            ok &= ModelBase::fromJson(fieldValue, refVal_setRecordLine);
            setRecordLine(refVal_setRecordLine);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("errors"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("errors")));
        if(!fieldValue.is_null())
        {
            std::vector<utility::string_t> refVal_setErrors;
            ok &= ModelBase::fromJson(fieldValue, refVal_setErrors);
            setErrors(refVal_setErrors);
        }
    }
    return ok;
}

void OmittedDataSet::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_RecordLineIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("recordLine")), m_RecordLine));
    }
    if(m_ErrorsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("errors")), m_Errors));
    }
}

bool OmittedDataSet::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("recordLine"))))
    {
        int32_t refVal_setRecordLine;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("recordLine"))), refVal_setRecordLine );
        setRecordLine(refVal_setRecordLine);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("errors"))))
    {
        std::vector<utility::string_t> refVal_setErrors;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("errors"))), refVal_setErrors );
        setErrors(refVal_setErrors);
    }
    return ok;
}

int32_t OmittedDataSet::getRecordLine() const
{
    return m_RecordLine;
}

void OmittedDataSet::setRecordLine(int32_t value)
{
    m_RecordLine = value;
    m_RecordLineIsSet = true;
}

bool OmittedDataSet::recordLineIsSet() const
{
    return m_RecordLineIsSet;
}

void OmittedDataSet::unsetRecordLine()
{
    m_RecordLineIsSet = false;
}
std::vector<utility::string_t>& OmittedDataSet::getErrors()
{
    return m_Errors;
}

void OmittedDataSet::setErrors(const std::vector<utility::string_t>& value)
{
    m_Errors = value;
    m_ErrorsIsSet = true;
}

bool OmittedDataSet::errorsIsSet() const
{
    return m_ErrorsIsSet;
}

void OmittedDataSet::unsetErrors()
{
    m_ErrorsIsSet = false;
}
}
}
}
}


