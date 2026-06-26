//
// Created by isabe on 26/06/2026.
//

#include "Empresa.h"

int Empresa::get_dni() const {
    return dni;
}

void Empresa::set_dni(int dni) {
    this->dni = dni;
}

 Empresa::Empresa() {
  dni=0;
}
