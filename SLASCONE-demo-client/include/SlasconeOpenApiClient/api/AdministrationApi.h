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
 * AdministrationApi.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_API_AdministrationApi_H_
#define ORG_OPENAPITOOLS_CLIENT_API_AdministrationApi_H_



#include "SlasconeOpenApiClient/ApiClient.h"

#include "SlasconeOpenApiClient/model/BackupStorageDto.h"
#include "SlasconeOpenApiClient/model/BackupStorageResponseErrors.h"
#include "SlasconeOpenApiClient/model/BackupStorageSasTokenCredentialsError.h"
#include "SlasconeOpenApiClient/model/ConfigurationDto.h"
#include "SlasconeOpenApiClient/model/CustomListDto.h"
#include "SlasconeOpenApiClient/model/CustomListResponseErrors.h"
#include "SlasconeOpenApiClient/model/ProblemDetails.h"
#include "SlasconeOpenApiClient/model/SlasconeLicenseInfoDto.h"
#include "SlasconeOpenApiClient/model/ValidateAssignmentsDto.h"
#include <vector>
#include <cpprest/details/basic_types.h>
#include <boost/optional.hpp>

namespace org {
namespace openapitools {
namespace client {
namespace api {

using namespace org::openapitools::client::model;



class  AdministrationApi 
{
public:

    explicit AdministrationApi( std::shared_ptr<const ApiClient> apiClient );

    virtual ~AdministrationApi();

    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="customListDto"></param>
    pplx::task<std::shared_ptr<CustomListDto>> addCustomList(
        utility::string_t isvId,
        std::shared_ptr<CustomListDto> customListDto
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    pplx::task<void> customOperations(
        utility::string_t isvId
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="customListId"></param>
    pplx::task<void> deleteCustomList(
        utility::string_t isvId,
        utility::string_t customListId
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    pplx::task<void> deleteInactiveSessions(
        utility::string_t isvId
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    pplx::task<void> gatherAnalytics(
        utility::string_t isvId
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    pplx::task<std::vector<std::shared_ptr<CustomListDto>>> getAllCustomLists(
        utility::string_t isvId
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    pplx::task<std::shared_ptr<BackupStorageDto>> getBackupStorage(
        utility::string_t isvId
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    pplx::task<utility::string_t> getBackupStorageAccessToken(
        utility::string_t isvId
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    pplx::task<std::shared_ptr<ConfigurationDto>> getConfiguration(
        utility::string_t isvId
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="customListId"></param>
    pplx::task<std::shared_ptr<CustomListDto>> getCustomList(
        utility::string_t isvId,
        utility::string_t customListId
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="productId"> (optional, default to utility::conversions::to_string_t(&quot;&quot;))</param>
    pplx::task<int32_t> getLicenseSeats(
        utility::string_t isvId,
        boost::optional<utility::string_t> productId
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="forceSendHeartbeat"> (optional, default to false)</param>
    pplx::task<std::shared_ptr<SlasconeLicenseInfoDto>> getSlasconeLicenseInfo(
        utility::string_t isvId,
        boost::optional<bool> forceSendHeartbeat
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    pplx::task<utility::string_t> healthCheck(
        utility::string_t isvId
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="customerId"> (optional, default to utility::conversions::to_string_t(&quot;&quot;))</param>
    /// <param name="includeInactive"> (optional, default to false)</param>
    pplx::task<utility::string_t> initBackupStorage(
        utility::string_t isvId,
        boost::optional<utility::string_t> customerId,
        boost::optional<bool> includeInactive
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    pplx::task<void> migrateDatabase(
        utility::string_t isvId
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="configurationDto"></param>
    pplx::task<std::shared_ptr<ConfigurationDto>> patchConfiguration(
        utility::string_t isvId,
        std::shared_ptr<ConfigurationDto> configurationDto
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="customListDto"></param>
    pplx::task<std::shared_ptr<CustomListDto>> patchCustomList(
        utility::string_t isvId,
        std::shared_ptr<CustomListDto> customListDto
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="body"></param>
    pplx::task<utility::string_t> signatureCheck(
        utility::string_t isvId,
        utility::string_t body
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="backupStorageDto"></param>
    pplx::task<std::shared_ptr<BackupStorageDto>> updateBackupStorage(
        utility::string_t isvId,
        std::shared_ptr<BackupStorageDto> backupStorageDto
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="customListDto"></param>
    pplx::task<std::shared_ptr<CustomListDto>> updateCustomList(
        utility::string_t isvId,
        std::shared_ptr<CustomListDto> customListDto
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    pplx::task<void> validateAlerts(
        utility::string_t isvId
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    pplx::task<void> validateAssignments(
        utility::string_t isvId
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="productId"></param>
    /// <param name="validateAssignmentsDto"></param>
    pplx::task<void> validateAssignmentsByProductId(
        utility::string_t isvId,
        utility::string_t productId,
        std::shared_ptr<ValidateAssignmentsDto> validateAssignmentsDto
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    pplx::task<void> validateConsumptionBalances(
        utility::string_t isvId
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    pplx::task<void> validateHeartbeatGroups(
        utility::string_t isvId
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    pplx::task<void> validateLicenseExpirationDate(
        utility::string_t isvId
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    pplx::task<void> validateSoftwareVersions(
        utility::string_t isvId
    ) const;

protected:
    std::shared_ptr<const ApiClient> m_ApiClient;
};

}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_API_AdministrationApi_H_ */
