/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* PROGRAMA DEL JUEGO DE SNAKE                                     *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 23/07/20									  *
* FECHA DE MODIFICACIÓN: 02/08/20								  *
******************************************************************/
/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* PROGRAMA DEL JUEGO DE SNAKE                                     *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 23/07/20									  *
* FECHA DE MODIFICACIÓN: 02/08/20								  *
******************************************************************/

#pragma once
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Nodo{
	public:
		Nodo(char, Nodo*);
		char getParte();
	private:
		char parte;
		Nodo *siguiente;
	
	friend class Lista;
};

