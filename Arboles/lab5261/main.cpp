/* 
 * Archivo:   main.cpp
 * Autor: Alessia Gastello 
 */

#include <iostream>
#include <iomanip>
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaPila/Pila.h"
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaPila/funcionesPila.h"
using namespace std;

NodoArbolBinarioBusqueda *buscaRaiz(NodoArbolBinarioBusqueda *raiz, int valor) {
    while (raiz != nullptr) {
        if (raiz->elemento.numero == valor) {
            return raiz;
        }
        if (raiz->elemento.numero > valor) {
            raiz = raiz->izquierda;
        } else raiz = raiz->derecha;
    }
    return nullptr;
}

void zigzag(ArbolBinarioBusqueda &arbol, Pila pila, Cola cola) {
    bool izquierdaDerecha = true;
    int separadorNivel = -1;
    encolar(cola, arbol.raiz->elemento.numero);
    encolar(cola, separadorNivel);
    NodoArbolBinarioBusqueda *nodo;
    while (!esColaVacia(cola)) {
        int valor = desencolar(cola);
        apilar(pila, valor);
        if (valor == separadorNivel) {
            if (!esColaVacia(cola))
                encolar(cola, separadorNivel);
        } else {
            nodo = buscaRaiz(arbol.raiz, valor);
            if (nodo) {
                if (nodo->izquierda)encolar(cola, nodo->izquierda->elemento.numero);
                if (nodo->derecha)encolar(cola, nodo->derecha->elemento.numero);
            }
        }
    }
    int nivel = 1;
    while (!esPilaVacia(pila)) {
        encolar(cola, desapilar(pila));
    }

    while (!esColaVacia(cola)) {
        apilar(pila, desencolar(cola));

    }

    cout << "Nivel 1:" << endl;
    while (!esPilaVacia(pila)) {
        int numero=desapilar(pila);
        if ( numero== separadorNivel) {
            if (!izquierdaDerecha) {
                if (!esColaVacia(cola)) {
                    cout<<desencolar(cola)<<" ";
                }
            }
            cout << endl;
            if (!esPilaVacia(pila)) {
                izquierdaDerecha = !izquierdaDerecha;
                nivel += 1;
                cout << "Nivel " << nivel << ":" << endl;
            }
        } else {
            if (izquierdaDerecha)
            cout << numero << " ";
            else encolar(cola, numero);
        }
    }
}

int main(int argc, char **argv) {
    ArbolBinarioBusqueda arbol;
    Pila pila;
    Cola cola;
    construir(arbol);
    construir(pila);
    construir(cola);
    insertar(arbol, {9});
    insertar(arbol, {4});
    insertar(arbol, {14});
    insertar(arbol, {1});
    insertar(arbol, {6});
    insertar(arbol, {11});
    insertar(arbol, {16});
    insertar(arbol, {19});

    // recorrerEnOrden(arbol);

    zigzag(arbol, pila, cola);
    return 0;
}
