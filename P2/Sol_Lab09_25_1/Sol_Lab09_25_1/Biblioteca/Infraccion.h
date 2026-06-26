//
// Created by Alan on 23/06/2026.
//

#ifndef SOL_LAB09_25_1_INFRACCION_H
#define SOL_LAB09_25_1_INFRACCION_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


class Infraccion {
private:
    string codigo;
    double multa;
    string gravedad;
    string descripcion;

public:
    Infraccion();
    string get_codigo() const;
    void set_codigo(const string &codigo);
    double get_multa() const;
    void set_multa(double multa);
    string get_gravedad() const;
    void set_gravedad(const string &gravedad);
    string get_descripcion() const;
    void set_descripcion(const string &descripcion);
    void leeinfracciones(ifstream &arch);
    bool operator < (const Infraccion & inf) const;
};


#endif //SOL_LAB09_25_1_INFRACCION_H
