cmake_minimum_required(VERSION 3.10)
project(hotel VERSION 1.0.0 DESCRIPTION "simple hotel management")

#test mode
option(ENABLE_TESTS "Enable tests" ON)
if (${ENABLE_TESTS})
    enable_testing()
endif()

#flag for compilator
SET(CMAKE_CXX_FLAGS "-std=c++17 -O3 -Wpedantic -Wall -Wextra -Wunused-variable -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused -Wnon-virtual-dtor -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches -Wuseless-cast -Wdouble-promotion")
#accountValidata module
add_library(accountDataValidate STATIC
    src/accountDataValidate/EmailValidation.cpp
    src/accountDataValidate/PasswordValidation.cpp
    src/accountDataValidate/PeselValidation.cpp
    header/accountDataValidate/EmailValidation.hpp
    header/accountDataValidate/PasswordValidation.hpp
    header/accountDataValidate/PeselValidation.hpp
)
#account module
add_library(accountRegistration STATIC
    src/account/AccountRegistration.cpp
    header/account/AccountRegistration.hpp
)


set(MAIN_FILE src/main.cpp)
add_executable(hotel ${MAIN_FILE})
target_link_libraries(hotel accountDataValidate accountRegistration)