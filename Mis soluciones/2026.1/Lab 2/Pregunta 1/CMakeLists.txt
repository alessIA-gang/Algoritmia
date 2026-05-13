cmake_minimum_required(VERSION 4.2)
project(Pregunta_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pregunta_1 main.cpp
        BibliotecaLista/Carta.h
        BibliotecaLista/Baraja.h
        BibliotecaLista/ElementoLista.h
        BibliotecaLista/funcionesLista.h
        BibliotecaLista/funcionesLista.cpp)
