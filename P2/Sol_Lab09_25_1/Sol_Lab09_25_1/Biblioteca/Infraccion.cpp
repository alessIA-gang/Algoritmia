//
// Created by Alan on 23/06/2026.
//

#include "Infraccion.h"

Infraccion::Infraccion() {
    multa = 0;
}

string Infraccion::get_codigo() const {
    return codigo;
}

void Infraccion::set_codigo(const string &codigo) {
    this->codigo = codigo;
}

double Infraccion::get_multa() const {
    return multa;
}

void Infraccion::set_multa(double multa) {
    this->multa = multa;
}

string Infraccion::get_gravedad() const {
    return gravedad;
}

void Infraccion::set_gravedad(const string &gravedad) {
    this->gravedad = gravedad;
}

string Infraccion::get_descripcion() const {
    return descripcion;
}

void Infraccion::set_descripcion(const string &descripcion) {
    this->descripcion = descripcion;
}

void Infraccion::leeinfracciones(ifstream &arch) {
    char c;
    getline(arch,codigo,',');
    if (arch.eof()) return;
    arch>>multa>>c;
    getline(arch,gravedad,',');
    getline(arch,descripcion,'\n');
}

bool Infraccion::operator<(const Infraccion &inf) const {
    return codigo < inf.codigo;
}
