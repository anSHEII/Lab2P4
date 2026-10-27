#include "../include/Usuario.h"
#include "../include/Calificacion.h"
#include <algorithm>

Usuario::Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;
}

Usuario::~Usuario() {}

std::string Usuario::getNickname() const {
    return this->nickname;
}

std::string Usuario::getNombre() const {
    return this->nombre;
}

Calificacion* Usuario::crearCalificacion(Calificacion* calificacion){
    calificaciones.push_back(calificacion);
    int calificacionPromedio = 0;
    int contadorCalifs = 0;
    for(Calificacion* c : calificaciones){
        contadorCalifs += 1;
        calificacionPromedio += c->getPuntaje();
    }
    calificacionPromedio /= contadorCalifs;
    this->calificacionPromedio = calificacionPromedio;
    return calificacion;
}


float Usuario::getCalificacionPromedio() const {
    return this->calificacionPromedio;
}

void Usuario::eliminarCalificacion(Calificacion* c) {
    auto it = std::find(calificaciones.begin(), calificaciones.end(), c);
    if (it != calificaciones.end()) {
        calificaciones.erase(it);
    }
    int calificacionPromedio = 0;
    int contadorCalifs = 0;
    for(Calificacion* calif : calificaciones){
        contadorCalifs += 1;
        calificacionPromedio += calif->getPuntaje();
    }
    if (contadorCalifs > 0) {
        calificacionPromedio /= contadorCalifs;
    }
    this->calificacionPromedio = calificacionPromedio;
}


std::vector<Calificacion*> Usuario::getCalificaciones() {
    return calificaciones;
}
