/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE PARA CREAR EL BACKUP DE LOS DATOS                         *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/06/20									  *
* FECHA DE MODIFICACIÓN: 02/07/20								  *
******************************************************************/

/**
	@file Respaldo.h
	@brief Clase que contiene metodos para realizar un backup de los datos
	@author Madely Betancourt y Kevin Caicedo
	@date 6/2020
*/


#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include "Fecha.h"
#include "ManejoArchivo.h"

class Respaldo
{
public: 
	Fecha fecha;
	string nombreArchivo;
	
public:
	Respaldo(string);
	Respaldo();
	string nombreRespaldo();
	string crearRespaldo();
	void imprimirNombreRespaldo();
	void ingresarRespaldo();
	void guardarRespaldo(string);
};

