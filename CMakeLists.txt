cmake_minimum_required(VERSION 3.16)

project(string_utils)

# Project settings
set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "--coverage")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(DIST ${PROJECT_SOURCE_DIR}/dist)
set(BINARY ${PROJECT_SOURCE_DIR}/bin)
set(INCLUDE ${PROJECT_SOURCE_DIR}/include)
set(TESTDIR ${PROJECT_SOURCE_DIR}/test)

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
file(GLOB test_files
        "test/wniemiec/util/cpp/*.cpp"
)
add_executable(string_utils ${string_utils_sources} ${test_files})

add_custom_target(dist
	COMMAND rm -rf ${DIST};
	mkdir ${DIST};
	cp ${BINARY}/StringUtils.o ${DIST};
	cp ${INCLUDE}/wniemiec/util/cpp/StringUtils.hpp ${DIST};
)
add_custom_target(clean-all
	COMMAND rm -rf CMakeFiles;
            rm -rf CMakeCache.txt; 
            rm -rf *.cmake; 
            rm -rf bin; 
            rm -rf Makefile;
            rm -rf lib;
            rm -rf build;
            rm -rf _deps;
            rm -rf test/CMakeFiles; 
            rm -rf test/CMakeCache.txt; 
            rm -rf test/*.cmake; 
            rm -rf test/bin; 
            rm -rf test/Makefile;
            rm -rf test/lib;
            rm -rf test/_deps;
            rm -rf test/runTests;
)

# Google testing framework
enable_testing()
target_link_libraries(
        string_utils
        gtest_main
)
include(GoogleTest)
gtest_discover_tests(string_utils)

add_subdirectory(test)
