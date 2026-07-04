#ifndef ARBOLBINARIOPALABRAS_H
#define ARBOLBINARIOPALABRAS_H

#include <string>

struct ElementoArbolBinario {
    char letra;
};

struct NodoArbolBinario {
    ElementoArbolBinario elemento;
    NodoArbolBinario * izquierda;
    NodoArbolBinario * derecha;
};

struct ArbolBinario {
    NodoArbolBinario * raiz;
};

/*FUNCIONES GENERALES DE ARBOL BINARIO*/
void construir(ArbolBinario & arbol);
bool esArbolVacio(const ArbolBinario & arbol);
bool esNodoVacio(const NodoArbolBinario * nodo);
void plantarNodoArbolBinario(NodoArbolBinario *& nodo, NodoArbolBinario * izquierda,
                              const ElementoArbolBinario & elemento, NodoArbolBinario * derecha);

/*CONSTRUCCION DEL ARBOL DE LA FIGURA 1*/
void construirArbolFigura1(ArbolBinario & arbol);

/*IMPRESION DE LAS PALABRAS (PARTE B)*/
void imprimirPalabras(const ArbolBinario & arbol);
void imprimirPalabrasRecursivo(NodoArbolBinario * nodo, std::string prefijo);

/*DESTRUCCION DEL ARBOL*/
void destruirArbolBinario(ArbolBinario & arbol);
void destruirRecursivo(NodoArbolBinario * nodo);

#endif
