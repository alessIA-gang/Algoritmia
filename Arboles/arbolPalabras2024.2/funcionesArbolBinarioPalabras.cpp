#include <iostream>
#include "ArbolBinarioPalabras.h"

using namespace std;

/*FUNCIONES GENERALES DE ARBOL BINARIO*/

void construir(ArbolBinario & arbol) {
    arbol.raiz = nullptr;
}

bool esArbolVacio(const ArbolBinario & arbol) {
    return arbol.raiz == nullptr;
}

bool esNodoVacio(const NodoArbolBinario * nodo) {
    return nodo == nullptr;
}

void plantarNodoArbolBinario(NodoArbolBinario *& nodo, NodoArbolBinario * izquierda,
                              const ElementoArbolBinario & elemento, NodoArbolBinario * derecha) {
    NodoArbolBinario * nuevo = new NodoArbolBinario;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    nuevo->derecha = derecha;
    nodo = nuevo;
}

/*a) CONSTRUCCION DEL ARBOL DE LA FIGURA 1
 *
 * Codificacion "primer hijo - siguiente hermano":
 *   izquierda -> siguiente letra de la palabra (se avanza en la palabra)
 *   derecha   -> letra alternativa en la misma posicion (otra rama/hermano)
 *
 * Se arma de abajo hacia arriba (de las hojas hacia la raiz B), plantando
 * primero los nodos que no dependen de otros.
 */
void construirArbolFigura1(ArbolBinario & arbol) {
    NodoArbolBinario *n1 = nullptr, *o1 = nullptr, *a1 = nullptr, *b1 = nullptr, *l = nullptr, *e1 = nullptr, *i = nullptr;
    NodoArbolBinario *s1 = nullptr, *a2 = nullptr, *o2 = nullptr, *n2 = nullptr, *e2 = nullptr;
    NodoArbolBinario *a3 = nullptr, *s2 = nullptr, *o3 = nullptr, *r2 = nullptr, *r1 = nullptr, *u = nullptr;
    NodoArbolBinario *b = nullptr;

    // Rama de I: BIEN, BILBAO
    plantarNodoArbolBinario(n1, nullptr, {'N'}, nullptr);          // BIEN termina en N
    plantarNodoArbolBinario(o1, nullptr, {'O'}, nullptr);          // BILBAO termina en O
    plantarNodoArbolBinario(a1, o1, {'A'}, nullptr);
    plantarNodoArbolBinario(b1, a1, {'B'}, nullptr);
    plantarNodoArbolBinario(l, b1, {'L'}, nullptr);
    plantarNodoArbolBinario(e1, n1, {'E'}, l);                     // E y L son hermanos bajo I
    plantarNodoArbolBinario(i, e1, {'I'}, nullptr);                // el hermano de I (U) se enlaza mas abajo

    // Rama de U: BUENAS, BUENO
    plantarNodoArbolBinario(s1, nullptr, {'S'}, nullptr);          // BUENAS termina en S
    plantarNodoArbolBinario(o2, nullptr, {'O'}, nullptr);          // BUENO termina en O
    plantarNodoArbolBinario(a2, s1, {'A'}, o2);                    // A y O son hermanos bajo N
    plantarNodoArbolBinario(n2, a2, {'N'}, nullptr);

    // Rama de U: BURRA, BURROS
    plantarNodoArbolBinario(s2, nullptr, {'S'}, nullptr);          // BURROS termina en S
    plantarNodoArbolBinario(o3, s2, {'O'}, nullptr);
    plantarNodoArbolBinario(a3, nullptr, {'A'}, o3);               // BURRA termina en A; A y O son hermanos
    plantarNodoArbolBinario(r2, a3, {'R'}, nullptr);
    plantarNodoArbolBinario(r1, r2, {'R'}, nullptr);

    plantarNodoArbolBinario(e2, n2, {'E'}, r1);                    // E y R son hermanos bajo U
    plantarNodoArbolBinario(u, e2, {'U'}, nullptr);

    i->derecha = u;                                                // I y U son hermanos bajo B

    plantarNodoArbolBinario(b, i, {'B'}, nullptr);                 // B es la raiz

    arbol.raiz = b;
}

/*b) IMPRESION DE LAS PALABRAS
 *
 * Se recorre el arbol arrastrando el prefijo formado hasta el momento.
 * Si el nodo no tiene "izquierda" (no hay mas letras que seguir), el
 * prefijo actual + la letra del nodo es una palabra completa: se imprime.
 * Si tiene "izquierda", se sigue formando la palabra por ese lado.
 * Siempre se explora "derecha" (hermano) con el prefijo SIN la letra
 * del nodo actual, porque representa una rama alternativa distinta.
 */
void imprimirPalabras(const ArbolBinario & arbol) {
    imprimirPalabrasRecursivo(arbol.raiz, "");
}

void imprimirPalabrasRecursivo(NodoArbolBinario * nodo, string prefijo) {
    if (esNodoVacio(nodo))
        return;

    string nuevoPrefijo = prefijo + nodo->elemento.letra;

    if (esNodoVacio(nodo->izquierda))
        cout << nuevoPrefijo << endl;
    else
        imprimirPalabrasRecursivo(nodo->izquierda, nuevoPrefijo);

    imprimirPalabrasRecursivo(nodo->derecha, prefijo);
}

/*DESTRUCCION DEL ARBOL*/
void destruirArbolBinario(ArbolBinario & arbol) {
    destruirRecursivo(arbol.raiz);
    arbol.raiz = nullptr;
}

void destruirRecursivo(NodoArbolBinario * nodo) {
    if (not esNodoVacio(nodo)) {
        destruirRecursivo(nodo->izquierda);
        destruirRecursivo(nodo->derecha);
        delete nodo;
    }
}
