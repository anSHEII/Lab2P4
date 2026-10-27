#include "../include/ControladorViajes.h"
#include "../include/ControladorFechaActual.h"
#include "../include/Conductor.h"
#include "../include/Pasajero.h"
#include "../include/Vehiculo.h"
#include "../include/Viaje.h"
#include "../include/Reserva.h"

ControladorViajes* ControladorViajes::instancia = nullptr;

ControladorViajes::ControladorViajes()
    : manejadorViaje(nullptr), manejadorUsuario(nullptr), manejadorVehiculo(nullptr), codigoViajeAEliminar(-1) {}

ControladorViajes* ControladorViajes::getInstance() {
    if (instancia == nullptr) {
        instancia = new ControladorViajes();
    }
    return instancia;
}




// Metodos de IEliminarViaje
    std::vector<DTListarViaje> ControladorViajes::listarViajes(){
        if(this->manejadorViaje == nullptr){
            this->manejadorViaje = ManejadorViaje::getInstance();
        }
        return this->manejadorViaje->listarViajes();
    }

    DTDetalleViaje ControladorViajes::detalleViaje(int codigo){
        if(this->manejadorViaje == nullptr){
            this->manejadorViaje = ManejadorViaje::getInstance();
        }
        this->codigoViajeAEliminar = codigo;
        return this->manejadorViaje->detalleViaje(codigo);
    }

    void ControladorViajes::eliminarViaje(){
        if(this->manejadorViaje == nullptr){
            this->manejadorViaje = ManejadorViaje::getInstance();
        }
        this->manejadorViaje->eliminarViaje(this->codigoViajeAEliminar);

        this->codigoViajeAEliminar = -1;
    }

    void ControladorViajes::cancelarEliminarViaje(){
        this->codigoViajeAEliminar = -1;
    }

// Metodos de IGenerarReserva
        bool ControladorViajes::generarReserva(std::string nickname, int codigo, int asientos){
            // TODO: implement
            if(this->manejadorViaje == nullptr){
                this->manejadorViaje = ManejadorViaje::getInstance();   
            }
            Viaje* v = this->manejadorViaje->encontrarViaje(codigo);    //consigue el viaje
            if(this->manejadorUsuario == nullptr){
                this->manejadorUsuario = ManejadorUsuario::getInstancia();
            }
            Pasajero* p = this->manejadorUsuario->findPasajero(nickname);   //consigue el pasajero
            bool ok = v->puedeReservar(p, asientos);
            if(ok)
            {
                DTFecha fecha = ControladorFechaActual::getInstance()->getFecha();  //consigue la fecha actual
                Reserva *r = new Reserva(asientos,fecha,p,v);
                p->addReserva(r);
                v->addReserva(r);
            }
            return ok;
        }

        std::vector<std::string> ControladorViajes::listarPasajeros(){
            if(this->manejadorUsuario == nullptr){
                this->manejadorUsuario = ManejadorUsuario::getInstancia();
            }
            return this->manejadorUsuario->listarPasajeros();
        }

        std::vector<DTConsultaViaje> ControladorViajes::consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos){
            if(this->manejadorViaje == nullptr){
                this->manejadorViaje = ManejadorViaje::getInstance();
            }
            return this->manejadorViaje->consultarViajes(fecha, origen, destino, asientos);
        }


// Metodos de IAltaViaje

std::vector<DTVehiculosConductor> ControladorViajes::listarVehiculosConductor(std::string nickname){
    if(this->manejadorUsuario == nullptr){
        this->manejadorUsuario = ManejadorUsuario::getInstancia();
    }
    Conductor* conductor = static_cast<Conductor*>(this->manejadorUsuario->encontrarUsuario(nickname));
    return conductor->listarVehiculos();
}

bool ControladorViajes::altaViaje(std::string matricula, DTFecha fecha, std::string origen,std::string destino, int asientos, float precio){
    if(this->manejadorVehiculo == nullptr){
        this->manejadorVehiculo = ManejadorVehiculo::getInstancia();
    }
    Vehiculo* vehiculo = this->manejadorVehiculo->getVehiculo(matricula);

    int capacidad = vehiculo->getCapacidad();
    if(capacidad < asientos) return false;

    bool hayViajesFecha = vehiculo->hayViajesConductor(fecha);
    if(hayViajesFecha) return false;

    if(this->manejadorViaje == nullptr){
        this->manejadorViaje = ManejadorViaje::getInstance();
    }

    Viaje* cvi = this->manejadorViaje->crearViaje(vehiculo, fecha, origen, destino, asientos, precio);

    vehiculo->addViaje(cvi);
    return true;
}