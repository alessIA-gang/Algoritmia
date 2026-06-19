#include <iostream>
using namespace std;

int busqueda(int*arr,int ini, int fin,int codigoBuscar) {
    if (fin<ini)return -1;
    int mid =(ini+fin)/2;
    if (arr[mid]==codigoBuscar)return mid;

    if (arr[ini]<=arr[mid]) {
        //x ahora se va a la derecha
        //return busqueda(arr,mid+1,fin,codigoBuscar);
        if (codigoBuscar>=arr[ini] && codigoBuscar<arr[mid]) {
            //x ahora se va a la izquierda
            return busqueda(arr,ini,mid-1,codigoBuscar);
        }else {
            //x ahora se va a la derecha
            return busqueda(arr,mid+1,fin,codigoBuscar);
        }
    }else {
        //x ahora se va a la izquierda
        //return busqueda(arr,ini,mid-1,codigoBuscar);
        if (codigoBuscar>arr[mid] && codigoBuscar<=arr[fin]) {
            //x ahora se va a la derecha
            return busqueda(arr,mid+1,fin,codigoBuscar);
        }else {
            //x ahora se va a la izquierda
            return busqueda(arr,ini,mid-1,codigoBuscar);
        }
    }
}

int main() {
    //int arr[]={300, 350, 400, 450, 500, 550, 600, 650, 100, 145, 190, 235, 280};
    int arr[]={4,5,6,7,8,1,2,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int codigoBuscar = 3;
    int pos=busqueda(arr,0, n-1, codigoBuscar);
    cout<<"posición: "<<pos<<endl;

    return 0;
}