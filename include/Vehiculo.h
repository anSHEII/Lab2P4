#ifndef VEHICULO_H
#define VEHICULO_H

#include "TipoVehiculo.h"
#include "DTFecha.h"
#include <string>
#include <map>
#include "DTDetalleVehiculo.h"
class Viaje;
class Conductor;

class Vehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;
    std::map<int, Viaje*> viajes;
    Conductor* conductor;

public:
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
    ~Vehiculo();

    std::string getMatricula() const;
    int getCapacidad() const;
    std::string getMarca() const;
    std::string getModelo() const;
    TipoVehiculo getTipo() const;
    Conductor* getConductor() const;

    void eliminarViaje(Viaje* v);
    std::map<int, Viaje*> getViajes() const;

    DTDetalleVehiculo getDetalleVehiculo() const;

    void setConductor(Conductor* c);
    void addViaje(Viaje* v);

    bool hayViajesConductor(DTFecha fecha);
    bool hayViajesFecha(DTFecha fecha);
};

#endif
