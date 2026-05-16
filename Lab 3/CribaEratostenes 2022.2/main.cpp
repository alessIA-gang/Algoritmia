#include <iostream>
#include <list>

#include "BibliotecaLista/funcionesLista.h"
#include "BibliotecaLista/Lista.h"

using namespace std;

struct NodoLista *obtenerNodoAnterior(const struct Lista listaTAD, const struct ElementoLista elemento) {
    struct NodoLista *recorrido = listaTAD.inicio;
    struct NodoLista *ultimo = nullptr;

    while (recorrido) {
        if (recorrido->elemento.codigo == elemento.codigo) break;
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }
    if (recorrido == nullptr) return nullptr;
    return ultimo;
}

void generarLista(struct Lista &lista, int n) {
    for (int i = 2; i <= n; i++) {
        ElementoLista elemento;
        elemento.codigo = i;
        insertarAlFinal(lista, elemento);
    }
}

void eliminaMultiplos(struct Lista &lista, NodoLista *recorrido, int valor) {
    if (recorrido == NULL) {
        return;
    }
    NodoLista *aux = recorrido->siguiente;
    if (recorrido->elemento.codigo % valor == 0) {
        cout << recorrido->elemento.codigo << " ";
        eliminaNodo(lista, recorrido->elemento);
    }
    eliminaMultiplos(lista, aux, valor);
}

void procesa(struct Lista &lista, NodoLista *recorrido, int n) {
    if (recorrido->elemento.codigo * recorrido->elemento.codigo >= n) {
        return;
    }
    cout << "Número Procesado: " << recorrido->elemento.codigo << endl;
    cout << "Números Tachados para el " << recorrido->elemento.codigo << ": ";
    eliminaMultiplos(lista, recorrido->siguiente, recorrido->elemento.codigo);
    cout << endl;
    procesa(lista, recorrido->siguiente, n);
}

void invierteLista(Lista &lista, int n) {
    NodoLista *ultimo;
    NodoLista *ultimoAnterior;
    if (n <= 1)return;
    ultimo = obtenerUltimoNodo(lista);
    ultimoAnterior = obtenerNodoAnterior(lista, ultimo->elemento);
    ultimo->siguiente = ultimoAnterior;
    ultimoAnterior->siguiente = nullptr;
    invierteLista(lista, n - 1);
    lista.inicio = ultimo;
}

int main() {
    Lista lista;
    int n;
    cout << "Ingrese n: ";
    cin >> n;
    construir(lista);
    generarLista(lista, n);
    imprimir(lista);
    // invierteLista(lista, lista.longitud);
    // cout << "Intvertido: ";
    // imprimir(lista);
    NodoLista * recorrido = lista.inicio;
    procesa(lista,recorrido, n);
    imprimir(lista);
    return 0;
}
