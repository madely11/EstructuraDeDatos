/***********************************************************************
 * Module:  Cliente.h
 * Author:  Madely Betancourt, Kevin Caicedo
 * Modified: martes, junio 16, 2020 7:06:58 PM
 * Purpose: Declaration of the class Cliente
 ***********************************************************************/

#if !defined(__Banco_Cliente_h)
#define __Banco_Cliente_h

#include <string.h>
#include "Cuenta.h"
#include "Validacion.h"
//#include "FileManager.h"
#include <iostream>
#include"Ingreso.h"
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
    std::string nombre;
    std::string cedula;
    std::string email;
    std::string direccion;
    Validacion validar;
    Cuenta *cuenta=NULL;
    string dato;
    Ingreso ingreso;
};

void Cliente :: pedirDatos(int num) {
    string dim;
    nombre = ingreso.leerString("Ingrese el nombre del titular : ", 1);
    cedula=cedula.assign(ingreso.ingresaNumericos("Ingrese la cedula del titular:"),10);
    while (!validar.cedula(cedula)) {
        cedula.assign(ingreso.ingresaNumericos("\nIngrese la cedula del titular:"),10);
    }
    
    email = ingreso.leerString("\nIngrese el email del titular : ", 1);
    direccion = ingreso.leerString("Ingrese la direccion del titular : ", 1);
    cuenta = new Cuenta(num, cedula);
    hacerString();
    FileManager fileM ("cliente.txt");
    fileM.agregarLinea(dato);
}

string Cliente::stringConsola() {
    string salida;
    salida = "Nombre: " + nombre +
        "\nCedula: " + cedula +
        "\nEmail: " + email +
        "\nDireccion: " + direccion +
        "\nNumero de cuenta: " + to_string(cuenta->getNumc())+
        "\nMonto: "+ to_string(cuenta->getMonto())+
        "\nTipo de cuenta: "+ cuenta->tipo->getNombre();
    return salida;
}


void Cliente::hacerString() {
    dato = nombre + "," + cedula + "," + email + "," + direccion;
}
#endif