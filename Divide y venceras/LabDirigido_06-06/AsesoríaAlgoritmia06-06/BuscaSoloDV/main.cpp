#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

void michiBusquedaSolitaria(int*arr,int ini,int fin) {
    if (ini>fin)return;
    if (ini==fin) {
        cout<<"El solitario es: "<<arr[ini]<<" uu"<<endl;
        return;
    }
    // Obteniendo el medio
    int med=(ini+fin)/2;
    // En ambos casos revisaremos el anterior
    // Caso medio par:
    if (med%2==0) {
        // Si el anterior es diferente, quiere decir que hasta el par anterior todo esta bien
        // por lo que nuestro sospechoso se encuentra a la derecha
        if (arr[med]!=arr[med-1])michiBusquedaSolitaria(arr,med,fin);
        // Si el anterior es diferente, entonces el sospechoso altero el orden antes
        // Asi que nos vamos a la izquierda
        else michiBusquedaSolitaria(arr,ini,med);
    // Caso medio impar:
    }else {
        // Si el anterior es diferente, quiere decir que algo altero el orden
        // por lo que nuestro sospechoso se encuentra a la izquierda
        if (arr[med]==arr[med-1])michiBusquedaSolitaria(arr,med+1,fin);
        // Si el anterior es diferente, entonces todo esta en orden
        // Asi que nos vamos a la derecha
        else michiBusquedaSolitaria(arr,ini,med-1);
    }
}

int main() {
    int arr[]={1,1,2,3,3,4,4};
    //int arr[]={1,1,2,2,3,4,4};
    //int arr[]={1,1,2,3,3,4,4,5,5};
    //int arr[]={1,1,2,2,3,3,4,5,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    michiBusquedaSolitaria(arr,0,n-1);
    return 0;
}