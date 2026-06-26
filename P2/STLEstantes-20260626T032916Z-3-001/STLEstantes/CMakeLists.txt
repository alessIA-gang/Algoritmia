cmake_minimum_required(VERSION 4.0)
project(STLEstantes)

set(CMAKE_CXX_STANDARD 20)

add_executable(STLEstantes main.cpp
        Biblioteca/Libros.cpp
        Biblioteca/Revista.cpp
        Biblioteca/Estante.cpp
        Biblioteca/Libreria.cpp
        Biblioteca/Libreria.h)
