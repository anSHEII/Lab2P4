#ifndef DT_FECHA_H
#define DT_FECHA_H

#include <iostream>

class DTFecha {
private:
    int dia;
    int mes;
    int anio;

public:
    DTFecha();
    DTFecha(int dia, int mes, int anio);

    int getDia();
    int getMes();
    int getAnio();

    bool operator==(DTFecha other);

};

std::ostream& operator<<(std::ostream& os, DTFecha f);

#endif
