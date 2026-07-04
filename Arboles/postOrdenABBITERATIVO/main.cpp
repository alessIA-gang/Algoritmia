/* 
 * Archivo:   main.cpp
 * Autor: Alessia Gastello 
 */

#include <cstdlib>
#include <iostream>
#include "ArbolBB.h"
#include "Pila.h"
#include "funcionesABB.h"
#include "funcionesAB.h"
#include "funcionesPila.h"

using namespace std;


NodoArbol * buscarNodo(NodoArbol *raiz,int elemento){
    if (raiz->elemento==elemento){
        return raiz;
    }
    if (raiz->elemento<elemento){
        return buscarNodo(raiz->derecha,elemento);
    }
    else{
        return buscarNodo(raiz->izquierda,elemento);
    }
}

void recorrerPostOrdenIterativo(ArbolBinarioBusqueda arbol){
    int valor=0;
    Pila pila;
    NodoArbol * raiz;
    construir(pila);

    if (esArbolVacio(arbol.arbolBinario))
        return ;
    raiz = arbol.arbolBinario.raiz;
    while (1){
        /*Aqui estamos apilando todos los nodos izquierdos*/
        while (raiz){
            apilar(pila,raiz->elemento);
            raiz = raiz->izquierda;
        }
        int superior = cima(pila);
        raiz = buscarNodo(arbol.arbolBinario.raiz,superior);
        if (raiz->derecha && raiz->derecha->elemento != valor){
            raiz = raiz->derecha;
        }
        else{
            valor = desapilar(pila);
            cout << valor << " ";
            raiz = nullptr; /*Para no entrar al while de izquierda al regresar*/
        }
        if (esPilaVacia(pila)){
            break;
        }
    }
}

int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    insertar(arbol,12);
    insertar(arbol,7);
    insertar(arbol,20);
    insertar(arbol,3);
    insertar(arbol,8);
    insertar(arbol,2);
    insertar(arbol,4);
    insertar(arbol,1);
    insertar(arbol,15);
    insertar(arbol,13);
    insertar(arbol,30);
    insertar(arbol,35);
    cout << "De forma Recursiva: " << endl;
    recorrerPostOrden(arbol.arbolBinario);
    cout << endl;
    cout << "De forma Iterativa: " << endl;
    recorrerPostOrdenIterativo(arbol);
    return 0;
}

