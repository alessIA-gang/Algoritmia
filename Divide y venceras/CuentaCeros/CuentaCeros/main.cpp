#include <iostream>
using namespace std;
int CuentaCeros(int A[],int inicial, int final, int contador_ceros) {
    cout<<"P.Inicial="<<inicial<<endl;
    cout<<"P.Final="<<final<<endl;
    cout<<"Contador_ceros="<<contador_ceros<<endl<<endl;
    //CASO BASE
    if (inicial==final) {
        if (A[inicial]==1)
            return contador_ceros;
        if (A[inicial]==0)
            return (contador_ceros+1);
    }
    //PARTE RECURSIVA
    int medio= (inicial+final)/2;
    if (A[medio]==0)//en el subarrglo de la DERECHA hay puros 0, entonces
        //descarto el subarreglo de la DERECHA, cuento los 0s
        //y analizo el subarreglo de la IZQUIERDA
        return CuentaCeros(A, inicial, medio-1,contador_ceros+1+(final-medio));
        // es de inicial a (medio-1) pues el medio ya lo cuento con los otros ceros
    else//en el subarreglo de la IZQUIERDA hay puros 1, entonces
        //descarto el subarreglo de la IZQUIERDA
        //y analizo el subarreglo de la DERECHA
        return CuentaCeros(A, medio+1, final, contador_ceros);

}
int main() {
    int A[]={1,1,1,0,0,0,0,0};
    int n=8;
    cout<<"Resultado: "<<CuentaCeros(A, 0, n-1,0)<<endl;

    return 0;
}