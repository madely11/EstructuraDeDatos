/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE INGRESO                                                   *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 1/09/20									  *
* FECHA DE MODIFICACIÓN: 13/09/20								  *
******************************************************************/

/**
	@file Fecha.h
	@brief Clase que contiene metodos para tomar la hora y fecha del sistema
	@author Madely Betancourt y Kevin Caicedo
	@date 9/2020
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
	string obtenerHora();
	string obtenerFecha();

private:
	string hora;
	string fecha;
};

