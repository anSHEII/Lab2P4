#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Usuario.h"
#include "TipoLibreta.h"
#include "DTFecha.h"
#include <vector>
#include <map>
#include "TipoVehiculo.h"


class Calificacion;
class Viaje;
class Vehiculo;
class DTVehiculosConductor;


class Conductor : public Usuario {
private:
    std::vector<TipoLibreta> libretas;
    std::map<std::string, Vehiculo*> vehiculos;

public:
    Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::vector<TipoLibreta> libs);

    std::map<std::string, Vehiculo*> getVehiculos() const;

    void agregarCalAReservaCalificado(Calificacion cal, Usuario calificado);

    bool ConduceViaje(Viaje vi);

    bool tieneLibreta(TipoVehiculo tipo);

    void agregarVehiculo(Vehiculo* v);

    std::vector<DTVehiculosConductor> listarVehiculos();

    bool hayViajesFechaConductor(DTFecha fecha);


    ~Conductor();
};

#endif
