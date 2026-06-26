//
// Created by Alan on 23/06/2026.
//

#ifndef SOL_LAB09_25_1_MINISTERIODETRANSPORTE_H
#define SOL_LAB09_25_1_MINISTERIODETRANSPORTE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <list>
using namespace std;
#include "Infraccion.h"
#include "Empresa.h"

class MinisterioDeTransporte {
private:
    list<class Infraccion> tablaInfracciones;
    list<class Empresa> listaEmpresas;
public:
    MinisterioDeTransporte();
    void cargaDeInfracciones(const char *nomb);
    void cargaEmpresas(const char *nomb);
    void cargaVehiculos(const char *nomb);
    void buscayasigna(int dni, ifstream &arch);
    void cargaInfraccionesCometidas(const char *nomb);
    void reporteDeEmpresasConInfracciones(const char *nomb);
    void eliminaInfraccionesPagadas();
};


#endif //SOL_LAB09_25_1_MINISTERIODETRANSPORTE_H
