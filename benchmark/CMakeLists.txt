cmake_minimum_required(VERSION 3.10)
project(Benchmark)
SET(CMAKE_CXX_FLAGS "-std=c++17 -Wpedantic -Wall -Wextra")
SET(CMAKE_BUILD_TYPE "RELEASE")
#google benchmark lib include to project
add_library(googleBenchmark STATIC IMPORTED)
include_directories(${PROJECT_SOURCE_DIR}/benchmark/include)   
link_directories(${PROJECT_SOURCE_DIR}/benchmark/build/src/)

#set(VALIDATE_DATE ValidationPesel.cpp ValidationEmail.cpp ValidationIDCard.cpp ValidationPassword.cpp) ${VALIDATE_DATE}
set(MAIN_FILE main.cpp)
add_executable(Benchmark ${MAIN_FILE})
add_dependencies(Benchmark googleBenchmark)
target_link_libraries(Benchmark benchmark shlwapi)