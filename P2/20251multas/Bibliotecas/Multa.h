//
// Created by isabe on 26/06/2026.
//

#ifndef INC_20251MULTAS_MULTA_H
#define INC_20251MULTAS_MULTA_H
#include <string>
using namespace std;

class Multa {
private:
    int fecha;
    string placa;
    string codMulta;
    bool pagada;
    int fechaDePago;

public:
    int get_fecha() const;

    void set_fecha(int fecha);

    string get_placa() const;

    void set_placa(const string &placa);

    string get_cod_multa() const;

    void set_cod_multa(const string &cod_multa);

    bool is_pagada() const;

    void set_pagada(bool pagada);

    int get_fecha_de_pago() const;

    void set_fecha_de_pago(int fecha_de_pago);
    void operator>>(ifstream &arch);

    Multa();
    virtual ~Multa();
};


#endif //INC_20251MULTAS_MULTA_H