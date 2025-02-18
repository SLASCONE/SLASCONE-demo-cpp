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
 * HistoryDto.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_HistoryDto_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_HistoryDto_H_


#include "SlasconeOpenApiClient/ModelBase.h"

#include "SlasconeOpenApiClient/model/HistoryAction.h"
#include <cpprest/details/basic_types.h>

namespace org {
namespace openapitools {
namespace client {
namespace model {



/// <summary>
/// 
/// </summary>
class  HistoryDto
    : public ModelBase
{
public:
    HistoryDto();
    virtual ~HistoryDto();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// HistoryDto members

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
    utility::string_t getNewValue() const;
    bool newValueIsSet() const;
    void unsetNew_value();

    void setNewValue(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<HistoryAction> getAction() const;
    bool actionIsSet() const;
    void unsetAction();

    void setAction(const std::shared_ptr<HistoryAction>& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getComment() const;
    bool commentIsSet() const;
    void unsetComment();

    void setComment(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getLastModifiedBy() const;
    bool lastModifiedByIsSet() const;
    void unsetLast_modified_by();

    void setLastModifiedBy(const utility::string_t& value);

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
    utility::datetime getCreatedDateUtc() const;
    bool createdDateUtcIsSet() const;
    void unsetCreated_date_utc();

    void setCreatedDateUtc(const utility::datetime& value);


protected:
    utility::string_t m_Id;
    bool m_IdIsSet;
    utility::string_t m_New_value;
    bool m_New_valueIsSet;
    std::shared_ptr<HistoryAction> m_Action;
    bool m_ActionIsSet;
    utility::string_t m_Comment;
    bool m_CommentIsSet;
    utility::string_t m_Last_modified_by;
    bool m_Last_modified_byIsSet;
    utility::datetime m_Modified_date_utc;
    bool m_Modified_date_utcIsSet;
    utility::datetime m_Created_date_utc;
    bool m_Created_date_utcIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_HistoryDto_H_ */
