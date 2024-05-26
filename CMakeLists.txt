cmake_minimum_required(VERSION 3.10)

project(ap-emu)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")

FetchContent_GetProperties(json-c)

if (NOT json_POPULATED)
    FetchContent_Populate(json-c)
    add_subdirectory(${json-c_SOURCE_DIR} ${json-c_BINARY_DIR} EXCLUDE_FROM_ALL)
endif ()


message(STATUS "")
include(${CMAKE_SOURCE_DIR}/scripts/DeployBinary.cmake)
include(${CMAKE_SOURCE_DIR}/deps/openssl.cmake)
include(${CMAKE_SOURCE_DIR}/deps/busybox.cmake)

add_subdirectory(hostapd)
