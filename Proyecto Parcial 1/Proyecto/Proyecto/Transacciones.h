#pragma once
#include "Fecha.h"

class Transacciones
{
public:
    void datosTransaccion();
    int depositar(int, int);
    int retirar(int, int);
    string stringConsola(string);
    void guardarTransaccion(int, int, int);

private:
    Fecha fecha;
    string tipoTransaccion;
    string dato;
};

