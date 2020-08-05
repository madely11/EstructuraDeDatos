#pragma once
#include <iostream>
#include "Validacion.h"
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

#ifndef Ingreso_H
#define Ingreso_H

class Ingreso {

public:
	string leer(string, int);
	string leerString(string, int);
	bool leerFecha(string);
	char* ingresaNumericos(const char*);
};

#endif 
string Ingreso::leer(string mensage, int tipo) {
	Validacion validacion;
	string entrada;
	cin.clear();
	cin.sync();
	cout << mensage << endl;
	cin >> entrada;
	while (validacion.validar(entrada, tipo)) {
		cin.clear();
		cin.sync();
		cout << "Valor no valido reingrese" << endl;
		cin >> entrada;
		cin.clear();
		cin.sync();
	}
	return entrada;
}

string Ingreso::leerString(string mensage, int tipo) {
	Validacion validacion;
	string entrada;
	cout << mensage << endl;
	getline(cin, entrada);
	while (validacion.validarString(entrada, tipo)) {

		cout << "Entrada invalida, reingrese:" << endl;
		getline(cin, entrada);
		cin.sync();
		cin.clear();
	}
	return entrada;

}


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
	return valor;
}



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

