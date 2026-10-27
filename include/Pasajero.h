#ifndef PASAJERO_H
#define PASAJERO_H

#include "Usuario.h"
#include <string>
#include <map>
#include <vector>


class Viaje;
class Reserva; 
class Calificacion;

class Pasajero : public Usuario {
private:
    std::string ci;
    std::vector<Reserva*> reservas;
public:
    Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento);

    std::vector<Reserva*> getReservas() const;

    void addReserva(Reserva* r);

    void agregarCalACalificado(Calificacion* calificacion);

    void agregarCalAReserva(Calificacion* calificacion);

    void eliminarReserva(Reserva* r);

    ~Pasajero();
};

#endif
