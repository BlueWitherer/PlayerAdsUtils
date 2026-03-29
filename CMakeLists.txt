cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

project(PlayerAdsUtils VERSION 1.0.1)

file(GLOB_RECURSE SOURCES src/*.cpp)
add_library(${PROJECT_NAME} STATIC ${SOURCES})

option(PAU_TRACK_STATS "Track views and clicks" OFF)

if(PAU_TRACK_STATS)
    add_compile_definitions(PAU_TRACK_STATS)
endif()

if(NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

if(PROJECT_IS_TOP_LEVEL)
    add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)
endif()

target_compile_definitions(${PROJECT_NAME} PRIVATE GEODE_MOD_ID="_pau")
target_compile_definitions(${PROJECT_NAME} PRIVATE PAU_VERSION=${PROJECT_VERSION})

target_link_libraries(PlayerAdsUtils geode-sdk)

if(NOT TARGET argon AND PAU_TRACK_STATS)
    CPMAddPackage("gh:GlobedGD/argon@1.4.6")
endif()

if(TARGET argon)
    target_link_libraries(PlayerAdsUtils argon)
endif()

target_include_directories(PlayerAdsUtils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
