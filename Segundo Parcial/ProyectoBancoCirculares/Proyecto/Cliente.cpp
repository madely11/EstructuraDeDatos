/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE CLIENTE                                                   *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/06/20									  *
* FECHA DE MODIFICACIÓN: 02/07/20								  *
******************************************************************/

/**
    @file Cliente.cpp
    @brief Clase que contiene metodos para poder crear un objeto Cliente
    @author Madely Betancourt y Kevin Caicedo
    @date 6/2020
*/


#include <string.h>
#include "Cliente.h"
#include <iostream>

using namespace std;
/**
    @brief Funcion para poder ingresar los datos del cliente
    @param numero tipo enter
    @returns void
*/

string Cliente::getNombre()
{
    return nombre;
}

string Cliente::getId()
{
    return cedula;
}

void Cliente::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Cliente::setId(string id)
{
    this->cedula = id;
}

string Cliente::getEmail()
{
    return email;
}

string Cliente::getDireccion(void)
{
    return direccion;
}

void Cliente::setEmail(string email)
{
    this->email = email;
}

void Cliente::setDireccion(string direccion)
{
    this->direccion = direccion;
}

void Cliente::pedirDatos(int num) {

    nombre = ingreso.leerString("\nIngrese el nombre del titular : ", 1);
    cedula = cedula.assign(ingreso.ingresaNumericos("\nIngrese la cedula del titular:"), 10);
    while (!validar.cedula(cedula)) {
        cedula = cedula.assign(ingreso.ingresaNumericos("\nIngrese la cedula del titular:"), 10);
    }
    cout << "\n\nIngrese el email del titular: "<<endl;
    getline(cin,email);
    while (validar.validarEmail(email)) {
        cout << "\nReingrese el email del titular: "<<endl;
        getline(cin, email);
    }

    cout<<"\nIngrese la direccion del titular : "<<endl;
    getline(cin, direccion);

    cuenta = new Cuenta(num, cedula); //algoritmo cuenta
    ManejoArchivo archivoM("cliente.txt");
    archivoM.agregarLinea(hacerString());
}
/**
    @brief Funcion para guardar en un string los datos que se van a mostrar en consola
    @param void
    @returns datos de tipo string
*/
string Cliente::stringConsola() {
    string salida;
    salida = "Nombre: " + nombre +
        "\nCedula: " + cedula +
        "\nEmail: " + email +
        "\nDireccion: " + direccion +
        "\nNumero de cuenta: " + to_string(cuenta->getNumc()) +
        "\nMonto: " + to_string(cuenta->getMonto()) +
        "\nTipo de cuenta: " + cuenta->tipo->getNombre();
    return salida;
}

/**
    @brief Funcion para poner los datos en un string
    @param void
    @returns void
*/
string Cliente::hacerString() {
    return (nombre + "," + cedula + "," + email + "," + direccion);
}
