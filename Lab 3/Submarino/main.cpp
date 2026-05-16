#include <iostream>
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
using namespace std;
void Submarino(struct Pila &pila, char orden[], int n) {
    int i = 0;
    int nivel=2;
    while (i < n) {
        if (esPilaVacia(pila))//En la primera iteración
            apilar(pila,{1});

        if (orden[i] == 'S') {//"suelto" todos los niveles acumulados
            while (!esPilaVacia(pila)) {
                cout<<desapilar(pila).numero<<" ";
            }
            apilar (pila, {nivel});
            nivel++;

        }else { //si es "B", no muestro el movimiento, solo apilo
            apilar(pila,{nivel});
            nivel++;
        }
        i++;
    }
    while (!esPilaVacia(pila)) {
        cout<<desapilar(pila).numero<<" ";
    }
}

int main() {
    struct Pila pila;
    construir (pila);

    //int n=7;
    //char orden[n]={'S','B','S','B','B','S','S'};
    //int n=5;
    //char orden[n]={'S','S','S','B','S'};
    int n=3;
    char orden[n]={'B','B','S'};
    Submarino(pila, orden, n);
    return 0;
}