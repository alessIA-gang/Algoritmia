#include <iostream>

#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#define N 20

using namespace std;

void merge(int codigos[N],int inicio,int medio,int fin)
{
    int aux[N];
    int i = inicio, j=medio+1, p=inicio;
    while(i<=medio && j<=fin)
    {
        if (codigos[i]>codigos[j])
        {
            aux[p] = codigos[j];
            j++;
        }
        else
        {
            aux[p] = codigos[i];
            i++;
        }
        p++;
    }
    while(i<=medio)
    {
        aux[p] = codigos[i];
        p++; i++;
    }
    while(j<=fin)
    {
        aux[p] = codigos[j];
        p++; j++;
    }
    for (i=inicio; i<= fin; i++)
    {
        codigos[i] = aux[i];
    }
}

void mergeSort(int codigos[N],int inicio,int fin)
{
    if (inicio>=fin)
    {
        return ;
    }
    int medio = (inicio+fin)/2;
    mergeSort(codigos,inicio,medio);
    mergeSort(codigos,medio+1,fin);
    merge(codigos,inicio,medio,fin);
}

void insertarAVL(int codigos[N],int inicio,int fin,NodoArbolBinarioBusqueda * &nodo)
{
    if (inicio>fin)
    {
        return ;
    }
    int medio = (inicio+fin)/2;
    ElementoArbolBinarioBusqueda elemento;
    elemento.numero = codigos[medio];
    insertarRecursivo(nodo,elemento);
    insertarAVL(codigos,inicio,medio-1 ,nodo);
    insertarAVL(codigos,medio+1,fin ,nodo);
}

int main()
{
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    int codigos[N] = {15,10,12,20,8,7,16,35};
    int n = 8;
    /*Paso 1. ordenar*/
    mergeSort(codigos,0,n-1);
    /*Paso 2. insertarconDV*/
    insertarAVL(codigos,0,n-1,arbol.raiz);
    if (esEquilibrado(arbol))
    {
        cout << "El árbol creado es equilibrado" << endl;
    }
    else
    {
        cout << "El árbol creado no es equilibrado" << endl;
    }
    recorrerPreOrden(arbol);
    return 0;
}