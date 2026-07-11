cmake_minimum_required(VERSION 4.0)
project(lab5261)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab5261 main.cpp
        BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.cpp
        BibliotecaPila/funcionesPila.cpp
        BibliotecaCola/funcionesCola.cpp)
