//Fecha:  martes 21 Octubre 2025 
//Autor: Ana Roncal

#include <iostream>
#include <fstream>
#include "funciones.h"
using namespace std;

void mergeSort(int * arreglo, int inicio , int fin)
{
    //caso base
    if (inicio >= fin) return;
    int centro = (inicio + fin) / 2;
    mergeSort(arreglo, inicio, centro);//izquierda
    mergeSort(arreglo, centro + 1, fin);//derecha
    merge(arreglo, inicio, centro, fin);

}

void merge(int * arreglo, int inicio, int centro, int fin)
{
    int size = fin - inicio + 1;
    int temp[size]; // arreglo auxiliar para comparar
    for (int i = 0; i < size; i++)
        temp[i] = arreglo[inicio + i];

    int izquierda = 0;
    int derecha = centro - inicio + 1;
    for (int indice = 0; indice < size; indice++)
    {
        if (derecha <= fin - inicio)   //verificar que tenga derecha
            if (izquierda <= centro - inicio)  // verifica izquierda
                if (temp[izquierda] > temp[derecha])
                    arreglo[inicio + indice] = temp[derecha++];
                else
                    arreglo[inicio + indice] = temp[izquierda++];
            else
                arreglo[inicio + indice] = temp[derecha++];
        else
            arreglo[inicio + indice] = temp[izquierda++];
    }
}

void imprime(int * arreglo, int n) {
    for (int i = 0; i < n; i++)
        cout << arreglo[i] << " ";
    cout << endl;
}

int busquedaBinaria(int * arreglo, int clave, int inicio, int fin) {
    //caso base
    if (inicio > fin ) return -1;
    int centro = (inicio + fin) / 2;
    if (arreglo[centro] == clave)
        return centro;
    else
        if (arreglo[centro] < clave)
            return busquedaBinaria(arreglo, clave, centro + 1, fin); //derecha
        else
            return busquedaBinaria(arreglo, clave, inicio, centro - 1);//izquierda

}