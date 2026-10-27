#include "../include/Fabrica.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ControladorViajes.h"
#include "../include/ControladorUsuario.h"

Fabrica* Fabrica::instancia = nullptr;

Fabrica::Fabrica() {}

Fabrica* Fabrica::getInstance() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }
    return instancia;
}

IControladorFechaActual* Fabrica::getIControladorFechaActual() {
    return ControladorFechaActual::getInstance();
}

IAltaViaje* Fabrica::getIAltaViaje() {
    return ControladorViajes::getInstance();
}

IEliminarViaje* Fabrica::getIEliminarViaje() {
    return ControladorViajes::getInstance();
}

IGenerarReserva* Fabrica::getIGenerarReserva() {
    return ControladorViajes::getInstance();
}

IAltaUsuario* Fabrica::getIAltaUsuario() {
    return ControladorUsuario::getInstancia();
}

ICalificarUsuario* Fabrica::getICalificarUsuario() {
    return ControladorUsuario::getInstancia();
}