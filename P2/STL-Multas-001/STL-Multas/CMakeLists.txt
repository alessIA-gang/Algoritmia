cmake_minimum_required(VERSION 4.0)
project(STL_Multas)

set(CMAKE_CXX_STANDARD 20)

add_executable(STL_Multas main.cpp
        Biblioteca/Infraccion.cpp
        Biblioteca/Infraccion.h
        Biblioteca/Vehiculo.cpp
        Biblioteca/Vehiculo.h
        Biblioteca/Multa.cpp
        Biblioteca/Multa.h
        Biblioteca/Empresa.cpp
        Biblioteca/Empresa.h
        Biblioteca/MinisterioDeTransporte.cpp
        Biblioteca/MinisterioDeTransporte.h)
