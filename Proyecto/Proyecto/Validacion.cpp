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
	@brief Funcion para validar cedula
	@param numero de cedula tipo string 
	@returns verdadero o falso 
*/
bool Validacion::cedula(string cedula) {
	char* aux;
	int aux_int;
	int aux_int2;
	int verificador;
	int suma = 0;

	if (cedula.length() != 10) {
		return false;
	}

	aux = (char*)malloc(sizeof(char) * 2);
	*(aux + 0) = cedula.at(0);
	*(aux + 1) = cedula.at(1);
	aux_int = atoi(aux);

	if (aux_int > 25) {
		return false;
	}

	aux = (char*)realloc(aux, sizeof(char) * 1);
	*(aux + 0) = cedula.at(2);
	aux_int = atoi(aux);
	if (aux_int > 5) {
		return false;
	}
	for (int i = 0; i < 9; i++)
	{
		*(aux + 0) = cedula.at(i);
		aux_int = atoi(aux);
		if (i % 2 == 0) {
			aux_int *= 2;
		}
		if (aux_int > 9) {
			aux_int -= 9;
		}
		suma += aux_int;
	}

	aux_int2 = suma / 10;
	aux_int2 = (aux_int2 + 1) * 10;
	verificador = aux_int2 - suma;

	*(aux + 0) = cedula.at(9);
	aux_int = atoi(aux);
	if (aux_int != verificador) {
		return false;
	}

	return true;
}
/**
	@brief Funcion para validar entrada de numeros
	@param entrada de datos tipo string y entero tipo int  
	@returns verdadero o falso
*/
bool Validacion::validar(string entrada, int tipo) {
	int contador = 0;
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
			if (entrada[i] == '.') {
				contador++;
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
/**
	@brief Funcion para validar el ingreso de una fecha
	@param fecha tipo string 
	@returns verdadero o falso
*/
bool Validacion::validarFecha(string fecha) {

	string dia;
	dia += fecha.at(0);
	dia += fecha.at(1);

	string mes;
	mes += fecha.at(3);
	mes += fecha.at(4);

	string anio;
	anio += fecha.at(6);
	anio += fecha.at(7);
	anio += fecha.at(8);
	anio += fecha.at(9);

	int d = atoi(dia.c_str());
	int m = atoi(mes.c_str());
	int a = atoi(anio.c_str());

	if ((d < 0 || d > 31)) {
		return false;
	}

	if ((m < 0 || m > 12)) {
		return false;
	}

	if ((a < 1920 || a > 2020)) {
		return false;
	}

	return true;
}
/**
	@brief Funcion para validar el ingreso del email
	@param entrada de datos tipo string 
	@returns verdadero o falso
*/

bool Validacion::validarEmail(string entrada)
{
	try {
		int cont=0;
		int cont2=0;
		if (entrada.length() == 0) {
			throw 1;
		}
		for (int i = 0; i < entrada.length();i++){
			if (entrada[i] == '@') {
				cont++;
			}
			if (cont == 1 && entrada[i] == '.') {
				cont2++;
			}
			if (cont == 1 && entrada[i]!='.' && isdigit(entrada[i])) {
				throw 1;
			}

			if (cont > 1 || cont > 2) {
				throw 1;
			}

		}
		if (cont == 0||cont2<1) {
			throw 1;
		}
		
	}
	catch (int e) {
		return true;
	}
	return false;
}
