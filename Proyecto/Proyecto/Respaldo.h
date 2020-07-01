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
	string nombreRespaldo();
	void crearRespaldo();
	void obtenerNombreRespaldo(int);
	void ingresarRespaldo(int);
	void guardarRespaldo(string, string);
};

