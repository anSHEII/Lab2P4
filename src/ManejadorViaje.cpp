
#include"../include/ManejadorViaje.h"
#include"../include/Viaje.h"
#include"../include/Vehiculo.h"
#include <algorithm>

ManejadorViaje* ManejadorViaje::instancia = nullptr;

ManejadorViaje::ManejadorViaje() {}

ManejadorViaje* ManejadorViaje::getInstance() {
    if (instancia == nullptr) {
        instancia = new ManejadorViaje();
    }
    return instancia;
}


void ManejadorViaje::addViaje(Viaje* v) {
    viajes.insert({v->getCodigo(), v});
}

void ManejadorViaje::eliminarViajeEnColeccion(int codigo) {
    for (auto it = viajes.begin(); it != viajes.end(); ++it) {
        if (it->second->getCodigo() == codigo) {
            viajes.erase(it);
            break;
        }
    }
}

std::vector<DTListarViaje> ManejadorViaje::listarViajes() {
    std::vector<DTListarViaje> lista;
    for (auto& par : viajes) {
        lista.push_back(par.second->getListarViaje());
    }
    return lista;
}

DTDetalleViaje ManejadorViaje::detalleViaje(int codigo) {
    for (auto& par : viajes) {
        if (par.second->getCodigo() == codigo) {
            return par.second->getDetalleViaje();
        }
    }
    throw std::runtime_error("Viaje no encontrado");
}

Viaje* ManejadorViaje::encontrarViaje(int codigo) {
    for (auto& par : viajes) {
        if (par.second->getCodigo() == codigo) {
            return par.second;
        }
    }
    return nullptr;
}

std::vector<DTConsultaViaje> ManejadorViaje::consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos) {
    std::vector<DTConsultaViaje> resultado;
    for (auto& par : viajes) {
        if (par.second->validarViaje(fecha, origen, destino, asientos)) {
            resultado.push_back(par.second->getConsultaViaje(asientos));
        }
    }
    std::sort(resultado.begin(), resultado.end());
    return resultado;
}

void ManejadorViaje::eliminarViaje(int codigo) {
    Viaje* viajeAEliminar = encontrarViaje(codigo);
    if (viajeAEliminar != nullptr) {
        viajeAEliminar->~Viaje();
        eliminarViajeEnColeccion(codigo);
    }
}

Viaje* ManejadorViaje::crearViaje(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio){
    Viaje* viaje = Viaje::create(v, fecha, origen, destino, asientos, precio);
    addViaje(viaje);
    return viaje;
}