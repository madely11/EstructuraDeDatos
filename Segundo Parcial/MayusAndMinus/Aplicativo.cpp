/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* PROGRAMA PARA CONVERTIR EN MAYUSCULAS O MINUSCULAS              *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/07/20									  *
* FECHA DE MODIFICACIÓN: 28/07/20								  *
******************************************************************/

#include"Letras.h"

/**
	@file Aplicativo.cpp
	@brief Convierte a mayusculas y a minusculas
	@author Madely Betancourt y Kevin Caicedo
	@date 7/2020
*/

int main(){
	
	Letras letra;
	letra.convertirMayus();
	letra.convertirMinus();
	system("pause");
	return 0;
}
