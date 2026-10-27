#include "../include/DTConsultaViaje.h"

DTConsultaViaje::DTConsultaViaje(int codigo, std::string marca, std::string modelo, std::string conductor, float calificacionProm, float precioTotal) {
    this->codigo = codigo;
    this->marca = marca;
    this->modelo = modelo;
    this->conductor = conductor;
    this->calificacionProm = calificacionProm;
    this->precioTotal = precioTotal;
}

int DTConsultaViaje::getCodigo() const { return codigo; }
std::string DTConsultaViaje::getMarca() const { return marca; }
std::string DTConsultaViaje::getModelo() const { return modelo; }
std::string DTConsultaViaje::getConductor() const { return conductor; }
float DTConsultaViaje::getCalificacionProm() const { return calificacionProm; }
float DTConsultaViaje::getPrecioTotal() const { return precioTotal; }

bool DTConsultaViaje::operator<(const DTConsultaViaje& other) const {
    if (precioTotal != other.precioTotal)
        return precioTotal < other.precioTotal;
    return calificacionProm > other.calificacionProm;
}
