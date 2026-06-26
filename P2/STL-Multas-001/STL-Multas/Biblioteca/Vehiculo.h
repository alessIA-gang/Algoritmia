//
// Created by cueva.r on 17/06/2026.
//

#ifndef STL_MULTAS_VEHICULO_H
#define STL_MULTAS_VEHICULO_H
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class Vehiculo {
    public:
        Vehiculo();
        string get_placa() const;
        void set_placa(const string &placa);
        string get_marca() const;
        void set_marca(const string &marca);
        string get_modelo() const;
        void set_modelo(const string &modelo);
        void leevehiculo(ifstream&);
        void imprimevehiculo(ofstream&);
    private:
        string placa;
        string marca;
        string modelo;
};


#endif //STL_MULTAS_VEHICULO_H