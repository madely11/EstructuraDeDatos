/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* LIBRERIA PARA LA VALIDACION DE INGRESO DE DATOS                 *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/06/20									  *
* FECHA DE MODIFICACIÓN: 02/07/20								  *
******************************************************************/

/**
	@file Validacion.h
	@brief Clase que contiene metodos para realizar las validaciones de los ingresos de datos
	@author Madely Betancourt y Kevin Caicedo
	@date 6/2020
*/
#pragma once
#include<string>
#include <iostream>
using namespace std;

class Validacion
{
public:
	bool cedula(string);
	bool validar(string, int);
	bool validarString(string, int);
	bool validarFecha(string);
	bool validarEmail(string);
};

