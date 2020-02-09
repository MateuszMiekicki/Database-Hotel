cmake_minimum_required(VERSION 3.10)
project(hotel VERSION 1.0.0 DESCRIPTION "simple hotel management")

#test mode
option(ENABLE_TESTS "Enable tests" ON)
if (${ENABLE_TESTS})
    add_subdirectory (test)
    add_test (NAME UnitTest COMMAND test)
    enable_testing()
endif()

#flag for compilator
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE} -std=c++17 -g3 -Og -Wpedantic -Wall -Wextra -Wunused-variable -Wno-deprecated -Wcast-align -Wcast-qual -Wstrict-overflow=5 -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow  -Wsign-promo -Wstrict-null-sentinel  -Wswitch-default -Wundef -Werror -Wno-unused -Wnon-virtual-dtor -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches -Wuseless-cast -Wdouble-promotion")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_RELEASE} -std=c++17 -g3 -Og -Wpedantic -Wall -Wextra -Wunused-variable -Wno-deprecated -Wcast-align -Wcast-qual -Wstrict-overflow=5 -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow  -Wsign-promo -Wstrict-null-sentinel  -Wswitch-default -Wundef -Werror -Wno-unused -Wnon-virtual-dtor -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches -Wuseless-cast -Wdouble-promotion")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++17 -Ofast -Wpedantic -Wall -Wextra -Wunused-variable -Wno-deprecated -Wcast-align -Wcast-qual -Wstrict-overflow=5 -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow  -Wsign-promo -Wstrict-null-sentinel  -Wswitch-default -Wundef -Werror -Wno-unused -Wnon-virtual-dtor -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches -Wuseless-cast -Wdouble-promotion")

#create lib with validate module
add_library(dataValidation STATIC
    header/validationDate/Validation.hpp #interface validation class
    src/validationDate/ValidationPesel.cpp
    header/validationDate/ValidationPesel.hpp
    src/validationDate/ValidationEmail.cpp
    header/validationDate/ValidationEmail.hpp
    src/validationDate/ValidationIDCard.cpp
    header/validationDate/ValidationIDCard.hpp
    src/validationDate/ValidationPassword.cpp
    header/validationDate/ValidationPassword.hpp
)

#nlohmann json lib, only header
set(nlohmannJson lib/nlohmannjson/json.hpp)

set(MAIN_FILE src/main.cpp)
add_executable(hotel ${MAIN_FILE})
target_link_libraries(hotel)
