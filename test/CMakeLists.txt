cmake_minimum_required(VERSION 3.10)
project(UnitTest)
SET(CMAKE_CXX_FLAGS "-std=c++17 -Wpedantic -Wall -Wextra")

#gtest
include(ExternalProject)
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_SOURCE_DIR}/gtest)
ExternalProject_Add(googletest
    GIT_REPOSITORY https://github.com/google/googletest
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)
include_directories(${EXTERNAL_INSTALL_LOCATION}/include)   
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

#create file exe with module dataValidate
set(MAIN_FILE main.cpp)
#file and lib with validate date content 
add_library(dataValidation STATIC IMPORTED)
set_target_properties(dataValidation PROPERTIES
  IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/../build/libdataValidation.a
  INTERFACE_INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}/../header/
)
set(VALIDATE_DATE validatePesel.cpp)

add_executable(UnitTests ${MAIN_FILE} ${VALIDATE_DATE})
add_dependencies(UnitTests googletest)
target_link_libraries(UnitTests gtest gtest_main dataValidation)