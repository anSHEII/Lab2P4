#include "../include/DTFecha.h"

DTFecha::DTFecha() {
    this->dia = 1;
    this->mes = 1;
    this->anio = 1900;
}

DTFecha::DTFecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

int DTFecha::getDia() { return dia; }
int DTFecha::getMes() { return mes; }
int DTFecha::getAnio() { return anio; }

bool DTFecha::operator==(DTFecha other) {
    return (dia == other.dia && mes == other.mes && anio == other.anio);
}

std::ostream& operator<<(std::ostream& os, DTFecha f) {
    os << f.getDia() << "/" << f.getMes() << "/" << f.getAnio();
    return os;
}
