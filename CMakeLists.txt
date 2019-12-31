cmake_minimum_required(VERSION 3.10)
project(hotel VERSION 1.0.0 DESCRIPTION "simple hotel management")
option(ENABLE_TESTS "Enable tests" ON)
if (${ENABLE_TESTS})
    enable_testing()
endif()

add_library(accountDataValidate STATIC
    src/accountDataValidate/EmailValidation.cpp
    src/accountDataValidate/PasswordValidation.cpp
    src/accountDataValidate/PeselValidation.cpp
    header/accountDataValidate/iValidation.hpp
    header/accountDataValidate/EmailValidation.hpp
    header/accountDataValidate/PasswordValidation.hpp
    header/accountDataValidate/PeselValidation.hpp
)
set(MAIN_FILE src/main.cpp)
add_executable(hotel ${MAIN_FILE})
target_link_libraries(hotel accountDataValidate)