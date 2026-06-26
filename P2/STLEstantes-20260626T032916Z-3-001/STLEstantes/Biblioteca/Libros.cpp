//
// Created by cueva.r on 12/11/2025.
//

#include "Libros.h"
#include <cstring>

using namespace  std;

Libros::Libros() {
    nombre=nullptr;

}

Libros::Libros(const Libros &orig) {
    nombre = nullptr;
    *this = orig;

}


int Libros::get_paginas() const {
    return paginas;
}

void Libros::set_paginas(int paginas) {
    this->paginas = paginas;
}

double Libros::get_peso() const {
    return peso;
}

void Libros::set_peso(double peso) {
    this->peso = peso;
}
void Libros::set_nombre(char *cad) {
    if (nombre != nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Libros::get_nombre(char* cad) const {
    strcpy(cad,nombre);
}


/*
Boletin de Arqueologia PUCP,40,3.25
Boletin de Arqueologia PUCP,45,1.25
 */
void Libros::leelibros(ifstream &arch) {
    char cad[100],c;

    arch.getline(cad,100,',');
    set_nombre(cad);
    arch >> paginas >> c >> peso;
    arch.get();

}

void Libros::operator=(const Libros &orig) {
    char cad[100];

    orig.get_nombre(cad);
    set_nombre(cad);
    paginas = orig.paginas;
    peso = orig.peso;

}

void Libros::imprimelibros(ofstream &arch) const {
    arch << "Titulo: " << nombre << endl;
    arch << "Peso: " << peso << endl;

}

