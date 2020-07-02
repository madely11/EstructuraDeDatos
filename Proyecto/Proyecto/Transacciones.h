#pragma once
#include "Fecha.h"

class Transacciones
{
public:
    void datosTransaccion(int);
    float depositar(float, int);
    float retirar(float, int);
    void stringConsola(string);
    void guardarTransaccion(int, int, int);
    string ingresarFecha();
    friend ostream& operator<<(ostream& o, Fecha& f);

private:
    Fecha fecha;
    string tipoTransaccion;
    string dato;
};

