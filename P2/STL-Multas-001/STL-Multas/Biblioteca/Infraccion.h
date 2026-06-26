//
// Created by cueva.r on 17/06/2026.
//

#ifndef STL_MULTAS_INFRACCION_H
#define STL_MULTAS_INFRACCION_H
#include <string>
#include <fstream>

using namespace std;

class Infraccion {
    private:
        string codigo;
        double multa;
        string gravedad;
        string descripcion;
    public:
        Infraccion();
        string get_codigo() const;
        void set_codigo(const string &codigo);
        double get_multa() const;
        void set_multa(double multa);
        string get_gravedad() const;
        void set_gravedad(const string &gravedad);
        string get_descripcion() const;
        void set_descripcion(const string &descripcion);
        void leeinfraccion(ifstream&);
};


#endif //STL_MULTAS_INFRACCION_H