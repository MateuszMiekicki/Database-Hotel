cmake_minimum_required(VERSION 3.10)
project(UnitTest)
SET(CMAKE_CXX_FLAGS "-std=c++17 -Wpedantic -Wall -Wextra")

#gtest
include(ExternalProject)
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_SOURCE_DIR}/test/gtest)
ExternalProject_Add(googleTest
    GIT_REPOSITORY https://github.com/google/googleTest
    GIT_TAG "v1.10.x"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)
include_directories(${EXTERNAL_INSTALL_LOCATION}/include)   
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

#file and lib with validate date content 
add_library(dataValidation STATIC IMPORTED)
set_target_properties(dataValidation PROPERTIES
  IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/../build/libdataValidation.a
  INTERFACE_INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}/../header/
)

#file and lib with validate date content 
add_library(guest STATIC IMPORTED)
set_target_properties(guest PROPERTIES
  IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/../build/libguest.a
  INTERFACE_INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}/../header/
)

#file and lib with staff content 
add_library(staff STATIC IMPORTED)
set_target_properties(staff PROPERTIES
  IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/../build/libstaff.a
  INTERFACE_INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}/../header/
)

#file and lib with database content, interface and all avilable version 
add_library(database STATIC IMPORTED)
set_target_properties(database PROPERTIES
  IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/../build/libdatabase.a
  INTERFACE_INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}/../header/
)

set(UTILITY_FOR_UNIT_TEST Utility/FileManagement.cpp 
                          Utility/FileManagement.hpp)
set(MAIN_FILE main.cpp)
set(VALIDATE_DATE validationDate/ValidationPesel.cpp 
                  validationDate/ValidationEmail.cpp 
                  validationDate/ValidationIDCard.cpp 
                  validationDate/ValidationPassword.cpp)
set(GUEST guest/Guest.cpp)
set(STAFF staff/Staff.cpp)
set(DATABASE database/JSON/JSON_connect.cpp
             database/JSON/JSON_disconnect.cpp
             database/JSON/JSON_find.cpp
             database/JSON/JSON_getDataWithDB.cpp)

add_executable(UnitTests ${UTILITY_FOR_UNIT_TEST} ${MAIN_FILE} ${VALIDATE_DATE} ${GUEST} ${STAFF} ${DATABASE})
add_dependencies(UnitTests googleTest)
target_link_libraries(UnitTests gtest gtest_main dataValidation guest staff database) 