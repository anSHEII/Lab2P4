#ifndef CONTROLADOR_USUARIO_H
#define CONTROLADOR_USUARIO_H

#include "ManejadorUsuario.h"
#include "ManejadorViaje.h"
#include "ManejadorVehiculo.h"
#include <iostream>
#include <vector>
#include <string>
#include "IAltaUsuario.h"
#include "ICalificarUsuario.h"


class ControladorUsuario : public IAltaUsuario, public ICalificarUsuario {
    private:
        static ControladorUsuario* instancia;
        ControladorUsuario();
        ManejadorUsuario* manejadorUsuario;
        ManejadorViaje* manejadorViaje;
        ManejadorVehiculo* manejadorVehiculo;
        //listarViajes(std::string nickname) guarda nickname
        std::string nicknameListarViajes;
        //listarUsuariosViaje(std::int codigo) guarda codigo
        int codigoUsuariosViaje;
    public:
        static ControladorUsuario* getInstancia();

        std::vector<DTListarViaje> listarViajes(std::string nickname);

        std::vector<DTUsuario> listarUsuarios(std::string nickname);

        bool altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci);

        bool altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::vector<TipoLibreta> libreta);

        bool calificarUsuario(std::string nickname, int calificacion);

        int registrarVehiculo(std::string nickname, std::string matricula, std::string marca, std::string modelo, int capacidad, TipoVehiculo tipo);

        std::vector<DTUsuarioViaje> listarUsuariosViaje(int codigo);
};



#endif