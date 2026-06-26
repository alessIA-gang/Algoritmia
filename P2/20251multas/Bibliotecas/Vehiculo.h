//
// Created by isabe on 26/06/2026.
//

#ifndef INC_20251MULTAS_VEHICULO_H
#define INC_20251MULTAS_VEHICULO_H
#include <string>
#include <fstream>
using namespace std;

class Vehiculo {
public:
    string get_placa() const;

    void set_placa(const string &placa);

    string get_marca() const;

    void set_marca(const string &marca);

    string get_modelo() const;

    void set_modelo(const string &modelo);

private:
    string placa;
     string marca;
    string modelo;
    public:
    Vehiculo();
    virtual ~Vehiculo();
    void operator>>(ifstream&arch);
};


#endif //INC_20251MULTAS_VEHICULO_H
