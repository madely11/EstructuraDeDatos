/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE PARA DEFINIR LA FECHA DE LAS TRANSACCIONES                *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/06/20									  *
* FECHA DE MODIFICACIÓN: 02/07/20								  *
******************************************************************/

/**
    @file Fecha.cpp
    @brief Clase que contiene metodos para tomar la fecha del sistema
    @author Madely Betancourt y Kevin Caicedo
    @date 6/2020
*/


#pragma once
#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;


class Fecha
{
public:
    void setFecha(string);
    void setHora(string);
    string fechaUnida();
    string horaUnida();
    string getFecha();
    string getHora();

private:
    string hora;
    string fecha;
};

