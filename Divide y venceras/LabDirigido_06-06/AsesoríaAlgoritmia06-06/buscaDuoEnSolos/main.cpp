#include <iostream>
using namespace std;

// CONSIDERACIONES, ESTE ALGORITMO APLICA ESTRICTAMENTE A
// ARREGLO ORDENADO DE MENOR A MAYOR
// LOS NUMEROS SON ESTRICTAMENTE CONSECUTIVOS
// SALUDOS JP: Oscar Cespedes uwu
int buscarDuplicado(int* arr, int ini, int fin) {
    if (ini == fin) return ini;
    int mid = (ini+fin) / 2;
    // Verificamos si mid esta en la posicion correcta
    if (arr[mid] == mid + 1) {
        // esto significa que hasta el medio todo esta en orden, x lo que el doble debe de estar
        // en el lado derecho
        return buscarDuplicado(arr, mid + 1, fin);
    }else{
        // esto significa que algo esta incorrecto en el medio,  lo que el doble debe de estar
        // en el lado izqueirdo
        return buscarDuplicado(arr, ini, mid);
    }
}

int main() {
    int arr[] = {1,1,2,3,4,5,6,7,8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int pos = buscarDuplicado(arr, 0, n - 1);

    cout<<"Num duplicado: "<<arr[pos]<<endl;
    cout<<"Posicion donde se repite: "<<pos<<endl;

    return 0;
}