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



#include "SlasconeOpenApiClient/model/UsageFeatureNameDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



UsageFeatureNameDto::UsageFeatureNameDto()
{
    m_Usage_feature_name = utility::conversions::to_string_t("");
    m_Usage_feature_nameIsSet = false;
    m_Usage_module_name = utility::conversions::to_string_t("");
    m_Usage_module_nameIsSet = false;
    m_Timestamp_utc = utility::datetime();
    m_Timestamp_utcIsSet = false;
    m_Value = 0.0;
    m_ValueIsSet = false;
}

UsageFeatureNameDto::~UsageFeatureNameDto()
{
}

void UsageFeatureNameDto::validate()
{
    // TODO: implement validation
}

web::json::value UsageFeatureNameDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_Usage_feature_nameIsSet)
    {
        val[utility::conversions::to_string_t(U("usage_feature_name"))] = ModelBase::toJson(m_Usage_feature_name);
    }
    if(m_Usage_module_nameIsSet)
    {
        val[utility::conversions::to_string_t(U("usage_module_name"))] = ModelBase::toJson(m_Usage_module_name);
    }
    if(m_Timestamp_utcIsSet)
    {
        val[utility::conversions::to_string_t(U("timestamp_utc"))] = ModelBase::toJson(m_Timestamp_utc);
    }
    if(m_ValueIsSet)
    {
        val[utility::conversions::to_string_t(U("value"))] = ModelBase::toJson(m_Value);
    }

    return val;
}

bool UsageFeatureNameDto::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("usage_feature_name"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("usage_feature_name")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setUsageFeatureName;
            ok &= ModelBase::fromJson(fieldValue, refVal_setUsageFeatureName);
            setUsageFeatureName(refVal_setUsageFeatureName);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("usage_module_name"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("usage_module_name")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setUsageModuleName;
            ok &= ModelBase::fromJson(fieldValue, refVal_setUsageModuleName);
            setUsageModuleName(refVal_setUsageModuleName);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("timestamp_utc"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("timestamp_utc")));
        if(!fieldValue.is_null())
        {
            utility::datetime refVal_setTimestampUtc;
            ok &= ModelBase::fromJson(fieldValue, refVal_setTimestampUtc);
            setTimestampUtc(refVal_setTimestampUtc);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("value"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("value")));
        if(!fieldValue.is_null())
        {
            double refVal_setValue;
            ok &= ModelBase::fromJson(fieldValue, refVal_setValue);
            setValue(refVal_setValue);
        }
    }
    return ok;
}

void UsageFeatureNameDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_Usage_feature_nameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("usage_feature_name")), m_Usage_feature_name));
    }
    if(m_Usage_module_nameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("usage_module_name")), m_Usage_module_name));
    }
    if(m_Timestamp_utcIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("timestamp_utc")), m_Timestamp_utc));
    }
    if(m_ValueIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("value")), m_Value));
    }
}

bool UsageFeatureNameDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("usage_feature_name"))))
    {
        utility::string_t refVal_setUsageFeatureName;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("usage_feature_name"))), refVal_setUsageFeatureName );
        setUsageFeatureName(refVal_setUsageFeatureName);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("usage_module_name"))))
    {
        utility::string_t refVal_setUsageModuleName;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("usage_module_name"))), refVal_setUsageModuleName );
        setUsageModuleName(refVal_setUsageModuleName);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("timestamp_utc"))))
    {
        utility::datetime refVal_setTimestampUtc;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("timestamp_utc"))), refVal_setTimestampUtc );
        setTimestampUtc(refVal_setTimestampUtc);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("value"))))
    {
        double refVal_setValue;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("value"))), refVal_setValue );
        setValue(refVal_setValue);
    }
    return ok;
}

utility::string_t UsageFeatureNameDto::getUsageFeatureName() const
{
    return m_Usage_feature_name;
}

void UsageFeatureNameDto::setUsageFeatureName(const utility::string_t& value)
{
    m_Usage_feature_name = value;
    m_Usage_feature_nameIsSet = true;
}

bool UsageFeatureNameDto::usageFeatureNameIsSet() const
{
    return m_Usage_feature_nameIsSet;
}

void UsageFeatureNameDto::unsetUsage_feature_name()
{
    m_Usage_feature_nameIsSet = false;
}
utility::string_t UsageFeatureNameDto::getUsageModuleName() const
{
    return m_Usage_module_name;
}

void UsageFeatureNameDto::setUsageModuleName(const utility::string_t& value)
{
    m_Usage_module_name = value;
    m_Usage_module_nameIsSet = true;
}

bool UsageFeatureNameDto::usageModuleNameIsSet() const
{
    return m_Usage_module_nameIsSet;
}

void UsageFeatureNameDto::unsetUsage_module_name()
{
    m_Usage_module_nameIsSet = false;
}
utility::datetime UsageFeatureNameDto::getTimestampUtc() const
{
    return m_Timestamp_utc;
}

void UsageFeatureNameDto::setTimestampUtc(const utility::datetime& value)
{
    m_Timestamp_utc = value;
    m_Timestamp_utcIsSet = true;
}

bool UsageFeatureNameDto::timestampUtcIsSet() const
{
    return m_Timestamp_utcIsSet;
}

void UsageFeatureNameDto::unsetTimestamp_utc()
{
    m_Timestamp_utcIsSet = false;
}
double UsageFeatureNameDto::getValue() const
{
    return m_Value;
}

void UsageFeatureNameDto::setValue(double value)
{
    m_Value = value;
    m_ValueIsSet = true;
}

bool UsageFeatureNameDto::valueIsSet() const
{
    return m_ValueIsSet;
}

void UsageFeatureNameDto::unsetValue()
{
    m_ValueIsSet = false;
}
}
}
}
}


