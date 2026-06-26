//
// Created by cueva.r on 12/11/2025.
//

#ifndef ESTANTE_REVISTA_H
#define ESTANTE_REVISTA_H
#include "Libros.h"
#include <string>
#include <fstream>

using namespace  std;

class Revista:public Libros {
public:
    int get_anho() const;
    void set_anho(int anho);
    int get_numero() const;
    void set_numero(int numero);
    int get_vigencia() const;
    void set_vigencia(int vigencia);
    void leerevista(ifstream&);
    void imprimerevista(ofstream&);
    string get_issn() const;

    void set_issn(const string &issn);

private:
    int anho;
        int numero;
        int vigencia;
        string ISSN;

};


#endif //ESTANTE_REVISTA_H