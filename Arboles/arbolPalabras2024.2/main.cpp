/* 
 * Archivo:   main.cpp
 * Autor: Alessia Gastello 
 */

#include <iostream>
#include "ArbolBinarioPalabras.h"
using namespace std;

int main() {
    ArbolBinario arbol;

    construir(arbol);
    construirArbolFigura1(arbol);

    imprimirPalabras(arbol);

    destruirArbolBinario(arbol);

    return 0;
}
