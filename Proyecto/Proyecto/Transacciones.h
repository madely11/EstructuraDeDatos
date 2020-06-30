#pragma once
#include "Fecha.h"

class Transacciones
{
public:
    void datosTransaccion();
    int depositar(int, int);
    int retirar(int, int);
    void stringConsola(string);
    void guardarTransaccion(int, int, int);
    //friend ostream& operator<<(ostream& o, Cuenta& c);
    friend ostream& operator<<(ostream& o, Fecha& f);

private:
    Fecha fecha;
    string tipoTransaccion;
    string dato;
};

