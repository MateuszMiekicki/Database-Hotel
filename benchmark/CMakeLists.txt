cmake_minimum_required(VERSION 3.10)
project(benchmark)
#goole benchmark
add_library(gbench STATIC IMPORTED) 
set_target_properties(gbench PROPERTIES
  IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/bin/libbenchmark.a
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/lib/include
)

set(MAIN_FILE bench.cpp)
add_executable(benchmark ${MAIN_FILE})
target_link_libraries(benchmark gbench -lshlwapi)