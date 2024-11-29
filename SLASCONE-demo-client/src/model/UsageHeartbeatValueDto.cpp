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



#include "SlasconeOpenApiClient/model/UsageHeartbeatValueDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



UsageHeartbeatValueDto::UsageHeartbeatValueDto()
{
    m_Usage_feature_id = utility::conversions::to_string_t("");
    m_Usage_feature_idIsSet = false;
    m_Usage_module_id = utility::conversions::to_string_t("");
    m_Usage_module_idIsSet = false;
    m_Timestamp_utc = utility::datetime();
    m_Timestamp_utcIsSet = false;
    m_Value = 0.0;
    m_ValueIsSet = false;
}

UsageHeartbeatValueDto::~UsageHeartbeatValueDto()
{
}

void UsageHeartbeatValueDto::validate()
{
    // TODO: implement validation
}

web::json::value UsageHeartbeatValueDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_Usage_feature_idIsSet)
    {
        val[utility::conversions::to_string_t(U("usage_feature_id"))] = ModelBase::toJson(m_Usage_feature_id);
    }
    if(m_Usage_module_idIsSet)
    {
        val[utility::conversions::to_string_t(U("usage_module_id"))] = ModelBase::toJson(m_Usage_module_id);
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

bool UsageHeartbeatValueDto::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("usage_feature_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("usage_feature_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setUsageFeatureId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setUsageFeatureId);
            setUsageFeatureId(refVal_setUsageFeatureId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("usage_module_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("usage_module_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setUsageModuleId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setUsageModuleId);
            setUsageModuleId(refVal_setUsageModuleId);
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

void UsageHeartbeatValueDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_Usage_feature_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("usage_feature_id")), m_Usage_feature_id));
    }
    if(m_Usage_module_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("usage_module_id")), m_Usage_module_id));
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

bool UsageHeartbeatValueDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("usage_feature_id"))))
    {
        utility::string_t refVal_setUsageFeatureId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("usage_feature_id"))), refVal_setUsageFeatureId );
        setUsageFeatureId(refVal_setUsageFeatureId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("usage_module_id"))))
    {
        utility::string_t refVal_setUsageModuleId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("usage_module_id"))), refVal_setUsageModuleId );
        setUsageModuleId(refVal_setUsageModuleId);
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

utility::string_t UsageHeartbeatValueDto::getUsageFeatureId() const
{
    return m_Usage_feature_id;
}

void UsageHeartbeatValueDto::setUsageFeatureId(const utility::string_t& value)
{
    m_Usage_feature_id = value;
    m_Usage_feature_idIsSet = true;
}

bool UsageHeartbeatValueDto::usageFeatureIdIsSet() const
{
    return m_Usage_feature_idIsSet;
}

void UsageHeartbeatValueDto::unsetUsage_feature_id()
{
    m_Usage_feature_idIsSet = false;
}
utility::string_t UsageHeartbeatValueDto::getUsageModuleId() const
{
    return m_Usage_module_id;
}

void UsageHeartbeatValueDto::setUsageModuleId(const utility::string_t& value)
{
    m_Usage_module_id = value;
    m_Usage_module_idIsSet = true;
}

bool UsageHeartbeatValueDto::usageModuleIdIsSet() const
{
    return m_Usage_module_idIsSet;
}

void UsageHeartbeatValueDto::unsetUsage_module_id()
{
    m_Usage_module_idIsSet = false;
}
utility::datetime UsageHeartbeatValueDto::getTimestampUtc() const
{
    return m_Timestamp_utc;
}

void UsageHeartbeatValueDto::setTimestampUtc(const utility::datetime& value)
{
    m_Timestamp_utc = value;
    m_Timestamp_utcIsSet = true;
}

bool UsageHeartbeatValueDto::timestampUtcIsSet() const
{
    return m_Timestamp_utcIsSet;
}

void UsageHeartbeatValueDto::unsetTimestamp_utc()
{
    m_Timestamp_utcIsSet = false;
}
double UsageHeartbeatValueDto::getValue() const
{
    return m_Value;
}

void UsageHeartbeatValueDto::setValue(double value)
{
    m_Value = value;
    m_ValueIsSet = true;
}

bool UsageHeartbeatValueDto::valueIsSet() const
{
    return m_ValueIsSet;
}

void UsageHeartbeatValueDto::unsetValue()
{
    m_ValueIsSet = false;
}
}
}
}
}

