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
#include <sstream>
#include"Fraccion.h"
#include"Ingreso.h"

using namespace std;

int main(){
	Fraccion frac1;
	Fraccion frac2;
	Fraccion resultado;
	Ingreso ingreso;
	string dim;
	int dato;

	dim = ingreso.leer("Ingrese el numerador de la fraccion uno", 2);
	istringstream(dim) >> dato;
	frac1.setNumerador(dato);

	dim = ingreso.leer("Ingrese el denominador de la fraccion uno", 2);
	istringstream(dim) >> dato;
	frac1.setDenominador(dato);

	dim = ingreso.leer("Ingrese el numerador de la fraccion dos", 2);
	istringstream(dim) >> dato;
	frac2.setNumerador(dato);

	dim = ingreso.leer("Ingrese el denominador de la fraccion dos", 2);
	istringstream(dim) >> dato;
	frac2.setDenominador(dato);

	resultado = resultado.Suma(frac1, frac2);

	cout << "El resultado es: " << resultado.getNumerador() << "/" << resultado.getDenominador() << endl;
	return 0;
}