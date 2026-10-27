#include "../include/ControladorFechaActual.h"

ControladorFechaActual* ControladorFechaActual::instancia = nullptr;

ControladorFechaActual::ControladorFechaActual() {
    fechaActual = DTFecha(1, 1, 2024); // Fecha inicial por defecto
}

ControladorFechaActual* ControladorFechaActual::getInstance() {
    if (instancia == nullptr) {
        instancia = new ControladorFechaActual();
    }
    return instancia;
}

DTFecha ControladorFechaActual::getFecha() {
    return fechaActual;
}

void ControladorFechaActual::setFecha(DTFecha nuevaFecha) {
    fechaActual = nuevaFecha;
}
