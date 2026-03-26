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

### Error handling and retry logic

The demo app includes a centralized error handling helper ([SLASCONE-demo-cpp/ErrorHandlingHelper.h](SLASCONE-demo-cpp/ErrorHandlingHelper.h)) that wraps every SLASCONE API call with standardized error classification and retry logic. The helper distinguishes three error categories:
 - **Functional** errors represent business logic responses such as HTTP 409 (Conflict). These carry a SLASCONE-specific error id and message that the caller should evaluate to drive application behavior.
 - **Technical** errors cover authentication failures (HTTP 401/403) and unexpected exceptions that indicate a configuration or programming issue.
 - **Network** errors include transient HTTP status codes (408, 429, 500, 502, 503, 504, 507) as well as low-level connectivity problems (e.g., DNS resolution failures or timeouts).

For transient errors the helper automatically retries the request up to one time. If the server includes a `Retry-After` header the helper respects it (clamped between 5 and 120 seconds); otherwise it falls back to a default wait of 15 seconds. Network-level exceptions (e.g., no internet connection) are treated the same way and retried once before being reported.

If retries are exhausted, the structured result is returned to the caller with the error category and details so that the application can implement a graceful fallback — for example falling back to locally cached license data as described in ['What and how to save in your client'](https://support.slascone.com/hc/en-us/articles/7702036319261-WHAT-AND-HOW-TO-SAVE-IN-YOUR-CLIENT). For more information about the recommended error handling strategy see the [error handling](https://support.slascone.com/hc/en-us/articles/360016160398-ERROR-HANDLING) article in the SLASCONE help center.

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
