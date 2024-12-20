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
 * DeviceAnalyticalHeartbeatDto.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_DeviceAnalyticalHeartbeatDto_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_DeviceAnalyticalHeartbeatDto_H_


#include "SlasconeOpenApiClient/ModelBase.h"

#include "SlasconeOpenApiClient/model/AnalyticalFieldDto.h"
#include <cpprest/details/basic_types.h>

namespace org {
namespace openapitools {
namespace client {
namespace model {

class AnalyticalFieldDto;


/// <summary>
/// 
/// </summary>
class  DeviceAnalyticalHeartbeatDto
    : public ModelBase
{
public:
    DeviceAnalyticalHeartbeatDto();
    virtual ~DeviceAnalyticalHeartbeatDto();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// DeviceAnalyticalHeartbeatDto members

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getLicenseAssignmentId() const;
    bool licenseAssignmentIdIsSet() const;
    void unsetLicense_assignment_id();

    void setLicenseAssignmentId(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getAnalyticalFieldId() const;
    bool analyticalFieldIdIsSet() const;
    void unsetAnalytical_field_id();

    void setAnalyticalFieldId(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getValue() const;
    bool valueIsSet() const;
    void unsetValue();

    void setValue(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getTransactionId() const;
    bool transactionIdIsSet() const;
    void unsetTransaction_id();

    void setTransactionId(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getSoftwareVersion() const;
    bool softwareVersionIsSet() const;
    void unsetSoftware_version();

    void setSoftwareVersion(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    utility::datetime getCreatedDateUtc() const;
    bool createdDateUtcIsSet() const;
    void unsetCreated_date_utc();

    void setCreatedDateUtc(const utility::datetime& value);

    /// <summary>
    /// 
    /// </summary>
    utility::datetime getModifiedDateUtc() const;
    bool modifiedDateUtcIsSet() const;
    void unsetModified_date_utc();

    void setModifiedDateUtc(const utility::datetime& value);

    /// <summary>
    /// 
    /// </summary>
    bool isIsLast() const;
    bool isLastIsSet() const;
    void unsetIs_last();

    void setIsLast(bool value);

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<AnalyticalFieldDto> getAnalyticalField() const;
    bool analyticalFieldIsSet() const;
    void unsetAnalytical_field();

    void setAnalyticalField(const std::shared_ptr<AnalyticalFieldDto>& value);


protected:
    utility::string_t m_License_assignment_id;
    bool m_License_assignment_idIsSet;
    utility::string_t m_Analytical_field_id;
    bool m_Analytical_field_idIsSet;
    utility::string_t m_Value;
    bool m_ValueIsSet;
    utility::string_t m_Transaction_id;
    bool m_Transaction_idIsSet;
    utility::string_t m_Software_version;
    bool m_Software_versionIsSet;
    utility::datetime m_Created_date_utc;
    bool m_Created_date_utcIsSet;
    utility::datetime m_Modified_date_utc;
    bool m_Modified_date_utcIsSet;
    bool m_Is_last;
    bool m_Is_lastIsSet;
    std::shared_ptr<AnalyticalFieldDto> m_Analytical_field;
    bool m_Analytical_fieldIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_DeviceAnalyticalHeartbeatDto_H_ */
