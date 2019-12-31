cmake_minimum_required(VERSION 3.10)
project(test)
#gtest
add_library(gtest STATIC IMPORTED) 
set_target_properties(gtest PROPERTIES
  IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/bin/libgtest.a
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/lib/include
)

#test add function
add_library(add STATIC IMPORTED) 
set_target_properties(add PROPERTIES
  IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libadd.a
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}
)

set(MAIN_FILE main.cpp)
set(ADD_TEST add_test.cpp)
add_executable(test ${MAIN_FILE} ${ADD_TEST})
target_link_libraries(test gtest add)