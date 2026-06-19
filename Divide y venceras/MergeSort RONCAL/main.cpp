//Fecha:  martes 26 mayo 2026 
//Autor: Ana Roncal

#include <iostream>
#include "Biblioteca/funciones.h"
using namespace std;
#define MAX 10
int main(int argc, char **argv) {

    
    //int arreglo[] = {90, 65, 7, 305, 120, 110, 8, 90, 110};
   //int arreglo[] = {1, 2, 3, 4, 5, 8, 90, 110};
    int arreglo[] = {120, 305, 110, 8};
    //int arreglo[] = {305, 120, 110, 8,7,6,5, 4};
    int longitud = sizeof(arreglo) / sizeof(arreglo[0]);
    imprime(arreglo, longitud);
    /*ORDENAMOS EL ARREGLO con complejidad n log(n) */
    cout << "Ordenamos el arreglo usando MergeSort complejidad nlog(n)" << endl;
    mergeSort(arreglo, 0, longitud - 1);
    imprime(arreglo, longitud);

    /*Busqueda binaria*/
    // Ojo!! solo funciona cuando los datos estan ordenados
    cout << "Busqueda binaria" << endl;
    int clave = 5;
    cout << "Buscar: " << clave << endl;

    int indice = busquedaBinaria(arreglo, clave, 0, longitud-1);
    if (indice != -1)
        cout << "YUPI!!!!" << endl;
    else
        cout << "PIPIPI!!!!" << endl;
    return 0;
}

