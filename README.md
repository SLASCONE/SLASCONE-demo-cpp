# LICENSING & ANALYTICS FOR SOFTWARE AND IoT VENDORS

This console application demonstrates the usage of the SLASCONE API for standard operations such as activation, license file validation, heartbeat and floating session management.

For more information about this solution, visit
https://slascone.com/ and/or
https://support.slascone.com/

## Development Container

This project leverages a development container (`devcontainer`) to establish a consistent and reliable development environment. The devcontainer is pre-configured with all required dependencies, ensuring an optimal setup for running and contributing to the project. To utilize the development container, open the project in Visual Studio Code and choose the option to reopen it within the container. This approach guarantees that all dependencies are properly installed and configured.

## Connecting to your SLASCONE environment

The application connects to the official SLASCONE environment. In order to connect to your SLASCONE environment, adjust the values of the file `Helper.cpp`.


## Running the demo app with Windows

To build and run this application with Windows you have to install all dependencies manually. You can install the dependencies with [`vcpkg`](https://vcpkg.io/en/).

Additionally you have to provide some paths to CMake so that the libraries can be found during the CMake configuration process.

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

## API client

This application uses a client generated by the [OpenAPI Generator](https://openapi-generator.tech/) using the generator [cpp-restsdk](https://openapi-generator.tech/docs/generators/cpp-restsdk).

Please find further information about the generated client in the [README](SLASCONE-demo-client/README.md).

### Signature check and (temporarily) offline files

To prevent fraud the SLASCONE API sends a cryptographic signature with each response. It is possible to set a callback in the API client that is triggered by every response, but unfortunately the callback function is provided with the response status and the response headers only. For the verification of the signature the response body is also needed.


For more information, please visit [Digital signature and data integrity](https://support.slascone.com/hc/en-us/articles/360016063637-DIGITAL-SIGNATURE-AND-DATA-INTEGRITY) in the SLASCONE help pages.

#### Make `callAPI` virtual

```
virtual pplx::task<web::http::http_response> callApi(
    const utility::string_t& path,
    const utility::string_t& method,
    const std::map<utility::string_t, utility::string_t>& queryParams,
    const std::shared_ptr<IHttpBody> postBody,
    const std::map<utility::string_t, utility::string_t>& headerParams,
    const std::map<utility::string_t, utility::string_t>& formParams,
    const std::map<utility::string_t, std::shared_ptr<HttpContent>>& fileParams,
    const utility::string_t& contentType
) const;
```

#### Derive `ApiClient` class

