#include <iostream>
#include <iomanip>
using namespace std;
int busquedaCodigo(int*arr,int ini,int fin,int codeBuscar) {
    if (fin<ini)return -1;
    int mid=(ini+fin)/2;
    if(arr[mid]==codeBuscar)return mid;

    if (arr[ini]<=arr[mid]) {
        //x ahora derecha
        //return busquedaCodigo(arr,mid+1,fin,codeBuscar);
        if (codeBuscar>=arr[ini] and codeBuscar<arr[mid]) {
            //izquierda
            return busquedaCodigo(arr,ini,mid-1,codeBuscar);
        }else {
            //derecha
            return busquedaCodigo(arr,mid+1,fin,codeBuscar);
        }
    }else {
        //x ahora izquierda
        //return busquedaCodigo(arr,mid-1,fin,codeBuscar);
        if (codeBuscar>arr[mid] and codeBuscar<=arr[fin]) {
            //derecha
            return busquedaCodigo(arr,mid+1,fin,codeBuscar);
        }else {
            //izquierda
            return busquedaCodigo(arr,ini,mid-1,codeBuscar);
        }
    }
}

int main() {
    int arr[]={4,5,6,7,8,1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int codeBuscar=3;

    int pos=busquedaCodigo(arr,0,n-1,codeBuscar);

    cout<<pos<<endl;
    return 0;
}