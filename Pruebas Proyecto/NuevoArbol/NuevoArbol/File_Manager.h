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
	@file File_Manager.h
	@brief Clase que contiene metodos para manejar archivos de texto
	@author Madely Betancourt y Kevin Caicedo
	@date 9/2020
*/

#pragma once
#include <fstream>
#include <string>
#include <cstdio>
#include "Binary_Tree.cpp"
#include "Translate.h"

class File_Manager
{

	private:
		string nombreArchivo;
		ifstream archivoLectura; //archivo de lectura
		ofstream archivoEscritura; //archivo de escritura

	public:
		File_Manager(string);
		File_Manager();
		bool crearLectura();
		bool crearEscritura();
		void agregarLinea(string);
		void cerrarLectura();
		void cerrarEscritura();
		void imprimir();
		string leerArchivo();

};

