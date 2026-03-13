// Error handling helper for SLASCONE API calls
//
// Equivalent to the C# ErrorHandlingHelper described in ErrorHandling.md.
// Wraps API calls with standard retry logic for transient errors.

#ifndef SLASCONE_ERROR_HANDLING_HELPER_H
#define SLASCONE_ERROR_HANDLING_HELPER_H

#include <iostream>
#include <functional>
#include <future>
#include <thread>
#include <chrono>
#include <string>
#include <algorithm>
#include <cpprest/json.h>
#include <SlasconeOpenApiClient/ApiException.h>
#include <SlasconeOpenApiClient/model/ErrorResultObjects.h>
#include <pplx/pplxtasks.h>

namespace SLASCONE_demo_cpp
{
    /// Error type enum to differentiate between error categories
    enum class ErrorType
    {
        /// No error occurred
        None,

        /// Business logic or validation error (e.g., invalid input, conflict)
        Functional,

        /// Technical error (e.g., internal server error) or network/connectivity issue
        Network
    };

    /// Result structure returned by ErrorHandlingHelper::execute
    template <typename T>
    struct ApiResult
    {
        T data;
        ErrorType errorType;
        std::string errorMessage;
        int32_t errorId;
    };

    /// Helper class to handle errors and standard retries while calling the SLASCONE API
    class ErrorHandlingHelper
    {
    private:
        /// Wait time between retries (in seconds)
        static constexpr int RetryWaitTime = 15;

        /// Do max 1 retry
        static constexpr int MaxRetryCount = 1;

        /// Get the retry-after period from the exception's response headers
        static int getRetryAfterPeriod(const org::openapitools::client::api::ApiException& e)
        {
            const auto& headers = e.getHeaders();
            auto it = headers.find(utility::conversions::to_string_t("Retry-After"));
            if (it != headers.end())
            {
                try
                {
                    int seconds = std::stoi(utility::conversions::to_utf8string(it->second));
                    return std::clamp(seconds, 5, 120);
                }
                catch (...) {}
            }
            return RetryWaitTime;
        }

        /// Parse error details from the exception's content stream
        static std::pair<int32_t, std::string> parseApiError(
            const org::openapitools::client::api::ApiException& e)
        {
            auto content = e.getContent();
            if (content == nullptr)
            {
                return {0, e.what()};
            }

            try
            {
                org::openapitools::client::model::ErrorResultObjects errorResult;
                std::string jsonStr((std::istreambuf_iterator<char>(*content)),
                                     std::istreambuf_iterator<char>());
                errorResult.fromJson(web::json::value::parse(jsonStr));
                return {errorResult.getId(),
                        utility::conversions::to_utf8string(errorResult.getMessage())};
            }
            catch (...)
            {
                return {0, e.what()};
            }
        }

        /// Check if the HTTP status code indicates a transient error
        static bool isTransientError(int statusCode)
        {
            return statusCode == 429   // Too Many Requests
                || statusCode == 503   // Service Unavailable
                || statusCode == 504;  // Gateway Timeout
        }

    public:
        /// Call a SLASCONE API endpoint with standard retry logic
        template <typename T>
        static ApiResult<T> execute(
            std::function<pplx::task<T>()> apiCall,
            const std::string& callerName)
        {
            using namespace org::openapitools::client::api;

            ApiResult<T> result{};
            result.errorType = ErrorType::None;
            result.errorId = 0;

            int retryCountdown = MaxRetryCount;

            while (0 <= retryCountdown)
            {
                // Bridge pplx::task to std::future via std::promise
                auto promise = std::make_shared<std::promise<T>>();
                std::future<T> future = promise->get_future();

                apiCall()
                    .then([promise](pplx::task<T> task) mutable
                    {
                        try
                        {
                            promise->set_value(task.get());
                        }
                        catch (...)
                        {
                            promise->set_exception(std::current_exception());
                        }
                    });

                try
                {
                    // Success
                    result.data = future.get();
                    result.errorType = ErrorType::None;
                    return result;
                }
                catch (const ApiException& e)
                {
                    int statusCode = e.error_code().value();
                    auto [errorId, errorMessage] = parseApiError(e);

                    if (statusCode == 409) // Conflict - functional error
                    {
                        result.errorType = ErrorType::Functional;
                        result.errorMessage = callerName + " received an error: " + errorMessage
                            + " (Id: " + std::to_string(errorId) + ")";
                        result.errorId = errorId;
                        return result;
                    }
                    else if (statusCode == 401 || statusCode == 403)
                    {
                        result.errorType = ErrorType::Network;
                        result.errorMessage = callerName + " received an error: Not authorized";
                        result.errorId = 0;
                        return result;
                    }
                    else if (isTransientError(statusCode))
                    {
                        // Transient error: wait and retry
                        --retryCountdown;
                        if (0 <= retryCountdown)
                        {
                            int retryAfterSeconds = getRetryAfterPeriod(e);
                            std::cout << callerName << ": Transient error (HTTP " << statusCode
                                      << "), retrying after " << retryAfterSeconds << " seconds..."
                                      << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(retryAfterSeconds));
                            continue;
                        }

                        // Retries exhausted
                        result.errorType = ErrorType::Network;
                        result.errorMessage = callerName + " received an error after "
                            + std::to_string(MaxRetryCount) + " retries: " + errorMessage
                            + " (Id: " + std::to_string(errorId) + ")";
                        result.errorId = errorId;
                        return result;
                    }
                    else
                    {
                        // Other HTTP errors
                        result.errorType = (statusCode >= 400 && statusCode < 500)
                            ? ErrorType::Functional : ErrorType::Network;
                        result.errorMessage = callerName + " received an error: " + errorMessage
                            + " (Id: " + std::to_string(errorId) + ")";
                        result.errorId = errorId;
                        return result;
                    }
                }
                catch (const std::exception& e)
                {
                    result.errorType = ErrorType::Network;
                    result.errorMessage = callerName + " threw an exception: "
                        + std::string(e.what());
                    result.errorId = 0;
                    return result;
                }
            }

            return result;
        }
    };
}

#endif // SLASCONE_ERROR_HANDLING_HELPER_H
