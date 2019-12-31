cmake_minimum_required(VERSION 3.10)
project(hotel VERSION 1.0.0 DESCRIPTION "simple hotel management")
option(ENABLE_TESTS "Enable tests" ON)
if (${ENABLE_TESTS})
    enable_testing()
endif()

add_library(add STATIC
    src/add.cpp
    header/add.hpp
)
set(MAIN_FILE src/main.cpp)
add_executable(hotel ${MAIN_FILE})
target_link_libraries(hotel add)