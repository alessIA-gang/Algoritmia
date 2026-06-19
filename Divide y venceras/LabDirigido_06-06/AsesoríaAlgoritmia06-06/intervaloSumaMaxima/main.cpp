#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

int maxCruce(int arr[],int inicio,int medio,int fin){
    int suma=0;
    int sumaIzquierda=-9999999;
    for(int i=medio;i>=inicio;i--){
        suma+=arr[i];
        if(sumaIzquierda<suma)sumaIzquierda=suma;
    }

    suma=0;
    int sumaDerecha=-9999999;
    for(int i=medio+1;i<=fin;i++){
        suma+=arr[i];
        if(sumaDerecha<suma)sumaDerecha=suma;
    }
    return sumaDerecha+sumaIzquierda;

}

int maximoDeTres(int a,int b,int c){

    if(a>=b and a>=c)return a;
    if(b>=a and b>=c)return b;
    return c;

}

int buscarSumaMaxima(int arr[],int inicio,int fin){
    if(inicio==fin)return arr[inicio];

    int medio=(inicio+fin)/2;

    int maxIzquierdo=buscarSumaMaxima(arr,inicio,medio);
    int maxDerecho=buscarSumaMaxima(arr,medio+1,fin);
    int maxSumaMedio=maxCruce(arr,inicio,medio,fin);

    return maximoDeTres(maxDerecho,maxIzquierdo,maxSumaMedio);
}

int main(int argc, char** argv) {
    int arreglo[]={45,34,6,-2,-3,-100,27,-6};
    int n=sizeof(arreglo)/sizeof(arreglo[0]);

    cout<<buscarSumaMaxima(arreglo,0,n-1);
    return 0;
}

