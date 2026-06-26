//
// Created by cueva.r on 12/11/2025.
//

#ifndef ESTANTE_LIBROS_H
#define ESTANTE_LIBROS_H
#include <fstream>

using namespace std;

class Libros {
public:
    Libros();
    Libros(const Libros &);
    int get_paginas() const;
    void set_paginas(int paginas);
    double get_peso() const;
    void set_peso(double peso);
    void get_nombre(char*) const;
    void set_nombre(char *);
    void leelibros(ifstream&);
    void imprimelibros(ofstream&) const;
    void operator=(const Libros &);

private:
        char *nombre;
        int paginas;
        double peso;
};


#endif //ESTANTE_LIBROS_H