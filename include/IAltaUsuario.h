#ifndef IALTA_USUARIO_H
#define IALTA_USUARIO_H

#include "DTVehiculosConductor.h"
#include "TipoLibreta.h"
#include "TipoVehiculo.h"
#include <vector>
#include <string>
#include "DTFecha.h"

class IAltaUsuario{
    public:
        virtual bool altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci) = 0;

        virtual bool altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::vector<TipoLibreta> libreta) = 0;

        virtual int registrarVehiculo(std::string nickname, std::string matricula, std::string marca, std::string modelo, int capacidad, TipoVehiculo tipo) = 0;
};


#endif