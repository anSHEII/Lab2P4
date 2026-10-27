#ifndef MENU_H
#define MENU_H

class Menu {
private:
    void altaUsuario();
    void altaViaje();
    void generarReserva();
    void calificarUsuario();
    void eliminarViaje();
    void administrarFechaActual();
    void cargarDatos();

public:
    void mostrarMenu();
};

#endif
