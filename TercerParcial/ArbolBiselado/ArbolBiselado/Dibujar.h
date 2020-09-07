/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE PARA DIBUJAR EL ARBOL               *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 04/07/20									  *
* FECHA DE MODIFICACIÓN: 09/07/20								  *
******************************************************************/
#pragma once
#include <iostream>
#include<string>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Dibujar
{
public:
	RenderWindow* ventana;
public:
	Dibujar();
	void dibujarNodo(int, int, string);
};

