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
 * TemplateConstrainedVariableDto.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_TemplateConstrainedVariableDto_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_TemplateConstrainedVariableDto_H_


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
class  TemplateConstrainedVariableDto
    : public ModelBase
{
public:
    TemplateConstrainedVariableDto();
    virtual ~TemplateConstrainedVariableDto();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// TemplateConstrainedVariableDto members

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
    utility::string_t getVariableId() const;
    bool variableIdIsSet() const;
    void unsetVariable_id();

    void setVariableId(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getVariableName() const;
    bool variableNameIsSet() const;
    void unsetVariable_name();

    void setVariableName(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    bool isIsAdjustable() const;
    bool isAdjustableIsSet() const;
    void unsetIs_adjustable();

    void setIsAdjustable(bool value);

    /// <summary>
    /// 
    /// </summary>
    std::vector<utility::string_t>& getValues();
    bool valuesIsSet() const;
    void unsetValues();

    void setValues(const std::vector<utility::string_t>& value);


protected:
    utility::string_t m_Template_id;
    bool m_Template_idIsSet;
    utility::string_t m_Variable_id;
    bool m_Variable_idIsSet;
    utility::string_t m_Variable_name;
    bool m_Variable_nameIsSet;
    bool m_Is_adjustable;
    bool m_Is_adjustableIsSet;
    std::vector<utility::string_t> m_Values;
    bool m_ValuesIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_TemplateConstrainedVariableDto_H_ */
