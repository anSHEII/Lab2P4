#ifndef DT_USUARIO_VIAJE_H
#define DT_USUARIO_VIAJE_H

#include "TipoUsuario.h"
#include <string>

class DTUsuarioViaje {
private:
    std::string nickname;
    TipoUsuario tipo;

public:
    DTUsuarioViaje(std::string nickname, TipoUsuario tipo);

    std::string getNickname();
    TipoUsuario getTipo();

    bool operator<(const DTUsuarioViaje& other) const;
};

#endif
