#include <iostream>
using namespace std;
int Maximo3 (int a, int b, int c) {
    if (a >= b && a >= c) return a;
    if (b >= a && b >= c) return b;
    if (c >= a && c >= b) return c;
}
int EncuentraMayorIncremento (int A[], int inicial, int medio, int final) {
    int contador_izq=1, contador_der=1;
    for (int i=medio; i>inicial; i--) {
        //Analizo los días hacia la IZQUIERDA
        if (A[i-1]<A[i])
            contador_izq++;
        else
            break;
    }
    for (int i=medio+1; i<final; i++) {
        //Analizo los días hacia la DEREITA
        if (A[i]<A[i+1])
            contador_der++;
        else
            break;
    }
    if (A[medio]<A[medio+1])//Si realmente hay incremento, sumo los contadores
        return contador_der+contador_izq;

    return 1;
}
int RebroteCOVID(int A[], int inicial, int final) {
    int maximo_incremento_izq, maximo_incremento_der, maximo_incremento_centro;
    //CASO BASE
    if (inicial==final)
        return 1;//1 día
    //PARTE RECURSIVA
    int medio=(inicial+final)/2;
    maximo_incremento_izq=RebroteCOVID(A, inicial, medio);
    maximo_incremento_der=RebroteCOVID(A, medio+1, final);
    maximo_incremento_centro=EncuentraMayorIncremento(A, inicial, medio, final);
    return Maximo3(maximo_incremento_izq, maximo_incremento_der, maximo_incremento_centro);
}
int main() {
    /*int A[]={10,20,15,10,12,10,13,18};
    int n=8;*/
    int A[]={7,2,9,10,16,10,13,8,2,10};
    int n=10;
    cout<<"Intervalo máximo de incremento: "<<RebroteCOVID(A, 0, n-1)<<endl;
    return 0;
}