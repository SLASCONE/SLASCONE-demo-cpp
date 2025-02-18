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
 * ConsumptionHeartbeatLazyLoadDto.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_ConsumptionHeartbeatLazyLoadDto_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_ConsumptionHeartbeatLazyLoadDto_H_


#include "SlasconeOpenApiClient/ModelBase.h"

#include <vector>
#include "SlasconeOpenApiClient/model/ConsumptionHeartbeatDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {

class ConsumptionHeartbeatDto;


/// <summary>
/// 
/// </summary>
class  ConsumptionHeartbeatLazyLoadDto
    : public ModelBase
{
public:
    ConsumptionHeartbeatLazyLoadDto();
    virtual ~ConsumptionHeartbeatLazyLoadDto();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// ConsumptionHeartbeatLazyLoadDto members

    /// <summary>
    /// 
    /// </summary>
    std::vector<std::shared_ptr<ConsumptionHeartbeatDto>>& getConsumptionHeartbeats();
    bool consumptionHeartbeatsIsSet() const;
    void unsetConsumption_heartbeats();

    void setConsumptionHeartbeats(const std::vector<std::shared_ptr<ConsumptionHeartbeatDto>>& value);

    /// <summary>
    /// 
    /// </summary>
    int32_t getMaxCount() const;
    bool maxCountIsSet() const;
    void unsetMax_count();

    void setMaxCount(int32_t value);

    /// <summary>
    /// 
    /// </summary>
    double getAggregateValue() const;
    bool aggregateValueIsSet() const;
    void unsetAggregate_value();

    void setAggregateValue(double value);


protected:
    std::vector<std::shared_ptr<ConsumptionHeartbeatDto>> m_Consumption_heartbeats;
    bool m_Consumption_heartbeatsIsSet;
    int32_t m_Max_count;
    bool m_Max_countIsSet;
    double m_Aggregate_value;
    bool m_Aggregate_valueIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_ConsumptionHeartbeatLazyLoadDto_H_ */
