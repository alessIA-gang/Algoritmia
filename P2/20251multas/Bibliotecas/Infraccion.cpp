//
// Created by isabe on 26/06/2026.
//

#include "Infraccion.h"

string Infraccion::get_codigo() const {
    return codigo;
}

void Infraccion::set_codigo(const string &cadena) {
    this->codigo = cadena;
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

bool Infraccion::compara(const Infraccion &infraccion) {
    return codigo>infraccion.codigo;
}

Infraccion::Infraccion() {
    multa = 0;
}

Infraccion::~Infraccion() {
}

void operator>>(ifstream &arch,Infraccion&inf) {
    //G2007,425.23,GRAVE,No conducir por el carril de extremo derecho de la calzada un vehiculo de transporte p�blico de pasajeros o de carga.
    char c;
    string code,grav,desc;
    double mul;
    getline(arch, code, ',');
    if (arch.eof())return;
    arch >> mul >> c;
    getline(arch, grav, ',');
    getline(arch, desc, '\n');
    inf.set_multa(mul);
    inf.set_codigo(code);
    inf.set_descripcion(desc);
    inf.set_gravedad(grav);
}
