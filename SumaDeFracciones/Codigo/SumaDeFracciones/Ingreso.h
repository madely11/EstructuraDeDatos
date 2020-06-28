/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* PROGRAMA PARA SUMAR DOS FRACCIONES                              *
* AUTORA: Madely Betancourt										  *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 26/05/20									  *
* FECHA DE MODIFICACIÓN: 26/05/20								  *
******************************************************************/


#include <iostream>
#include "Validacion.h"

using namespace std;

class Ingreso {

public:
	string leer(string, int);
};
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

