#include"../include/ManejadorUsuario.h"
#include "../include/Pasajero.h"
#include "../include/Conductor.h"
#include "../include/Calificacion.h"
#include "../include/ControladorFechaActual.h"
#include "../include/Vehiculo.h"


ManejadorUsuario* ManejadorUsuario::instancia = nullptr;

ManejadorUsuario::ManejadorUsuario() {
    manejadorVehiculo = ManejadorVehiculo::getInstancia();
} 

ManejadorUsuario* ManejadorUsuario::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ManejadorUsuario();
    }
    return instancia;
}

Usuario* ManejadorUsuario::encontrarUsuario(std::string nickname){
    auto it = this->usuarios.find(nickname);
    if (it != this->usuarios.end()) {
        return it->second;
    }
    return nullptr; 
}

Pasajero* ManejadorUsuario::findPasajero(std::string nickname) {
    Usuario* u = encontrarUsuario(nickname);
    return dynamic_cast<Pasajero*>(u);
}

bool ManejadorUsuario::nuevoPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci) {
    if (usuarios.count(nickname) > 0) return false;
    Pasajero* p = new Pasajero(nickname, nombre, contrasena, email, ci);
    usuarios[nickname] = p;
    return true;
}

bool ManejadorUsuario::nuevoConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::vector<TipoLibreta> libreta) {
    if (usuarios.count(nickname) > 0) return false;
    Conductor* c = new Conductor(nickname, nombre, contrasena, email, libreta);
    usuarios[nickname] = c;
    return true;
}
 
std::vector<DTUsuario> ManejadorUsuario::listarUsuarios() {
    std::vector<DTUsuario> res;
    for (auto& par : usuarios) {
        if (dynamic_cast<Conductor*>(par.second) != nullptr)
            res.push_back(DTUsuario(par.second->getNickname(), par.second->getNombre()));
    }
    for (auto& par : usuarios) {
        if (dynamic_cast<Pasajero*>(par.second) != nullptr)
            res.push_back(DTUsuario(par.second->getNickname(), par.second->getNombre()));
    }
    return res;
}
 
bool ManejadorUsuario::calificarUsuario(std::string nicknameCalificado, std::string nicknameCalificador, int calificacion) {
    Usuario* u = encontrarUsuario(nicknameCalificado);
    if (u == nullptr) return false; 
    ControladorFechaActual* ctrlFechaActual = ControladorFechaActual::getInstance(); 
    Calificacion* calif = new Calificacion(ctrlFechaActual->getFecha(), calificacion);
    u->crearCalificacion(calif);
    calif->setCalificado(u);
    Usuario* calificador = encontrarUsuario(nicknameCalificador);
    calif->setCalificador(calificador);
    return true;
}
 
std::vector<std::string> ManejadorUsuario::listarPasajeros() {
    std::vector<std::string> vecP;
    Pasajero* p;
    for (auto& par : usuarios)
    {
        if ((p = dynamic_cast<Pasajero*>(par.second))!=nullptr)
            vecP.push_back(par.first);
    }
    return vecP;
}
    

bool ManejadorUsuario::regVehCon(std::string nickname, TipoVehiculo tipo) {
    Conductor* c = dynamic_cast<Conductor*>(this->usuarios[nickname]);
    bool res = c->tieneLibreta(tipo);
    return res;
}

void ManejadorUsuario::agregarVehiculoConductor(Vehiculo* v, std::string nickname) {
    Conductor* c = dynamic_cast<Conductor*>(this->usuarios[nickname]);
    if (c != nullptr) {
        c->agregarVehiculo(v);
        v->setConductor(c);
    }
}
 
std::vector<DTUsuarioViaje> ManejadorUsuario::encontrarConductoViaje(std::string nickname) {
    return {};
}