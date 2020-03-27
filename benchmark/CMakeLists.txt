cmake_minimum_required(VERSION 3.10)
project(Benchmark)
SET(CMAKE_CXX_FLAGS "-std=c++17 -O3 -Wpedantic -Wall -Wextra")

include(ExternalProject)
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/install)
ExternalProject_Add(googletest
  GIT_REPOSITORY    https://github.com/google/benchmark.git
  CMAKE_ARGS        -DBENCHMARK_DOWNLOAD_DEPENDENCIES=ON
  CMAKE_ARGS        -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
  GIT_TAG           master
)

include_directories(${EXTERNAL_INSTALL_LOCATION}/include)   
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

set(MAIN_FILE main.cpp)
add_executable(Benchmark ${MAIN_FILE})
target_link_libraries(Benchmark benchmark shlwapi)



