cmake_minimum_required(VERSION 3.10)
project(test)
SET(CMAKE_CXX_FLAGS "-std=c++17 -Wpedantic -Wall -Wextra")

#gtest
add_library(gtest STATIC IMPORTED) 
set_target_properties(gtest PROPERTIES
  IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/bin/libgtest.a
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/lib/include
)

#test accountDataValidate
add_library(accountDataValidate STATIC IMPORTED) 
set_target_properties(accountDataValidate PROPERTIES
  IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/module/libaccountDataValidate.a
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}
)

set(MAIN_FILE main.cpp)
set(accountDataValidate_EmailTest accountDataValidate_EmailTest.cpp)
set(accountDataValidate_PeselTest accountDataValidate_PeselTest.cpp)
add_executable(test ${MAIN_FILE} ${accountDataValidate_PeselTest})
target_link_libraries(test gtest accountDataValidate)