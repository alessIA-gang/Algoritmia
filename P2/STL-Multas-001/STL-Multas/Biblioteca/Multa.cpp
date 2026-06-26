//
// Created by cueva.r on 17/06/2026.
//

#include "Multa.h"

Multa::Multa() {

}

int Multa::get_fecha() const {
    return fecha;
}

string Multa::get_placa() const {
    return placa;
}

string Multa::get_cod_multa() const {
    return codMulta;
}

double Multa::get_multa() const {
    return multa;
}

bool Multa::is_pagada() const {
    return pagada;
}

int Multa::get_fecha_de_pago() const {
    return fechaDePago;
}


