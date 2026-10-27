#include "../include/Pasajero.h"
#include "../include/Reserva.h"
#include "../include/Viaje.h"
#include "../include/Calificacion.h"
#include <algorithm>

Pasajero::Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento)
    : Usuario(nickname, nombre, contrasena, email) {
    this->ci = documento;
    this->calificacionPromedio = 5.0;
}

void Pasajero::addReserva(Reserva* r){
    reservas.push_back(r);
}

std::vector<Reserva*> Pasajero::getReservas() const {
    return reservas;
}


void Pasajero::eliminarReserva(Reserva* r) {
    auto it = std::find(reservas.begin(), reservas.end(), r);
    if (it != reservas.end()) {
        reservas.erase(it);
    }
}



void Pasajero::agregarCalACalificado(Calificacion* calificacion) {
    calificaciones.push_back(calificacion);
}

void Pasajero::agregarCalAReserva(Calificacion* calificacion) {
    for (Reserva* r : reservas) {
        if (r->resvSobreViaje(calificacion->getResvCalificada()->getViaje()->getCodigo())) {
            r->agregarCalAReserva(calificacion);
            break;
        }
    }
}

Pasajero::~Pasajero() {

}
