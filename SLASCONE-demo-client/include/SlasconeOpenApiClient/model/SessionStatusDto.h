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
 * SessionStatusDto.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_SessionStatusDto_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_SessionStatusDto_H_


#include "SlasconeOpenApiClient/ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace org {
namespace openapitools {
namespace client {
namespace model {



/// <summary>
/// 
/// </summary>
class  SessionStatusDto
    : public ModelBase
{
public:
    SessionStatusDto();
    virtual ~SessionStatusDto();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// SessionStatusDto members

    /// <summary>
    /// 
    /// </summary>
    bool isIsSessionValid() const;
    bool isSessionValidIsSet() const;
    void unsetIs_session_valid();

    void setIsSessionValid(bool value);

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
    utility::datetime getSessionCreatedDate() const;
    bool sessionCreatedDateIsSet() const;
    void unsetSession_created_date();

    void setSessionCreatedDate(const utility::datetime& value);

    /// <summary>
    /// 
    /// </summary>
    utility::datetime getSessionModifiedDate() const;
    bool sessionModifiedDateIsSet() const;
    void unsetSession_modified_date();

    void setSessionModifiedDate(const utility::datetime& value);

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
    bool m_Is_session_valid;
    bool m_Is_session_validIsSet;
    utility::datetime m_Session_valid_until;
    bool m_Session_valid_untilIsSet;
    utility::datetime m_Session_created_date;
    bool m_Session_created_dateIsSet;
    utility::datetime m_Session_modified_date;
    bool m_Session_modified_dateIsSet;
    int32_t m_Max_open_session_count;
    bool m_Max_open_session_countIsSet;
    int32_t m_Max_active_client_count;
    bool m_Max_active_client_countIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_SessionStatusDto_H_ */
