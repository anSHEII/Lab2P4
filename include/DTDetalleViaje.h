#ifndef DT_DETALLE_VIAJE_H
#define DT_DETALLE_VIAJE_H

#include "DTFecha.h"
#include "DTDetalleVehiculo.h"
#include "DTDetalleReserva.h"
#include <string>
#include <vector>

class DTDetalleViaje {
private:
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;
    DTDetalleVehiculo vehiculo;
    std::vector<DTDetalleReserva> reservas;

public:
    DTDetalleViaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio, DTDetalleVehiculo vehi, std::vector<DTDetalleReserva> res);

    int getCodigo();
    DTFecha getFecha();
    std::string getOrigen();
    std::string getDestino();
    int getAsientosPublicados();
    float getPrecio();
    DTDetalleVehiculo getVehiculo();
    std::vector<DTDetalleReserva> getReservas();
};

#endif
