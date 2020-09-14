/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* LIBRERIA PARA LA VALIDACION DE INGRESO DE DATOS                 *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 1/09/20									  *
* FECHA DE MODIFICACIÓN: 13/09/20								  *
******************************************************************/

/**
	@file Validacion.h
	@brief Clase que contiene metodos para realizar las validaciones de los ingresos de datos
	@author Madely Betancourt y Kevin Caicedo
	@date 9/2020
*/
#pragma once
#include<string>
#include <conio.h>
#include <iostream>
using namespace std;

class Validacion
{
public:
	bool validarString(string, int);
	string noNumericos(string);
};

