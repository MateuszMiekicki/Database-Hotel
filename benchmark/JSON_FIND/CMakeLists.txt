cmake_minimum_required(VERSION 3.10)
project(BenchmarkJSON_FIND)
SET(CMAKE_CXX_FLAGS "-std=c++17 -O3 -Wpedantic -Wall -Wextra")
set(CMAKE_BUILD_TYPE "Release")
include_directories(${PROJECT_SOURCE_DIR}/../build/install/include)   
link_directories(${PROJECT_SOURCE_DIR}/../build/install/lib)

add_library(database STATIC IMPORTED)
set_target_properties(database PROPERTIES
  IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/../../build/libdatabase.a
  INTERFACE_INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}/../../header/
)

set(FILE main.cpp createLargeJSON.hpp)
set(UTILITY_FOR_UNIT_TEST ../../test/Utility/FileManagement.cpp ../../test/Utility/FileManagement.hpp)
add_executable(Benchmark ${FILE} ${UTILITY_FOR_UNIT_TEST})

target_link_libraries(Benchmark benchmark database shlwapi) 