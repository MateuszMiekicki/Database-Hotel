cmake_minimum_required(VERSION 3.10)
project(hotel VERSION 1.0.0 DESCRIPTION "simple hotel management")

#test mode
option(ENABLE_TESTS "Enable tests" ON)
if (${ENABLE_TESTS})
    enable_testing()
endif()

#flag for compilator
#-Wstrict-overflow=5 must off becouse new version gcc not support
SET(CMAKE_CXX_FLAGS "-std=c++17 -O3 -Wpedantic -Wall -Wextra -Wunused-variable -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel  -Wswitch-default -Wundef -Werror -Wno-unused -Wnon-virtual-dtor -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches -Wuseless-cast -Wdouble-promotion")
add_definitions(-Wno-deprecated)
#accountValidata module
add_library(dataValidate STATIC
    src/dataValidate/EmailValidation.cpp
    src/dataValidate/PasswordValidation.cpp
    src/dataValidate/PeselValidation.cpp
    src/dataValidate/IDCardValidation.cpp
    header/dataValidate/EmailValidation.hpp
    header/dataValidate/PasswordValidation.hpp
    header/dataValidate/PeselValidation.hpp
    header/dataValidate/IDCardValidation.hpp
)
#account module
add_library(accountLoginRegistration STATIC
    src/accountLoginRegistration/AccountRegistration.cpp
    header/accountLoginRegistration/AccountRegistration.hpp
    src/accountLoginRegistration/AddAccount.cpp
    header/accountLoginRegistration/AddAccount.hpp
    src/accountLoginRegistration/AccountLogin.cpp
    header/accountLoginRegistration/AccountLogin.hpp
    header/accountLoginRegistration/Permissions.hpp
)
#booking module
add_library(booking STATIC
    src/booking/Guest.cpp
    header/booking/Guest.hpp
)

#nlohmann json lib, only header
set(nlohmannJson lib/nlohmannjson/json.hpp)
#nlohmann date lib, only header
set(date lib/date/date.h)

set(MAIN_FILE src/main.cpp)
add_executable(hotel ${MAIN_FILE} ${nlohmannJson} ${date})
target_link_libraries(hotel )