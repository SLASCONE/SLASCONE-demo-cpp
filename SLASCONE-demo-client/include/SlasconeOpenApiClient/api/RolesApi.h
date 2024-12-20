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
 * RolesApi.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_API_RolesApi_H_
#define ORG_OPENAPITOOLS_CLIENT_API_RolesApi_H_



#include "SlasconeOpenApiClient/ApiClient.h"

#include "SlasconeOpenApiClient/model/ProblemDetails.h"
#include "SlasconeOpenApiClient/model/UserRoleContextDto.h"
#include "SlasconeOpenApiClient/model/UserRolesDto.h"
#include <boost/optional.hpp>

namespace org {
namespace openapitools {
namespace client {
namespace api {

using namespace org::openapitools::client::model;



class  RolesApi 
{
public:

    explicit RolesApi( std::shared_ptr<const ApiClient> apiClient );

    virtual ~RolesApi();

    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    pplx::task<std::shared_ptr<UserRolesDto>> get_user_roles_and_last_active_context(
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="userRoleContextDto"></param>
    pplx::task<void> switch_user_context(
        std::shared_ptr<UserRoleContextDto> userRoleContextDto
    ) const;

protected:
    std::shared_ptr<const ApiClient> m_ApiClient;
};

}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_API_RolesApi_H_ */

