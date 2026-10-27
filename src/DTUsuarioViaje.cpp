#include "../include/DTUsuarioViaje.h"

DTUsuarioViaje::DTUsuarioViaje(std::string nickname, TipoUsuario tipo)
    {
    this->nickname = nickname;
    this->tipo = tipo;
}

std::string DTUsuarioViaje::getNickname() { return nickname; }
TipoUsuario DTUsuarioViaje::getTipo() { return tipo; }

bool DTUsuarioViaje::operator<(const DTUsuarioViaje& other) const {
    return nickname < other.nickname;
}


