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

# Find and include LibXML2
find_package(LibXml2 REQUIRED)

# Find and include libxslt
find_package(LibXslt REQUIRED)

# Find and include iconv
find_package(Iconv REQUIRED)

# Include directories
include_directories(${OPENSSL_INCLUDE_DIR} ${LIBXML2_INCLUDE_DIR} ${LIBXSLT_INCLUDE_DIR} ${Iconv_INCLUDE_DIR} ${XMLSEC_INCLUDE_DIR})

# Define XMLSEC definitions
add_definitions(-D__XMLSEC_FUNCTION__=__func__)
add_definitions(-DXMLSEC_NO_SIZE_T)
add_definitions(-DXMLSEC_OPENSSL3_ENGINES=1)
add_definitions(-DXMLSEC_NO_GOST=1)
add_definitions(-DXMLSEC_NO_GOST2012=1)
add_definitions(-DXMLSEC_NO_CRYPTO_DYNAMIC_LOADING=1)
add_definitions(-DXMLSEC_CRYPTO_OPENSSL=1)
add_definitions(-DXMLSEC_NO_XSLT=1)

# Link libraries
target_link_libraries(SLASCONE-demo-cpp ${OPENSSL_LIBRARIES} ${LIBXML2_LIBRARIES} ${LIBXSLT_LIBRARIES} ${Iconv_LIBRARY} ${XMLSEC_LIBRARY} ${XMLSEC_OPENSSL_LIBRARY} /usr/lib/x86_64-linux-gnu/libxmlsec1-gnutls.so /usr/lib/x86_64-linux-gnu/libxmlsec1-nss.so /usr/lib/x86_64-linux-gnu/libxmlsec1-gcrypt.so)
