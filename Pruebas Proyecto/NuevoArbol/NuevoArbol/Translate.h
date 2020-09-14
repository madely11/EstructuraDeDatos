/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE INGRESO                                                   *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 1/09/20									  *
* FECHA DE MODIFICACIÓN: 13/09/20								  *
******************************************************************/

/**
	@file Translate.h
	@brief Clase que contiene metodos para manejar un objeto Translate
	@author Madely Betancourt y Kevin Caicedo
	@date 9/2020
*/

#pragma once
#include <iostream>
#include<sapi.h>
#include <atlconv.h>
#include <string>
using namespace std;

class Translate
{
public:
	Translate(string, string);
	Translate();
	void set_spanish(string _word);
	void set_english(string _word);
	string _to_string_T();
	string get_spanish();
	string get_english();
	
	void hablar(int);
	bool operator < (const Translate& p)const;
	bool operator != (const Translate& p)const;
	bool operator == (const Translate& p)const;
	friend ostream& operator << (ostream& o, const Translate& p);
private:
	string _spanish;
	string _english;
};

