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
 * ResellerApi.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_API_ResellerApi_H_
#define ORG_OPENAPITOOLS_CLIENT_API_ResellerApi_H_



#include "SlasconeOpenApiClient/ApiClient.h"

#include "SlasconeOpenApiClient/AnyType.h"
#include "SlasconeOpenApiClient/model/ProblemDetails.h"
#include "SlasconeOpenApiClient/model/ResellerContactDto.h"
#include "SlasconeOpenApiClient/model/ResellerDto.h"
#include "SlasconeOpenApiClient/model/ResellerFilterDto.h"
#include "SlasconeOpenApiClient/model/ResellerLazyLoadDto.h"
#include "SlasconeOpenApiClient/model/ResellerLightDto.h"
#include "SlasconeOpenApiClient/model/ResellerTemplateDto.h"
#include "SlasconeOpenApiClient/model/ResellerTypeDto.h"
#include <vector>
#include <cpprest/details/basic_types.h>
#include <boost/optional.hpp>

namespace org {
namespace openapitools {
namespace client {
namespace api {

using namespace org::openapitools::client::model;



class  ResellerApi 
{
public:

    explicit ResellerApi( std::shared_ptr<const ApiClient> apiClient );

    virtual ~ResellerApi();

    /// <summary>
    /// Creates a reseller
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="resellerDto"></param>
    pplx::task<std::shared_ptr<ResellerDto>> addReseller(
        utility::string_t isvId,
        std::shared_ptr<ResellerDto> resellerDto
    ) const;
    /// <summary>
    /// Creates a reseller contact
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="resellerId"></param>
    /// <param name="resellerContactDto"></param>
    pplx::task<std::shared_ptr<ResellerContactDto>> addResellerContact(
        utility::string_t isvId,
        utility::string_t resellerId,
        std::shared_ptr<ResellerContactDto> resellerContactDto
    ) const;
    /// <summary>
    /// Grants access to a product templates (edition)
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="resellerTemplateDto"></param>
    pplx::task<std::shared_ptr<ResellerTemplateDto>> addResellerTemplate(
        utility::string_t isvId,
        std::shared_ptr<ResellerTemplateDto> resellerTemplateDto
    ) const;
    /// <summary>
    /// Creates a reseller type
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="resellerTypeDto"></param>
    pplx::task<std::shared_ptr<ResellerTypeDto>> addResellerType(
        utility::string_t isvId,
        std::shared_ptr<ResellerTypeDto> resellerTypeDto
    ) const;
    /// <summary>
    /// Deletes a reseller
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="resellerId"></param>
    pplx::task<std::vector<std::shared_ptr<ResellerDto>>> deleteReseller(
        utility::string_t isvId,
        utility::string_t resellerId
    ) const;
    /// <summary>
    /// Deletes a reseller contact
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="resellerId"></param>
    /// <param name="contactId"></param>
    /// <param name="removeIdentity"> (optional, default to false)</param>
    pplx::task<std::shared_ptr<ResellerContactDto>> deleteResellerContact(
        utility::string_t isvId,
        utility::string_t resellerId,
        utility::string_t contactId,
        boost::optional<bool> removeIdentity
    ) const;
    /// <summary>
    /// Revokes access to a product templates (edition)
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="resellerId"></param>
    /// <param name="templateId"></param>
    pplx::task<std::shared_ptr<ResellerTemplateDto>> deleteResellerTemplate(
        utility::string_t isvId,
        utility::string_t resellerId,
        utility::string_t templateId
    ) const;
    /// <summary>
    /// Returns all resellers
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    pplx::task<std::vector<std::shared_ptr<ResellerDto>>> getAllResellers(
        utility::string_t isvId
    ) const;
    /// <summary>
    /// Returns all resellers with reduced information
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    pplx::task<std::vector<std::shared_ptr<ResellerLightDto>>> getAllResellersLight(
        utility::string_t isvId
    ) const;
    /// <summary>
    /// Returns all resellers matching a filter
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="resellerFilterDto"></param>
    pplx::task<std::shared_ptr<ResellerLazyLoadDto>> getFilteredResellers(
        utility::string_t isvId,
        std::shared_ptr<ResellerFilterDto> resellerFilterDto
    ) const;
    /// <summary>
    /// Returns a reseller
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="resellerId"></param>
    pplx::task<std::shared_ptr<ResellerDto>> getReseller(
        utility::string_t isvId,
        utility::string_t resellerId
    ) const;
    /// <summary>
    /// Returns a reseller
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="resellerNumber"></param>
    pplx::task<std::shared_ptr<ResellerDto>> getResellerByNumber(
        utility::string_t isvId,
        utility::string_t resellerNumber
    ) const;
    /// <summary>
    /// Returns all resellers of the logged in user
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    pplx::task<std::shared_ptr<ResellerDto>> getResellerByUser(
        utility::string_t isvId
    ) const;
    /// <summary>
    /// Returns a reseller contact
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    pplx::task<std::vector<std::shared_ptr<ResellerContactDto>>> getResellerContactByUserId(
        utility::string_t isvId
    ) const;
    /// <summary>
    /// Returns a reseller&#39;s contacts
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="resellerId"></param>
    pplx::task<std::vector<std::shared_ptr<ResellerContactDto>>> getResellerContacts(
        utility::string_t isvId,
        utility::string_t resellerId
    ) const;
    /// <summary>
    /// Returns the number of all resellers
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    pplx::task<std::vector<std::shared_ptr<AnyType>>> getResellerCount(
        utility::string_t isvId
    ) const;
    /// <summary>
    /// Returns all available product templates (editions) for a reseller
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="resellerId"></param>
    pplx::task<std::vector<std::shared_ptr<ResellerTemplateDto>>> getResellerTemplates(
        utility::string_t isvId,
        utility::string_t resellerId
    ) const;
    /// <summary>
    /// Returns all reseller types
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    pplx::task<std::vector<std::shared_ptr<ResellerTypeDto>>> getResellerTypes(
        utility::string_t isvId
    ) const;
    /// <summary>
    /// Deletes a reseller type
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="typeId"></param>
    /// <param name="newTypeId"></param>
    pplx::task<std::shared_ptr<ResellerTypeDto>> removeResellerType(
        utility::string_t isvId,
        utility::string_t typeId,
        utility::string_t newTypeId
    ) const;
    /// <summary>
    /// Returns a reseller (deprecated; use api/v{version:apiVersion}/isv/{isv_id}/resellers/by_number instead)
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="resellerNumber"></param>
    pplx::task<std::shared_ptr<ResellerDto>> resellerGetResellerByResellerNumberDeprecated(
        utility::string_t isvId,
        utility::string_t resellerNumber
    ) const;
    /// <summary>
    /// Sends a new invitation email to a reseller contact
    /// </summary>
    /// <remarks>
    /// A first invitation is send during creation of a contact
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="resellerId"></param>
    /// <param name="contactId"></param>
    pplx::task<void> resendResellerContactInvitation(
        utility::string_t isvId,
        utility::string_t resellerId,
        utility::string_t contactId
    ) const;
    /// <summary>
    /// Toggles a reseller contact state
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="resellerId"></param>
    /// <param name="contactId"></param>
    pplx::task<std::shared_ptr<ResellerContactDto>> toggleResellerContactState(
        utility::string_t isvId,
        utility::string_t resellerId,
        utility::string_t contactId
    ) const;
    /// <summary>
    /// Updates a reseller
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="resellerDto"></param>
    pplx::task<std::shared_ptr<ResellerDto>> updateReseller(
        utility::string_t isvId,
        std::shared_ptr<ResellerDto> resellerDto
    ) const;
    /// <summary>
    /// Updates a reseller contact
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="resellerId"></param>
    /// <param name="resellerContactDto"></param>
    pplx::task<std::shared_ptr<ResellerContactDto>> updateResellerContact(
        utility::string_t isvId,
        utility::string_t resellerId,
        std::shared_ptr<ResellerContactDto> resellerContactDto
    ) const;
    /// <summary>
    /// Updates access to a product templates (edition)
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="resellerTemplateDto"></param>
    pplx::task<std::shared_ptr<ResellerTemplateDto>> updateResellerTemplate(
        utility::string_t isvId,
        std::shared_ptr<ResellerTemplateDto> resellerTemplateDto
    ) const;
    /// <summary>
    /// Updates a reseller type
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="resellerTypeDto"></param>
    pplx::task<std::shared_ptr<ResellerTypeDto>> updateResellerType(
        utility::string_t isvId,
        std::shared_ptr<ResellerTypeDto> resellerTypeDto
    ) const;

protected:
    std::shared_ptr<const ApiClient> m_ApiClient;
};

}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_API_ResellerApi_H_ */

