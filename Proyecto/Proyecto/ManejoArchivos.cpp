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



#include "ManejoArchivo.h"
/**
	@brief Constructor de la Clase ManejoArchivo
	@param entrada archivo tipo string 
	@returns ManejoArchivo
*/
ManejoArchivo::ManejoArchivo(string archivo)
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
ManejoArchivo::ManejoArchivo()
{
	nombreArchivo = "";
}
/**
	@brief Funcion para empezar la escritura de un archivo
	@param void
	@returns bool
*/
bool ManejoArchivo::crearEscritura()
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
void ManejoArchivo::cerrarEscritura()
{
	archivoEscritura.flush();
	archivoEscritura.close();
}
/**
	@brief Funcion para crear la lectura de un archivo
	@param void
	@returns bool
*/
bool ManejoArchivo::crearLectura()
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
void ManejoArchivo::cerrarLectura()
{
	archivoLectura.close();
}
/**
	@brief Funcion para agregar linea en un archivo
	@param string
	@returns void
*/
void ManejoArchivo::agregarLinea(string linea)
{
	crearEscritura();
	archivoEscritura << linea << endl;
	cerrarEscritura();
}
/**
	@brief Funcion para contar las lineas de un archivo
	@param void
	@returns int
*/
int ManejoArchivo::contarLineas()
{
	crearLectura();
	int cuentaLinea = 0;
	string texto;
	//if (!crearLectura()) {
	//	//cerrarLectura();
	//	return -1;
	//}
	while (!archivoLectura.eof())
	{
		getline(archivoLectura, texto);
		cuentaLinea++;
	}
	cerrarLectura();
	return cuentaLinea;
}
/**
	@brief Funcion para leer archivo
	@param void
	@returns string
*/
string ManejoArchivo::leerArchivo() {
	string texto ;
	string linea;
	int i = 0;

	crearLectura();

	/*if (!crearLectura()) {
		texto = "salir";
		return texto;
	}*/
	while (!archivoLectura.eof())
	{
		getline(archivoLectura, linea);
		while (i < linea.length() && linea.at(i) != ',') {
			texto += linea.at(i);
			i++;
		}
		i = 0;
		texto += "\n\t";
	}
	cerrarLectura();
	return texto;
}
/**
	@brief Funcion para buscar respaldo de datos
	@param string
	@returns string
*/
string ManejoArchivo::buscarRespaldo(string ingresado) {
	crearLectura();
	string linea;
	string dato;
	string texto = "salir";
	int i;
	while (!archivoLectura.eof())
	{
		i = 0;
		dato = "";
		getline(archivoLectura, linea);
		while (i < linea.length() && linea.at(i) != ',') {
			dato += linea.at(i);
			i++;
		}
		if (dato._Equal(ingresado)) {
			dato += ",";
			i++;
			while (i < linea.length() && linea.at(i) != ',') {
				dato += linea.at(i);
				i++;
			}
			dato += ",";
			i++;
			while (i < linea.length() && linea.at(i) != ',') {
				dato += linea.at(i);
				i++;
			}
			dato += ",";
			i++;
			while (i < linea.length() && linea.at(i) != ',') {
				dato += linea.at(i);
				i++;
			}
			cerrarLectura();
			return dato;
		}
	}
	cerrarLectura();
	return texto;
}
/**
	@brief Funcion para actualizar datos al archivo de respaldo
	@param string
	@returns void
*/
void ManejoArchivo::actualizarRespaldo(string linea) {
	crearLectura();
	string rCuenta, rCliente, rTransacciones;
	int i=0;

	while (i < linea.length() && linea.at(i) != ',') {
		i++;
	}
	i++;
	while (i < linea.length() && linea.at(i) != ',') {
		rCliente += linea.at(i);
		i++;
	}
	i++;
	while (i < linea.length() && linea.at(i) != ',') {
		rCuenta += linea.at(i);
		i++;
	}
	i++;
	while (i < linea.length() && linea.at(i) != ',') {
		rTransacciones += linea.at(i);
		i++;
	}

	remove("cliente.txt");
	rename(rCliente.c_str(), "cliente.txt");

	remove("cuenta.txt");
	rename(rCuenta.c_str(), "cuenta.txt");

	remove("Transacciones.txt");
	rename(rTransacciones.c_str(), "Transacciones.txt");
	
}
/**
	@brief Funcion para buscar una cuenta por numero de cuenta
	@param int
	@returns string
*/
string ManejoArchivo::buscarCuenta(int numCuenta)
{
	crearLectura();
	string texto;
	string texto2 = "salir";
	string id_string;
	while (!archivoLectura.eof())
	{
		getline(archivoLectura, texto);
		texto = comparar(numCuenta, texto);
		if (!texto._Equal("salir")) {
			cerrarLectura();
			return texto;
		}
	}
	cerrarLectura();
	return texto2;
}
/**
	@brief Funcion para actualizar datos de un archivo
	@param int , string
	@returns void
*/
void ManejoArchivo::actualizar(int numCuenta, string datoNuevo)
{
	crearLectura();
	ofstream archivoAux;
	string dato;

	archivoAux.open("cuentaAux.txt", ios::out | ios::app);


	if (archivoAux.fail()) {
		cout << "No se abre el aux" << endl;
		return;
	}

	while (!archivoLectura.eof()) {

		getline(archivoLectura, dato);
		if (comparar(numCuenta, dato)._Equal("salir")) {
			archivoAux << dato << endl;
		}
		else {
			archivoAux << datoNuevo << endl;
		}
	}
	archivoAux.close();
	cerrarLectura();
	remove("cuenta.txt");
	rename("cuentaAux.txt", "cuenta.txt");
}
/**
	@brief Funcion comparar datos de un archivo
	@param int , string
	@returns string
*/
string ManejoArchivo::comparar(int numCuenta, string dato)
{
	int i = 0;
	int id = 0;
	string texto2 = "salir";
	string id_string;
	id_string = "";
	while (i < dato.length() && dato.at(i) != ',') {
		i++;
	}
	i++;
	while (i < dato.length() && dato.at(i) != ',') {
		id_string += dato.at(i);
		i++;
	}
	id = atoi(id_string.c_str());
	if (id == numCuenta) {
		return dato;
	}
	return texto2;
}
/**
	@brief Funcion para buscar registro
	@param int, int
	@returns string
*/
string ManejoArchivo::buscarRegistro(int numCuenta, int coincidencia)
{
	crearLectura();
	string texto;
	string texto2 = "salir";
	string idString;
	int i = 0;
	while (!archivoLectura.eof())
	{
		getline(archivoLectura, texto);
		texto = compararRegistro(numCuenta, texto);

		if (!texto._Equal("salir")) {
			i++;
		}
		if (!texto._Equal("salir") && i == coincidencia) {
			//i++;
			cerrarLectura();
			return texto;
		}
	}
	cerrarLectura();
	return texto2;
}
/**
	@brief Funcion para buscar registro
	@param string, int, int
	@returns string
*/
string ManejoArchivo::buscarRegistro(string f, int numCuenta, int coincidencia)
{
	crearLectura();
	string texto;
	string texto2 = "salir";
	string idString;
	int i = 0;
	while (!archivoLectura.eof())
	{
		getline(archivoLectura, texto);
		texto = compararRegistro(numCuenta, texto);
		texto = compararRegistro(f, texto);
		if (!texto._Equal("salir")) {
			i++;
		}
		if (!texto._Equal("salir") && i == coincidencia) {
			//i++;
			cerrarLectura();
			return texto;
		}
	}
	cerrarLectura();
	return texto2;
}
/**
	@brief Funcion para comparar registro por fecha
	@param string, string 
	@returns string
*/
string ManejoArchivo::compararRegistro(string f, string dato)
{
	int i = 0;
	string texto2 = "salir";
	string idFecha;

	while (i < dato.length() && dato.at(i) != ',') {
		i++;
	}
	i++;
	while (i < dato.length() && dato.at(i) != ',') {
		i++;
	}
	i++;
	while (i < dato.length() && dato.at(i) != ',') {
		i++;
	}
	i++;
	while (i < dato.length() && dato.at(i) != ',') {
		i++;
	}
	i++;
	while (i < dato.length() && dato.at(i) != ',') {
		idFecha += dato.at(i);
		i++;
	}

	if (f._Equal(idFecha)) {
		return dato;
	}
	return texto2;
}
/**
	@brief Funcion para comparar registro de un archivo
	@param numCuenta, string
	@returns String
*/
string ManejoArchivo::compararRegistro(int numCuenta, string dato)
{
	int i = 0;
	int id = 0;
	string texto2 = "salir";
	string idString;
	idString = "";
	while (i < dato.length() && dato.at(i) != ',') {
		idString += dato.at(i);
		i++;
	}
	id = atoi(idString.c_str());
	if (id == numCuenta) {
		return dato;
	}
	return texto2;
}

