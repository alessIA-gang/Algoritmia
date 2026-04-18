/* 
 * Archivo:   main.cpp
 * Autor: *** 20241238, Alessia Isabella Gastello Anglas ***
 * Fecha y Hora: *** xx/xx/25 xx:xx ***
 * 
 * ==========================================================================
 * descprición
 * ==========================================================================
 */

#include <iostream>
#include <iomanip>
#define N 6
#define M 3
#include <cmath>
using namespace std;

void cambiarBase(int i, int base, int *cromosoma, int cant) {
    int j;
    for (j = 0; j < cant; j++) {
        cromosoma[j] = 0;
    }
    j = 0;
    while (i > 0) {
        cromosoma[j++] = i % base;
        i = i / base;
    }
}

void imprimirDistribución(int i, int discos[M], int tablas[N], int cromosoma[N],int mejMen) {
    cout << "Mejor distribución: "<<endl<<"Disco"<<setw(10)<<"Tablas"<<endl;;
    for (int i = 0; i < M; i++) {
        cout<<i+1<<setw(10);
        for (int j=0;j<N;j++) {
           if (cromosoma[j]==i) {
               cout<<j+1<<" ";//numero de tabla
           }
        }
        cout<<endl;
    }
    cout<<"Velocidad mínima: "<<mejMen<<endl;
}

int main(int argc, char **argv) {
    int tablas[N] = {150, 100, 80, 50, 120, 10};
    int discos[M] = {250, 200, 200};
    int canTablas = 6, menor,mejorIndice = -1, mejorMenor = -1;
    int base = M;
    int cromosoma[canTablas];
    int cantCombinaciones = pow(base, canTablas);
    // consideramos el estado 0 como 1 y así sucesivamente
    for (int i = 1; i < cantCombinaciones; i++) {

        int discosCopia[M];
        for (int j = 0; j < M; j++) discosCopia[j] = discos[j];
        cambiarBase(i, base, cromosoma, canTablas);
        for (int j = 0; j < canTablas; j++) {
            // cout << cromosoma[j];
            int d = cromosoma[j];
            discosCopia[d] -= tablas[j]; //le resta velocidad
        }
        // cout << endl;
        menor = discosCopia[0];
        for (int p = 1; p < canTablas; p++) {
            if (menor > discosCopia[p]) {
                menor = discosCopia[p];
            }
        }

        if (menor > mejorMenor) {
            mejorMenor = menor;
            mejorIndice = i;
        }
    }
    cambiarBase(mejorIndice, base, cromosoma,N);
    imprimirDistribución(mejorIndice, discos, tablas, cromosoma,mejorMenor);


    return 0;
}
