/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* PROGRAMA QUE RELAIZA EL PROBLEMA DE LA MOCHILA                  *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/07/20									  *
* FECHA DE MODIFICACIÓN: 28/07/20								  *
******************************************************************/

#include <iostream>
#include <sstream>
#include<stdio.h>
#include "Objeto.h"
#include "Ingreso.h"

using namespace std;
/**
	@file Aplicativo.cpp
	@brief Resuelve problema de la mochila
	@author Madely Betancourt y Kevin Caicedo
	@date 7/2020
*/

void main() {
	Ingreso ingreso;
	string dim;
	int pMochila=0, cObjetos=0, posicion = 0, i =0;
	float s=0;
	dim = ingreso.leer("Ingrese el peso de la mochila: ", 1);
	istringstream(dim) >> pMochila;
	fflush(stdin);
	Objeto <int, float> obj(pMochila);
	obj.calcularPeso();
	obj.valorOptimo(posicion, s);
	obj.imprimir();
	

	free(obj.peso);
	free(obj.valor);
	free(obj.valorPorGramo);
	free(obj.cantidad);
}
