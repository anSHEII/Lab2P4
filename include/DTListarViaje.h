#ifndef DT_LISTAR_VIAJE_H
#define DT_LISTAR_VIAJE_H

#include "DTFecha.h"
#include <string>

class DTListarViaje {
private:
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    std::string conductor;

public:
    DTListarViaje(int codigo, DTFecha fecha, std::string origen, std::string destino, std::string conductor);

    int getCodigo();
    DTFecha getFecha();
    std::string getOrigen();
    std::string getDestino();
    std::string getConductor();

    bool operator<(const DTListarViaje& other) const;

};

#endif
