#ifndef MANEJADOR_USUARIO_H
#define MANEJADOR_USUARIO_H

#include <map>
#include <vector>
#include <string>
#include "DTUsuario.h"
#include "DTUsuarioViaje.h"
#include "TipoVehiculo.h"
#include "TipoLibreta.h"
#include "ManejadorVehiculo.h"

class Pasajero;
class Usuario;

class ManejadorUsuario {
    private:
        static ManejadorUsuario* instancia;
        ManejadorUsuario();
        std::map<std::string,Usuario*> usuarios;
        ManejadorVehiculo* manejadorVehiculo;

    public:
        
        static ManejadorUsuario* getInstancia();
        
        Pasajero* findPasajero(std::string nickname);
        
        Usuario* encontrarUsuario(std::string nickname);
        
        std::vector<DTUsuario> listarUsuarios();
        
        bool nuevoPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci);
        
        bool calificarUsuario(std::string nicknameCalificado, std::string nicknameCalificador, int calificacion);

        std::vector<DTUsuarioViaje> encontrarConductoViaje(std::string nickname);

        std::vector<std::string> listarPasajeros();

        bool regVehCon(std::string nickname, TipoVehiculo tipo);

        bool nuevoConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::vector<TipoLibreta> libreta);

        void agregarVehiculoConductor(Vehiculo* v, std::string nickname);

        ~ManejadorUsuario();



};




#endif