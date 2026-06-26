//
// Created by isabe on 26/06/2026.
//

#ifndef INC_20251MULTAS_EMPRESA_H
#define INC_20251MULTAS_EMPRESA_H
#include <string>
#include <vector>
#include <map>
#include "Vehiculo.h"
#include "Multa.h"
using namespace std;
class Empresa {
public:
    int get_dni() const;

    void set_dni(int dni);

    string get_nombre() const;

    void set_nombre(const string &nombre);

    string get_distrito() const;

    void set_distrito(const string &distrito);

private:
    int dni;
    string nombre;
    string distrito;
    map<string, Vehiculo> vehiculos;
    vector<Multa> multasRecibidas;

public:
    Empresa();


};


#endif //INC_20251MULTAS_EMPRESA_H
