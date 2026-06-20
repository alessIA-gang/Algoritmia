/* 
 * Archivo:   main.cpp
 * Autor: Alessia Gastello 
 */

#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

void merge(int *arreglo, int inicio, int medio, int fin) {
    int longitud1 = (medio - inicio) + 1;
    int longitud2 = fin - medio;
    int P[longitud1+1], Q[longitud2+1];
    P[longitud1] = INT_MAX;
    Q[longitud2] = INT_MAX;
    for (int i = inicio; i <= medio; i++) {
        P[i-inicio] = arreglo[i];
    }
    for (int i = medio + 1; i <= fin; i++) {
        Q[i-(medio+1)] = arreglo[i];
    }
    int p = 0, q = 0;
    for (int i = inicio; i <= fin; i++) {
        if (P[p] < Q[q]) {
            arreglo[i] = P[p++];
        } else arreglo[i] = Q[q++];
    }
}

void mergeSort(int *arreglo, int inicio, int fin) {
    if (inicio == fin)return;
    int medio = (inicio + fin) / 2;
    mergeSort(arreglo, inicio, medio); //izquierda
    mergeSort(arreglo, medio + 1, fin); //derecha
    merge(arreglo, inicio, medio, fin);
}


int main(int argc, char **argv) {
    int arreglo[] = {7, 5, 9, 4, 12, 3,14};
    int n = 7;
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;


    cout << "Combinando arreglos" << endl;
    mergeSort(arreglo, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
    return 0;
}
