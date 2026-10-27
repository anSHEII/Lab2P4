#ifndef DT_USUARIO_H
#define DT_USUARIO_H

#include <string>

class DTUsuario {
private:
    std::string nickname;
    std::string nombre;

public:
    DTUsuario(std::string nickname, std::string nombre);

    std::string getNickname();
    std::string getNombre();

    bool operator<(const DTUsuario& other) const;
};

#endif
