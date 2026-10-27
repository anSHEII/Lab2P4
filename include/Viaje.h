#ifndef VIAJE_H
#define VIAJE_H

#include "DTFecha.h"
#include <string>
#include <vector>
#include <map>
#include "DTConsultaViaje.h"
#include "DTDetalleViaje.h"
#include "DTListarViaje.h"
class Pasajero;
class Reserva;
class Vehiculo;

class Viaje {
private:
    static int proximoCodigo;
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;
    std::vector<Reserva*> reservas;
    Vehiculo* vehiculo;
public:
    Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);

    static int getProximoCodigo();
    int getCodigo() const;
    DTFecha getFecha() const;
    std::string getOrigen() const;
    std::string getDestino() const;
    int getAsientosPublicados() const;
    float getPrecio() const;
    Vehiculo* getVehiculo() const;
    std::map<std::string, Pasajero*> getPasajeros() const;

    void setVehiculo(Vehiculo* v);
    void addReserva(Reserva* r);
    std::vector<Reserva*> getReservas() const;

    DTDetalleViaje getDetalleViaje() const;

    DTListarViaje getListarViaje() const;

    DTConsultaViaje getConsultaViaje(int asientos) const;

    bool puedeReservar(Pasajero* p, int asientos);

    bool validarViaje(DTFecha fecha, std::string origen, std::string destino, int asientos);

    DTConsultaViaje datosViaje();

    static Viaje* create(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio);

    static void incrementarProximoCodigo();

    ~Viaje();

};

#endif
