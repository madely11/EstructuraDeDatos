#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include "Fecha.h"
#include "Validacion.h"
#include "Translate.h"
#include "File_Manager.h"
#include "Binary_Tree.cpp"
/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE PARA DEFINIR EL MENU DEL PROGRAMA                         *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 01/09/20									  *
* FECHA DE MODIFICACIÓN: 13/09/20								  *
******************************************************************/

/**
	@file Menu.h
	@brief Clase que contiene metodos para presentar el menu en la consola
	@author Madely Betancourt y Kevin Caicedo
	@date 9/2020
*/


using namespace std;

class Menu
{
public:
	void menuTeclas();
	void ocultarCursor();

public:
	Binary_Tree<Translate> _tree;
	Translate _data;
	Validacion v;
	string datoS;
};
