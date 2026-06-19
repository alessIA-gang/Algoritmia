#include <iostream>
using namespace std;
void BuscarNoDupla(int A[], int inicial, int final) {
    //CASO BASE
    //cuando nos quedamos con un solo elemento, hemos encontrado el Soli
    if (inicial==final) {
        cout<<A[inicial]<<endl;
        return;
    }
    //PARTE RECURSIVA
    int medio=(inicial+final)/2;
    //Hacemos el análisis de la posición medio: se espera que las duplas comiencen en un par: 0,2,4,6,etc y que terminen en un impar: 1,3,5,7, etc.
    if (medio%2==0)//la posición de medio es PAR, se espera que "inicie una dupla"
        if (A[medio]==A[medio+1])
            BuscarNoDupla(A, medio+2, final);
        else
            BuscarNoDupla(A, inicial, medio);
    else//La posición es IMPAR, se espera que "termine la dupla"
        if (A[medio]==A[medio-1])
            BuscarNoDupla(A, medio+1, final);
        else
            BuscarNoDupla(A, inicial, medio-1);
}
int main() {
    int A[]={1,1,3,3,4,5,5,7,7,8,8};
    int n=11;
    BuscarNoDupla(A, 0, n-1);
    return 0;
}