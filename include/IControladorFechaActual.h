#ifndef ICONTROLADOR_FECHA_ACTUAL_H
#define ICONTROLADOR_FECHA_ACTUAL_H

#include "DTFecha.h"

class IControladorFechaActual {
public:
    virtual ~IControladorFechaActual() {}
    virtual DTFecha getFecha() = 0;
    virtual void setFecha(DTFecha nuevaFecha) = 0;
};

#endif
