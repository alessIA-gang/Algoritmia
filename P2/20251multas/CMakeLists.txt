cmake_minimum_required(VERSION 4.0)
project(20251multas)

set(CMAKE_CXX_STANDARD 20)

add_executable(20251multas main.cpp
        Bibliotecas/Infraccion.cpp
        Bibliotecas/Infraccion.h
        Bibliotecas/Vehiculo.cpp
        Bibliotecas/Vehiculo.h
        Bibliotecas/Multa.cpp
        Bibliotecas/Multa.h
        Bibliotecas/Empresa.cpp
        Bibliotecas/Empresa.h
        Bibliotecas/MinisterioDeTransporte.cpp
        Bibliotecas/MinisterioDeTransporte.h)
