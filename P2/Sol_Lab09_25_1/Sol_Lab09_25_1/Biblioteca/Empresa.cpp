//
// Created by Alan on 23/06/2026.
//

#include "Empresa.h"

Empresa::Empresa() {
    dni=0;
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

void Empresa::leeempresa(ifstream &arch) {
    char c;
    arch>>dni>>c;
    if (arch.eof()) return;
    getline(arch,nombre,',');
    getline(arch,distrito,'\n');
}

void Empresa::insertaVehiculo(ifstream &arch) {
    Vehiculo aux;
    aux.leeVehiculo(arch);
    vehiculos[aux.get_placa()] = aux;
}

bool Empresa::operator<(const Empresa &emp) const {
    return dni<emp.dni;
}

void Empresa::agregarMulta(const char *nomb, list<Infraccion> tablaInfracciones) {
    ifstream arch(nomb, ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nomb<<endl;
        exit(1);
    }
    Multa aux;
    while (true) {
        aux.leeMultas(arch);
        if (arch.eof()) break;
        if (vehiculos.find(aux.get_placa())!= vehiculos.end()) {
            // Completar el valor de la multa buscando en la tabla de referencia
            for (list<Infraccion>::const_iterator it = tablaInfracciones.begin(); it != tablaInfracciones.end(); ++it) {
                if (it->get_codigo() == aux.get_cod_multa()) {
                    aux.set_multa(it->get_multa());
                    break;
                }
            }
            multasRecibidas.push_back(aux);
        }
    }
}

void Empresa::ordenarMultas() {
    // Al no pasarle un tercer parámetro, sort buscará automáticamente
    // el operator< que definiste dentro de la clase Multa.
    sort(multasRecibidas.begin(), multasRecibidas.end());
}

void Empresa::eliminaMultasPagadas() {
    // Uso de iteradores seguro con erase para limpiar el vector interno
    for (vector<Multa>::iterator it = multasRecibidas.begin(); it != multasRecibidas.end(); ) {
        if (it->is_pagada()) {
            it = multasRecibidas.erase(it); // erase actualiza el iterador automáticamente
        } else {
            ++it;
        }
    }
}

void Empresa::imprimirEmpresa(ofstream &arch) {
    arch<<setw(15)<<left<<dni<<setw(45)<<left<<nombre
        <<setw(20)<<left<<distrito<<endl;
    arch<<"VEHICULOS DE LA EMPRESA:"<<endl;
    for (map<string, Vehiculo>::iterator it=vehiculos.begin();
                        it!=vehiculos.end();it++) {
        it->second.imprimirVehiculo(arch);
    }
    arch<<"---------------------------------------------------------------------------------"<<endl;
    arch<<"MULTAS IMPUESTAS:"<<endl;
    for (vector<Multa>::iterator it = multasRecibidas.begin(); it != multasRecibidas.end(); it++) {
        it->imprimirMulta(arch);
    }
    arch<<"=================================================================================="<<endl;
}