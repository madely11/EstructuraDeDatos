#pragma once

/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE PARA DEFINIR EL MENU DEL PROGRAMA                         *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/06/20									  *
* FECHA DE MODIFICACIÓN: 02/07/20								  *
******************************************************************/

/**
	@file Menu.h
	@brief Clase que contiene metodos para presentar el menu en la consola
	@author Madely Betancourt y Kevin Caicedo
	@date 6/2020
*/



#include <iostream>
#include "Ingreso.h"
#include "Translate.h"
#include "Binary_Tree.cpp"
#include "File_Manager.h"
//#include"Conection_DB.h"
using namespace std;

class Menu
{
public:
	void menuTeclas();
	void ocultarCursor();

public:
	Binary_Tree<Translate> _tree;
	Translate _data;
	Ingreso ingreso;
	string datoS;
};
