#pragma once
#include "Cuenta.h"
#include "Ingreso.h"
#include "Validacion.h"
#include "ManejoArchivo.h"
#include <iostream>

using namespace std;

class Cliente
{
public:
    string getNombre();
    string getId(void);
    void setNombre(string);
    void setId(string);
    void pedirDatos(int);
    void hacerString();
    string stringConsola();

protected:
private:
    string nombre;
    string cedula;
    string email;
    string direccion;
    Validacion validar;
    Cuenta* cuenta = NULL;
    string dato;
    Ingreso ingreso;
    
};

