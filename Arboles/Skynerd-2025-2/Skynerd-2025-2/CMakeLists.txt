cmake_minimum_required(VERSION 4.0)
project(Skynerd_2025_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Skynerd_2025_2 main.cpp
        BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.cpp
        BibliotecaPila/funcionesPila.cpp)
