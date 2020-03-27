cmake_minimum_required(VERSION 3.10)
project(Benchmark)
SET(CMAKE_CXX_FLAGS "-std=c++17 -O3 -Wpedantic -Wall -Wextra")
SET(CMAKE_BUILD_TYPE "RELEASE")

include(ExternalProject)
file(MAKE_DIRECTORY install)
ExternalProject_Add(googletest
  GIT_REPOSITORY    "https://github.com/google/benchmark.git"
  CMAKE_ARGS        "-DBENCHMARK_DOWNLOAD_DEPENDENCIES=ON"
  CMAKE_ARGS        "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/install"
  GIT_TAG           master
  SOURCE_DIR        "${CMAKE_BINARY_DIR}/googletest-src"
  BINARY_DIR        "${CMAKE_BINARY_DIR}/googletest-build"
)

add_library(googleBenchmark STATIC IMPORTED)
set_target_properties(googleBenchmark PROPERTIES
  IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/build/install/lib/libbenchmark.a
  INTERFACE_INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}/build/install/include
)
set(MAIN_FILE main.cpp)
add_executable(Benchmark ${MAIN_FILE})
add_dependencies(Benchmark googleBenchmark)
target_link_libraries(Benchmark googleBenchmark shlwapi)



