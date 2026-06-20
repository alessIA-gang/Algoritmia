/* 
 * Archivo:   main.cpp
 * Autor: Alessia Gastello 
 */

#include <iostream>
#include <iomanip>
using namespace std;

void cuentaCeros(int *arreglo, int ini, int fin, int cont) {
    if (fin < ini) {
        cout << "Ceros: " << cont << endl;
        return;
    }
    if (fin == ini) {
        if (arreglo[ini] == 0)
            cont++;
        cout << "Ceros: " << cont << endl;
        return;
    }
    int medio = (ini + fin) / 2;
    if (arreglo[medio] == 0) {
        cuentaCeros(arreglo, ini, medio - 1, cont + 1 + (fin - medio));
    } else {
        cuentaCeros(arreglo, medio + 1, fin, cont);
    }
}

int main(int argc, char **argv) {
    int arreglo[] = {1, 1, 1, 0, 0};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    int cuenta = 0;
    cuentaCeros(arreglo, 0, n - 1, cuenta);
    return 0;
}
