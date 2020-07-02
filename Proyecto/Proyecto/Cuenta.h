#pragma once
#include "TipoCuenta.h"
#include "ManejoArchivo.h"
#include "Transacciones.h"
#include <iostream>

using namespace std;

class Cuenta
{
public:
    int getNumc(void);
    float getMonto(void);
    void setNumc(int);
    void setMonto(float);
    bool verificarCuenta(int);

    void hacerString();
    void guardarDatos(string);
    Cuenta();
    Cuenta(int, string);
    TipoCuenta* tipo;
    Transacciones t;
protected:
private:
    float monto;
    int numeroCuenta;
    string idCliente;
    string dato;
};

