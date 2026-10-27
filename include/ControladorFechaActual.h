#ifndef CONTROLADOR_FECHA_ACTUAL_H
#define CONTROLADOR_FECHA_ACTUAL_H

#include "IControladorFechaActual.h"

class ControladorFechaActual : public IControladorFechaActual {
private:
    static ControladorFechaActual* instancia;
    DTFecha fechaActual;

    ControladorFechaActual();

public:
    static ControladorFechaActual* getInstance();

    DTFecha getFecha();
    void setFecha(DTFecha nuevaFecha);
};

#endif
