#include "../include/DTVehiculosConductor.h"

DTVehiculosConductor::DTVehiculosConductor(std::string matricula, std::string marca, int capacidad) {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    
}


std::string DTVehiculosConductor::getMatricula() {
    return matricula;
}
int DTVehiculosConductor::getCapacidad() {
    return capacidad;
}
std::string DTVehiculosConductor::getMarca() {
    return marca;
}