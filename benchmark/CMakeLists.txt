cmake_minimum_required(VERSION 3.10)
project(Benchmark)
SET(CMAKE_CXX_FLAGS_RELEASE "-std=c++17 -O3 -Wpedantic -Wall -Wextra")

include(ExternalProject)
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/install)
ExternalProject_Add(googletest
  GIT_REPOSITORY    https://github.com/google/benchmark.git
  CMAKE_ARGS        -DCMAKE_BUILD_TYPE=Release
  CMAKE_ARGS        -DBENCHMARK_DOWNLOAD_DEPENDENCIES=ON
  CMAKE_ARGS        -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
  GIT_TAG           master
)

if(JSON_FIND) 
    add_subdirectory(JSON)
endif()