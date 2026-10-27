#ifndef CONTROLADOR_VIAJES_H
#define CONTROLADOR_VIAJES_H

#include "IAltaViaje.h"
#include "IEliminarViaje.h"
#include "IGenerarReserva.h"
#include "ManejadorViaje.h"
#include <iostream>
#include <vector>
#include <string>
#include "ManejadorUsuario.h"
#include "ManejadorVehiculo.h"



class ControladorViajes : public IAltaViaje, public IEliminarViaje, public IGenerarReserva {
    private:
        static ControladorViajes* instancia;
        ControladorViajes();
        ManejadorViaje* manejadorViaje;
        ManejadorUsuario* manejadorUsuario;
        ManejadorVehiculo* manejadorVehiculo;
        //Memoria para eliminar viaje
        int codigoViajeAEliminar;
    public:

        // funciones de IAltaViaje
        static ControladorViajes* getInstance();
        std::vector<DTVehiculosConductor> listarVehiculosConductor(std::string nickname);
        bool altaViaje(std::string matricula, DTFecha fecha, std::string origen,std::string destino, int asientos, float precio);

        // funciones de IEliminarViaje
        std::vector<DTListarViaje> listarViajes();

        DTDetalleViaje detalleViaje(int codigo);

        void eliminarViaje();

        void cancelarEliminarViaje();
        // funciones de IGenerarReserva

        bool generarReserva(std::string nickname, int codigo, int asientos);

        std::vector<std::string> listarPasajeros();

        std::vector<DTConsultaViaje> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos);



};


#endif 