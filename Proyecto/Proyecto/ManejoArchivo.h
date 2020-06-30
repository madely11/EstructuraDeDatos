#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <iostream>

using namespace std;

class ManejoArchivo
{
private:
	string nombreArchivo;
	ifstream archivoLectura; //archivo de lectura
	ofstream archivoEscritura; //archivo de escritura

public:
	ManejoArchivo(string);
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

