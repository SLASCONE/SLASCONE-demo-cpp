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
 * LookupDto.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_LookupDto_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_LookupDto_H_


#include "SlasconeOpenApiClient/ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace org {
namespace openapitools {
namespace client {
namespace model {



/// <summary>
/// 
/// </summary>
class  LookupDto
    : public ModelBase
{
public:
    LookupDto();
    virtual ~LookupDto();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// LookupDto members

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getProductId() const;
    bool productIdIsSet() const;
    void unsetProduct_id();

    void setProductId(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getCustomerNumber() const;
    bool customerNumberIsSet() const;
    void unsetCustomer_number();

    void setCustomerNumber(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getClientId() const;
    bool clientIdIsSet() const;
    void unsetClient_id();

    void setClientId(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getLegacyKey() const;
    bool legacyKeyIsSet() const;
    void unsetLegacy_key();

    void setLegacyKey(const utility::string_t& value);


protected:
    utility::string_t m_Product_id;
    bool m_Product_idIsSet;
    utility::string_t m_Customer_number;
    bool m_Customer_numberIsSet;
    utility::string_t m_Client_id;
    bool m_Client_idIsSet;
    utility::string_t m_Legacy_key;
    bool m_Legacy_keyIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_LookupDto_H_ */