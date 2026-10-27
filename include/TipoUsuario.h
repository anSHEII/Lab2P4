#ifndef TIPO_USUARIO_H
#define TIPO_USUARIO_H

#include <iostream>

enum class TipoUsuario {
    Conductor,
    Pasajero
};
std:: ostream& operator << (std:: ostream& os, TipoUsuario tUsuario);
#endif
