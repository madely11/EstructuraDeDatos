#pragma once
#include <iostream>
#include "Validacion.h"
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

#ifndef Ingreso_H
#define Ingreso_H

class Ingreso {

public:
	string leer(string, int);
	string leerString(string, int);
	bool leerFecha(string);
	char* ingresaNumericos(const char*);
};

#endif 
