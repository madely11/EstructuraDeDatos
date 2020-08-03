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
    @file Cliente.h
    @brief Clase que contiene la declaraacion de los metodos para poder crear un objeto Cliente
    @author Madely Betancourt y Kevin Caicedo
    @date 6/2020
*/
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

