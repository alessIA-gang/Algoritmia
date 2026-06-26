//
// Created by isabe on 26/06/2026.
//

#ifndef INC_20251MULTAS_INFRACCION_H
#define INC_20251MULTAS_INFRACCION_H
#include <string>
#include <fstream>
using namespace std;

class Infraccion {
public:
    string get_codigo() const;

    void set_codigo(const string &cadena);

    double get_multa() const;

    void set_multa(double multa);

    string get_gravedad() const;

    void set_gravedad(const string &gravedad);

    string get_descripcion() const;

    void set_descripcion(const string &descripcion);
    bool compara(const Infraccion &infraccion);
private:
    string codigo;
    double multa;
    string gravedad;
    string descripcion;
public:
    Infraccion();
    virtual ~Infraccion();
};

void operator >>(ifstream&arch,Infraccion &inf);


#endif //INC_20251MULTAS_INFRACCION_H
