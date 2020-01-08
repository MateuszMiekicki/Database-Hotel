cmake_minimum_required(VERSION 3.10)
project(test)
SET(CMAKE_CXX_FLAGS "-std=c++17 -Wpedantic -Wall -Wextra")
add_definitions(-Wno-deprecated) #for date lib
#gtest
add_library(gtest STATIC IMPORTED)
set_target_properties(gtest PROPERTIES
  IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/bin/libgtest.a
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/lib/include
)

#create file exe with module dataValidate
add_executable(test ${MAIN_FILE})
target_link_libraries(test gtest )