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
 * ValidateAssignmentsDto.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_ValidateAssignmentsDto_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_ValidateAssignmentsDto_H_


#include "SlasconeOpenApiClient/ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace org {
namespace openapitools {
namespace client {
namespace model {



/// <summary>
/// 
/// </summary>
class  ValidateAssignmentsDto
    : public ModelBase
{
public:
    ValidateAssignmentsDto();
    virtual ~ValidateAssignmentsDto();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// ValidateAssignmentsDto members

    /// <summary>
    /// 
    /// </summary>
    int32_t getDays() const;
    bool daysIsSet() const;
    void unsetDays();

    void setDays(int32_t value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getCustomerTypeId() const;
    bool customerTypeIdIsSet() const;
    void unsetCustomerTypeId();

    void setCustomerTypeId(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getLicenseTypeId() const;
    bool licenseTypeIdIsSet() const;
    void unsetLicenseTypeId();

    void setLicenseTypeId(const utility::string_t& value);


protected:
    int32_t m_Days;
    bool m_DaysIsSet;
    utility::string_t m_CustomerTypeId;
    bool m_CustomerTypeIdIsSet;
    utility::string_t m_LicenseTypeId;
    bool m_LicenseTypeIdIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_ValidateAssignmentsDto_H_ */
