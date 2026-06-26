//
// Created by cueva.r on 17/06/2026.
//
#include <iomanip>
#include "Empresa.h"

using namespace std;

Empresa::Empresa() {

}

int Empresa::get_dni() const {
    return dni;
}

void Empresa::set_dni(int dni) {
    this->dni = dni;
}

string Empresa::get_nombre() const {
    return nombre;
}

void Empresa::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

string Empresa::get_distrito() const {
    return distrito;
}

void Empresa::set_distrito(const string &distrito) {
    this->distrito = distrito;
}

// 79672079,CONTRERAS CHANG JOHANA CINTHIA,CHORRILLOS
// 77763722,FARFAN SALAZAR MARGOT,LA MOLINA
void Empresa::leeempresa(ifstream &arch) {
    arch >> dni;
    if (arch.eof())return;
    arch.get();
    getline(arch,nombre,',');
    getline(arch,distrito,'\n');
}

void Empresa::cargarvehiculo(ifstream &arch) {
    Vehiculo aux;
    aux.leevehiculo(arch);
    vehiculos[aux.get_placa()]=aux;
}

void Empresa::imprimeempresa(ofstream &arch) {
    arch<<setw(20) << dni<<setw(40) << nombre<<setw(30) << distrito<<endl;
    for (map<string,Vehiculo>::iterator it=vehiculos.begin(); it!=vehiculos.end(); it++) {
        it->second.imprimevehiculo(arch);
    }
}
