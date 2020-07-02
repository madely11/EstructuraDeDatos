/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE PARA DETERMINAR TIPO DE CUENTA                            *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/06/20									  *
* FECHA DE MODIFICACIÓN: 02/07/20								  *
******************************************************************/

/**
    @file TipoCuenta.H
    @brief Clase que contiene los nombre de los tipos de cuenta
    @author Madely Betancourt y Kevin Caicedo
    @date 6/2020
*/
#pragma once
#include <string>
#include <iostream>

using namespace std;
class TipoCuenta
{
public:
    string getNombre();
    void setNombre(string);
    TipoCuenta(int);
    int getId();
    void setId(int);

private:
    string nombre;
    int id;
};

