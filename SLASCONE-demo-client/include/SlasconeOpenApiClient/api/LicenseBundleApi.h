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
 * LicenseBundleApi.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_API_LicenseBundleApi_H_
#define ORG_OPENAPITOOLS_CLIENT_API_LicenseBundleApi_H_



#include "SlasconeOpenApiClient/ApiClient.h"

#include "SlasconeOpenApiClient/model/LicenseBundleDto.h"
#include "SlasconeOpenApiClient/model/ProblemDetails.h"
#include <vector>
#include <cpprest/details/basic_types.h>
#include <boost/optional.hpp>

namespace org {
namespace openapitools {
namespace client {
namespace api {

using namespace org::openapitools::client::model;



class  LicenseBundleApi 
{
public:

    explicit LicenseBundleApi( std::shared_ptr<const ApiClient> apiClient );

    virtual ~LicenseBundleApi();

    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="licenseBundleDto"></param>
    pplx::task<std::shared_ptr<LicenseBundleDto>> addLicenseBundle(
        utility::string_t isvId,
        std::shared_ptr<LicenseBundleDto> licenseBundleDto
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="licenseBundleId"></param>
    pplx::task<std::shared_ptr<LicenseBundleDto>> deleteLicenseBundle(
        utility::string_t isvId,
        utility::string_t licenseBundleId
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="licenseBundleId"></param>
    pplx::task<std::shared_ptr<LicenseBundleDto>> getLicenseBundle(
        utility::string_t isvId,
        utility::string_t licenseBundleId
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="customerId"> (optional, default to utility::conversions::to_string_t(&quot;&quot;))</param>
    pplx::task<std::vector<std::shared_ptr<LicenseBundleDto>>> getLicenseBundles(
        utility::string_t isvId,
        boost::optional<utility::string_t> customerId
    ) const;
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="isvId"></param>
    /// <param name="licenseBundleDto"></param>
    pplx::task<std::shared_ptr<LicenseBundleDto>> updateLicenseBundle(
        utility::string_t isvId,
        std::shared_ptr<LicenseBundleDto> licenseBundleDto
    ) const;

protected:
    std::shared_ptr<const ApiClient> m_ApiClient;
};

}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_API_LicenseBundleApi_H_ */

