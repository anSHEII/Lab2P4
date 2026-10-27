#ifndef MANEJADOR_VIAJE_H
#define MANEJADOR_VIAJE_H

#include <map>
#include <vector>
#include <string>
#include "DTConsultaViaje.h"
#include "DTListarViaje.h"
#include "DTDetalleViaje.h"
#include "DTFecha.h"
class Viaje;
class Vehiculo;

class ManejadorViaje {
    private:
        static ManejadorViaje* instancia;
        ManejadorViaje();
        std::map<int, Viaje*> viajes;
    public:

        static ManejadorViaje* getInstance();

        Viaje* encontrarViaje(int codigo);

        std::vector<DTConsultaViaje> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos);

        std::vector<DTListarViaje> listarViajes();

        void addViaje(Viaje* v);

        void eliminarViajeEnColeccion(int codigo);

        DTDetalleViaje detalleViaje(int codigo);

        void eliminarViaje(int codigo);

        Viaje* crearViaje(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio);
};

#endif