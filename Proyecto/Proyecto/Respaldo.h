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
	Respaldo();
	string nombreRespaldo();
	string crearRespaldo();
	void imprimirNombreRespaldo();
	void ingresarRespaldo();
	void guardarRespaldo(string);
};

