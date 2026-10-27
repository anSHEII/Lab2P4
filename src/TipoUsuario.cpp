#include "../include/TipoUsuario.h"

std:: ostream& operator << (std:: ostream& os, TipoUsuario tUsuario){
    if (tUsuario == TipoUsuario::Conductor) {
        os << "Conductor";
    }else {
        os << "Pasajero";
    }
    return os;
}
