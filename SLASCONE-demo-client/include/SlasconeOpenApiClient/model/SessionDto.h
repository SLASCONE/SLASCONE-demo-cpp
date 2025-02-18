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
 * SessionDto.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_SessionDto_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_SessionDto_H_


#include "SlasconeOpenApiClient/ModelBase.h"

#include "SlasconeOpenApiClient/model/DeviceLicenseAssignmentDto.h"
#include <cpprest/details/basic_types.h>

namespace org {
namespace openapitools {
namespace client {
namespace model {

class DeviceLicenseAssignmentDto;


/// <summary>
/// 
/// </summary>
class  SessionDto
    : public ModelBase
{
public:
    SessionDto();
    virtual ~SessionDto();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// SessionDto members

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getId() const;
    bool idIsSet() const;
    void unsetId();

    void setId(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getSessionId() const;
    bool sessionIdIsSet() const;
    void unsetSession_id();

    void setSessionId(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    utility::datetime getSessionValidUntil() const;
    bool sessionValidUntilIsSet() const;
    void unsetSession_valid_until();

    void setSessionValidUntil(const utility::datetime& value);

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
    utility::string_t getLicenseId() const;
    bool licenseIdIsSet() const;
    void unsetLicense_id();

    void setLicenseId(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getAssignmentId() const;
    bool assignmentIdIsSet() const;
    void unsetAssignment_id();

    void setAssignmentId(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<DeviceLicenseAssignmentDto> getAssignment() const;
    bool assignmentIsSet() const;
    void unsetAssignment();

    void setAssignment(const std::shared_ptr<DeviceLicenseAssignmentDto>& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getUserId() const;
    bool userIdIsSet() const;
    void unsetUser_id();

    void setUserId(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    int32_t getMaxOpenSessionCount() const;
    bool maxOpenSessionCountIsSet() const;
    void unsetMax_open_session_count();

    void setMaxOpenSessionCount(int32_t value);

    /// <summary>
    /// 
    /// </summary>
    int32_t getMaxActiveClientCount() const;
    bool maxActiveClientCountIsSet() const;
    void unsetMax_active_client_count();

    void setMaxActiveClientCount(int32_t value);


protected:
    utility::string_t m_Id;
    bool m_IdIsSet;
    utility::string_t m_Session_id;
    bool m_Session_idIsSet;
    utility::datetime m_Session_valid_until;
    bool m_Session_valid_untilIsSet;
    utility::datetime m_Created_date_utc;
    bool m_Created_date_utcIsSet;
    utility::datetime m_Modified_date_utc;
    bool m_Modified_date_utcIsSet;
    utility::string_t m_License_id;
    bool m_License_idIsSet;
    utility::string_t m_Assignment_id;
    bool m_Assignment_idIsSet;
    std::shared_ptr<DeviceLicenseAssignmentDto> m_Assignment;
    bool m_AssignmentIsSet;
    utility::string_t m_User_id;
    bool m_User_idIsSet;
    int32_t m_Max_open_session_count;
    bool m_Max_open_session_countIsSet;
    int32_t m_Max_active_client_count;
    bool m_Max_active_client_countIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_SessionDto_H_ */
