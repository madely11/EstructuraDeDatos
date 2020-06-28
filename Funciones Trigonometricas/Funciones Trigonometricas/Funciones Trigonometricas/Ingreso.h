/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* LIBRERIA PARA INGRESAR UN VALOR                                 *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 01/06/20									  *
* FECHA DE MODIFICACIÓN: 03/06/20								  *
******************************************************************/

#include <iostream>
#include "Validacion.h"

using namespace std;

class Ingreso {

public:
	string leer(string, int);
};

/**
	@brief Funcion ingresar llamada desde el Aplicativo
	@param primeor un strinng que es el mensaje que se despliega, segundo un entero
	@returns entrada que es el valor validado
*/

string Ingreso::leer(string mensage, int tipo) {
	Validacion validacion;
	string entrada;
	cout << mensage << endl;
	cin >> entrada;
	while (validacion.validar(entrada, tipo)) {
		cout << "Valor no valido reingrese" << endl;
		cin >> entrada;
	}
	return entrada;
}

