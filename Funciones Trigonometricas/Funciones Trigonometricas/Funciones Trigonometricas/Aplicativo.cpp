/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* PROGRAMA PARA CALCULAR EL SENO, COSENO Y TANGENTE DADO UN ANGULO*
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 01/06/20									  *
* FECHA DE MODIFICACIÓN: 19/06/20								  *
******************************************************************/

/**
	@file Aplicativo.cpp
	@brief Funcion para ingresar, imprimir y llamar otras funciones
	@author Madely Betancourt y Kevin Caicedo
	@date 6/2020
*/

#include <iostream>
#include <sstream>
#include "Funciones.h"
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "Ingreso.h"
using namespace std;

int main()
{
	Ingreso ingreso;
	string dim;
	Funciones <float> funcion;
	float temporal=0;

	dim = ingreso.leer("Ingrese el angulo en grados: ", 1);
	istringstream(dim) >> funcion.angulo;
	cout << "El seno es: " << funcion.miSeno(funcion.angulo) << endl;
	cout << "El coseno es: " << funcion.miCoseno(funcion.angulo) << endl;
	if(funcion.miTangente(funcion.angulo) != 0)
		cout << "La tangente es: " << funcion.miTangente(funcion.angulo) << endl;
	system("pause");
	return 0;
}

