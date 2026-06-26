//
// Created by isabe on 26/06/2026.
//

#include "Multa.h"
#include <fstream>

int Multa::get_fecha() const {
    return fecha;
}

void Multa::set_fecha(int fecha) {
    this->fecha = fecha;
}

string Multa::get_placa() const {
    return placa;
}

void Multa::set_placa(const string &placa) {
    this->placa = placa;
}

string Multa::get_cod_multa() const {
    return codMulta;
}

void Multa::set_cod_multa(const string &cod_multa) {
    codMulta = cod_multa;
}

bool Multa::is_pagada() const {
    return pagada;
}

void Multa::set_pagada(bool pagada) {
    this->pagada = pagada;
}

int Multa::get_fecha_de_pago() const {
    return fechaDePago;
}

void Multa::set_fecha_de_pago(int fecha_de_pago) {
    fechaDePago = fecha_de_pago;
}

void Multa::operator>>(ifstream &arch) {
    // 1/12/2020,G760-721,G2022,N
    // 23/07/2023,P474-593,G2060,P,22/08/2023
//falta leer multa
    int dd, mm, aa;
    char c,let;
    arch >> dd;
    if (arch.eof())return;
    arch >> c >> mm >> c >> aa >> c;
    set_fecha(aa * 10000 + mm * 100 + dd);
    getline(arch, placa, ',');
    getline(arch, codMulta, ',');
arch>>let;
    if (let=='P') {
        pagada = true;
        arch>>c>>dd>>c>>mm>>c>>aa;
        set_fecha_de_pago(aa * 10000 + mm * 100 + dd);
    }
    else {
        arch.ignore();
    }
}

Multa::Multa() {
    fechaDePago = 0;
    fecha = 0;
}

Multa::~Multa() {
}
