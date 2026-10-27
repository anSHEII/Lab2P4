#include "../include/Reserva.h"
#include "../include/Pasajero.h"
#include "../include/Viaje.h"
#include "../include/Calificacion.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha, Pasajero* pasajero, Viaje* viaje) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
    this->pasajero = pasajero;
    this->viaje = viaje;
}

DTDetalleReserva Reserva::getDetalleReserva() const {
    return DTDetalleReserva(asientosReservados, fecha, this->pasajero->getNickname());
}

int Reserva::getAsientosReservados() const {
    return asientosReservados;
}

Pasajero* Reserva::getPasajero() const {
    return pasajero;
}

Viaje* Reserva::getViaje() const {
    return viaje;
}

bool Reserva::esPasajeroIgual(Pasajero* p) {
    return pasajero == p;
}

bool Reserva::resvSobreViaje(int codigo) {
    return viaje->getCodigo() == codigo;
}

void Reserva::agregarCalAReserva(Calificacion* calificacion) {
    calificaciones.push_back(calificacion);
}

Reserva::~Reserva() {
    pasajero->eliminarReserva(this);
    pasajero = nullptr;
    viaje = nullptr;
    for (Calificacion* c : calificaciones) {
        delete c;
    }
    calificaciones.clear();
}