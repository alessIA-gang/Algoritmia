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
#include <cmath>
#define N 10
#define P 70000
#define B 150
#define F 5
using namespace std;
void cambiarBase(int i,int n,int base,int *cromosoma) {
   int j;
    for(j=0;j<n;j++) {
        cromosoma[j]=0;
    }
    j=0;
    while(i>0) {
        cromosoma[j++]=i%base;
        i/=base;
    }
}


int main(int argc, char **argv) {
    int datos[8][3]={
        {35000,80,1},
        {24000,60,3},
        {30000,70,2},
        {27000,48,1},
        {10000,20,1},
        {7000,35,2},
        {6000,10,1},
        {40000,40,3},
    };
    int costoTotal,benficio,falsos;
    int solucion[8];
    int productos=8;

    int base=2;
    int n=pow(base,productos);
    int cromosoma[N];
    for(int i=1;i<n;i++) {
        cambiarBase(i,productos,base,cromosoma);
        costoTotal=0,benficio=0,falsos=0;
        for (int j = 0; j < productos; j++) {
            if (cromosoma[j]==1) {
                costoTotal+= datos[j][0];
                benficio += datos[j][1];
                falsos += datos[j][2];
            }
        }
        if (costoTotal <= P && benficio >= B && falsos <= F) {
            cout << "Recursos: " ;
            for (int j = 0; j < productos; j++) {
                if (cromosoma[j]==1) cout<<j+1<<" ";

            }
            cout << "Costo Total: "<<costoTotal<<" "<<benficio<<" "<<falsos<<endl;
        }else continue;
    }
    return 0;
}