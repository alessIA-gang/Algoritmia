/* 
 * Archivo:   main.cpp
 * Autor: Alessia Gastello 
 */

#include <iostream>
#include <iomanip>
using namespace std;
// Dado un arreglo de enteros, encontrar el número de inversiones.
// Una inversión es un par de elementos A[i] y A[j] tal que i < j y
// A[i] > A[j].
void contar(int*arreglo,int&contador,int inicio,int medio,int final) {
    int longitud1=(medio-inicio)+1;
    int longitud2=(final-medio);
    int P[longitud1+1],Q[longitud2+1];
    P[longitud1]=INT_MAX;
    Q[longitud2]=INT_MAX;
    for(int i=inicio;i<=medio;i++) {
        P[i-inicio]=arreglo[i];
    }
    for(int i=medio+1;i<=final;i++) {
        Q[i-(medio+1)]=arreglo[i];
    }
    int p=0,j=0;
    for (int i=inicio;i<=final; i++) {
        if(P[p]>Q[j]) {
            contador += (longitud1 - p); //porque todos los indices de P son menores que los de Q, y una inversión es cada par encontrado.
            //a partir de p todos son inversiones pq está ordenado
            arreglo[i]=Q[j++];
        }
        else arreglo[i]=P[p++];
    }
    // cout<<"prueba cont: "<<contador<<endl;
}

void invertirYContar(int*arreglo,int inicio,int final,int &contador) {
    //caso base
    if (inicio==final) return;
    int medio=(inicio+final)/2;
    invertirYContar(arreglo,inicio,medio,contador);
    invertirYContar(arreglo,medio+1,final,contador);

    contar(arreglo,contador,inicio,medio,final);


}
int main(int argc,char**argv) {
    int arreglo[]={2,8,7,5,80,9,4,6,12,70};
    int n=10;
    int contador=0;
    for(int i=0;i<n;i++) {
        cout<<arreglo[i]<<" ";
    }
    cout<<endl;
    invertirYContar(arreglo,0,n-1,contador);
    for(int i=0;i<n;i++) {
        cout<<arreglo[i]<<" ";
    }
    cout<<endl;
    cout<<"Cantidad de inversiones: "<<contador<<endl;
    return 0;
}
