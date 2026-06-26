//
// Created by cueva.r on 12/11/2025.
//

#ifndef ESTANTE_ESTANTE_H
#define ESTANTE_ESTANTE_H
#include <fstream>

using namespace std;

class Estante {
public:
    Estante();
    Estante(const Estante&);
    int get_id() const;
    void set_id(int id);
    double get_capacidad() const;
    void set_capacidad(double capacidad);
    void leestante(ifstream&);
    void operator=(const Estante&);
    bool operator==(const Estante&) const;
    bool operator<(const Estante&) const;
    void imprimeestante(ofstream&) const;

private:
        char clase;
        int id;
        double capacidad;
};


#endif //ESTANTE_ESTANTE_H