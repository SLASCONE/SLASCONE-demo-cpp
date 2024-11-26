# CMakeList.txt : CMake project for SLASCONE-demo-cpp, include source and define
# project specific logic here.
#

# SLASCONE-demo-cpp executable.
add_executable (SLASCONE-demo-cpp "SLASCONE-demo-cpp.cpp" "SLASCONE-demo-cpp.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SLASCONE-demo-cpp PROPERTY CXX_STANDARD 20)
endif()

# Find and include OpenSSL
find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

# Find and include LibXML2
find_package(LibXml2 REQUIRED)
include_directories(${LIBXML2_INCLUDE_DIR})

# Find and include libxslt
find_package(LibXslt REQUIRED)
include_directories(${LIBXSLT_INCLUDE_DIR})

# Find and include iconv
find_package(Iconv REQUIRED)
include_directories(${Iconv_INCLUDE_DIR})

# Find and include xmlsec
# find_package(xmlsec1 REQUIRED)
include_directories(${XMLSEC_INCLUDE_DIR})

# Define XMLSEC_CRYPTO_DYNAMIC_LOADING
add_definitions(-DXMLSEC_CRYPTO_DYNAMIC_LOADING=1)
add_definitions(-DXMLSEC_CRYPTO_OPENSSL=1)

# Link libraries
target_link_libraries(XmlSignatureValidationCpp ${OPENSSL_LIBRARIES} ${LIBXML2_LIBRARIES} ${LIBXSLT_LIBRARIES} ${Iconv_LIBRARY} ${XMLSEC_LIBRARY})
