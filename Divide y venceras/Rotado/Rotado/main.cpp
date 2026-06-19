#include <iostream>
using namespace std;
int Rotado(int A[], int inicial, int final) {
    //CASO BASE
    if (inicial==final)//encontramos el menor
        return A[inicial];
    //PARTE RECURSIVA
    int medio=(inicial+final)/2;
    if (A[medio]<A[final])
        return Rotado(A, inicial, medio);
    else
        return Rotado(A, medio+1, final);
}
int main() {
    int A[]={10,12,2,3,4,5};
    int n=6;
    cout<<Rotado(A, 0, n-1)<<endl;
    return 0;
}