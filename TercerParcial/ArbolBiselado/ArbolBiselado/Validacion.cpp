/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* INGRESO DE DATOS               *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 04/07/20									  *
* FECHA DE MODIFICACIÓN: 09/07/20								  *
******************************************************************/

/**
	@file Validacion.cpp
	@brief Clase que contiene metodos para realizar las validaciones de los ingresos de datos
	@author Madely Betancourt y Kevin Caicedo
	@date 6/2020
*/

#include "Validacion.h"

/**
	@brief Funcion para validar entrada de numeros
	@param entrada de datos tipo string y entero tipo int
	@returns verdadero o falso
*/
bool Validacion::validar(string entrada, int tipo) {
	int contador = 0, contDecimales = 0;
	try {
		if (entrada.length() == 0) {
			throw 1;
		}

		for (int i = 0; i < entrada.length(); i++) {
			if (isalpha(entrada[i])) {
				throw 1;
			}
			if (!isdigit(entrada[i]) && tipo == 1) {
				throw 1;
			}
			if (entrada[i] == '.' || entrada[i] == ',') {
				contador++;
			}
			if (contador == 1 && entrada[i] != '.') {
				contDecimales++;
				if (contDecimales > 2) {
					throw 1;
				}
			}
			if ((isdigit(entrada[i]) == 0 && entrada[i] != '.') || (contador > 1)) {
				throw 1;
			}
		}
	}
	catch (int e) {
		return true;
	}
	return false;
}



