/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* PROGRAMA QUE RELIZAR EL PROBLEMA DE LA MOCHILA                  *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/07/20									  *
* FECHA DE MODIFICACIÓN: 28/07/20								  *
******************************************************************/

#include <stdlib.h>
#include <time.h>
#include "Fecha.h"
#include <iostream>
using namespace std;

/**
	@file Random.h
	@brief Clase que genera numeros randomicos
	@author Madely Betancourt y Kevin Caicedo
	@date 7/2020
*/

class Random
{
private:
	int cObjetos=0;
	int limite=0;
public:
	Random(int);
	Random();
	int cantidadObjetos();
	int obtenerNumero();
};

