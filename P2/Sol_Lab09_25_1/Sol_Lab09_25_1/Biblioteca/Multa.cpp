//
// Created by Alan on 23/06/2026.
//

#include "Multa.h"

Multa::Multa() {
    fecha = 0;
    multa = 0;
    pagada = false;
    fechaDePago=0;
}

int Multa::get_fecha_de_pago() const {
    return fechaDePago;
}

void Multa::set_fecha_de_pago(int fecha_de_pago) {
    fechaDePago = fecha_de_pago;
}

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

double Multa::get_multa() const {
    return multa;
}

void Multa::set_multa(double multa) {
    this->multa = multa;
}

bool Multa::is_pagada() const {
    return pagada;
}

void Multa::set_pagada(bool pagada) {
    this->pagada = pagada;
}

void Multa::leeMultas(ifstream &arch) {
    int dd,mm,aa,ddP,mmP,aaP;
    char c,tipo;
    arch>>dd>>c>>mm>>c>>aa>>c;
    if (arch.eof()) return;
    fecha = aa*10000+mm*100+dd;
    getline(arch,placa,',');
    getline(arch,codMulta,',');
    arch>>tipo;
    if (tipo=='P') {
        pagada = true;
        arch>>c>>ddP>>c>>mmP>>c>>aaP;
        fechaDePago = aaP*10000+mmP*100+ddP;
    }
    else
        pagada = false;
}

bool Multa::operator<(const Multa& mul) const {
    return fecha > mul.fecha;
}

void Multa::imprimirMulta(ofstream &arch) {
    arch<<setw(10)<<left<<placa<<setw(15)<<left<<fecha
        <<setw(10)<<left<<codMulta<<setw(10)<<left<<multa;
    if (pagada) {
        arch<<setw(10)<<"SI";
        arch<<setw(10)<<fechaDePago;
    }
    else
        arch<<setw(10)<<"NO";
    arch<<endl;
}
