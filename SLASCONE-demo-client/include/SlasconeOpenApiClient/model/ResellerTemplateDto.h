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
 * ResellerTemplateDto.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_ResellerTemplateDto_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_ResellerTemplateDto_H_


#include "SlasconeOpenApiClient/ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace org {
namespace openapitools {
namespace client {
namespace model {



/// <summary>
/// 
/// </summary>
class  ResellerTemplateDto
    : public ModelBase
{
public:
    ResellerTemplateDto();
    virtual ~ResellerTemplateDto();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// ResellerTemplateDto members

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getResellerId() const;
    bool resellerIdIsSet() const;
    void unsetReseller_id();

    void setResellerId(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getTemplateId() const;
    bool templateIdIsSet() const;
    void unsetTemplate_id();

    void setTemplateId(const utility::string_t& value);


protected:
    utility::string_t m_Reseller_id;
    bool m_Reseller_idIsSet;
    utility::string_t m_Template_id;
    bool m_Template_idIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_ResellerTemplateDto_H_ */
