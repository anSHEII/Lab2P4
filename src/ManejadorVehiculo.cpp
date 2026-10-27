#include "../include/ManejadorVehiculo.h"
#include "../include/Vehiculo.h"

ManejadorVehiculo* ManejadorVehiculo::instancia = nullptr;

ManejadorVehiculo::ManejadorVehiculo() {}

ManejadorVehiculo* ManejadorVehiculo::getInstancia(){
    if(instancia == nullptr){
        instancia = new ManejadorVehiculo();
    }
    return instancia;
}

Vehiculo* ManejadorVehiculo::getVehiculo(std::string matricula){
    auto it = this->vehiculos.find(matricula);
    return it->second;
}

bool ManejadorVehiculo::existeVehiculo(std::string mat){
    return vehiculos.count(mat) > 0;
}

Vehiculo* ManejadorVehiculo::nuevoVehiculo(std::string matricula, std::string marca, std::string modelo, int capacidad, TipoVehiculo tipo){
    Vehiculo* v = new Vehiculo(matricula, capacidad, marca, modelo, tipo);
    vehiculos[matricula] = v;
    return v;
}
