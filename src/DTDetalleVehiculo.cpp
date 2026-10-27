#include "../include/DTDetalleVehiculo.h"

DTDetalleVehiculo::DTDetalleVehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo)
    {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
}

std::string DTDetalleVehiculo::getMatricula() { return matricula; }
int DTDetalleVehiculo::getCapacidad() { return capacidad; }
std::string DTDetalleVehiculo::getMarca() { return marca; }
std::string DTDetalleVehiculo::getModelo() { return modelo; }
TipoVehiculo DTDetalleVehiculo::getTipo() { return tipo; }
