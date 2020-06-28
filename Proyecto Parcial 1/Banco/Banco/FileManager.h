#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


class FileManager
{
private:
	string nombreArchivo;
	ifstream archivoLectura; //archivo de lectura
	ofstream archivoEscritura; //archivo de escritura

public:
	FileManager(string);
	bool crearLectura();
	bool crearEscritura();
	void agregarLinea(string);
	void cerrarLectura();
	void cerrarEscritura();
	int contarLineas();
	string buscarCuenta(int);
	void actualizar(int, string);
	string comparar(int, string);
	string compararRegistro(int, string);
	string buscarRegistro(int, int);
};



bool FileManager::crearEscritura()
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

FileManager::FileManager(string archivo)
{
	
	nombreArchivo = archivo;
	crearEscritura();
	cerrarEscritura();
}

bool FileManager::crearLectura()
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

void FileManager::cerrarLectura()
{
	archivoLectura.close();
}

void FileManager::cerrarEscritura()
{
	archivoEscritura.close();
}

void FileManager::agregarLinea(string linea)
{
	crearEscritura();
	archivoEscritura << linea << endl;
	cerrarEscritura();
}


inline int FileManager::contarLineas()
{
	int cuentaLinea=0;
	string texto;
	if (!crearLectura()) {
		cerrarLectura();
		return -1;
	}
	while (!archivoLectura.eof())
	{
		
		getline(archivoLectura, texto);
		cuentaLinea++;
		
	}
	cerrarLectura();
	return cuentaLinea;
}

string FileManager::buscarCuenta(int numCuenta)
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

inline void FileManager::actualizar(int numCuenta, string datoNuevo)
{
	ofstream archivoAux;
	string dato;

	archivoAux.open("cuentaAux.txt", ios::out | ios::app);
	if (!crearLectura()) {
		return;
	}

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

inline string FileManager::comparar(int numCuenta, string dato)
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

inline string FileManager::buscarRegistro(int numCuenta, int coincidencia)
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

inline string FileManager::compararRegistro(int numCuenta, string dato)
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


