#ifndef DT_VEHICULOS_CONDUCTOR_H
#define DT_VEHICULOS_CONDUCTOR_H

#include <string>
#include "./TipoVehiculo.h"

class DTVehiculosConductor {
private:
  std::string matricula;
  std::string marca;
  int capacidad;
  

public:
  DTVehiculosConductor(std::string matricula, std::string marca, int capacidad);

  std::string getMatricula();
  int getCapacidad();
  std::string getMarca();
};

#endif
