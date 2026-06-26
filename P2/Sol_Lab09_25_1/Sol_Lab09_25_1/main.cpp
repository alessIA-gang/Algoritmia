#include "Biblioteca/MinisterioDeTransporte.h"
using namespace std;

int main() {
    MinisterioDeTransporte min;

    min.cargaDeInfracciones("Datos/TablaDeInfracciones.csv");
    min.cargaEmpresas("Datos/EmpresasRegistradas.csv");
    min.cargaVehiculos("Datos/VehiculosRegistrados.csv");
    min.cargaInfraccionesCometidas("Datos/InfraccionesCometidas.csv");
    min.reporteDeEmpresasConInfracciones("Reporte/Reporte.txt");
    min.eliminaInfraccionesPagadas();
    min.reporteDeEmpresasConInfracciones("Reporte/ReporteDeudas.txt");

    return 0;
}
