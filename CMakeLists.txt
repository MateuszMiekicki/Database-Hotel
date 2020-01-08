cmake_minimum_required(VERSION 3.10)
project(hotel VERSION 1.0.0 DESCRIPTION "simple hotel management")

#test mode
option(ENABLE_TESTS "Enable tests" ON)
if (${ENABLE_TESTS})
    enable_testing()
endif()

#flag for compilator
SET(CMAKE_CXX_FLAGS "-std=c++17 -O3 -Wpedantic -Wall -Wextra -Wunused-variable -Wno-deprecated -Wcast-align -Wcast-qual -Wstrict-overflow=5 -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow  -Wsign-promo -Wstrict-null-sentinel  -Wswitch-default -Wundef -Werror -Wno-unused -Wnon-virtual-dtor -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches -Wuseless-cast -Wdouble-promotion")
add_definitions(-Wno-deprecated) #for date lib

#nlohmann json lib, only header
set(nlohmannJson lib/nlohmannjson/json.hpp)
#nlohmann date lib, only header
set(date lib/date/date.h)

set(MAIN_FILE src/main.cpp)
add_executable(hotel ${MAIN_FILE} ${nlohmannJson} ${date})
target_link_libraries(hotel)