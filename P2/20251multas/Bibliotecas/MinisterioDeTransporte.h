//
// Created by isabe on 26/06/2026.
//

#ifndef INC_20251MULTAS_MINISTERIODETRANSPORTE_H
#define INC_20251MULTAS_MINISTERIODETRANSPORTE_H
#include <list>
#include <iostream>

#include "Empresa.h"
#include "Infraccion.h"
using namespace std;

class MinisterioDeTransporte {
    private:
        list<Infraccion> tablaInfracciones;
        list<Empresa> listaEmpresas;

    public:
    void cargaDeInfracciones(const char*a);

};
bool compara(const Infraccion &infraccion, const Infraccion &infraccion2);




#endif //INC_20251MULTAS_MINISTERIODETRANSPORTE_H
