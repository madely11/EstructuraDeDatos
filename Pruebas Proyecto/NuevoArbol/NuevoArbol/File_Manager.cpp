/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE MANEJO DE ARCHIVOS                                        *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 01/09/20									  *
* FECHA DE MODIFICACIÓN: 13/09/20								  *
******************************************************************/

/**
	@file File_Manager.cpp
	@brief Clase que contiene metodos manejar archivos
	@author Madely Betancourt y Kevin Caicedo
	@date 9/2020
*/



#include "File_Manager.h"
/**
	@brief Constructor de la Clase File_Manager
	@param string nombre
	@returns File_Manager
*/
File_Manager::File_Manager(string archivo)
{
	nombreArchivo = archivo;
	crearEscritura();
	cerrarEscritura();
}
/**
	@brief Constructor de la Clase ManejoArchivo
	@param void
	@returns ManejoArchivo
*/
File_Manager::File_Manager()
{
	nombreArchivo = "";
}

/**
	@brief Funcion para empezar la escritura de un archivo
	@param void
	@returns bool
*/
bool File_Manager::crearEscritura()
{
	archivoEscritura.open(nombreArchivo, ios::out | ios::app);

	if (archivoEscritura.fail()) {
		cout << "Imposible abrir el archivo: " << nombreArchivo << endl;
		return false;
	}
	else {
		return true;
	}
}
/**
	@brief Funcion para cerrar la escritura de un archivo
	@param void
	@returns void
*/
void File_Manager::cerrarEscritura()
{
	archivoEscritura.flush();
	archivoEscritura.close();
}

/**
	@brief Funcion para mostrar datos del archivo
	@param void
	@returns void
*/
bool File_Manager::imprimir()
{
	string texto, linea;
	bool v = false; 
	int i = 0;

	crearLectura();

	while (!archivoLectura.eof())
	{
		getline(archivoLectura, linea);
		if (linea != "")
			v = true;
	}
	cerrarLectura();

	crearLectura();

	while (!archivoLectura.eof())
	{
		getline(archivoLectura, linea);
		if (v) {
			cout << linea << endl;
		}
			
		else {
			cout << "No existen Backups creados" << endl;
			return false;
		}
			
	}
	cerrarLectura();
	return true;
}




/**
	@brief Funcion para crear la lectura de un archivo
	@param void
	@returns bool
*/
bool File_Manager::crearLectura()
{
	archivoLectura.open(nombreArchivo, ios::in);

	if (archivoLectura.fail()) {
		cout << "Imposible abrir el archivo: " << nombreArchivo << endl;
		return false;
	}
	else {
		return true;
	}
}


/**
	@brief Funcion para cerrar la lectura de un archivo
	@param void
	@returns void
*/
void File_Manager::cerrarLectura()
{
	archivoLectura.close();
}


/**
	@brief Funcion para agregar linea en un archivo
	@param string
	@returns void
*/
void File_Manager::agregarLinea(string linea)
{
	crearEscritura();
	archivoEscritura << linea << endl;
	cerrarEscritura();
}


/**
	@brief Funcion para leer archivo
	@param void
	@returns string
*/
string File_Manager::leerArchivo() {
	string texto;
	string linea;
	int i = 0;

	crearLectura();

	while (!archivoLectura.eof())
	{
		getline(archivoLectura, linea);
		while (i < linea.length() && linea.at(i) != ',') {
			texto += linea.at(i);
			i++;
		}
		i = 0;
		texto = "";
	}
	cerrarLectura();
	return texto;
}
