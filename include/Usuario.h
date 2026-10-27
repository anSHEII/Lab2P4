#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>

class Calificacion;
class DTListarViajes;

class Usuario {
protected:
    std::string nickname;
    std::string nombre;
    std::string contrasena;
    std::string email;
    float calificacionPromedio;
    std::vector<Calificacion*> calificaciones;

public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);

    std::vector<DTListarViajes> listarViajes(std::string nickname);

    bool pNickIgualNickname();

    bool existeCalifUsuario(std::string nicknameCalificado);

    Calificacion* crearCalificacion(Calificacion* calificacion);
    void eliminarCalificacion(Calificacion* c);

    std::vector<Calificacion*> getCalificaciones ();

    virtual ~Usuario();
    std::string getNickname() const;
    std::string getNombre() const;
    float getCalificacionPromedio() const;
};

#endif
