cmake_minimum_required(VERSION 3.9)
project(express-friendly-cpprest)

set(VCPKG_PATH "C:/src/vcpkg" CACHE STRING "VCPKG path")
message("VCPKG_PATH=${VCPKG_PATH}")

set(VCPKG_TARGET_TRIPLET "x64-windows")
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_PATH}/scripts/buildsystems/vcpkg.cmake")

set(CPPRESTSDK_INCLUDE_DIR "${VCPKG_PATH}/installed/x64-windows/include/cpprest")
set(CPPRESTSDK_LIBRARY "${VCPKG_PATH}/installed/x64-windows/lib")

find_path(CPPRESTSDK_INCLUDE_DIR version.h)
find_library(CPPRESTSDK_LIBRARY cpprest_2_10)

add_executable(express-friendly-cpprest src/main.cpp)

target_include_directories(express-friendly-cpprest PRIVATE ${CPPRESTSDK_INCLUDE_DIR})
target_link_libraries(express-friendly-cpprest PRIVATE "${CPPRESTSDK_LIBRARY}/cpprest_2_10.lib")