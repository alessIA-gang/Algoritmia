#include <iostream>
#include "BibliotecaLista/funcionesLista.h"
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/NodoLista.h"
#include "BibliotecaLista/ElementoLista.h"
using namespace std;

void reordenar(Lista &lista) {
    NodoLista *iniA, *finA, *iniB, *finB, *iniC, *recorrido = lista.inicio;
    iniA, finA, iniB, finB, iniC = nullptr;
    while (recorrido) {
        if (recorrido->elemento.tipoProduccion == 'A') {

        } else if (recorrido->elemento.tipoProduccion == 'B') {

        } else if (recorrido->elemento.tipoProduccion == 'C') {

        }
    }
    recorrido = recorrido->siguiente;
}

}

int main() {
    Lista lista;
    construir(lista);
    ElementoLista elemento;
    elemento.id = 7;
    elemento.tipoProduccion = 'B';
    insertarAlFinal(lista, elemento);
    elemento.id = 2;
    elemento.tipoProduccion = 'A';
    insertarAlFinal(lista, elemento);
    elemento.id = 9;
    elemento.tipoProduccion = 'C';
    insertarAlFinal(lista, elemento);
    elemento.id = 5;
    elemento.tipoProduccion = 'A';
    insertarAlFinal(lista, elemento);
    elemento.id = 6;
    elemento.tipoProduccion = 'B';
    insertarAlFinal(lista, elemento);
    cout << "Entrada: ";
    imprimir(lista);
    cout << endl;
    // cout<<lista.fin->elemento.id<<lista.fin->elemento.tipoProduccion<<endl;

    reordenar(lista);
    cout << "Salida: ";
    imprimir(lista);
    cout << endl;

    return 0;
}
