#include <iostream>
#define N 20
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"

using namespace std;

void insertarRecursivoP1(struct NodoArbolBinarioBusqueda *& raiz, const struct ElementoArbolBinarioBusqueda & elemento){
    if(esNodoVacio(raiz))
        plantarNodoArbolBinario(raiz, nullptr, elemento, nullptr);
    else
        if(raiz->elemento.numero > elemento.numero)
            insertarRecursivoP1(raiz->izquierda, elemento);
        else
            if(raiz->elemento.numero < elemento.numero)
                insertarRecursivoP1(raiz->derecha, elemento);
            else
            {
                /*Pregunta 1*/
                raiz->elemento.cantidad = raiz->elemento.cantidad + elemento.cantidad;
            }
}

void insertarP1(struct ArbolBinarioBusqueda & arbol, const struct ElementoArbolBinarioBusqueda & elemento) {
    insertarRecursivoP1(arbol.raiz, elemento);
}

NodoArbolBinarioBusqueda *buscarRecursivoP2(struct NodoArbolBinarioBusqueda * nodo, const struct ElementoArbolBinarioBusqueda & elemento){
    if(esNodoVacio(nodo))
        return nullptr;
    if(comparaElementos(nodo->elemento.numero, elemento.numero) == 0)
        return nodo;
    if(comparaElementos(nodo->elemento.numero, elemento.numero) == 1)
        return buscarRecursivoP2(nodo->izquierda, elemento);
    else
        if(comparaElementos(nodo->elemento.numero, elemento.numero) == -1)
            return buscarRecursivoP2(nodo->derecha, elemento);
}

void imprimirReporte(const struct ArbolBinarioBusqueda &arbol)
{
    ElementoPila elemento;
    Pila pila;
    construir(pila);
    NodoArbolBinarioBusqueda *aux = arbol.raiz;
    while (aux!=nullptr || !esPilaVacia(pila))
    {
        while (aux!=nullptr)
        {
            elemento.numero = aux->elemento.numero;
            apilar(pila, elemento);
            aux = aux->derecha;
        }
        elemento = desapilar(pila);
        /*Se debe cambiar el buscarRecursivo por Iterativo*/
        ElementoArbolBinarioBusqueda elementoArbol;
        elementoArbol.numero = elemento.numero;
        NodoArbolBinarioBusqueda *nodo = buscarRecursivoP2(arbol.raiz,elementoArbol);
        imprimirNodo(nodo);
        if (!esNodoVacio(nodo->izquierda))
        {
            aux = nodo->izquierda;
        }
    }
}

int main()
{
    int lotes[N] = {2018,2011,2022,2010,2017,2019,2023,2020,2022};
    int cantidades[N] = {100,150,50,175,25,125,200,75,30};
    int n = 9;
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    /*Pregunta 1 - Generar Árbol*/
    for (int i=0; i < n; i++)
    {
        ElementoArbolBinarioBusqueda elemento;
        elemento.cantidad = cantidades[i];
        elemento.numero = lotes[i];
        insertarP1(arbol, elemento);
    }
    recorrerPreOrden(arbol);
    cout << endl << "Reporte " << endl;
    imprimirReporte(arbol);
    return 0;
}