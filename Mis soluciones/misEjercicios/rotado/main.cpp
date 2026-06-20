/* 
 * Archivo:   main.cpp
 * Autor: Alessia Gastello 
 */

#include <iostream>
#include <iomanip>
using namespace std;

void encuentraMin(int *arreglo, int inicio, int final, int minimo) {
    if (inicio == final) {
        if (arreglo[inicio] < minimo)minimo = arreglo[inicio];
        cout << "Minimo: " << minimo << endl;
        return;
    }
    int medio=(inicio+final)/2;

    if (arreglo[medio] <arreglo[final]) {
        encuentraMin(arreglo, inicio, medio, minimo);
    }else{
        encuentraMin(arreglo, medio+1, final, arreglo[medio]);
    }
}

int main(int argc, char **argv) {
    int arreglo[] = {8,10,12,2,3,4,5};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    int minimo=999;
    encuentraMin(arreglo, 0, n - 1, minimo);
    return 0;
}
