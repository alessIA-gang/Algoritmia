cmake_minimum_required(VERSION 4.1)
project(Submarino)

set(CMAKE_CXX_STANDARD 20)

add_executable(Submarino main.cpp
        BibliotecaPila/ElementoPila.h
        BibliotecaPila/funcionesPila.cpp
        BibliotecaPila/funcionesPila.h
        BibliotecaPila/NodoPila.h
        BibliotecaPila/Pila.h)
