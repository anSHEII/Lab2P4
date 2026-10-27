#include "../include/Conductor.h"
#include "../include/DTVehiculosConductor.h"
#include "../include/Vehiculo.h"
#include <algorithm>

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::vector<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {
    this->libretas = libs;
    this->calificacionPromedio = 5.0;
}

Conductor::~Conductor() {}

std::map<std::string, Vehiculo*> Conductor::getVehiculos() const {
    return vehiculos;
}

std::vector<DTVehiculosConductor> Conductor::listarVehiculos(){
    std::vector<DTVehiculosConductor> res;
    for(auto vehiculo: vehiculos){
        DTVehiculosConductor elem(vehiculo.second->getMatricula(), vehiculo.second->getModelo(), vehiculo.second->getCapacidad());
        res.push_back(elem);
    }
    return res;
}

void Conductor::agregarVehiculo(Vehiculo* v) {
    vehiculos.insert({v->getMatricula(), v});
}

bool Conductor::tieneLibreta(TipoVehiculo tipo) {
    if(tipo == TipoVehiculo::Auto){
        return std::count(libretas.begin(), libretas.end(), TipoLibreta::AutoProfesional) > 0 || std::count(libretas.begin(), libretas.end(), TipoLibreta::AutoAmateur) > 0;
    } else if (tipo == TipoVehiculo::Moto){
        return std::count(libretas.begin(), libretas.end(), TipoLibreta::MotoProfesional) > 0 || std::count(libretas.begin(), libretas.end(), TipoLibreta::MotoAmateur) > 0;
    }
    return false;
}

bool Conductor::hayViajesFechaConductor(DTFecha fecha){
    for(auto vehiculo: vehiculos){
        if(vehiculo.second->hayViajesFecha(fecha)) return true;
    }
    return false;
}