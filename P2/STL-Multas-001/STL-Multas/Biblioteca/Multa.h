//
// Created by cueva.r on 17/06/2026.
//

#ifndef STL_MULTAS_MULTA_H
#define STL_MULTAS_MULTA_H
#include <string>

using namespace std;

class Multa {
    private:
        int fecha;
        string placa;
        string codMulta;
        double multa;

    public:
        int get_fecha() const;
        string get_placa() const;
        string get_cod_multa() const;
        double get_multa() const;
        bool is_pagada() const;
        int get_fecha_de_pago() const;
    private:
        bool pagada;
        int fechaDePago;
    public:
        Multa();
};


#endif //STL_MULTAS_MULTA_H