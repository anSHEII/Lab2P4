#include "../include/ControladorUsuario.h"
#include "../include/Pasajero.h"
#include "../include/Conductor.h"
#include "../include/Reserva.h"
#include "../include/Calificacion.h"
#include "../include/Viaje.h"
#include "../include/Vehiculo.h"
#include <algorithm>

ControladorUsuario* ControladorUsuario::instancia = nullptr;

ControladorUsuario::ControladorUsuario()
    : manejadorUsuario(nullptr), manejadorViaje(nullptr), manejadorVehiculo(nullptr),
      nicknameListarViajes(""), codigoUsuariosViaje(-1) {}

ControladorUsuario* ControladorUsuario::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ControladorUsuario();
    }
    return instancia;
}

std::vector<DTListarViaje> ControladorUsuario::listarViajes(std::string nickname) {
    if (this->manejadorUsuario == nullptr) {
        this->manejadorUsuario = ManejadorUsuario::getInstancia();
    }
    ManejadorUsuario* mnjUsuario = this->manejadorUsuario;
    Usuario* us = mnjUsuario->encontrarUsuario(nickname);
    std::vector<DTListarViaje> listadoViajesNick;
    Pasajero* pUs = dynamic_cast<Pasajero*>(us);
    if (pUs != nullptr) {
        std::vector<Reserva*> reservasUs = pUs->getReservas();
        for (Reserva* r : reservasUs) {
            Viaje* v = r->getViaje();
            listadoViajesNick.push_back(v->getListarViaje());
        }
        std::sort(listadoViajesNick.begin(), listadoViajesNick.end(), [](DTListarViaje a, DTListarViaje b) {
            return a.getCodigo() < b.getCodigo();
        });
    } else {
        Conductor* cUs = dynamic_cast<Conductor*>(us);
        if (cUs != nullptr) {
            std::map<std::string, Vehiculo*> vehiculosUs = cUs->getVehiculos();
            for (auto veh : vehiculosUs) {
                std::map<int, Viaje*> viajesVeh = veh.second->getViajes();
                for (auto viaje : viajesVeh) {
                    Viaje* v = viaje.second;
                    listadoViajesNick.push_back(v->getListarViaje());
                }
            }
        }
    }
    this->nicknameListarViajes = nickname;
    return listadoViajesNick;
}

std::vector<DTUsuario> ControladorUsuario::listarUsuarios(std::string nickname) {
    if (this->manejadorUsuario == nullptr) {
        this->manejadorUsuario = ManejadorUsuario::getInstancia();
    }
    return this->manejadorUsuario->listarUsuarios();
}

bool ControladorUsuario::altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci) {
    if (this->manejadorUsuario == nullptr) {
        this->manejadorUsuario = ManejadorUsuario::getInstancia();
    }
    return this->manejadorUsuario->nuevoPasajero(nickname, nombre, contrasena, email, ci);
}

bool ControladorUsuario::altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::vector<TipoLibreta> libreta) {
    if (this->manejadorUsuario == nullptr) {
        this->manejadorUsuario = ManejadorUsuario::getInstancia();
    }
    return this->manejadorUsuario->nuevoConductor(nickname, nombre, contrasena, email, libreta);
}

bool ControladorUsuario::calificarUsuario(std::string nicknameCalificado, int calificacion) {
    if (this->manejadorUsuario == nullptr) {
        this->manejadorUsuario = ManejadorUsuario::getInstancia();
    }
    ManejadorUsuario* mnjUsuario = this->manejadorUsuario;
    Usuario* usCalificado = mnjUsuario->encontrarUsuario(nicknameCalificado);
    std::vector <Calificacion*> califsCalificado = usCalificado->getCalificaciones();
    bool existeInstanciaC = false;
    for (Calificacion* c : califsCalificado) {
        Usuario* usCalificadorC = c->getUsCalificador();
        if (usCalificadorC != nullptr && usCalificadorC->getNickname() == nicknameListarViajes) {
            Reserva* resvC = c->getResvCalificada();
            if (resvC != nullptr) {
                Viaje* viajeResvC = resvC->getViaje();
                if (viajeResvC != nullptr && viajeResvC->getCodigo() == codigoUsuariosViaje) {
                    existeInstanciaC = true;
                    break;
                }
            }
        }
    }
    std::string calificadorNick = nicknameListarViajes;
    nicknameListarViajes = "";
    codigoUsuariosViaje = -1;
    if (existeInstanciaC) {
        return false;
    }
    bool resultado = mnjUsuario->calificarUsuario(nicknameCalificado, calificadorNick, calificacion);

    return resultado;
}

int ControladorUsuario::registrarVehiculo(std::string nickname, std::string matricula, std::string marca, std::string modelo, int capacidad, TipoVehiculo tipo) {
    if(this->manejadorVehiculo == nullptr){
        this->manejadorVehiculo = ManejadorVehiculo::getInstancia();
    }
    
    bool ev = this->manejadorVehiculo->existeVehiculo(matricula);

    if (ev) {
        return -1; 
    }
    if(this->manejadorUsuario == nullptr){
        this->manejadorUsuario = ManejadorUsuario::getInstancia();
    }

    bool tieneLibreta = this->manejadorUsuario->regVehCon(nickname,tipo);
    if (!tieneLibreta) {
        return -2;  
    }

    Vehiculo* v = this->manejadorVehiculo->nuevoVehiculo(matricula, marca, modelo, capacidad, tipo);
    this->manejadorUsuario->agregarVehiculoConductor(v, nickname);
    return 0;
}

std::vector<DTUsuarioViaje> ControladorUsuario::listarUsuariosViaje(int codigo) {
    if (this->manejadorViaje == nullptr) {
        this->manejadorViaje = ManejadorViaje::getInstance();
    }
    ManejadorViaje* mnjViaje = this->manejadorViaje;
    std::vector<DTUsuarioViaje> usuariosViaje;
    Viaje* viaje = mnjViaje->encontrarViaje(codigo);
    if (viaje == nullptr) return usuariosViaje;
    Vehiculo* vehViaje = viaje->getVehiculo();
    if (vehViaje != nullptr) {
        Conductor* cViaje = vehViaje->getConductor();
        if (cViaje != nullptr && cViaje->getNickname() != nicknameListarViajes) {
            usuariosViaje.push_back(DTUsuarioViaje(cViaje->getNickname(), TipoUsuario::Conductor));
        }
    }
    for (Reserva* r : viaje->getReservas()) {
        Pasajero* p = r->getPasajero();
        if (p->getNickname() != nicknameListarViajes) {
            usuariosViaje.push_back(DTUsuarioViaje(p->getNickname(), TipoUsuario::Pasajero));
        }
    }
    this->codigoUsuariosViaje = codigo;
    return usuariosViaje;
}
