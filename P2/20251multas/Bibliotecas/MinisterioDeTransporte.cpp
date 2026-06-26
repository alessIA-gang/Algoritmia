//
// Created by isabe on 26/06/2026.
//

#include "MinisterioDeTransporte.h"
#include "Infraccion.h"
void MinisterioDeTransporte::cargaDeInfracciones(const char *a) {
    ifstream arch(a,ios::in);
    if(!arch.is_open()) {
        cout<<"Error archivo infracciones"<<endl;
        exit(1);
    }
    while (true) {
        Infraccion aux;
        arch>>aux;
        if (arch.eof()) break;
        tablaInfracciones.push_back(aux);
    }
    tablaInfracciones.sort(compara);
}

bool compara(const Infraccion &infraccion, const Infraccion &infraccion2) {
        return infraccion.get_codigo()<infraccion2.get_codigo();
}
