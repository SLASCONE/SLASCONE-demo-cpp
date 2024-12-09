# LICENSING & ANALYTICS FOR SOFTWARE AND IoT VENDORS

This console application demonstrates the usage of the SLASCONE API for standard operations such as activation, license file validation, heartbeat and floating session management.

For more information about this solution, visit
https://slascone.com/ and/or
https://support.slascone.com/.

## Development Container

This project leverages a development container (`devcontainer`) to establish a consistent and reliable development environment. The devcontainer is pre-configured with all required dependencies, ensuring an optimal setup for running and contributing to the project. To utilize the development container, open the project in Visual Studio Code and choose the option to reopen it within the container. This approach guarantees that all dependencies are properly installed and configured.

## Connecting to your SLASCONE environment

The application connects to the official SLASCONE environment. In order to connect to your SLASCONE environment, adjust the values of the file `Helper.cpp`.

## Coverage

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

The demo app contains exemplary implementations of how to verify the SLASCONE WebAPI response with the signature header or verify the integrity of an offline license file in XML format. You can find more details about [digital signature and data integrity](https://support.slascone.com/hc/en-us/articles/360016063637-DIGITAL-SIGNATURE-AND-DATA-INTEGRITY) in the SLASCONE help center.

## Running the demo app with Windows

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

## API client

This application uses a client generated by the [OpenAPI Generator](https://openapi-generator.tech/) using the generator [cpp-restsdk](https://openapi-generator.tech/docs/generators/cpp-restsdk).

Please find further information about the generated client in the [README](SLASCONE-demo-client/README.md).
