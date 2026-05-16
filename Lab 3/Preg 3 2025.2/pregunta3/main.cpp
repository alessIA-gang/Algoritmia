#include <iostream>
#include "BibliotecaLista/funcionesLista.h"
#include "BibliotecaLista/ElementoLista.h"
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/NodoLista.h"
using namespace std;

void reordenaLista(Lista &lista) {
    NodoLista *iniA = nullptr, *finA = nullptr,
            *iniB = nullptr, *finB = nullptr,
            *iniC = nullptr, *finC = nullptr;

    NodoLista *recorrido = lista.inicio;

    // Paso 1: Separar en 3 sublistas manteniendo orden original
    while (recorrido != nullptr) {
        NodoLista *siguiente = recorrido->siguiente; // guardar antes de cortar
        recorrido->siguiente = nullptr; // desconectar nodo

        if (recorrido->elemento.tipo_de_produccion == 'A') {
            if (iniA == nullptr) {
                iniA = recorrido; // primer A
                finA = recorrido;
            } else {
                finA->siguiente = recorrido; // encadenar al final de A
                finA = recorrido;
            }
        } else if (recorrido->elemento.tipo_de_produccion == 'B') {
            if (iniB == nullptr) {
                iniB = recorrido;
                finB = recorrido;
            } else {
                finB->siguiente = recorrido;
                finB = recorrido;
            }
        } else if (recorrido->elemento.tipo_de_produccion == 'C') {
            if (iniC == nullptr) {
                iniC = recorrido;
                finC = recorrido;
            } else {
                finC->siguiente = recorrido;
                finC = recorrido;
            }
        }

        recorrido = siguiente;
    }


    // AHORA INTERCALAMOS
    // Usamos un puntero auxiliar que va "tejiendo" la lista final
    NodoLista* resultado = nullptr;
    NodoLista* finalResultado = nullptr;

    while (iniA != nullptr || iniB != nullptr || iniC != nullptr) {
        // Tomar uno de A
        if (iniA != nullptr) {
            NodoLista* tmp = iniA;
            iniA = iniA->siguiente;
            tmp->siguiente = nullptr;
            if (resultado == nullptr) resultado = tmp;
            else finalResultado->siguiente = tmp;
            finalResultado = tmp;
        }
        // Tomar uno de B
        if (iniB != nullptr) {
            NodoLista* tmp = iniB;
            iniB = iniB->siguiente;
            tmp->siguiente = nullptr;
            if (resultado == nullptr) resultado = tmp;
            else finalResultado->siguiente = tmp;
            finalResultado = tmp;
        }
        // Tomar uno de C
        if (iniC != nullptr) {
            NodoLista* tmp = iniC;
            iniC = iniC->siguiente;
            tmp->siguiente = nullptr;
            if (resultado == nullptr) resultado = tmp;
            else finalResultado->siguiente = tmp;
            finalResultado = tmp;
        }
    }

    lista.inicio = resultado;
    // Si tu Lista también tiene un puntero fin:
    lista.fin = finalResultado;
}

void colocarElementos(Lista &lista) {
    ElementoLista elemento;
    elemento.id = 3;
    elemento.tipo_de_produccion = 'C';
    insertarAlFinal(lista, elemento);
    elemento.id = 9;
    elemento.tipo_de_produccion = 'A';
    insertarAlFinal(lista, elemento);
    elemento.id = 8;
    elemento.tipo_de_produccion = 'C';
    insertarAlFinal(lista, elemento);
    elemento.id = 4;
    elemento.tipo_de_produccion = 'A';
    insertarAlFinal(lista, elemento);
    // elemento.id = 6;
    // elemento.tipo_de_produccion = 'B';
    // insertarAlFinal(lista, elemento);
}

int main() {
    Lista lista;
    construir(lista);
    colocarElementos(lista);
    cout << "Entrada:";
    imprimir(lista);
    // cout<<lista.fin->elemento.id<<lista.fin->elemento.tipo_de_produccion<<endl;
    reordenaLista(lista);
    cout << "Salida:";
    imprimir(lista);
    return 0;
}
