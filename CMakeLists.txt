cmake_minimum_required(VERSION 3.17)

project(string_utils)

# Project settings
set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "--coverage")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Google testing framework
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Include directories
include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/src")
include_directories("${PROJECT_SOURCE_DIR}/test")

# Project source files
set(string_utils_sources
        src/wniemiec/util/cpp/StringUtils.cpp
)

add_executable(string_utils ${string_utils_sources})

# Google testing framework
enable_testing()
target_link_libraries(
        string_utils
        gtest_main
)
include(GoogleTest)
gtest_discover_tests(string_utils)

add_subdirectory(test)