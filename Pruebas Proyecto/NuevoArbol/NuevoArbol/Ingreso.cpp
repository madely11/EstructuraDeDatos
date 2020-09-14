#/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE INGRESO                                                   *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 01/09/20									  *
* FECHA DE MODIFICACIÓN: 13/09/20								  *
******************************************************************/

/**
	@file Ingreso.cpp
	@brief Clase que contiene metodos para ingresar los datos
	@author Madely Betancourt y Kevin Caicedo
	@date 9/2020
*/

#include "Ingreso.h"
#include "Validacion.h"

#pragma once

/**
	@brief Funcion para leer un numero entero o flotante
	@param string entrada
	@param int tipo
	@returns string lectura
*/
string Ingreso::leerString(string mensage, int tipo) {
	Validacion validacion;
	string entrada;
	cout << mensage << endl;
	getline(cin, entrada);
	while (validacion.validarString(entrada, tipo)) {
		cout << "Entrada no valida, reingrese: " << endl;
		getline(cin, entrada);
	}
	return entrada;

}