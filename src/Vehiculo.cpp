#include "../include/Vehiculo.h"
#include "../include/Viaje.h"
#include "../include/Conductor.h"

Vehiculo::Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
    this->conductor = nullptr;
}

Vehiculo::~Vehiculo() {}

DTDetalleVehiculo Vehiculo::getDetalleVehiculo() const {
    return DTDetalleVehiculo(matricula, capacidad, marca, modelo, tipo);
}

std::string Vehiculo::getMatricula() const {
    return matricula;
}

int Vehiculo::getCapacidad() const {
    return capacidad;
}

std::string Vehiculo::getMarca() const {
    return marca;
}

std::string Vehiculo::getModelo() const {
    return modelo;
}

TipoVehiculo Vehiculo::getTipo() const {
    return tipo;
}

Conductor* Vehiculo::getConductor() const {
    return conductor;
}

void Vehiculo::setConductor(Conductor* c) {
    this->conductor = c;
}

void Vehiculo::addViaje(Viaje* v) {
    viajes.insert({v->getCodigo(), v});
}

void Vehiculo::eliminarViaje(Viaje* v) {
    viajes.erase(v->getCodigo());
}

std::map<int, Viaje*> Vehiculo::getViajes() const {
    return viajes;
}

bool Vehiculo::hayViajesConductor(DTFecha fecha){
    return this->getConductor()->hayViajesFechaConductor(fecha);
}

bool Vehiculo::hayViajesFecha(DTFecha fecha){
    for(auto viaje: viajes){
        if(viaje.second->getFecha() == fecha) return true;
    }
    return false;
}

