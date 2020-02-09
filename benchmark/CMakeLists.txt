cmake_minimum_required(VERSION 3.10)
project(Benchamrk)
SET(CMAKE_CXX_FLAGS "-std=c++17 -Wpedantic -Wall -Wextra")


include (ExternalProject)
ExternalProject_Add (gbenchmark
    GIT_REPOSITORY "https://github.com/google/benchmark.git"

)
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_SOURCE_DIR}/gtest)
ExternalProject_Add(googleTest
    GIT_REPOSITORY "https://github.com/google/googletest.git benchmark/googletest"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)
