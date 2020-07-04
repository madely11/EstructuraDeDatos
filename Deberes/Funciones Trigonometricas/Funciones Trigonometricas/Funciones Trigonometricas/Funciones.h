/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* LIBRERIA DE FUNCIONES PARA CALCULAR SENO, COSENO Y TANGENTE     *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 01/06/20									  *
* FECHA DE MODIFICACIÓN: 03/06/20								  *
******************************************************************/

/**
	@file Funciones.h
	@brief Clase que contiene metodos para calcular las funciones trigonometricas
	@author Madely Betancourt y Kevin Caicedo
	@date 6/2020
*/

#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include <iostream>
#define PI 3.14159265
using namespace std;

template <typename tipo> class Funciones{
public:
	tipo angulo;

public:
	tipo convierte(tipo);
	tipo miSeno(tipo);
	tipo miCoseno(tipo);
	int factorial(int);
	tipo potencia(tipo, int);
	tipo miTangente(tipo);
};


/**
	@brief Funcion para calcular la potencia de un numero
	@param base de tipo tipo, expo de tipo int
	@returns la potencia del numero
*/
template <typename tipo>
tipo Funciones <tipo> :: potencia (tipo num_base, int exp) {
	if (exp < 0) {
		exp *= -1;
		return 1 / (num_base * potencia(num_base, exp - 1));
	}

	if (exp == 0) {
		return 1;
	}
	else {
		return num_base * potencia(num_base, exp - 1);
	}
}

/**
	@brief Funcion para calcular el factorial de un numero
	@param numero de tipo int
	@returns el factorial del numero
*/
template <typename tipo>
int Funciones <tipo> :: factorial(int num) {
	if (num == 0)
		return 1;
	else
		return num * factorial(num - 1);
}


/**
	@brief Funcion para convertir de grados a radianes
	@param angulo de tipo int
	@returns el grado en radianes
*/
template <typename tipo>
tipo Funciones <tipo>::convierte(tipo angulo) {
	float conversion;
	if (angulo == 360)
		return 0;
	else 
		conversion = angulo * (float)PI / 180;
	return conversion;
}


/**
	@brief Funcion para calcular el seno de un angulo
	@param angulo de tipo tipo
	@returns el valor del seno
*/
template <typename tipo>
tipo Funciones <tipo>::miSeno(tipo angulo) {
	int gradPol = 7;
	float seno = 0;
	float num = 0;
	float den = 0;
	int signo = 0;
	angulo = convierte(angulo);

	for (int i = 0; i < gradPol; i++) {
		//signo = potencia(-1, i);
		num = (float)potencia(angulo, 2 * i + 1); //numerador de la serie de Taylor
		den = (float)factorial(2 * i + 1);//denominador de la serie de Taylor
		if (i % 2 == 0)
			seno += (num / den);
		else
			seno -= (num / den);
		//cout << seno << endl;
	}
	return seno;
}

/**
	@brief Funcion para calcular el coseno de un angulo
	@param angulo de tipo tipo
	@returns el valor del coseno
*/
template <typename tipo>
tipo Funciones <tipo>::miCoseno(tipo angulo) {
	int gradPol = 7;
	float coseno = 0;
	float num = 0;
	float den = 0;
	//int signo = 0;
	angulo = convierte(angulo);

	for (int i = 0; i <= gradPol-1; i++) {
		//signo =(double) potencia(-1, i);
		num = (float)potencia(angulo, 2 * i); //numerador de la serie de Taylor
		den = (float)factorial(2 * i);//denominador de la serie de Taylor
		if (i % 2 == 0)
			coseno += (num / den);
		else
			coseno -= (num / den);
		//cout << coseno << endl;
	}
	return coseno;
}

/**
	@brief Funcion para calcular la tangente de un angulo
	@param angulo de tipo tipo
	@returns el valor de la tangente
*/
template <typename tipo>
tipo Funciones <tipo>::miTangente(tipo angulo) {
	if (((int)angulo % 90) == 0) {
		cout << "Error:para la tangente el angulo no debe ser multiplo de 90" << endl;
		return 0;
	}
	else {
		return (miSeno(angulo) / miCoseno(angulo));
	}
}