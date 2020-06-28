
#include <iostream>
#include "Validacion.h"
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

class Ingreso {

public:
	string leer(string, int);
	string leerString(string, int);
	char* ingresaNumericos(const char*);
};

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
		
		cout << "Ingrese solo letras reingrese:" << endl;
		getline(cin,entrada);
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
	while ((caracter = _getch()) != 13){
		if (caracter >= 48 && caracter <= 57) {
			*(valor+i) = caracter;
			printf("%c", caracter);
			i++;
		}
	}
	return valor;
}
