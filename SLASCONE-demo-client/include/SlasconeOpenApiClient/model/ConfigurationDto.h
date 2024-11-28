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
 * ConfigurationDto.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_ConfigurationDto_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_ConfigurationDto_H_


#include "SlasconeOpenApiClient/ModelBase.h"


namespace org {
namespace openapitools {
namespace client {
namespace model {



/// <summary>
/// 
/// </summary>
class  ConfigurationDto
    : public ModelBase
{
public:
    ConfigurationDto();
    virtual ~ConfigurationDto();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// ConfigurationDto members

    /// <summary>
    /// 
    /// </summary>
    bool isOnDeleteRemoveIdentity() const;
    bool onDeleteRemoveIdentityIsSet() const;
    void unsetOn_delete_remove_identity();

    void setOnDeleteRemoveIdentity(bool value);


protected:
    bool m_On_delete_remove_identity;
    bool m_On_delete_remove_identityIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_ConfigurationDto_H_ */
