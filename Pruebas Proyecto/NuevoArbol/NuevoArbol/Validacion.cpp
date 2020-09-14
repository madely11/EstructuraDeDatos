/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* LIBRERIA PARA LA VALIDACION DE INGRESO DE DATOS                 *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 01/09/20									  *
* FECHA DE MODIFICACIÓN: 13/09/20								  *
******************************************************************/

/**
	@file Validacion.cpp
	@brief Clase que contiene metodos para realizar las validaciones de los ingresos de datos
	@author Madely Betancourt y Kevin Caicedo
	@date 9/2020
*/

#include "Validacion.h"

/**
	@brief Funcion para validar entrada de Letras
	@param string  
	@param int
	@returns bool
*/
bool Validacion::validarString(string entrada, int tipo) {
	int contador = 0;
	try {
		if (entrada.length() == 0) {
			throw 1;
		}
		for (int i = 0; i < entrada.length(); i++) {
			if (isdigit(entrada[i])) {
				throw 1;
			}
			if (!isalpha(entrada[i]) && tipo == 1 && entrada[i] != 32) {
				throw 1;
			}
			if (entrada[i] == '.') {
				throw 1;
			}
			if (isalpha(entrada[i]) == 0 && i == 0) {
				throw 1;
			}
		}
	}
	catch (int e) {
		return true;
	}
	return false;
}
/**
	@brief Funcion para invalidar el ingreso de numero
	@param string
	@returns string
*/
string Validacion::noNumericos(string msg) {
	int caracter;
	puts(msg.c_str());
	int i = 0;
	string valor;
	while ((caracter = _getch()) != 13) {
		if (!(caracter >= 48 && caracter <= 57)) {
			valor += caracter;
			printf("%c", caracter);
		}
	}
	if (!validarString(valor, 1)) {
		return valor;
	}
	else {
		return noNumericos(" \n Dato invalido, ingrese de nuevo: ");
	}
}


