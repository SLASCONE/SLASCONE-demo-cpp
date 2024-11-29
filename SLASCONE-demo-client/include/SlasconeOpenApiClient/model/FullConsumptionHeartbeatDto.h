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
 * FullConsumptionHeartbeatDto.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_FullConsumptionHeartbeatDto_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_FullConsumptionHeartbeatDto_H_


#include "SlasconeOpenApiClient/ModelBase.h"

#include "SlasconeOpenApiClient/model/ConsumptionHeartbeatValueDto.h"
#include <cpprest/details/basic_types.h>
#include <vector>

namespace org {
namespace openapitools {
namespace client {
namespace model {

class ConsumptionHeartbeatValueDto;


/// <summary>
/// 
/// </summary>
class  FullConsumptionHeartbeatDto
    : public ModelBase
{
public:
    FullConsumptionHeartbeatDto();
    virtual ~FullConsumptionHeartbeatDto();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// FullConsumptionHeartbeatDto members

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getClientId() const;
    bool clientIdIsSet() const;
    void unsetClient_id();

    void setClientId(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    std::vector<std::shared_ptr<ConsumptionHeartbeatValueDto>>& getConsumptionHeartbeat();
    bool consumptionHeartbeatIsSet() const;
    void unsetConsumption_heartbeat();

    void setConsumptionHeartbeat(const std::vector<std::shared_ptr<ConsumptionHeartbeatValueDto>>& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getTokenKey() const;
    bool tokenKeyIsSet() const;
    void unsetToken_key();

    void setTokenKey(const utility::string_t& value);


protected:
    utility::string_t m_Client_id;
    bool m_Client_idIsSet;
    std::vector<std::shared_ptr<ConsumptionHeartbeatValueDto>> m_Consumption_heartbeat;
    bool m_Consumption_heartbeatIsSet;
    utility::string_t m_Token_key;
    bool m_Token_keyIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_FullConsumptionHeartbeatDto_H_ */