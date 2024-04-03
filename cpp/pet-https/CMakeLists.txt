cmake_minimum_required(VERSION 3.22)

project(pet-https)

add_executable(
    mainHTTPS src/mainHTTPS_U.cpp src/mainHTTPS_A.cpp src/mainServer.cpp)

set_target_properties(
    mainHTTPS PROPERTIES
    CXX_STANDART 20
    CXX_STANDART_REQUIRED ON
    CXX_EXTENSIONS ON
)