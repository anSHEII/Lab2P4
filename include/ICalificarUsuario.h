#ifndef ICALIFICARUSUARIO_H
#define ICALIFICARUSUARIO_H

#include <vector>
#include <string>
#include "DTListarViaje.h"
#include "DTUsuario.h"
#include "DTUsuarioViaje.h"

class ICalificarUsuario {
    public:
        virtual std::vector<DTListarViaje> listarViajes(std::string nickname) = 0;

        virtual std::vector<DTUsuario> listarUsuarios(std::string nickname) = 0;

        virtual std::vector<DTUsuarioViaje> listarUsuariosViaje(int codigo) = 0;

        virtual bool calificarUsuario(std::string nicknameCalificado, int calificacion) = 0;
};

#endif