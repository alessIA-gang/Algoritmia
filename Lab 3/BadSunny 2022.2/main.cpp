#include <iostream>

#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaPila/Pila.h"
#define N 20

using namespace std;

void calcularFrecuenciayDuracion(int frecuencias[N],int n,int &frecMaxima,int &duracion)
{
    Pila pila;
    ElementoPila elemento;
    construir(pila);
    int tiempo=1, area, intervalo, areaMaxima=0;
    while (tiempo<=n)
    {
        if (esPilaVacia(pila))
        {
            elemento.numero = tiempo;
            apilar(pila,elemento);
            tiempo++;
        }
        else
        {
            elemento = cima(pila);
            if (frecuencias[tiempo-1]>=frecuencias[elemento.numero-1])
            {
                elemento.numero = tiempo;
                apilar(pila,elemento);
                tiempo++;
            }
            else
            {
                //Aqui hay una desafinacion (bajada)
                elemento = desapilar(pila);
                intervalo = tiempo - elemento.numero;
                area = intervalo * frecuencias[elemento.numero-1];
                if (area>areaMaxima)
                {
                    frecMaxima = frecuencias[elemento.numero-1];
                    duracion = intervalo;
                    areaMaxima = area;
                }
            }
        }
    }
}

int main()
{
    int frecuencias[N] = {1,2,1,4,5,6,4,5,2,2,1};
    int n=11, frecMaxima, duracion;
    calcularFrecuenciayDuracion(frecuencias,n,frecMaxima,duracion);
    cout << "Frecuencia Máxima: " << frecMaxima << endl;
    cout << "Duración: " << duracion << endl;
    return 0;
}