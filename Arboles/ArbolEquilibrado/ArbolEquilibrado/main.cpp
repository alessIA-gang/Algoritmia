#include <iostream>
#define N 20

#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/ElementoArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
using namespace std;

NodoArbolBinarioBusqueda *crearNodo(ElementoArbolBinarioBusqueda elemento)
{
    NodoArbolBinarioBusqueda *nodo = new NodoArbolBinarioBusqueda;
    nodo->elemento = elemento;
    nodo->izquierda = NULL;
    nodo->derecha = NULL;
    return nodo;
}

int calcularFactorEquilibrio(NodoArbolBinarioBusqueda *nodo)
{
    if (nodo==NULL)
    {
        return 0;
    }
    int alturaIzq = alturaRecursivo(nodo->izquierda);
    int alturaDer = alturaRecursivo(nodo->derecha);
    return (alturaIzq-alturaDer);
}

NodoArbolBinarioBusqueda *rotarDerecha(NodoArbolBinarioBusqueda *nodo)
{
    NodoArbolBinarioBusqueda *aux = nodo->izquierda;
    NodoArbolBinarioBusqueda *aux2 = aux->derecha;
    aux->derecha = nodo;
    nodo->izquierda = aux2;
    return aux;
}

NodoArbolBinarioBusqueda *rotarIzquierda(NodoArbolBinarioBusqueda *nodo)
{
    NodoArbolBinarioBusqueda *aux = nodo->derecha;
    NodoArbolBinarioBusqueda *aux2 = aux->izquierda;
    aux->izquierda = nodo;
    nodo->derecha = aux2;
    return aux;
}

NodoArbolBinarioBusqueda *insertarAVLRecursivo(NodoArbolBinarioBusqueda *nodo, ElementoArbolBinarioBusqueda elemento)
{
    /*Insertar en un arbol binario de busqueda*/
    if (nodo == NULL)
    {
        NodoArbolBinarioBusqueda *nodo = crearNodo(elemento);
        return nodo;
    }
    if (elemento.numero<nodo->elemento.numero)
    {
        nodo->izquierda = insertarAVLRecursivo(nodo->izquierda, elemento);
    }
    else
    {
        if (elemento.numero>nodo->elemento.numero)
        {
            nodo->derecha = insertarAVLRecursivo(nodo->derecha, elemento);
        }
        else
        {
            return nodo;
        }
    }
    /*Aqui se podría dar el desequilibrio*/
    int factorEquilibrio = calcularFactorEquilibrio(nodo);
    /*Analicemos el desequilibrio por izquierda*/
    /*Caso 1 - Izquierda-Izquierda*/
    if (factorEquilibrio>1 && elemento.numero<nodo->izquierda->elemento.numero)
    {
        return rotarDerecha(nodo);
    }
    /*Caso 2 - Izquierda-Derecha*/
    if (factorEquilibrio>1 && elemento.numero>nodo->izquierda->elemento.numero)
    {
        nodo->izquierda = rotarIzquierda(nodo->izquierda);
        return rotarDerecha(nodo);
    }
    /*Analicemos el desequilibrio por derecha*/
    /*Caso 3 - Derecha-Derecha*/
    if (factorEquilibrio<-1 && elemento.numero>nodo->derecha->elemento.numero)
    {
        return rotarIzquierda(nodo);
    }
    /*Caso 4 - Derecha-Izquierda*/
    if (factorEquilibrio<-1 && elemento.numero<nodo->derecha->elemento.numero)
    {
        nodo->derecha = rotarDerecha(nodo->derecha);
        return rotarIzquierda(nodo);
    }
    return nodo;
}

void insertarAVL(struct ArbolBinarioBusqueda &arbol, ElementoArbolBinarioBusqueda elemento)
{
    arbol.raiz = insertarAVLRecursivo(arbol.raiz, elemento);
}

struct NodoArbolBinarioBusqueda * maximoArbol(struct NodoArbolBinarioBusqueda * nodo){
    if(esNodoVacio(nodo))
        return nodo;
    if(esNodoVacio(nodo->derecha))
        return nodo;
    return maximoArbol(nodo->derecha);
}

void equilibraArbolRecursivo(NodoArbolBinarioBusqueda * &nodo)
{
    if (nodo==NULL)
    {
        return;
    }
    NodoArbolBinarioBusqueda *nuevaRaiz;
    while (1)
    {
        NodoArbolBinarioBusqueda *aux = nodo;
        int alturaIzquierda = alturaRecursivo(aux->izquierda);
        int alturaDerecha = alturaRecursivo(aux->derecha);
        int factorBalance = alturaIzquierda - alturaDerecha;
        if (factorBalance>1)
        {
            nuevaRaiz = maximoArbol(aux->izquierda);
        }
        else
        {
            if (factorBalance<-1)
            {
                nuevaRaiz = minimoArbol(aux->derecha);
            }
            else
            {
                break;
            }
        }
        ElementoArbolBinarioBusqueda elementoAux = nuevaRaiz->elemento;
        eliminarRecursivo(nodo, elementoAux);
        ElementoArbolBinarioBusqueda elementoAux2 = aux->elemento;
        aux->elemento = elementoAux;
        insertarRecursivo(nodo, elementoAux2);
    }
    equilibraArbolRecursivo(nodo->izquierda);
    equilibraArbolRecursivo(nodo->derecha);
}

void equilibraArbol(struct ArbolBinarioBusqueda &arbol)
{
    equilibraArbolRecursivo(arbol.raiz);
}


int main()
{
    ArbolBinarioBusqueda arbol, arbol2;
    construir(arbol);
    construir(arbol2);
    int arreglo[N] = {15,19,20,25,14,26,32,40,18,12};
    int n = 9;
    for (int i=0; i<n; i++)
    {
        ElementoArbolBinarioBusqueda elemento;
        elemento.numero = arreglo[i];
        cout << "Insertando elemento: " << arreglo[i] << endl;
        insertarAVL(arbol, elemento);
        cout << "Es equilibrado: " << esEquilibrado(arbol) << endl;
        recorrerPreOrden(arbol);
        insertar(arbol2, elemento);
        cout << endl;
    }
    recorrerPreOrden(arbol2);
    cout << endl;
    cout << "Arbol 2 es equilibrado?: " << esEquilibrado(arbol2);
    equilibraArbol(arbol2);
    recorrerPreOrden(arbol2);
    cout << endl;
    cout << "Arbol 2 es equilibrado?: " << esEquilibrado(arbol2);
    return 0;
}