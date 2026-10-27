#ifndef RESERVA_H
#define RESERVA_H

#include "DTFecha.h"
#include "DTDetalleReserva.h"
#include <vector>
class Pasajero;
class Viaje;
class Calificacion;

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;
    Pasajero* pasajero;
    Viaje* viaje;
    std::vector<Calificacion*> calificaciones;
public:
    Reserva(int asientosReservados, DTFecha fecha, Pasajero* pasajero, Viaje* viaje);

    int getAsientosReservados() const;
    Pasajero* getPasajero() const;
    Viaje* getViaje() const;

    bool esPasajeroIgual(Pasajero* p);

    bool resvSobreViaje(int codigo);

    void agregarCalAReserva(Calificacion* calificacion);

    DTDetalleReserva getDetalleReserva() const;

    ~Reserva();
};

#endif
