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
 * DataExchangeAddLicenseResponseErrors.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_DataExchangeAddLicenseResponseErrors_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_DataExchangeAddLicenseResponseErrors_H_


#include "SlasconeOpenApiClient/ModelBase.h"

#include "SlasconeOpenApiClient/model/ErrorResultObjects.h"
#include <cpprest/details/basic_types.h>
#include <vector>

namespace org {
namespace openapitools {
namespace client {
namespace model {

class ErrorResultObjects;


/// <summary>
/// 
/// </summary>
class  DataExchangeAddLicenseResponseErrors
    : public ModelBase
{
public:
    DataExchangeAddLicenseResponseErrors();
    virtual ~DataExchangeAddLicenseResponseErrors();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// DataExchangeAddLicenseResponseErrors members

    /// <summary>
    /// 
    /// </summary>
    int32_t getId() const;
    bool idIsSet() const;
    void unsetId();

    void setId(int32_t value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getMessage() const;
    bool messageIsSet() const;
    void unsetMessage();

    void setMessage(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getHelp() const;
    bool helpIsSet() const;
    void unsetHelp();

    void setHelp(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    std::vector<std::shared_ptr<ErrorResultObjects>>& getExpectedErrors();
    bool expectedErrorsIsSet() const;
    void unsetExpectedErrors();

    void setExpectedErrors(const std::vector<std::shared_ptr<ErrorResultObjects>>& value);


protected:
    int32_t m_Id;
    bool m_IdIsSet;
    utility::string_t m_Message;
    bool m_MessageIsSet;
    utility::string_t m_Help;
    bool m_HelpIsSet;
    std::vector<std::shared_ptr<ErrorResultObjects>> m_ExpectedErrors;
    bool m_ExpectedErrorsIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_DataExchangeAddLicenseResponseErrors_H_ */
