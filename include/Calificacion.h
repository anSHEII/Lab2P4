#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "DTFecha.h"

class Usuario;
class Reserva;

class Calificacion {
private:
    DTFecha fecha;
    int puntaje;

    Usuario* usuarioCalificador;
    Usuario* usuarioCalificado;
    Reserva* reserva;

public:
    Calificacion(DTFecha fecha, int puntaje);   

    Usuario* getUsCalificador();

    Usuario* getUsCalificado();

    Reserva* getResvCalificada();

    void setCalificado(Usuario* u);

    void setCalificador(Usuario* u);

    bool nickUsIgualUsCalif(std::string nicknameCalificado);

    bool califSobreViaje(int codigo);

    int getPuntaje();

    ~Calificacion();
};

#endif