//
// Created by cueva.r on 17/06/2026.
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
// M421-807,Honda,Fit
void Vehiculo::leevehiculo(ifstream &arch) {
    getline(arch, placa,',');
    if (arch.eof())return;
    getline(arch, marca,',');
    getline(arch, modelo,'\n');
}
void Vehiculo::imprimevehiculo(ofstream &arch) {
    arch<<left<<setw(20)<<placa<<setw(30)<<marca<<setw(30)<<modelo<<endl;
}

