//
// Created by cueva.r on 24/06/2026.
//

#ifndef STLESTANTES_LIBRERIA_H
#define STLESTANTES_LIBRERIA_H
#include <map>
#include <vector>
#include "Estante.h"
#include "Libros.h"


class Libreria {
    private:
        map<Estante,vector<Libros>> mlibros;
    public:
        void carga();
        void cargalibros();
};


#endif //STLESTANTES_LIBRERIA_H