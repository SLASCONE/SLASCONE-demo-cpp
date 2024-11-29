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

/*
 * UsageHeartbeatValueDto.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_UsageHeartbeatValueDto_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_UsageHeartbeatValueDto_H_


#include "SlasconeOpenApiClient/ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace org {
namespace openapitools {
namespace client {
namespace model {



/// <summary>
/// 
/// </summary>
class  UsageHeartbeatValueDto
    : public ModelBase
{
public:
    UsageHeartbeatValueDto();
    virtual ~UsageHeartbeatValueDto();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// UsageHeartbeatValueDto members

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getUsageFeatureId() const;
    bool usageFeatureIdIsSet() const;
    void unsetUsage_feature_id();

    void setUsageFeatureId(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getUsageModuleId() const;
    bool usageModuleIdIsSet() const;
    void unsetUsage_module_id();

    void setUsageModuleId(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    utility::datetime getTimestampUtc() const;
    bool timestampUtcIsSet() const;
    void unsetTimestamp_utc();

    void setTimestampUtc(const utility::datetime& value);

    /// <summary>
    /// 
    /// </summary>
    double getValue() const;
    bool valueIsSet() const;
    void unsetValue();

    void setValue(double value);


protected:
    utility::string_t m_Usage_feature_id;
    bool m_Usage_feature_idIsSet;
    utility::string_t m_Usage_module_id;
    bool m_Usage_module_idIsSet;
    utility::datetime m_Timestamp_utc;
    bool m_Timestamp_utcIsSet;
    double m_Value;
    bool m_ValueIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_UsageHeartbeatValueDto_H_ */