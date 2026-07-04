//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal 

#ifndef PILA_ELEMENTOPILA_H
#define PILA_ELEMENTOPILA_H
#include "NodoPila.h"

struct NodoArbolBinarioBusqueda;

struct ElementoPila{
    int numero;
    int tipo;
    NodoArbolBinarioBusqueda* nodo;
};
#endif //PILA_ELEMENTOPILA_H