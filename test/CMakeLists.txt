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
#test account
add_library(accountLoginRegistration STATIC IMPORTED)
set_target_properties(accountLoginRegistration PROPERTIES
  IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/module/libaccountLoginRegistration.a
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}
)

set(MAIN_FILE main.cpp)
#set file accountDataValidate
set(accountDataValidate_EmailTest accountDataValidate_EmailTest.cpp)
set(accountDataValidate_PeselTest accountDataValidate_PeselTest.cpp)
set(accountDataValidate_PasswordTest accountDataValidate_PasswordTest.cpp)
#set file accountLoginRegistration
set(accountLoginRegistration_AccountRegistrationTEST accountLoginRegistration_AccountRegistrationTEST.cpp)
set(accountLoginRegistration_AddAccountTEST accountLoginRegistration_AddAccountTEST.cpp)
#create file exe with module accountDataValidate
add_executable(test ${MAIN_FILE} ${accountDataValidate_EmailTest} ${accountDataValidate_PeselTest} ${accountDataValidate_PasswordTest} ${accountLoginRegistration_AccountRegistrationTEST} ${accountLoginRegistration_AddAccountTEST})
target_link_libraries(test gtest accountDataValidate accountLoginRegistration)