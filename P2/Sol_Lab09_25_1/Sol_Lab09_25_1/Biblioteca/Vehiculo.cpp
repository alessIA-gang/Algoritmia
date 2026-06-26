//
// Created by Alan on 23/06/2026.
//

#include "Vehiculo.h"

Vehiculo::Vehiculo() {

}

string Vehiculo::get_placa() const {
    return placa;
}

void Vehiculo::set_placa(const string &placa) {
    this->placa = placa;
}

string Vehiculo::get_marca() const {
    return marca;
}

void Vehiculo::set_marca(const string &marca) {
    this->marca = marca;
}

string Vehiculo::get_modelo() const {
    return modelo;
}

void Vehiculo::set_modelo(const string &modelo) {
    this->modelo = modelo;
}

void Vehiculo::leeVehiculo(ifstream &arch) {
    getline(arch, placa,',');
    if (arch.eof()) return;
    getline(arch, marca,',');
    getline(arch, modelo,'\n');
}

void Vehiculo::imprimirVehiculo(ofstream &arch) {
    arch<<setw(10)<<left<<placa<<setw(15)<<left<<marca
        <<setw(20)<<left<<modelo<<endl;
}
