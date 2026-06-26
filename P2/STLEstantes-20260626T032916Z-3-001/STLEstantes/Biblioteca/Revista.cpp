//
// Created by cueva.r on 12/11/2025.
//
#include <string>
#include "Revista.h"

using namespace  std;

int Revista::get_anho() const {
    return anho;
}

void Revista::set_anho(int anho) {
    this->anho = anho;
}

int Revista::get_numero() const {
    return numero;
}

void Revista::set_numero(int numero) {
    this->numero = numero;
}

int Revista::get_vigencia() const {
    return vigencia;
}

void Revista::set_vigencia(int vigencia) {
    this->vigencia = vigencia;
}
//Boletin de Arqueologia PUCP,40,0.25,10292004,2023,3
//Boletin de Arqueologia PUCP,45,0.25,10292005,2023,2
void Revista::leerevista(ifstream& arch){
    char c;

    Libros::leelibros(arch);
    getline(arch,ISSN,',');
    arch >> anho >> c >> numero;
    arch.get();
}

string Revista::get_issn() const {
    return ISSN;
}

void Revista::set_issn(const string &issn) {
    ISSN = issn;
}

void Revista::imprimerevista(ofstream&arch) {
    Libros::imprimelibros(arch);
    arch << "ISSN: " << ISSN << "  Año" << anho <<" Numero "<< numero<<  endl;
}