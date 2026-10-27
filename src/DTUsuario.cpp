#include "../include/DTUsuario.h"

DTUsuario::DTUsuario(std::string nickname, std::string nombre)
    {
    this->nickname = nickname;
    this->nombre = nombre;
}

std::string DTUsuario::getNickname() { return nickname; }
std::string DTUsuario::getNombre() { return nombre; }

bool DTUsuario::operator<(const DTUsuario& other) const {
    return nickname < other.nickname;
}
