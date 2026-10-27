#include "../include/Calificacion.h"
#include "../include/Usuario.h"
#include "../include/Reserva.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
    this->usuarioCalificador = nullptr;
    this->usuarioCalificado = nullptr;
    this->reserva = nullptr;
}

Usuario* Calificacion::getUsCalificador(){
    return this->usuarioCalificador;
}

Usuario* Calificacion::getUsCalificado(){
    return this->usuarioCalificado;
}

void Calificacion::setCalificado(Usuario* u){
    this->usuarioCalificado = u;
}

void Calificacion::setCalificador(Usuario* u){
    this->usuarioCalificador = u;
}

Reserva* Calificacion::getResvCalificada(){
    return this->reserva;
}

int Calificacion::getPuntaje(){
    return this->puntaje;
}


Calificacion::~Calificacion() {
    if (usuarioCalificado != nullptr) {
        usuarioCalificado->eliminarCalificacion(this);
    }
}