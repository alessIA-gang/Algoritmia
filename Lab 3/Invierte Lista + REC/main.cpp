#include <iostream>

#include "BibliotecaLista/funcionesLista.h"
#include "BibliotecaLista/Lista.h"

using namespace std;

void invertirLista(struct Lista & listaTAD) {
    struct NodoLista * ultimo;
    struct NodoLista * anteriorUltimo;

    struct NodoLista * ultimoNodo=obtenerUltimoNodo(listaTAD);//para "guardar" el último nodo que se convertirá en la nueva cabeza de la Lista
    ultimo=obtenerUltimoNodo(listaTAD);

    while (true) {//O(n)
        anteriorUltimo=obtenerNodoAnterior(listaTAD, ultimo->elemento);//O(n)
        if (anteriorUltimo==nullptr) break;
        ultimo->siguiente=anteriorUltimo;
        anteriorUltimo->siguiente=nullptr;
        ultimo=anteriorUltimo;

    }
    listaTAD.inicio=ultimoNodo;
}

void invertirListaRec(struct Lista & listaTAD, int n) {
    struct NodoLista * ultimo;
    struct NodoLista * anteriorUltimo;
    //CASO BASE
    if (n<=1)
        return;
    //PARTE RECURSIVA
    ultimo=obtenerUltimoNodo(listaTAD);
    anteriorUltimo=obtenerNodoAnterior(listaTAD, ultimo->elemento);//O(n)
    ultimo->siguiente=anteriorUltimo;
    anteriorUltimo->siguiente=nullptr;
    invertirListaRec(listaTAD, n-1);

    listaTAD.inicio=ultimo;
}


int main() {
    struct ElementoLista elemento;
    struct Lista listaInicio;
    construir(listaInicio);//"inicializamos" la Lista
    cout << "La lista esta vacia: " << esListaVacia(listaInicio) <<endl;


    elemento.codigo=5;
    insertarAlFinal(listaInicio, elemento);
    elemento.codigo=8;
    insertarAlFinal(listaInicio, elemento);
    elemento.codigo=10;
    insertarAlFinal(listaInicio, elemento);
    elemento.codigo=11;
    insertarAlFinal(listaInicio, elemento);
    elemento.codigo=15;
    insertarAlFinal(listaInicio, elemento);

    imprimir(listaInicio);

    //invertirLista(listaInicio);

    invertirListaRec(listaInicio, listaInicio.longitud);



    imprimir(listaInicio);
    return 0;
}