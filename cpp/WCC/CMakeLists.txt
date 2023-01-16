cmake_minimum_required(VERSION 3.22)

project(WCC)

add_executable(mainWCC src/mainWCC.cpp)

set_target_properties(
    mainWCC PROPERTIES
    CXX_STANDART 20
    CXX_STANDART_REQUIRED ON
    CXX_EXTENSIONS ON
)