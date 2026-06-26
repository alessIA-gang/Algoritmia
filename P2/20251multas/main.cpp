/* 
 * Archivo:   main.cpp
 * Autor: Alessia Gastello 
 */

#include <iostream>
#include <iomanip>

#include "Bibliotecas/MinisterioDeTransporte.h"
using namespace std;

int main(int argc, char **argv) {
    MinisterioDeTransporte min;
    min.cargaDeInfracciones("Datos/TablaDeInfracciones.csv");

    return 0;
}