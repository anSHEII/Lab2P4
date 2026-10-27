#ifndef MANEJADOR_VEHICULO_H
#define MANEJADOR_VEHICULO_H

#include "TipoVehiculo.h"
#include <string>
#include <map>
#include <iostream>

class Vehiculo;

class ManejadorVehiculo {
    private:
        static ManejadorVehiculo* instancia;
        ManejadorVehiculo();
        std::map<std::string, Vehiculo*> vehiculos;

    public:
        static ManejadorVehiculo* getInstancia();
        
        bool existeVehiculo(std::string mat);
        
        Vehiculo* nuevoVehiculo( std::string matricula, std::string marca, std::string modelo, int capacidad, TipoVehiculo tipo);

        Vehiculo* getVehiculo(std::string matricula);
        
};

#endif