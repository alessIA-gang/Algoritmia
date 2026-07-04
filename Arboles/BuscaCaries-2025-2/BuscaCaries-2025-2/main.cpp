#include <iostream>
#define N 20

using namespace std;

int buscarCaries(int densidades[N],int T,int inicio,int fin)
{
    if (inicio>fin)
    {
        return -1;
    }
    int medio = (inicio+fin)/2;
    if (densidades[medio]<T)
    {
        int izquierda = buscarCaries(densidades,T,inicio,medio-1);
        if (izquierda==-1)
        {
            return medio;
        }
        else
        {
            return izquierda;
        }
    }
    else
    {
        return buscarCaries(densidades,T,medio+1,fin);
    }
}

int main()
{
    int densidades[N] = {98,95,93,90,72,60,55,50};
    int n = 8;
    int T = 100;
    int posicion = buscarCaries(densidades,T,0,n-1);
    cout << "Posicion: " << posicion << endl;
    if (posicion>=0)
    {
        cout << "Primera zona con caries clínica detectada en la posición " << posicion << endl;
        cout << "Densidad registrada: " << densidades[posicion] << endl;
    }
    else
    {
        cout << "No se detecta caries clínica";
    }
    return 0;
}