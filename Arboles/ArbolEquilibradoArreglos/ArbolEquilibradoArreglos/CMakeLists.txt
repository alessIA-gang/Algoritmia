cmake_minimum_required(VERSION 4.0)
project(ArbolEquilibradoArreglos)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArbolEquilibradoArreglos main.cpp
        BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.cpp
        main.cpp)
