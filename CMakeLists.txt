cmake_minimum_required(VERSION 3.9)

set(PROJECT_NAME "express-friendly-cpprest")
project("${PROJECT_NAME}")

SET(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
SET(BUILD_SHARED_LIBS ON)

message(CMAKE_INSTALL_PREFIX="${CMAKE_INSTALL_PREFIX}")

set(VCPKG_PATH "C:/src/vcpkg" CACHE STRING "VCPKG path")
message("VCPKG_PATH=${VCPKG_PATH}")

set(VCPKG_TARGET_TRIPLET "x64-windows")
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_PATH}/scripts/buildsystems/vcpkg.cmake")

set(SOURCE_INCLUDE_DIR "include")
file(GLOB INCLUDE_FILES "include/*.hpp")

set(STATIC_INCLUDE__DIR "${VCPKG_PATH}/installed/x64-windows-static/include")
set(CPPRESTSDK_INCLUDE_DIR "${VCPKG_PATH}/installed/x64-windows/include")
set(CPPRESTSDK_LIBRARY "${VCPKG_PATH}/installed/x64-windows/lib")

include("${VCPKG_PATH}/scripts/buildsystems/vcpkg.cmake")
find_package(cpprestsdk CONFIG REQUIRED)

add_library("${PROJECT_NAME}"	SHARED	"src/App.cpp"
										"src/InterruptHandler.cpp"
										"src/Request.cpp"
										"src/Router.cpp"
										"src/Utils.cpp" 
										"src/ValidationManager.cpp" 
										"src/Validator.cpp")

set(LIBRARIES_INCLUDE_DIRS ${SOURCE_INCLUDE_DIR} ${CPPRESTSDK_INCLUDE_DIR} ${STATIC_INCLUDE__DIR})

target_include_directories("${PROJECT_NAME}" PRIVATE ${LIBRARIES_INCLUDE_DIRS})
target_link_libraries("${PROJECT_NAME}" PRIVATE cpprestsdk::cpprest)

set(INSTALL_LIBS "${PROJECT_NAME}")

install(TARGETS ${INSTALL_LIBS} DESTINATION lib)
install(FILES ${INCLUDE_FILES} DESTINATION include)