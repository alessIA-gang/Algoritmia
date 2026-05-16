cmake_minimum_required(VERSION 4.0)
project(BadSunny)

set(CMAKE_CXX_STANDARD 20)

add_executable(BadSunny main.cpp
        BibliotecaPila/ElementoPila.h
        BibliotecaPila/funcionesPila.cpp)
