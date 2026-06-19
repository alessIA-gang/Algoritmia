#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

int buscarMin(int*arr,int limInf,int limSup){
    // X si en algun momento tenemos el arreglo ordenado
    if(arr[limInf]<=arr[limSup])return arr[limInf];

    int medio=(limInf+limSup)/2;
    // x si en algun momento tenemos en el centro el caso fin
    // if(arr[medio]>arr[medio+1])return arr[medio+1];
    if(arr[medio]<arr[medio-1])return arr[medio];

    if(arr[medio]>arr[limSup])return buscarMin(arr,medio+1,limSup);
    else return buscarMin(arr,limInf,medio);
}

int main(int argc, char** argv) {
    int arr[]={8,9,10,1,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"El elemento minimo en el arrRotado: "<<buscarMin(arr,0,n-1);

    return 0;
}
