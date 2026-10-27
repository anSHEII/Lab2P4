#ifndef TIPO_VEHICULO_H
#define TIPO_VEHICULO_H

enum TipoVehiculo {
    Auto,
    Moto
};

inline const char* tipoVehiculoToString(TipoVehiculo tipo) {
    switch(tipo) {
        case Auto: return "Auto";
        case Moto: return "Moto";
        default:   return "Desconocido";
    }
}

#endif
