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
 * AlertDto.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_AlertDto_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_AlertDto_H_


#include "SlasconeOpenApiClient/ModelBase.h"

#include "SlasconeOpenApiClient/model/EmailTemplateDto.h"
#include <cpprest/details/basic_types.h>
#include "SlasconeOpenApiClient/model/TemplateDto.h"
#include "SlasconeOpenApiClient/model/AlertMode.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {

class TemplateDto;
class EmailTemplateDto;


/// <summary>
/// 
/// </summary>
class  AlertDto
    : public ModelBase
{
public:
    AlertDto();
    virtual ~AlertDto();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// AlertDto members

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
    utility::string_t getName() const;
    bool nameIsSet() const;
    void unsetName();

    void setName(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    bool isIsActive() const;
    bool isActiveIsSet() const;
    void unsetIs_active();

    void setIsActive(bool value);

    /// <summary>
    /// 
    /// </summary>
    int32_t getAlertDays() const;
    bool alertDaysIsSet() const;
    void unsetAlert_days();

    void setAlertDays(int32_t value);

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<AlertMode> getMode() const;
    bool modeIsSet() const;
    void unsetMode();

    void setMode(const std::shared_ptr<AlertMode>& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getTemplateId() const;
    bool templateIdIsSet() const;
    void unsetTemplate_id();

    void setTemplateId(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<TemplateDto> getRTemplate() const;
    bool rTemplateIsSet() const;
    void unsetr_template();

    void setRTemplate(const std::shared_ptr<TemplateDto>& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getEmailTemplateId() const;
    bool emailTemplateIdIsSet() const;
    void unsetEmail_template_id();

    void setEmailTemplateId(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<EmailTemplateDto> getEmailTemplate() const;
    bool emailTemplateIsSet() const;
    void unsetEmail_template();

    void setEmailTemplate(const std::shared_ptr<EmailTemplateDto>& value);

    /// <summary>
    /// 
    /// </summary>
    utility::datetime getCreatedDateUtc() const;
    bool createdDateUtcIsSet() const;
    void unsetCreated_date_utc();

    void setCreatedDateUtc(const utility::datetime& value);


protected:
    utility::string_t m_Id;
    bool m_IdIsSet;
    utility::string_t m_Name;
    bool m_NameIsSet;
    bool m_Is_active;
    bool m_Is_activeIsSet;
    int32_t m_Alert_days;
    bool m_Alert_daysIsSet;
    std::shared_ptr<AlertMode> m_Mode;
    bool m_ModeIsSet;
    utility::string_t m_Template_id;
    bool m_Template_idIsSet;
    std::shared_ptr<TemplateDto> m_r_template;
    bool m_r_templateIsSet;
    utility::string_t m_Email_template_id;
    bool m_Email_template_idIsSet;
    std::shared_ptr<EmailTemplateDto> m_Email_template;
    bool m_Email_templateIsSet;
    utility::datetime m_Created_date_utc;
    bool m_Created_date_utcIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_AlertDto_H_ */
