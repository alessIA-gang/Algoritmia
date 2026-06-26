//
// Created by cueva.r on 12/11/2025.
//

#include "Estante.h"
Estante::Estante() {

}

Estante::Estante(const Estante &orig) {
    *this=orig;
}


int Estante::get_id() const {
    return id;
}

void Estante::set_id(int id) {
    this->id = id;
}

double Estante::get_capacidad() const {
    return capacidad;
}

void Estante::set_capacidad(double capacidad) {
    this->capacidad = capacidad;
}
/*
H,1,20
V,2,10
 */
void Estante::leestante(ifstream& arch) {
    char c;

    arch >> clase;
    if (arch.eof()) return;
    arch >> c >> id >> c >> capacidad;
    arch.get();
}

void Estante::operator=(const Estante& orig) {
    clase = orig.clase;
    id = orig.id;
    capacidad = orig.capacidad;
}

bool Estante::operator<(const Estante &aux) const {
    return id<aux.get_id();
}
bool Estante::operator==(const Estante &aux) const {
    return id == aux.id;
}

void Estante::imprimeestante(ofstream& arch) const {
    arch <<"Codigo:" << id << "  Capacidad:" << capacidad << endl;
    if (clase=='V')
        arch <<"Vertical" << endl;
    else
        arch <<"Horizontal" << endl;
    arch << "Libros contenidos:"<<endl;

}