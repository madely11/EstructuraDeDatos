/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* iNGRESO, BORRADO, GRAFICO ARBOL AVL                *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 04/07/20									  *
* FECHA DE MODIFICACIÓN: 09/07/20								  *
******************************************************************/
/**
	@file Ingreso.cpp
	@brief Clase que contiene metodos para ingresar los datos
	@author Madely Betancourt y Kevin Caicedo
	@date 6/2020
*/


#include "Ingreso.h"
#include "Validacion.h"
//#include "Validacion.h"
#pragma once

/**
	@brief Funcion para leer un numero entero o flotante
	@param entrada string y tipo entero
	@returns string lectura
*/
string Ingreso::leer(string mensage, int tipo) {
	Validacion validacion;
	string entrada;
	cout << mensage << endl;
	getline(cin, entrada);
	while (validacion.validar(entrada, tipo)) {
		cout << "Entrada no valida, reingrese: " << endl;
		getline(cin, entrada);
	}
	return entrada;

}