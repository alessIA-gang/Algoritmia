/* 
 * Archivo:   main.cpp
 * Autor: Alessia Gastello 
 */

#include <iostream>
using namespace std;

void BuscarNoDupla(int A[], int inicio, int final) {
    if (inicio == final) {
        cout << "Solo: " << A[inicio] << endl;
        return;
    }
    int medio = (inicio + final) / 2;
    if (medio % 2 == 0) {
        if (A[medio] == A[medio + 1])
            BuscarNoDupla(A, medio + 2, final); //derecha
        else BuscarNoDupla(A, inicio, medio); //izquierda
    } else {
        if (A[medio] == A[medio - 1])
            BuscarNoDupla(A, medio + 1, final);
        else BuscarNoDupla(A, inicio, medio - 1);
    }
}

int main() {
    int A[] = {1, 1, 3, 3, 5, 5, 7, 7, 8, 8,4};
    int n = 11;
    BuscarNoDupla(A, 0, n - 1);
    return 0;
}
