//
// Created by Alan on 23/06/2026.
//

#ifndef SOL_LAB09_25_1_MULTA_H
#define SOL_LAB09_25_1_MULTA_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class Multa {
private:
    int fecha;
    string placa;
    string codMulta;
    double multa;
    bool pagada;
    int fechaDePago;

public:
    Multa();
    int get_fecha_de_pago() const;
    void set_fecha_de_pago(int fecha_de_pago);
    int get_fecha() const;
    void set_fecha(int fecha);
    string get_placa() const;
    void set_placa(const string &placa);
    string get_cod_multa() const;
    void set_cod_multa(const string &cod_multa);
    double get_multa() const;
    void set_multa(double multa);
    bool is_pagada() const;
    void set_pagada(bool pagada);
    void leeMultas(ifstream &arch);
    bool operator<(const Multa &mul) const;
    void imprimirMulta(ofstream &arch);
};


#endif //SOL_LAB09_25_1_MULTA_H
