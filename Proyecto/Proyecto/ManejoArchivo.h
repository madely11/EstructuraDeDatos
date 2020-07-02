#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class ManejoArchivo
{
private:
	string nombreArchivo;
	ifstream archivoLectura; //archivo de lectura
	ofstream archivoEscritura; //archivo de escritura

public:
	ManejoArchivo(string);
	ManejoArchivo();
	bool crearLectura();
	bool crearEscritura();
	void agregarLinea(string);
	void cerrarLectura();
	void cerrarEscritura(); 
	int contarLineas();
	void actualizarRespaldo(string);
	string leerArchivo();
	string buscarRespaldo(string);
	string buscarCuenta(int);
	void actualizar(int, string);
	string comparar(int, string);
	string compararRegistro(int, string);
	string compararRegistro(string, string);
	string buscarRegistro(int, int);
	string buscarRegistro(string, int, int);
};

