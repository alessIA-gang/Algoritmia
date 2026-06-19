#include <iostream>
#include <iomanip>
using namespace std;
int buscaCarie(int*arr,int ini,int fin,int umbral) {
    if (ini>=fin) {
        if (arr[fin]<umbral)return fin;
        return -1;
    }
    int med=(ini+fin)/2;

    if (arr[med]<umbral) {
        //buscamos a la izquierda
        return buscaCarie(arr,ini,med,umbral);
    }else {
        //buscamos a la derecha}
        return buscaCarie(arr,med+1,fin,umbral);
    }
}

int main() {
    int arr[]={98, 95, 93, 90, 72, 60, 55, 50};
    int n=sizeof(arr)/sizeof(arr[0]);
    int umbral=40;

    int posCarie=buscaCarie(arr,0,n-1,umbral);
   if (posCarie!=-1)cout<<posCarie<<endl;
    else cout<<"Not found"<<endl;
    return 0;
}