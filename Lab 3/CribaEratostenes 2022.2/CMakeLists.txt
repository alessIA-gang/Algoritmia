cmake_minimum_required(VERSION 4.0)
project(CribaEratostenes)

set(CMAKE_CXX_STANDARD 20)

add_executable(CribaEratostenes main.cpp
        BibliotecaLista/ElementoLista.h
        BibliotecaLista/funcionesLista.cpp)
