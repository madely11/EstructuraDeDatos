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
	@file Respaldo.cpp
	@brief Clase que contiene metodos para realizar un backup de los datos
	@author Madely Betancourt y Kevin Caicedo
	@date 6/2020
*/

#include "Respaldo.h"

/**
	@brief Constructor clase respaldo
	@param entrada nombre de archivos tipo string 
	@returns Respaldo
*/
Respaldo::Respaldo(string nombre) {
	nombreArchivo = nombre;
}
/**
	@brief Constructor clase respaldo
	@param void
	@returns Respaldo
*/
Respaldo::Respaldo() {
	nombreArchivo = "";
}
/**
	@brief Funcion para crear el nombre del respaldo
	@param void
	@returns nombre del Respaldo tipo string 
*/
string Respaldo::nombreRespaldo() {
	string respaldo = "";
	int i = 0;
	while (i < nombreArchivo.length() && nombreArchivo.at(i) != '.') {
		respaldo += nombreArchivo.at(i);
		i++;
	}
	respaldo += fecha.fechaUnida();
	respaldo +=fecha.horaUnida();
	respaldo += ".txt";
	return respaldo;
}
/**
	@brief Funcion para crear el archivo de respaldo
	@param void
	@returns nombre de respaldo string 
*/
string Respaldo::crearRespaldo() {
	string respaldo;
	int i = 0;
	respaldo = nombreRespaldo();

	ifstream a(nombreArchivo);
	ofstream aR(respaldo);

	filebuf* inbuf = a.rdbuf();
	filebuf* outbuf = aR.rdbuf();

	char c = inbuf->sbumpc();
	while (c != EOF)
	{
		outbuf->sputc(c);
		c = inbuf->sbumpc();
	}
	aR.close();
	a.close();
	return respaldo;
}
/**
	@brief Funcion para Guardar los nombres de los archivos de respaldo
	@param entrada nombre de archivos tipo string
	@returns Respaldo
*/
void Respaldo::guardarRespaldo(string linea) {
		ManejoArchivo archivo("respaldos.txt");
		archivo.agregarLinea(linea);
}
/**
	@brief Funcion para mostrar los nombres del archivo de pespaldo
	@param void
	@returns void
*/
void Respaldo::imprimirNombreRespaldo() {
	string mensaje;
	ManejoArchivo archivo("respaldos.txt");
	mensaje = archivo.leerArchivo();
	if (!mensaje._Equal("salir")) {
		cout << "\t" << mensaje << endl;
	}
}
/**
	@brief Funcion para ingresar el respaldo que se desa restaurar
	@param void
	@returns void
*/
void Respaldo::ingresarRespaldo() {
	string respaldoSeleccionado, texto;
	cout << "\n" << "Ingrese el respaldo que desea restaurar: " << endl << "\t";
	getline(cin, respaldoSeleccionado);
	while (respaldoSeleccionado.length() == 0) {
		cout << "\n" << "Reingrese el respaldo que desea restaurar: " << endl << "\t";
		getline(cin, respaldoSeleccionado);
	}
	ManejoArchivo archivo(nombreArchivo);
	texto = archivo.buscarRespaldo(respaldoSeleccionado);
	while (texto._Equal("salir"))
	{ 
		cout << "\n" << "Reingrese el respaldo que desea restaurar: " << endl<< "\t";
		getline(cin, respaldoSeleccionado);
		texto = archivo.buscarRespaldo(respaldoSeleccionado);
	}
	archivo.actualizarRespaldo(texto);

}