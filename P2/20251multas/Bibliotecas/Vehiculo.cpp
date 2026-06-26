//
// Created by isabe on 26/06/2026.
//

#include "Vehiculo.h"

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

Vehiculo::Vehiculo() {

}

Vehiculo::~Vehiculo() {

}

void Vehiculo::operator>>(ifstream &arch) {
    // 12443643,M421-807,Honda,Fit
    // 90467829,P985-495,Honda,HR-V
    // 80310768,M982-853,Honda,Civic
    int dni;
    arch >> dni;
    if (arch.eof())return;
    arch.get();
    getline(arch, placa,',');
    getline(arch, marca,',');
    getline(arch, modelo,'\n');
}
