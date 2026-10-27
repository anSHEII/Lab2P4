#include "../include/Viaje.h"
#include "../include/Reserva.h"
#include "../include/Vehiculo.h"
#include "../include/Conductor.h"
#include "../include/Pasajero.h"

int Viaje::proximoCodigo = 1;

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
}


int Viaje::getProximoCodigo(){
    return proximoCodigo;
}

int Viaje::getCodigo() const {
    return codigo;
}

DTFecha Viaje::getFecha() const {
    return fecha;
}

std::string Viaje::getOrigen() const {
    return origen;
}

std::string Viaje::getDestino() const {
    return destino;
}

int Viaje::getAsientosPublicados() const {
    return asientosPublicados;
}

float Viaje::getPrecio() const {
    return precio;
}

void Viaje::setVehiculo(Vehiculo* v) {
    this->vehiculo = v;
}

void Viaje::addReserva(Reserva* r) {
    reservas.push_back(r);
}

std::vector<Reserva*> Viaje::getReservas() const {
    return reservas;
}



std::map<std::string, Pasajero*> Viaje::getPasajeros() const {
    std::map<std::string, Pasajero*> pasajeros;
    for(Reserva* r : reservas) {
        Pasajero* p = r->getPasajero();
        pasajeros[p->getNickname()] = p;
    }
    return pasajeros;
}

DTDetalleViaje Viaje::getDetalleViaje() const {
    std::vector<DTDetalleReserva> res;
    for (Reserva* r : reservas) {
        res.push_back(r->getDetalleReserva());
    }
    DTDetalleVehiculo vehi = vehiculo->getDetalleVehiculo();
    return DTDetalleViaje(codigo, fecha, origen, destino, asientosPublicados, precio, vehi, res);
}

DTListarViaje Viaje::getListarViaje() const {
    Conductor* c = vehiculo->getConductor();
    return DTListarViaje(codigo, fecha, origen, destino, c->getNickname());
}

DTConsultaViaje Viaje::getConsultaViaje(int asientos) const {
    Conductor* c = vehiculo->getConductor();
    float precioTotal = precio * asientos;
    return DTConsultaViaje(codigo, this->vehiculo->getMarca(), this->vehiculo->getModelo(), c->getNombre(), c->getCalificacionPromedio(), precioTotal);
}

bool Viaje::puedeReservar(Pasajero* p, int asientos) {
    std::map<std::string, Pasajero*> pasajeros = getPasajeros();
    if (pasajeros.find(p->getNickname()) != pasajeros.end()) return false;
    int reservados = 0;
    for (Reserva* r : reservas) {
        reservados += r->getDetalleReserva().getAsientosReservados();
    }
    return (asientosPublicados - reservados) >= asientos;
}

bool Viaje::validarViaje(DTFecha fecha, std::string origen, std::string destino, int asientos) {
    int reservados = 0;
    for (Reserva* r : reservas) {
        reservados += r->getDetalleReserva().getAsientosReservados();
    }
    return this->fecha == fecha &&
           this->origen == origen &&
           this->destino == destino &&
           (asientosPublicados - reservados) >= asientos;
}

DTConsultaViaje Viaje::datosViaje() {
    Conductor* c = vehiculo->getConductor();
    float precioTotal = precio * asientosPublicados;
    return DTConsultaViaje(codigo, vehiculo->getMarca(), vehiculo->getModelo(), c->getNombre(), c->getCalificacionPromedio(), precioTotal);
}

Vehiculo* Viaje::getVehiculo() const {
    return vehiculo;
}

Viaje::~Viaje(){
    if (vehiculo != nullptr) {
        vehiculo->eliminarViaje(this);
        this->vehiculo = nullptr;
        for (Reserva* r : reservas) {
            delete r;
        }
        reservas.clear();
    }
}

void Viaje::incrementarProximoCodigo(){
    proximoCodigo++;
}

Viaje* Viaje::create(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio){
    int codigo = getProximoCodigo();
    Viaje* viaje = new Viaje(codigo, fecha, origen, destino, asientos, precio);
    viaje->setVehiculo(v);
    incrementarProximoCodigo();
    return viaje;
}

