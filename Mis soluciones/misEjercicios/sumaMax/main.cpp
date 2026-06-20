/* 
 * Archivo:   main.cpp
 * Autor: Alessia Gastello 
 */

// #include <iostream>
// #include <iomanip>
// using namespace std;
//
// void sumaMax(int *arreglo, int inicio, int fin, int suma) {
//     if (inicio > fin) {
//         suma+=arreglo[inicio];
//         cout << "Suma: " << suma << endl;
//         return;
//     }
//
//     if (inicio == fin) {
//         cout << "Suma: " << suma << endl;
//         return;
//     }
//     int medio = (inicio + fin) / 2;
//     if (arreglo[medio] + arreglo[medio + 1] > arreglo[medio] + arreglo[medio - 1]) {
//         sumaMax(arreglo, medio + 1, fin, suma + arreglo[medio] + arreglo[medio + 1]);
//     } else {
//         sumaMax(arreglo, inicio, medio , suma + arreglo[medio] + arreglo[medio - 1]);
//     }
// }
//
// int main(int argc, char **argv) {
//     int arreglo[] = {-2, -5, 6, -2, -3, 1, 5, -6};
//     int n = sizeof(arreglo) / sizeof(arreglo[0]);
//     int suma = 0;
//     sumaMax(arreglo, 0, n - 1, suma);
//     return 0;
// }
//


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

int max(int a, int b, int c) {
    if (a > b && a > c) return a;
    if (b > a && b > c) return b;
    if (c > a && c > b) return c;
}
int max(int a, int b) {
    if (a > b) return a;
    if (b > a) return b;

}

int maxIzq(int *A, int ini, int medio) {
    if (ini == medio) return A[medio];
    return max(A[medio], A[medio] + maxIzq(A, ini, medio - 1));
}

// suma máxima desde 'medio+1' yendo hacia la derecha
int maxDer(int *A, int medio, int fin) {
    if (medio + 1 == fin) return A[fin];
    return max(A[medio + 1], A[medio + 1] + maxDer(A, medio + 1, fin));
}

int maxSubarray(int *A, int ini, int fin) {
    // caso base
    if (ini == fin) return A[ini];

    int medio = (ini + fin) / 2;

    int iz = maxSubarray(A, ini, medio); // máximo en mitad izquierda
    int der = maxSubarray(A, medio + 1, fin); // máximo en mitad derecha
    int cruz = maxIzq(A, ini, medio) + maxDer(A, medio, fin); // máximo cruzando

    return max(iz, der, cruz);
}

int main() {
    int A[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(A) / sizeof(A[0]);
    cout << "Suma maxima: " << maxSubarray(A, 0, n - 1) << endl;
    return 0;
}
