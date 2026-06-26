//
// Created by cueva.r on 17/06/2026.
//

#include "MinisterioDeTransporte.h"
#include <iostream>

using namespace std;

MinisterioDeTransporte::MinisterioDeTransporte() {

}

void MinisterioDeTransporte::cargaDeInfracciones(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch.is_open()) {
        cout <<"Error no se puede abrir el archivo "<<nom<<endl;
        exit(1);
    }
    while (true) {
        Infraccion aux;
        aux.leeinfraccion(arch);
        if (arch.eof())break;
        tablaInfracciones.push_back(aux);
    }
}

void MinisterioDeTransporte::cargaEmpresas(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch.is_open()) {
        cout <<"Error no se puede abrir el archivo "<<nom<<endl;
        exit(1);
    }
    while (true) {
        Empresa aux;
        aux.leeempresa(arch);
        if (arch.eof())break;
        listaEmpresas.push_back(aux);
    }
}

void MinisterioDeTransporte::cargaVehiculos(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch.is_open()) {
        cout <<"Error no se puede abrir el archivo "<<nom<<endl;
        exit(1);
    }
    while (true) {
        int dni;
        arch >> dni;
        if (arch.eof())break;
        arch.get();
        buscarasigna(dni,arch);
    }
}

void MinisterioDeTransporte::buscarasigna(int dni,ifstream &arch) {
    char cad[200];
    for (list<Empresa>::iterator it=listaEmpresas.begin();
        it!=listaEmpresas.end(); it++) {
        if (it->get_dni()==dni) {
            it->cargarvehiculo(arch);
            return;
        }
    }
    arch.getline(cad,200);
}

void MinisterioDeTransporte::reporteDeEmpresas(const char *nom) {
    ofstream arch(nom,ios::out);
    if (not arch.is_open()) {
        cout <<"Error no se puede abrir el archivo "<<nom<<endl;
        exit(1);
    }
    for (list<Empresa>::iterator it=listaEmpresas.begin();
    it!=listaEmpresas.end(); it++) {
        it->imprimeempresa(arch);
        arch<<endl;
    }

}