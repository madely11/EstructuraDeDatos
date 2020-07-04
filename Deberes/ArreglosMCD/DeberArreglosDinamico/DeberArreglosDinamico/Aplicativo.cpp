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

/**
	@file Aplicativo.cpp
	@brief Funcion para ingresar, imprimir y llamar otras funciones
	@author Madely Betancourt y Kevin Caicedo
	@date 6/2020
*/


#include <iostream>
#include <sstream>
#include "Arreglo.h"
#include "Operaciones.h"
#include "Ingreso.h"

using namespace std;
/**
	@brief Funcion main donde se hace la llamada a las librerias por medio de los objetos
	@returns 0 para que finalize el programa
*/

int main() {
	Arreglo <int> arr1;
	Ingreso ingreso;
	Operaciones <int> op;
	string dim;
	int valor=1;
	int mcd, mcm;

	arr1.encerar();

	cout << "Ingrese la cantidad de numeros que desee, " ;
	cout << "cuando ingrese 0 el proceso de ingresar datos terminara" << endl;
	dim = ingreso.leer("Ingrese el numero :", 1);
	istringstream(dim) >> valor;

	while (valor!=0)
	{
		arr1.ingresar(valor);
		dim = ingreso.leer("Ingrese el numero :", 1);
		istringstream(dim) >> valor;
	}


	mcd = op.calcularMCD(arr1.getArreglo(), arr1.getLongitud());

	mcm = op.calcularMCM(arr1.getArreglo(), arr1.getLongitud());
	cout << "El MCD es: " << mcd << endl;
	cout << "EL MCM es: " << mcm << endl;
	return 0;
}