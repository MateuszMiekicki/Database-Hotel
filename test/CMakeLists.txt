cmake_minimum_required(VERSION 3.10)
project(test)
SET(CMAKE_CXX_FLAGS "-std=c++17 -Wpedantic -Wall -Wextra")
add_definitions(-Wno-deprecated)
#gtest
add_library(gtest STATIC IMPORTED)
set_target_properties(gtest PROPERTIES
  IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/bin/libgtest.a
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/lib/include
)

#test dataValidate
add_library(dataValidate STATIC IMPORTED)
set_target_properties(dataValidate PROPERTIES
  IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/module/libdataValidate.a
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}
)
#test account
add_library(accountLoginRegistration STATIC IMPORTED)
set_target_properties(accountLoginRegistration PROPERTIES
  IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/module/libaccountLoginRegistration.a
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}
)
#test booking
add_library(booking STATIC IMPORTED)
set_target_properties(booking PROPERTIES
  IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/module/libbooking.a
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}
)
set(MAIN_FILE main.cpp)
#set file dataValidate
set(dataValidate_EmailTest dataValidate_EmailTest.cpp)
set(dataValidate_PeselTest dataValidate_PeselTest.cpp)
set(dataValidate_PasswordTest dataValidate_PasswordTest.cpp)
set(dataValidate_IDCardValidation dataValidate_IDCardValidationTest.cpp)
#set file accountLoginRegistration
set(accountLoginRegistration_AccountRegistrationTEST accountLoginRegistration_AccountRegistrationTEST.cpp)
set(accountLoginRegistration_AddAccountTEST accountLoginRegistration_AddAccountTEST.cpp)
set(accountLoginRegistration_AccountLoginTEST accountLoginRegistration_AccountLoginTEST.cpp)
#set file booking
set(booking_GuestTEST booking_GuestTEST.cpp)
set(booking_BookingTEST booking_BookingTEST.cpp)
#create file exe with module dataValidate
add_executable(test ${MAIN_FILE} ${booking_BookingTEST} ${booking_GuestTEST} ${dataValidate_EmailTest} ${dataValidate_PeselTest} ${dataValidate_IDCardValidation} ${dataValidate_PasswordTest} ${accountLoginRegistration_AccountRegistrationTEST} ${accountLoginRegistration_AddAccountTEST} ${accountLoginRegistration_AccountLoginTEST})
target_link_libraries(test gtest dataValidate accountLoginRegistration booking)