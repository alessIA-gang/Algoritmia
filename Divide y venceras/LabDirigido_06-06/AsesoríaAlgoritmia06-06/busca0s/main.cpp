#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
// Estos condicionales es divide y venceras, sino es un problema de recursion mas
int michiCuentaCeros(int *arr,int ini,int fin, int cont){
    if(ini>fin)return cont;

    int med=(ini+fin)/2;
    // Como el medio es 0, se trata del 1er 0 o estar màs a la izquierda, asì que trasladamos
    // a izquierda, contando todos los 0s de las derecha
    if(arr[med]==0) return michiCuentaCeros(arr,ini,med-1,cont+fin-med+1);
    // Si el medio no es 0, entonces se encuentra a la derecha
    else return michiCuentaCeros(arr,med+1,fin,cont);

}

int main(int argc, char** argv) {
    int arr[]={1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"La cantidad de 0s es: "<<michiCuentaCeros(arr,0,n-1,0);

    return 0;
}
