#pragma once
#include <string.h>
#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;

#ifndef Validacion_H
#define Validacion_H

class Validacion {
public:
	bool cedula(string);
	bool validar(string, int);
	bool validarString(string, int);
	bool validarFecha(string);
};
#endif 
