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
 * AnalyticalFieldFilterDto.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_AnalyticalFieldFilterDto_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_AnalyticalFieldFilterDto_H_


#include "SlasconeOpenApiClient/ModelBase.h"

#include <cpprest/details/basic_types.h>
#include <vector>

namespace org {
namespace openapitools {
namespace client {
namespace model {



/// <summary>
/// 
/// </summary>
class  AnalyticalFieldFilterDto
    : public ModelBase
{
public:
    AnalyticalFieldFilterDto();
    virtual ~AnalyticalFieldFilterDto();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// AnalyticalFieldFilterDto members

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
    std::vector<utility::string_t>& getValues();
    bool valuesIsSet() const;
    void unsetValues();

    void setValues(const std::vector<utility::string_t>& value);


protected:
    utility::string_t m_Id;
    bool m_IdIsSet;
    std::vector<utility::string_t> m_Values;
    bool m_ValuesIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_AnalyticalFieldFilterDto_H_ */
