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
 * LicenseUserGroupDto.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_LicenseUserGroupDto_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_LicenseUserGroupDto_H_


#include "SlasconeOpenApiClient/ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace org {
namespace openapitools {
namespace client {
namespace model {



/// <summary>
/// 
/// </summary>
class  LicenseUserGroupDto
    : public ModelBase
{
public:
    LicenseUserGroupDto();
    virtual ~LicenseUserGroupDto();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// LicenseUserGroupDto members

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
    int32_t getUserLimit() const;
    bool userLimitIsSet() const;
    void unsetUser_limit();

    void setUserLimit(int32_t value);

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
    utility::string_t getLastModifiedBy() const;
    bool lastModifiedByIsSet() const;
    void unsetLast_modified_by();

    void setLastModifiedBy(const utility::string_t& value);


protected:
    utility::string_t m_Id;
    bool m_IdIsSet;
    utility::string_t m_Name;
    bool m_NameIsSet;
    int32_t m_User_limit;
    bool m_User_limitIsSet;
    utility::datetime m_Created_date_utc;
    bool m_Created_date_utcIsSet;
    utility::datetime m_Modified_date_utc;
    bool m_Modified_date_utcIsSet;
    utility::string_t m_Last_modified_by;
    bool m_Last_modified_byIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_LicenseUserGroupDto_H_ */
