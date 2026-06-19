#include <iostream>
#include <climits>
using namespace std;

// Paso 1: encontrar punto de rotacion con D&V
// este es logn
int puntoRotacion(int arr[][2], int ini, int fin) {
    if (arr[ini][0] <= arr[fin][0]) return ini; // ya ordenado

    int mid = (ini + fin) / 2;
    if (arr[mid][0]<arr[mid-1][0]) return mid; // x si en algun momento tenemos en el centro el caso fin

    if (arr[mid][0] > arr[fin][0]) return puntoRotacion(arr, mid+1, fin);
    else return puntoRotacion(arr, ini, mid);
}

// Paso 2: suma maxima subarreglo (D&V) sobre fila de riesgo
int maxCruce(int* riesgo, int lo, int mid, int hi) {
    int suma = 0, sumaIzq = INT_MIN;
    for (int i = mid; i >= lo; i--) {
        suma += riesgo[i];
        if (suma > sumaIzq) sumaIzq = suma;
    }
    suma = 0;
    int sumaDer = INT_MIN;
    for (int i = mid + 1; i <= hi; i++) {
        suma += riesgo[i];
        if (suma > sumaDer) sumaDer = suma;
    }
    return sumaIzq + sumaDer;
}
//nlogn
int maxSubarray(int* riesgo, int lo, int hi) {
    if (lo == hi) return riesgo[lo];
    int mid = (lo + hi) / 2;
    int izq  = maxSubarray(riesgo, lo, mid);
    int der  = maxSubarray(riesgo, mid + 1, hi);
    int cruz = maxCruce(riesgo, lo, mid, hi);
    return max(izq, max(der, cruz));
}

int main() {
    int A[][2] = {{50,4},{60,-1},{70,3},{80,-2},{10,-4},{20,5},{30,1},{40,-2}};
    int n = 8;

    //Encontrar inicio del orden cronologico
    int rot = puntoRotacion(A, 0, n - 1);
    cout<<"Posicion inicial original: "<<rot<<endl;

    //Construir arreglo de riesgo en orden cronologico
    int riesgo[8];
    for (int i=0;i<n;i++)riesgo[i] = A[(rot+i)%n][1];

    cout<<"Maxima acumulacion: "<<maxSubarray(riesgo, 0, n - 1)<<endl;

    return 0;
}