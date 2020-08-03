/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE INGRESO                                                   *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/06/20									  *
* FECHA DE MODIFICACIÓN: 02/07/20								  *
******************************************************************/

/**
	@file Ingreso.cpp
	@brief Clase que contiene metodos para ingresar los datos	
	@author Madely Betancourt y Kevin Caicedo
	@date 6/2020
*/


#include "Ingreso.h"
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

/**
	@brief Funcion para el ingreso de letras
	@param entrada strin, tipo entero
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

/**
	@brief Funcion para que solo se pueda ingresar numero en la consola
	@param entrada tipo char*
	@returns valor char* 
*/
char* Ingreso::ingresaNumericos(const char* msg) {
	int caracter;
	puts(msg);
	int i = 0;
	char* valor;
	valor = (char*)calloc(10, sizeof(char));
	while ((caracter = _getch()) != 13) {
		if (caracter >= 48 && caracter <= 57) {
			*(valor + i) = caracter;
			printf("%c", caracter);
			i++;
			
		}
		
	}
	if (i > 10) {
		ingresaNumericos(msg);
	}
	return valor;
}
/**
	@brief Funcion para leer fecha
	@param entrada string
	@returns bool
*/
bool Ingreso::leerFecha(string fecha) {
	char* aux;
	Validacion validacion;
	if (fecha.length() != 10) {
		return false;
	}
	else {
		aux = (char*)malloc(fecha.length() * sizeof(char));
	}

	for (int i = 0; i < fecha.length(); i++)
	{
		*(aux + i) = fecha.at(i);
	}
	//retorna 0 si no es numero
	//retorna 1 si es numero
	if (!isdigit(*(aux + 0)) || !isdigit(*(aux + 1))) {
		return false;
	}

	if (*(aux + 2) != '/') {
		return false;
	}

	if (!isdigit(*(aux + 3)) || !isdigit(*(aux + 4))) {
		return false;
	}

	if (*(aux + 5) != '/') {
		return false;
	}

	if (!isdigit(*(aux + 6)) || !isdigit(*(aux + 7)) || !isdigit(*(aux + 8)) || !isdigit(*(aux + 9))) {
		return false;
	}

	if (!validacion.validarFecha(fecha)) {
		return false;
	}

	return true;
}
