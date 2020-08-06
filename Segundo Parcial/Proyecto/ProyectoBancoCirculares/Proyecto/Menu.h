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
#include <conio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <iostream>
#include "Ingreso.h"
#include "ManejoArchivo.h"
#include <clocale>
#include "Cuenta.h"
#include "Cliente.h"
#include "Respaldo.h"
#include "Lista.h"
using namespace std;

class Menu
{
public:
	void menuTeclas();
	void ocultarCursor();
	void submenu1();
	void submenu2();
	void submenu3();
public:
	Lista* listaCliente = new Lista();
	Lista* listaCuentas = new Lista();
	Lista* listaTrans = new Lista();
	Ingreso ingreso;
};

