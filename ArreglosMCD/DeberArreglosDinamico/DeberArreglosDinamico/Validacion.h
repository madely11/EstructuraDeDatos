/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* PROGRAMA PARA CALCULAR EL MCM Y MCD DE UN ARREGLO DINÁMICO      *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 01/06/20									  *
* FECHA DE MODIFICACIÓN: 03/06/20								  *
******************************************************************/


#include <iostream>
#include <ctype.h>
#include <string.h>

using namespace std;

class Validacion {
public:
	bool validar(string, int);
};



/**
	@brief Funcion validar
	@param strign entrada que representa el mensaje, un int de tipo para la validacion
	@returns un booleano
*/

bool Validacion::validar(string entrada, int tipo) {
	int contador = 0;
	try {
		for (int i = 0; i < entrada.length(); i++) {
			if (isalpha(entrada[i])) {
				throw 1;
			}
			if (!isdigit(entrada[i]) && tipo == 1) {
				throw 1;
			}
			if (entrada[i] == '.') {
				contador++;
			}
			if ((isdigit(entrada[i]) == 0 && entrada[i] != '.' && entrada[i] != '-') || (contador > 1)) {
				throw 1;
			}
		}
	}
	catch (int e) {
		return true;
	}
	return false;
}

