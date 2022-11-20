cmake_minimum_required(VERSION 3.22)

project(SCA)

add_executable(mainSCA src/main.cpp)

set_target_properties(
    mainSCA PROPERTIES
    CXX_STANDART 20
    CXX_STANDART_REQUIRED ON
    CXX_EXTENSIONS ON
)