/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE MANEJO DE ARCHIVOS                                        *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/06/20									  *
* FECHA DE MODIFICACIÓN: 02/07/20								  *
******************************************************************/

/**
	@file ManejoArchivos.cpp
	@brief Clase que contiene metodos manejar archivos
	@author Madely Betancourt y Kevin Caicedo
	@date 6/2020
*/



#include "File_Manager.h"
/**
	@brief Constructor de la Clase ManejoArchivo
	@param entrada archivo tipo string
	@returns ManejoArchivo
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


void File_Manager::load_file(Binary_Tree<Translate>* _tree)
{
	string _text;
	string _line;
	Translate _obj;
	int i = 0;
	crearLectura();

	while (!archivoLectura.eof())
	{
		getline(archivoLectura, _line);
		//cout << _line << endl;
		if (_line != "") {
			while (i < _line.length()) {
				if (_line.at(i) == ',') {
					_obj.set_spanish(_text);
					_text = "";
					i++;
				}
				else {
					_text += _line.at(i);
					i++;
				}
			}
			_obj.set_english(_text);
			i = 0;
			_text ="";
			_tree->_add(_obj, _tree->get_root(), NULL);
		}
		
		
	}
	cerrarLectura();
}
