#ifndef DT_CONSULTA_VIAJE_H
#define DT_CONSULTA_VIAJE_H

#include "DTFecha.h"
#include <string>

class DTConsultaViaje {
private:
  int codigo;
  std::string marca;
  std::string modelo;
  std::string conductor;
  float calificacionProm;
  float precioTotal;

public:
  DTConsultaViaje(int codigo, std::string marca, std::string modelo, std::string conductor, float calificacionProm, float precioTotal);

  int getCodigo() const;
  std::string getMarca() const;
  std::string getModelo() const;
  std::string getConductor() const;
  float getCalificacionProm() const;
  float getPrecioTotal() const;

  bool operator<(const DTConsultaViaje& other) const;
};

#endif
