//
// Created by Alan on 23/06/2026.
//

#ifndef SOL_LAB09_25_1_VEHICULO_H
#define SOL_LAB09_25_1_VEHICULO_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class Vehiculo {
private:
    string placa;
    string marca;
    string modelo;

public:
    Vehiculo();
    string get_placa() const;
    void set_placa(const string &placa);
    string get_marca() const;
    void set_marca(const string &marca);
    string get_modelo() const;
    void set_modelo(const string &modelo);
    void leeVehiculo(ifstream &arch);
    void imprimirVehiculo(ofstream &arch);
};


#endif //SOL_LAB09_25_1_VEHICULO_H
