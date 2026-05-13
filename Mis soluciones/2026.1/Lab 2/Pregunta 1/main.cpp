#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

#include "BibliotecaLista/Baraja.h"
#include "BibliotecaLista/Carta.h"
#include "BibliotecaLista/NodoBaraja.h"
using namespace std;

struct NodoBaraja *obtenerUltimoNodo(const struct Baraja &baraja) {
    struct NodoBaraja *ultimo = nullptr;
    struct NodoBaraja *recorrido = baraja.inicio;

    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

void insertar_Carta_Final(Baraja &baraja, Carta carta) {
    struct NodoBaraja *ultimoNodoBaraja = obtenerUltimoNodo(baraja);
    struct NodoBaraja *nuevo;
    nuevo = new struct NodoBaraja;
    nuevo->carta = carta;
    nuevo->siguiente = nullptr;

    if (ultimoNodoBaraja == nullptr) {
        /*Si la lista está vacía*/
        baraja.inicio = nuevo; /*se inserta en la cabeza de la lista*/
        baraja.fin = nuevo;
    } else {
        //La lista ya tiene NodoListas
        ultimoNodoBaraja->siguiente = nuevo;
        baraja.fin = nuevo;
    }
    baraja.longitud++;
}

void crear_baraja(Baraja &baraja) {
    baraja.inicio = nullptr;
    baraja.fin = nullptr;
    baraja.longitud = 0;

    Carta carta;
    carta.numero = 1;
    carta.palo = 'C';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 2;
    carta.palo = 'C';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 3;
    carta.palo = 'C';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 4;
    carta.palo = 'C';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 5;
    carta.palo = 'C';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 6;
    carta.palo = 'C';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 7;
    carta.palo = 'C';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 8;
    carta.palo = 'C';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 9;
    carta.palo = 'C';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 10;
    carta.palo = 'C';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 11;
    carta.palo = 'C';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 12;
    carta.palo = 'C';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 13;
    carta.palo = 'C';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 1;
    carta.palo = 'D';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 2;
    carta.palo = 'D';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 3;
    carta.palo = 'D';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 4;
    carta.palo = 'D';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 5;
    carta.palo = 'D';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 6;
    carta.palo = 'D';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 7;
    carta.palo = 'D';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 8;
    carta.palo = 'D';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 9;
    carta.palo = 'D';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 10;
    carta.palo = 'D';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 11;
    carta.palo = 'D';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 12;
    carta.palo = 'D';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 13;
    carta.palo = 'D';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 1;
    carta.palo = 'T';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 2;
    carta.palo = 'T';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 3;
    carta.palo = 'T';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 4;
    carta.palo = 'T';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 5;
    carta.palo = 'T';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 6;
    carta.palo = 'T';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 7;
    carta.palo = 'T';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 8;
    carta.palo = 'T';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 9;
    carta.palo = 'T';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 10;
    carta.palo = 'T';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 11;
    carta.palo = 'T';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 12;
    carta.palo = 'T';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 13;
    carta.palo = 'T';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 1;
    carta.palo = 'E';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 2;
    carta.palo = 'E';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 3;
    carta.palo = 'E';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 4;
    carta.palo = 'E';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 5;
    carta.palo = 'E';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 6;
    carta.palo = 'E';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 7;
    carta.palo = 'E';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 8;
    carta.palo = 'E';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 9;
    carta.palo = 'E';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 10;
    carta.palo = 'E';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 11;
    carta.palo = 'E';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 12;
    carta.palo = 'E';
    insertar_Carta_Final(baraja, carta);
    carta.numero = 13;
    carta.palo = 'E';
    insertar_Carta_Final(baraja, carta);
}

bool esListaVacia(const struct Baraja &baraja) {
    return baraja.inicio == nullptr;
}

void imprimirBaraja(const struct Baraja &baraja) {
    if (esListaVacia(baraja)) {
        cout << "BARAJA VACIA" << endl;
    } else {
        struct NodoBaraja *recorrido = baraja.inicio;

        while (recorrido != nullptr) {
            cout << recorrido->carta.numero << recorrido->carta.palo << "  ";
            recorrido = recorrido->siguiente;
        }
        cout << endl;
    }
}

NodoBaraja *extraerEnPosicion(Baraja &baraja, int pos) {
    NodoBaraja *recorrido = baraja.inicio;
    NodoBaraja *anterior = nullptr;
    int n = 0;
    while (recorrido != nullptr and n != pos) {
        anterior = recorrido;
        recorrido = recorrido->siguiente;
        n++;
    }
    baraja.longitud--;
    if (recorrido != nullptr) {
        if (anterior == nullptr) {
            baraja.inicio = recorrido->siguiente;
        } else {
            anterior->siguiente = recorrido->siguiente;
        }
        return recorrido;
    } else {
        // anterior = nullptr;
        return anterior;
    }
}
// NodoBaraja *extraerEnPosicion(Baraja baraja, int pos) {
//     NodoBaraja *recorrido = baraja.inicio;
//     NodoBaraja *anterior = nullptr;
//     int n = 0;
//     while (recorrido != nullptr) {
//         if (n == pos) {
//
//         }
//         anterior = recorrido;
//         recorrido = recorrido->siguiente;
//         n++;
//     }
//     baraja.longitud--;
//     if (recorrido != nullptr) {
//         if (anterior == nullptr) {
//             baraja.inicio = recorrido->siguiente;
//         } else {
//             anterior->siguiente = recorrido->siguiente;
//         }
//         return recorrido;
//     } else {
//         // anterior = nullptr;
//         return anterior;
//     }
// }

void barajar(Baraja &baraja) {
    srand(time(nullptr));
    NodoBaraja *insertar;
    int porbarajar=baraja.longitud;
    while (porbarajar > 0) {
        int n = rand() % porbarajar;
        insertar= extraerEnPosicion(baraja, n);
        insertar_Carta_Final(baraja, insertar->carta);
        porbarajar--;
    }
};

int main() {
    Baraja baraja;
    crear_baraja(baraja);
    imprimirBaraja(baraja);
    cout << endl << "BARAJADO: " << endl;
    barajar(baraja);
    imprimirBaraja(baraja);
    // cout << extraerEnPosicion(baraja, 8)->carta.numero << endl;
    // imprimirBaraja(baraja);

    return 0;
}
