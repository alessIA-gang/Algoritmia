#include <iostream>
using namespace std;
void Merge(int A[], int inicial, int medio, int final) {
    //Recordemos que A[] está partido en "medio" y ambos subarreglos ya vienen ORDENADOS pero de manera aislada
    int longitud1, longitud2;
    longitud1=(medio-inicial)+1;
    longitud2=(final-medio);
    int P[longitud1+1];//aumento "un espacio" para el entero "muy grande"
    int Q[longitud2+1];//aumento "un espacio" para el entero "muy grande"
    //Matriculamos el entero "muy grande"
    P[longitud1]=INT_MAX;
    // cout<<INT_MAX<<endl;//mayor valor posible para un int
    Q[longitud2]=INT_MAX;
    //copiamos los valores a los subarreglos auxiliares
    for (int i=inicial; i<=medio; i++) {
        P[i-inicial]=A[i];//OJO! tener cuidado con los índices de P y A
        cout<<i-inicial<<endl;
    }
    for (int i=medio+1; i<=final; i++)
        Q[i-(medio+1)]=A[i];//OJO! tener cuidado con los índices de Q y A
    //Ahora recien pasamos a hacer la mezcla
    int p=0, q=0;
    for (int i=inicial; i<=final; i++)
        if (P[p]<Q[q])
            A[i]=P[p++];//Colocamos en p y luego aumentamos p en 1
        else
            A[i]=Q[q++];//Colocamos en q y luego aumentamos q en 1
}
void MergeSort(int A[], int inicial, int final) {//Función recursiva
    //CASO BASE
    //Cuando solo tengamos un elemento en el subarreglo
    if (inicial==final) return;

    //PARTE RECURSIVA
    int medio = (inicial+final)/2;
    MergeSort(A, inicial, medio);//Mitad de la izquierda
    MergeSort(A, medio+1, final); //Mitad de la derecha

    Merge(A, inicial, medio, final);//Mezclamos los subarreglos
}
int main() {
    int A[]={11,4,7,1,6,3,2,9};
    int n=8;
    //Mostramos el arreglo
    for (int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;

    MergeSort(A, 0, n-1);
    //Mostramos el arreglo
    for (int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}