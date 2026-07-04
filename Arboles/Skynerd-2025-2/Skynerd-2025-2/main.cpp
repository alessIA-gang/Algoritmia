#include <iostream>

#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
#define N 20

using namespace std;

NodoArbolBinarioBusqueda * ubicaSkynerd(NodoArbolBinarioBusqueda *raiz)
{
    /*Es un pre-orden iterativo utilizaremos una pila*/
    Pila pila;
    ElementoPila elementoPila;
    construir(pila);
    elementoPila.nodo = raiz;
    apilar(pila,elementoPila);
    while (!esPilaVacia(pila))
    {
        ElementoPila elementoPilaAux = desapilar(pila);
        cout << elementoPilaAux.nodo->elemento.flag << "-" << elementoPilaAux.nodo->elemento.numero << " ";
        if (elementoPilaAux.nodo->elemento.flag=='S')
        {
            return elementoPilaAux.nodo;
        }
        if (elementoPilaAux.nodo->derecha!=NULL)
        {
            elementoPila.nodo = elementoPilaAux.nodo->derecha;
            apilar(pila,elementoPila);
        }
        if (elementoPilaAux.nodo->izquierda!=NULL)
        {
            elementoPila.nodo = elementoPilaAux.nodo->izquierda;
            apilar(pila,elementoPila);
        }
    }
    return NULL;
}

void eliminarSkynerd(NodoArbolBinarioBusqueda *&raiz)
{
    if (raiz==NULL)
    {
        return;
    }
    Pila pila1, pila2;
    construir(pila1);
    construir(pila2);
    ElementoPila elementoPila;
    elementoPila.nodo = raiz;
    apilar(pila1,elementoPila);
    while (!esPilaVacia(pila1))
    {
        ElementoPila elementoPilaAux = desapilar(pila1);
        apilar(pila2,elementoPilaAux);
        if (elementoPilaAux.nodo->izquierda!=NULL)
        {
            elementoPila.nodo = elementoPilaAux.nodo->izquierda;
            apilar(pila1,elementoPila);
        }
        if (elementoPilaAux.nodo->derecha!=NULL)
        {
            elementoPila.nodo = elementoPilaAux.nodo->derecha;
            apilar(pila1,elementoPila);
        }
    }
    while (!esPilaVacia(pila2))
    {
        ElementoPila elementoPilaAux = desapilar(pila2);
        if (!esPilaVacia(pila2))
        {
            cout << elementoPilaAux.nodo->elemento.flag << "-" << elementoPilaAux.nodo->elemento.numero << " ";
            delete elementoPilaAux.nodo;
        }
    }
}

int main()
{
    /*Para cargar los datos*/
    int ids[N] = {100,50,150,25,75,125,175,110,140,200,105,115,130};
    char flags[N] = {'N','N','N','N','N','S','N','N','N','N','N','N','N'};
    int n=13;
    /*Generacion del arbol abb*/
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    for (int i=0; i<n; i++)
    {
        ElementoArbolBinarioBusqueda aux;
        aux.numero = ids[i];
        aux.flag = flags[i];
        insertar(arbol,aux);
    }

    /*Funcion 1 - Iterativa - Ubicar Skynerd*/
    NodoArbolBinarioBusqueda *skynerd = ubicaSkynerd(arbol.raiz);
    cout <<  endl;
    cout << "Skynerd: " << skynerd->elemento.flag << "-" << skynerd->elemento.numero;
    /*Funcion 2 - Iterativa - Eliminar Skynerd*/
    cout << endl;
    cout << "Eliminando: ";
    eliminarSkynerd(skynerd);
    return 0;
}