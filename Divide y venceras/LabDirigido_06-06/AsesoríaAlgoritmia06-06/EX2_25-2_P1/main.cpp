#include <iostream>

using namespace std;
// Michisistema SAC
int michiDentista(int*arr,int ini,int fin,int umbral) {
    int mid = (ini+fin)/2;
    //cout<<ini<<" "<<fin<<" "<<mid<<endl;
    if (ini >= fin) {
        if (arr[fin]<umbral)return fin;
        return -1;
    }

    if (arr[mid]<umbral) {
        //buscamos en la parte izquierda
        return michiDentista(arr, ini,mid,umbral);
    }else{
        //buscamos en la parte derecha
        return michiDentista(arr, mid+1,fin,umbral);
    }

}

int main() {
    int arr[]={98, 95, 93, 90, 72, 60, 55, 50};
    int n=sizeof(arr)/sizeof(arr[0]);
    int umbral=80;

    int posCarie = michiDentista(arr,0,n-1,umbral);

    if (posCarie!=-1)cout<<"Posicion de la carie: "<<posCarie;
    else cout<<"MichiDentista exitoso";
    return 0;
}