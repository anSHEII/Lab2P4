#ifndef FABRICA_H
#define FABRICA_H

#include "IControladorFechaActual.h"
#include "IAltaViaje.h"
#include "IEliminarViaje.h"
#include "IGenerarReserva.h"
#include "IAltaUsuario.h"
#include "ICalificarUsuario.h"

class CtrUsuario;
class CtrViaje;

class Fabrica {
private:
    static Fabrica* instancia;
    Fabrica();
    CtrUsuario* ctrUsuario;
    CtrViaje* ctrViaje;

public:
    static Fabrica* getInstance();

    IControladorFechaActual* getIControladorFechaActual();

    IAltaViaje* getIAltaViaje();

    IEliminarViaje* getIEliminarViaje();

    IGenerarReserva* getIGenerarReserva();

    IAltaUsuario* getIAltaUsuario();

    ICalificarUsuario* getICalificarUsuario();
};

#endif
