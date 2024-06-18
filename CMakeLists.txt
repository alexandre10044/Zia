cmake_minimum_required(VERSION 3.0)
project(Zia C CXX)

set(CMAKE_BUILD_TYPE Debug)
include(openZia/openZia/openZia.cmake)
#include(modules/httpModule/httpModule.cmake)
## Zia Server

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/zia)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/zia/Logging)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/zia/Config)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/zia/Network)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/zia/Network/Client)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/openZia/openZia)



add_executable(
    zia
    ${CMAKE_CURRENT_SOURCE_DIR}/zia/Config/Config.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/zia/Logging/Logging.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/zia/Network/NetworkManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/zia/Network/Client/Client.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/zia/main.cpp
)



target_link_libraries(zia ${openZiaLibs})
target_include_directories(zia PRIVATE ${openZiaIncludes})


find_package (Threads)
target_link_libraries (zia ${CMAKE_THREAD_LIBS_INIT})
## Modules
include(modules/httpParseRequest/httpParseRequest.cmake)
include(modules/httpCheckRequest/httpCheckRequest.cmake)
include(modules/httpGet/httpGet.cmake)
include(modules/phpCgiModule/phpCgiModule.cmake)
include(modules/httpWriteResponse/httpWriteResponse.cmake)
include(modules/httpDelete/httpDelete.cmake)
include(modules/httpPut/httpPut.cmake)
include(modules/sslDecrypt/sslDecrypt.cmake)
include(modules/sslEncrypt/sslEncrypt.cmake)
## Conan basic setup changes the output directory to /lib ? strange, to fix
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#conan_basic_setup(SecureConnectionModule)
#include(modules/SecureConnectionModule/SecureConnectionModule.cmake)
## Zia config file
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.conf ./config.conf COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/modules/SecureConnectionModule/ssl/mycert.pem ./mycert.pem COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/modules/SecureConnectionModule/ssl/mykey.pem ./mykey.pem COPYONLY)