//
// Created by cueva.r on 17/06/2026.
//

#ifndef STL_MULTAS_MINISTERIODETRANSPORTE_H
#define STL_MULTAS_MINISTERIODETRANSPORTE_H
#include <list>

#include "Empresa.h"
#include "Infraccion.h"

using namespace std;

class MinisterioDeTransporte {
    private:
        list<Infraccion>tablaInfracciones;
        list<Empresa>listaEmpresas;
        void buscarasigna(int dni,ifstream &arch);
    public:
        MinisterioDeTransporte();
        void cargaDeInfracciones(const char*);
        void cargaEmpresas(const char*);
        void cargaVehiculos(const char*);
        void reporteDeEmpresas(const char*);
};


#endif //STL_MULTAS_MINISTERIODETRANSPORTE_H