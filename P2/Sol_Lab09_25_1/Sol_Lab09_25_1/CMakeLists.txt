cmake_minimum_required(VERSION 4.0)
project(Sol_Lab09_25_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Sol_Lab09_25_1 main.cpp
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
