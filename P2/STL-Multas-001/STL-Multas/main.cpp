#include "Biblioteca/MinisterioDeTransporte.h"

int main() {
    MinisterioDeTransporte min;
    min.cargaDeInfracciones("TablaDeInfracciones.csv");
    min.cargaEmpresas("EmpresasRegistradas.csv");
    min.cargaVehiculos("VehiculosRegistrados.csv");
    min.reporteDeEmpresas("reporte.txt");

    return 0;
}