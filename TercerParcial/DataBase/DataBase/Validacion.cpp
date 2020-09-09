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
	@file Validacion.cpp
	@brief Clase que contiene metodos para realizar las validaciones de los ingresos de datos
	@author Madely Betancourt y Kevin Caicedo
	@date 6/2020
*/

#include "Validacion.h"
/**
	@brief Funcion para validar entrada de Letras
	@param entrada de datos tipo string y entero tipo int
	@returns verdadero o falso
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

