//
// Created by Alan on 23/06/2026.
//

#ifndef SOL_LAB09_25_1_EMPRESA_H
#define SOL_LAB09_25_1_EMPRESA_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <list>
#include <vector>
using namespace std;
#include "Vehiculo.h"
#include "Multa.h"
#include "Infraccion.h"

class Empresa {
private:
    int dni;
    string nombre;
    string distrito;
    map<string,class Vehiculo> vehiculos;
    vector<class Multa> multasRecibidas;

public:
    Empresa();
    int get_dni() const;
    void set_dni(int dni);
    string get_nombre() const;
    void set_nombre(const string &nombre);
    string get_distrito() const;
    void set_distrito(const string &distrito);
    void leeempresa(ifstream &arch);
    void insertaVehiculo(ifstream &arch);
    void imprimirEmpresa(ofstream &arch);
    bool operator < (const Empresa &emp) const;
    void agregarMulta(const char *nomb, list<Infraccion> tablaInfracciones);
    void ordenarMultas();
    void eliminaMultasPagadas();
};


#endif //SOL_LAB09_25_1_EMPRESA_H
