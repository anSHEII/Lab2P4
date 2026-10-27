#ifndef IELIMINAR_VIAJE_H
#define IELIMINAR_VIAJE_H

#include <iostream>
#include <vector>
#include <string>
#include "DTListarViaje.h"
#include "DTDetalleViaje.h"

class IEliminarViaje {
    public:
        virtual std::vector<DTListarViaje> listarViajes() = 0;

        virtual DTDetalleViaje detalleViaje(int codigo) = 0;

        virtual void eliminarViaje() = 0;

        virtual void cancelarEliminarViaje() = 0;
};
#endif
