//
// Created by Alan on 23/06/2026.
//

#include "MinisterioDeTransporte.h"

MinisterioDeTransporte::MinisterioDeTransporte() {

}

void MinisterioDeTransporte::cargaDeInfracciones(const char *nomb) {
    ifstream arch(nomb, ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nomb<<endl;
        exit(1);
    }
    Infraccion aux;
    while (true) {
        aux.leeinfracciones(arch);
        if (arch.eof()) break;
        tablaInfracciones.push_back(aux);
    }
    tablaInfracciones.sort();
}

void MinisterioDeTransporte::cargaEmpresas(const char *nomb) {
    ifstream arch(nomb, ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nomb<<endl;
        exit(1);
    }
    Empresa aux;
    while (true) {
        aux.leeempresa(arch);
        if (arch.eof()) break;
        listaEmpresas.push_back(aux);
    }
    listaEmpresas.sort();
}

void MinisterioDeTransporte::cargaVehiculos(const char *nomb) {
    ifstream arch(nomb, ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nomb<<endl;
        exit(1);
    }
    int dni;
    char c;
    while (true) {
        arch>>dni>>c;
        if (arch.eof()) break;
        buscayasigna(dni,arch);
    }
}

void MinisterioDeTransporte::buscayasigna(int dni, ifstream &arch) {
    for (list<Empresa>::iterator it=listaEmpresas.begin();
                                                it!=listaEmpresas.end(); it++) {
        if (it->get_dni() == dni) {
            it->insertaVehiculo(arch);
            return;
        }
    }
    while (arch.get()!='\n');
}

void MinisterioDeTransporte::cargaInfraccionesCometidas(const char *nomb) {
    for (list<Empresa>::iterator itE = listaEmpresas.begin(); itE != listaEmpresas.end(); ++itE) {
        itE->agregarMulta(nomb,tablaInfracciones);
        // itE->ordenarMultas(); // Se ordena inmediatamente después de cargar
    }
}

void MinisterioDeTransporte::reporteDeEmpresasConInfracciones(const char *nomb) {
    ofstream arch(nomb, ios::out);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nomb<<endl;
        exit(1);
    }
    for (list<Empresa>::iterator it=listaEmpresas.begin();
                                        it!=listaEmpresas.end();it++) {
        it->imprimirEmpresa(arch);
    }
}

void MinisterioDeTransporte::eliminaInfraccionesPagadas() {
    // Delegación limpia: cada empresa limpia su propio contenedor
    for (list<Empresa>::iterator itE = listaEmpresas.begin(); itE != listaEmpresas.end(); ++itE) {
        itE->eliminaMultasPagadas();
    }
}