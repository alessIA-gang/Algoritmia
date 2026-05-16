#include <iostream>
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"

using namespace  std;
void PasaPilaRec(struct Pila & pila,struct Pila & pila2) {
    //CASO BASE
    if (esPilaVacia(pila)) return;
    //PARTE RECURSIVA
    int valor=desapilar(pila).numero;
    PasaPilaRec(pila,pila2);
    apilar(pila2,{valor});
}
void PasaPila(struct Pila & pila,struct Pila & pila2) {
    int valor, aux;
    int n;//#elementos que apilo en pila2
    while (!esPilaVacia(pila)) {
        valor=desapilar(pila).numero;
        n=0;
        while (!esPilaVacia(pila)) {
            apilar(pila2,{valor});
            n++;
            valor=desapilar(pila).numero;
        }//me quedo con el último elemento de la pila.
        while (n>0) {
            aux=desapilar(pila2).numero;
            apilar(pila,{aux});
            n--;
        }//pasé los n elementos de pila 2 a pila1
        apilar(pila2,{valor});
        //con esto tengo "pasados" los n elementos de pila1 a pila2
        cout<<"Pila 1: ";
        imprimir(pila);
        cout<<"Pila 2: ";
        imprimir(pila2);
    }
}

int main() {
    struct Pila pila;
    struct Pila pila2;
    construir(pila);
    construir(pila2);

    apilar(pila, {1});
    apilar(pila, {2});
    apilar(pila, {3});
    apilar(pila, {4});

    cout<<"Pila 1: ";
    imprimir(pila);
    cout<<"Pila 2: ";
    imprimir(pila2);

    //PasaPila(pila, pila2);
    PasaPilaRec(pila, pila2);
    cout<<endl<<"EJECUTANDO PASAPILA()"<<endl<<endl;
    cout<<"Pila 1: ";
    imprimir(pila);
    cout<<"Pila 2: ";
    imprimir(pila2);
    return 0;
}