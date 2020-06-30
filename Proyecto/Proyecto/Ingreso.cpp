#include "Ingreso.h"
#pragma once


string Ingreso::leer(string mensage, int tipo) {
	Validacion validacion;
	string entrada;
	cout << mensage << endl;
	getline(cin, entrada);
	while (validacion.validar(entrada, tipo)) {
		cout << "Valor no valido reingrese" << endl;
		getline(cin, entrada);
	}
	return entrada;

}

string Ingreso::leerString(string mensage, int tipo) {
	Validacion validacion;
	string entrada;
	cout << mensage << endl;
	getline(cin, entrada);
	while (validacion.validarString(entrada, tipo)) {
		cout << "Ingrese solo letras reingrese:" << endl;
		getline(cin, entrada);
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

