cmake_minimum_required(VERSION 4.0)
project(arbolPalabras)

set(CMAKE_CXX_STANDARD 20)

add_executable(arbolPalabras main.cpp
        ArbolBinarioPalabras.h
        funcionesArbolBinarioPalabras.cpp)
