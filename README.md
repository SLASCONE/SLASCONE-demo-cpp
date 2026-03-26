# LICENSING & ANALYTICS FOR SOFTWARE AND IoT VENDORS

This console application demonstrates the usage of the SLASCONE API for standard operations such as activation, license file validation, heartbeat and floating session management.

For more information about this solution, visit
https://slascone.com/ and/or
https://support.slascone.com/.

## TABLE OF CONTENTS

- [LICENSING & ANALYTICS FOR SOFTWARE AND IoT VENDORS](#licensing--analytics-for-software-and-iot-vendors)
  - [DEVELOPMENT CONTAINER](#development-container)
  - [BUILDING AND RUNNING WITH CMAKE PRESETS](#building-and-running-with-cmake-presets)
  - [CONNECTING TO YOUR SLASCONE ENVIRONMENT](#connecting-to-your-slascone-environment)
  - [COVERAGE](#coverage)
  - [ERROR HANDLING AND RETRY LOGIC](#error-handling-and-retry-logic)
  - [RUNNING THE DEMO APP WITH WINDOWS](#running-the-demo-app-with-windows)
  - [API CLIENT](#api-client)

## DEVELOPMENT CONTAINER

This project leverages a development container (`devcontainer`) to establish a consistent and reliable development environment. The devcontainer is pre-configured with all required dependencies, ensuring an optimal setup for running and contributing to the project. To utilize the development container, open the project in Visual Studio Code and choose the option to reopen it within the container. This approach guarantees that all dependencies are properly installed and configured.

## BUILDING AND RUNNING WITH CMAKE PRESETS

The repo includes a `linux-debug` preset in [CMakePresets.json](CMakePresets.json) that keeps every build in an isolated tree under `out/build/linux-debug`. Run the following from the repository root:

```
cmake --preset linux-debug          # configure once
cmake --build --preset linux-debug  # compile sources
```

The resulting executable lives at `out/build/linux-debug/SLASCONE-demo-cpp/SLASCONE-demo-cpp`, matching the default `.vscode/launch.json` entry so you can hit F5 immediately. If you prefer the classic in-source build, you can still run `cmake -S . -B . && cmake --build .`, but then update the launch configuration (or set `CMAKE_RUNTIME_OUTPUT_DIRECTORY`) to align with the new output path. Optional installs follow the usual `cmake --install --preset linux-debug` flow.

## CONNECTING TO YOUR SLASCONE ENVIRONMENT

The application connects to the official SLASCONE environment. In order to connect to your SLASCONE environment, adjust the values of the file `Helper.cpp`.

## COVERAGE

The demo app covers the main tasks and aspects involved in using SLASCONE licensing.

### License lifecycle

The license lifecycle consists of activating the license, sending license heartbeat and potentially unassigning the license. 
For details and the differences in the [various license models](https://support.slascone.com/hc/en-us/sections/360004693117-Licensing-Models) please read the documentation.

In the demo app you can
 - activate a license
 - send a license heartbeat
 - unassign a license

 Additionally the demo app implements how the license information can be stored locally for use if the client is temporarily disconnected from the internet. For details please read the article ['What and how to save in your client'](https://support.slascone.com/hc/en-us/articles/7702036319261-WHAT-AND-HOW-TO-SAVE-IN-YOUR-CLIENT).

### Analytical heartbeats

In the demo app you can create several types of heartbeats:
 - Analytical and 
 - Usage heartbeats (see: [product analytics](https://support.slascone.com/hc/en-us/articles/360016055537-PRODUCT-ANALYTICS))
 - Consumption heartbeats (see: [consumption based limitations](https://support.slascone.com/hc/en-us/articles/360016057197-CONSUMPTION-BASED-LIMITATIONS))

### Session management

In the demo app you can open and close sessions in a _floating_ licensing model. Please refer to the articles about floating [user licenses](https://support.slascone.com/hc/en-us/articles/7756256586653-FLOATING-USER-LICENSES) and [device licenses](https://support.slascone.com/hc/en-us/articles/360016152858-FLOATING-DEVICE-LICENSES).

### Security aspects

The demo app contains exemplary implementations of how to verify the SLASCONE WebAPI response with the signature header or verify the integrity of an offline license file in XML format. On every request the client also generates a cryptographically strong random nonce, base64 encodes it, adds it to the `x-nonce` header, and later verifies the `x-nonce-signature` header so the server response cannot be replayed with stale data. You can inspect the full nonce and header handling inside [SLASCONE-demo-client/src/SlasconeApiClient.cpp](SLASCONE-demo-client/src/SlasconeApiClient.cpp#L54-L142), especially the `callApi()` override where the nonce, response signature, and persistence logic live. You can find more details about [digital signature and data integrity](https://support.slascone.com/hc/en-us/articles/360016063637-DIGITAL-SIGNATURE-AND-DATA-INTEGRITY) in the SLASCONE help center.

## ERROR HANDLING AND RETRY LOGIC

This sample application demonstrates how to handle SLASCONE API errors and implement retry logic using the `ErrorHandlingHelper` class ([SLASCONE-demo-cpp/ErrorHandlingHelper.h](SLASCONE-demo-cpp/ErrorHandlingHelper.h)). All API calls are routed through this helper, which provides consistent error classification, automatic retries for transient failures, and a unified response wrapper. For detailed information about SLASCONE API error codes, refer to the [SLASCONE error handling documentation](https://support.slascone.com/hc/en-us/articles/360016160398-ERROR-HANDLING).

### Error Categories

The `ErrorHandlingHelper` classifies API errors into three categories:

1. **Functional Errors (HTTP 409)**
   - Represent business logic conflicts returned by the SLASCONE API
   - Examples include attempting to activate an already-activated license, unknown client IDs, or exceeded license limits
   - The response body is automatically parsed into an `ErrorResultObjects` with a specific error code and message
   - These errors are never retried, as they require the caller to address the underlying business logic issue

2. **Technical Errors (HTTP 4xx/5xx)**
   - Represent server-side or request issues such as internal server errors, bad gateways, or service unavailability
   - Transient HTTP errors (408, 429, 500, 502, 503, 504, 507) are automatically retried
   - Non-transient errors (e.g., 401, 403, 404) are returned immediately without retry

3. **Network Errors**
   - Represent connectivity issues such as socket timeouts, connection refused, DNS resolution failures, or SSL errors
   - All network-level exceptions (caught as `web::http::http_exception`) are treated as transient and are automatically retried
   - If retries are exhausted, the error is reported with the underlying exception message and error code

### Retry Logic

The `ErrorHandlingHelper` implements automatic retry logic for transient errors:

1. **Retry Count**: By default, the helper performs a maximum of 1 automatic retry (`MaxRetryCount`). This follows the SLASCONE recommendation of a moderate retry policy to avoid putting unnecessary strain on the server.

2. **Wait Time**: The default wait time between retries is 15 seconds (`RetryWaitTime`).

3. **Retry-After Header**: For HTTP errors that include a `Retry-After` response header (commonly sent with 429 or 503 responses), the helper uses the server-specified wait time instead of the default. The value is clamped between 5 and 120 seconds to avoid excessively short or long waits.

4. **Non-Transient Errors**: Errors that are not classified as transient (e.g., HTTP 404 or a functional 409 conflict) are returned immediately without any retry attempt.

### Handling API Responses

All API calls wrapped by `ErrorHandlingHelper::execute()` return an `ApiResult<T>` struct, which encapsulates either a successful result or error details:

1. **Success Check**: Check the `errorType` field — a value of `ErrorType::None` indicates success.

2. **Success Path**: Use the `data` field to access the API response data (e.g., `LicenseInfoDto`, `SessionStatusDto`).

3. **Error Inspection**: When an error occurs, use the following fields:
   - `errorType` — Returns the error category (`Functional`, `Technical`, or `Network`)
   - `errorMessage` — Returns a formatted error description including the caller name and error details
   - `errorId` — For functional errors (HTTP 409), returns the specific SLASCONE error code from the parsed `ErrorResultObjects`

4. **Usage Example**: The following pattern demonstrates standard error handling for API calls:

```cpp
auto result = ErrorHandlingHelper::execute<std::shared_ptr<LicenseInfoDto>>(
    [&]() { return provisioningApi->activateLicenseAsync(activateInfo); },
    "activateLicense");

if (result.errorType != ErrorType::None)
{
    std::cout << "Error Type: " << static_cast<int>(result.errorType) << std::endl;
    std::cout << "Message: " << result.errorMessage << std::endl;

    if (result.errorType == ErrorType::Functional)
    {
        // Handle specific business logic error codes
        int errorId = result.errorId;
    }
    return;
}

auto licenseInfo = result.data;
```

### Recommended Error Handling Strategy

Based on the SLASCONE error handling guidelines, consider the following strategies when integrating SLASCONE licensing into your application:

1. **Always Handle HTTP 409 Explicitly**: These are business logic responses, not unexpected errors. Check the specific error code from `errorId` and handle each case according to your application's needs. Refer to the endpoint-specific documentation in the [SLASCONE API](https://api.slascone.com/swagger/index.html?urls.primaryName=V2) for possible conflict scenarios.

2. **Fallback for Transient Failures**: The built-in retry logic handles the first retry automatically. If retries are exhausted, implement a fallback strategy such as using cached license data from the last successful heartbeat (see ['What and how to save in your client'](https://support.slascone.com/hc/en-us/articles/7702036319261-WHAT-AND-HOW-TO-SAVE-IN-YOUR-CLIENT)).

3. **Heartbeat Failure Resilience**: When a license heartbeat fails after retries, fall back to the locally cached license data. The freeride period provides a grace period during which the application can continue operating. Do not apply freeride logic for server errors — reserve it for true offline scenarios.

4. **Session Open Resilience**: For floating license session open failures caused by transient errors, consider treating the request as successful to avoid disrupting the user experience. This approach prioritizes usability while maintaining license compliance once connectivity is restored.

## RUNNING THE DEMO APP WITH WINDOWS

To build and run this application with Windows you have to install all dependencies manually. You can install the dependencies with [`vcpkg`](https://vcpkg.io/en/). Additionally you have to provide some paths to CMake so that the libraries can be found during the CMake configuration process.

These variables are defined in the `CMakeSettings.json` file. Please locate this file in the top level of the project folder.

```
 {
  "configurations": [
    {
      "name": "x64-Debug",
      "generator": "Ninja",
      "configurationType": "Debug",
      "inheritEnvironments": [ "msvc_x64_x64" ],
      "buildRoot": "${projectDir}\\out\\build\\${name}",
      "installRoot": "${projectDir}\\out\\install\\${name}",
      "cmakeCommandArgs": "",
      "buildCommandArgs": "",
      "ctestCommandArgs": "",
      "variables": [
        {
          "name": "CMAKE_PREFIX_PATH",
          "value": "C:\\git\\microsoft\\vcpkg\\packages\\brotli_x64-windows\\share\\unofficial-brotli",
          "type": "PATH"
        },
        {
          "name": "cpprestsdk_DIR",
          "value": "C:\\git\\microsoft\\vcpkg\\packages\\cpprestsdk_x64-windows\\share\\cpprestsdk",
          "type": "PATH"
        },
        {
          "name": "ZLIB_LIBRARY",
          "value": "C:\\git\\microsoft\\vcpkg\\packages\\zlib_x64-windows\\lib",
          "type": "PATH"
        },
        {
          "name": "ZLIB_INCLUDE_DIR",
          "value": "C:\\git\\microsoft\\vcpkg\\packages\\zlib_x64-windows\\include",
          "type": "PATH"
        },
        {
          "name": "BOOST_ROOT",
          "value": "C:\\Projects\\boost_1_86_0",
          "type": "PATH"
        },
        {
          "name": "Boost_USE_DEBUG_LIBS",
          "value": "OFF",
          "type": "BOOL"
        },
        {
          "name": "OPENSSL_ROOT_DIR",
          "value": "C:\\git\\microsoft\\vcpkg\\packages\\openssl_x64-windows",
          "type": "PATH"
        }
      ]
    }
  ]
}
```

## API CLIENT

This application uses a client generated by the [OpenAPI Generator](https://openapi-generator.tech/) using the generator [cpp-restsdk](https://openapi-generator.tech/docs/generators/cpp-restsdk).

Please find further information about the generated client in the [README](SLASCONE-demo-client/README.md).
