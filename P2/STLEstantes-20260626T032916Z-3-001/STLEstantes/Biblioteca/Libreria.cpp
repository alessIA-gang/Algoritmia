//
// Created by cueva.r on 24/06/2026.
//
#include <iostream>
#include "Libreria.h"

void Libreria::carga() {
    ifstream arch("Estantes2.csv", ios::in);
    if (not arch.is_open()) {
        cout <<"No se puede abrir el archivo Estantes";
        exit(1);
    }
    while (true) {
        Estante aux;
        aux.leestante(arch);
        if (arch.eof())break;
        vector<Libros>vlibros;
        mlibros[aux]=vlibros;
    }
}

void Libreria::cargalibros() {
    ifstream arch("Libros4.csv", ios::in);
    if (not arch.is_open()) {
        cout <<"No se puede abrir el archivo Libros";
        exit(1);
    }
    while (true) {
        Libros aux;
        aux.leelibros(arch);
        if (arch.eof())break;
        for (map<Estante,vector<Libros>>::iterator it=mlibros.begin();
            it!=mlibros.end(); it++) {
            double total=0;
            for (int i=0;i<it->second.size();i++)
                total+=it->second[i].get_peso();
            if (it->first.get_capacidad()-total>=aux.get_peso()) {
                it->second.push_back(aux);
                break;
            }
        }
    }
}


