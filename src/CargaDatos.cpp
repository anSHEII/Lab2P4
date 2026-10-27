#include "../include/CargaDatos.h"
#include <iostream>
#include "../include/ControladorUsuario.h"
#include "../include/ControladorViajes.h"
#include "../include/ControladorFechaActual.h"
#include "../include/DTFecha.h"

CargaDatos* CargaDatos::instancia = nullptr;

CargaDatos::CargaDatos() {
    datosCargados = false;
}

CargaDatos* CargaDatos::getInstance() {
    if (instancia == nullptr) {
        instancia = new CargaDatos();
    }
    return instancia;
}

void CargaDatos::cargarDatos() {
    if (datosCargados) {
        std::cout << "Error: Los datos ya han sido cargados anteriormente.\n";
        return;
    }
    
    // Aquí iría la lógica de carga de datos harcodeados
    std::cout << "Cargando datos harcodeados del sistema...\n";
    // ... (inserción de usuarios, vehículos, viajes, reservas) ...

    ControladorUsuario* controladorUsuario = ControladorUsuario::getInstancia();
    ControladorViajes* controladorViajes = ControladorViajes::getInstance();
    
    //conductores
    controladorUsuario->altaConductor("matil92", "Matias Lopez", "m4t14s92", "matias.lopez.92@gmail.com", {TipoLibreta::AutoAmateur});
    controladorUsuario->altaConductor("ana_silva", "Ana Silva", "asilva2026", "anasilva.m@outlook.com", {TipoLibreta::AutoProfesional});
    controladorUsuario->altaConductor("greg_m", "Diego Rodriguez", "drodriguez88", "diegorodriguez@fing.edu.uy", {TipoLibreta::MotoAmateur});
    controladorUsuario->altaConductor("lau_vaz", "Laura Vazquez", "lvazquezQ7", "laura.vazquez@fing.edu.uy", {TipoLibreta::MotoProfesional});
    controladorUsuario->altaConductor("carlos_r", "Carlos Rossi", "crossi99x", "carlos.rossi.uy@gmail.com", {TipoLibreta::AutoProfesional, TipoLibreta::MotoAmateur});

    //pasajeros
    controladorUsuario->altaPasajero("santi_90", "Santiago Acosta", "sacosta90", "santiago.acosta@gmail.com", "1.492.304-2");
    controladorUsuario->altaPasajero("mari_b", "Maria Noel Barreto", "maribarreto6", "mari.barreto@outlook.com", "4.103.859-1");
    controladorUsuario->altaPasajero("nacho_f", "Ignacio Figueroa", "ifigueroa26", "ignacio.figueroa@fing.edu.uy", "3.847.112-5");
    controladorUsuario->altaPasajero("valen_uy", "Valentina Mendez", "vmendezQ2", "valen.mendez@fing.edu.uy", "2.956.403-0");
    controladorUsuario->altaPasajero("joaco_r", "Joaquin Rivero", "jrivero99x", "joaquin_rivero@hotmail.com", "5.021.784-3");

    //vehículos
    controladorUsuario->registrarVehiculo("matil92", "ABJ4586", "Chevrolet", "Onix", 4, TipoVehiculo::Auto);
    controladorUsuario->registrarVehiculo("matil92", "ACM4455", "Toyota", "Rush", 6, TipoVehiculo::Auto);
    controladorUsuario->registrarVehiculo("ana_silva", "BAS7895", "Fiat", "Argo", 4, TipoVehiculo::Auto);
    controladorUsuario->registrarVehiculo("ana_silva", "BCS4105", "Hyundai", "H1", 9, TipoVehiculo::Auto);
    controladorUsuario->registrarVehiculo("greg_m", "LDA4875", "Honda", "CB Twist", 1, TipoVehiculo::Moto);
    controladorUsuario->registrarVehiculo("lau_vaz", "PDB1205", "Yumbo", "Max 110", 1, TipoVehiculo::Moto);
    controladorUsuario->registrarVehiculo("carlos_r", "SBJ4874", "Volkswagen", "Gol", 4, TipoVehiculo::Auto);
    controladorUsuario->registrarVehiculo("carlos_r", "SCF2469", "Yamaha", "FZ S", 1, TipoVehiculo::Moto);

    //Viajes
	controladorViajes->altaViaje("ABJ4586",  DTFecha(21, 10, 2026), "montevideo", "mercedes", 4, 200);
	controladorViajes->altaViaje("ACM4455",  DTFecha(20, 10, 2026), "young", "montevideo", 5, 250);
	controladorViajes->altaViaje("BAS7895",  DTFecha(20, 10, 2026), "young", "montevideo", 4, 200);
	controladorViajes->altaViaje("BCS4105",  DTFecha(21, 10, 2026), "montevideo", "mercedes", 9, 200);
	controladorViajes->altaViaje("LDA4875",  DTFecha(21, 10, 2026), "montevideo", "mercedes", 1, 300);
	controladorViajes->altaViaje("PDB1205",  DTFecha(21, 10, 2026), "montevideo", "mercedes", 1, 350);
	controladorViajes->altaViaje("SBJ4874",  DTFecha(21, 10, 2026), "montevideo", "mercedes", 4, 260);
	controladorViajes->altaViaje("SCF2469",  DTFecha(20, 10, 2026), "montevideo", "cerro chato", 1, 150);
	controladorViajes->altaViaje("ABJ4586",  DTFecha(15, 3, 2026), "montevideo", "colonia", 4, 140);
	controladorViajes->altaViaje("BCS4105",  DTFecha(15, 3, 2026), "montevideo", "colonia", 9, 180);
	controladorViajes->altaViaje("SBJ4874",  DTFecha(15, 3, 2026), "montevideo", "colonia", 1, 100);
	controladorViajes->altaViaje("SBJ4874",  DTFecha(14, 3, 2026), "montevideo", "colonia", 4, 600);
	controladorViajes->altaViaje("LDA4875",  DTFecha(20, 10, 2026), "young", "montevideo", 1, 250);

    //reservas
    ControladorFechaActual::getInstance()->setFecha(DTFecha(14, 3, 2026));
    controladorViajes->generarReserva("santi_90", 9, 2);

    controladorViajes->generarReserva("mari_b", 9, 1);
    
    controladorViajes->generarReserva("nacho_f", 10, 5);

    controladorViajes->generarReserva("valen_uy", 10, 3);
    
    controladorViajes->generarReserva("joaco_r", 10, 1);

    controladorViajes->generarReserva("mari_b", 12, 1);

    controladorViajes->generarReserva("nacho_f", 12, 1);

    controladorViajes->generarReserva("mari_b", 1, 2);
;
    controladorViajes->generarReserva("nacho_f", 9, 1);

    //calificaciones

    controladorUsuario->listarViajes("santi_90");
    controladorUsuario->listarUsuariosViaje(9);
    controladorUsuario->calificarUsuario("matil92", 4);
   
    controladorUsuario->listarViajes("mari_b");
    controladorUsuario->listarUsuariosViaje(9);
    controladorUsuario->calificarUsuario("matil92", 4);

    controladorUsuario->listarViajes("matil92");
    controladorUsuario->listarUsuariosViaje(9);
    controladorUsuario->calificarUsuario("mari_b", 3);

    controladorUsuario->listarViajes("ana_silva");
    controladorUsuario->listarUsuariosViaje(10);
    controladorUsuario->calificarUsuario("valen_uy", 5);

    controladorUsuario->listarViajes("ana_silva");
    controladorUsuario->listarUsuariosViaje(10);
    controladorUsuario->calificarUsuario("joaco_r", 5);

    controladorUsuario->listarViajes("mari_b");
    controladorUsuario->listarUsuariosViaje(12);
    controladorUsuario->calificarUsuario("carlos_r", 5);

    controladorUsuario->listarViajes("carlos_r");
    controladorUsuario->listarUsuariosViaje(12);
    controladorUsuario->calificarUsuario("nacho_f", 5);

    datosCargados = true;
    std::cout << "Datos cargados exitosamente.\n";
}
