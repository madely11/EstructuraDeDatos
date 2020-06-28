#include "TipoCuenta.h"


string TipoCuenta::getNombre()
{
    return nombre;
}

void TipoCuenta::setNombre(string newNombre)
{
    this->nombre = newNombre;
}

TipoCuenta::TipoCuenta(int num) {
    if (num == 1) {
        this->nombre = "Ahorros";
        this->id = 1;
    }
    else {
        this->nombre = "Credito";
        this->id = 2;
    }
}

int TipoCuenta::getId()
{
    return id;
}

void TipoCuenta::setId(int newId)
{
    id = newId;
}
