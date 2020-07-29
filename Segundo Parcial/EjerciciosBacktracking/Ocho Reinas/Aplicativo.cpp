/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* PROGRAMA QUE RELAIZA EL PROBLEMA DE LAS 8 REINAS                *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/07/20									  *
* FECHA DE MODIFICACIÓN: 28/07/20								  *
******************************************************************/

#include"Reina.h"
#include "Ingreso.h"
#include <sstream>

/**
	@file Aplicativo.cpp
	@brief Resuelve problema 8 reinas
	@author Madely Betancourt y Kevin Caicedo
	@date 7/2020
*/

int main(){
	Ingreso ingreso;
	string dim;
	int n;
	dim = ingreso.leer("Ingrese la dimension del tablero", 1);
	istringstream(dim) >> n;
	Reina* r=new Reina(n);
	if(!r->colocarReina(0,n)){
		cout <<"No existe solucion"<<endl;
	}	
}
