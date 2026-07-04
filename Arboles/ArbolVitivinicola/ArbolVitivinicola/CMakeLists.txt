cmake_minimum_required(VERSION 4.0)
project(ArbolVitivinicola)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArbolVitivinicola main.cpp
        BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.cpp
        BibliotecaPila/funcionesPila.cpp)
