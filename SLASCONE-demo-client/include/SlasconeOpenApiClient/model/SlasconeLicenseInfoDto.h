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
 * SlasconeLicenseInfoDto.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_SlasconeLicenseInfoDto_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_SlasconeLicenseInfoDto_H_


#include "SlasconeOpenApiClient/ModelBase.h"

#include "SlasconeOpenApiClient/model/LicenseInfoDto.h"
#include "SlasconeOpenApiClient/model/SlasconeLicensingState.h"
#include <cpprest/details/basic_types.h>

namespace org {
namespace openapitools {
namespace client {
namespace model {

class LicenseInfoDto;


/// <summary>
/// 
/// </summary>
class  SlasconeLicenseInfoDto
    : public ModelBase
{
public:
    SlasconeLicenseInfoDto();
    virtual ~SlasconeLicenseInfoDto();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// SlasconeLicenseInfoDto members

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<SlasconeLicensingState> getSlasconeLicensingState() const;
    bool slasconeLicensingStateIsSet() const;
    void unsetSlascone_licensing_state();

    void setSlasconeLicensingState(const std::shared_ptr<SlasconeLicensingState>& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getErrorMessage() const;
    bool errorMessageIsSet() const;
    void unsetError_message();

    void setErrorMessage(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<LicenseInfoDto> getSlasconeLicenseInfo() const;
    bool slasconeLicenseInfoIsSet() const;
    void unsetSlascone_license_info();

    void setSlasconeLicenseInfo(const std::shared_ptr<LicenseInfoDto>& value);


protected:
    std::shared_ptr<SlasconeLicensingState> m_Slascone_licensing_state;
    bool m_Slascone_licensing_stateIsSet;
    utility::string_t m_Error_message;
    bool m_Error_messageIsSet;
    std::shared_ptr<LicenseInfoDto> m_Slascone_license_info;
    bool m_Slascone_license_infoIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_SlasconeLicenseInfoDto_H_ */
