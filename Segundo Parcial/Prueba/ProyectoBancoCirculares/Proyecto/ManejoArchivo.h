#pragma once
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <cstdio>
using namespace std;

class ManejoArchivo
{
public:
	string nombreArchivo;
	ifstream archivoLectura; //archivo de lectura
	ofstream archivoEscritura; //archivo de escritura

public:
	ManejoArchivo(string);
	ManejoArchivo();
	void setNombre(string);
	bool crearLectura();
	bool crearEscritura();
	void agregarLinea(string);
	void cerrarLectura();
	void cerrarEscritura(); 
	int contarLineas();
	char** leerArchivo(string, int);
	void actualizarRespaldo(string);
	string leerArchivo();
	string buscarRespaldo(string);
	string buscarCuenta(int);
	void actualizar(int, string);
	string comparar(int, string);
	string compararRegistro(int, string);
	string compararRegistroCartola(int, string);
	string compararRegistro(string, string);
	string buscarRegistro(int, int);
	string buscarRegistroCartola(int);
	string buscarRegistro(string, int, int);
	void actualizarTransacciones(string);
	string cambiarDato(string);
};

