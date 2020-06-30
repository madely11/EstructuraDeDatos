#pragma once
#include <iostream>
#include "Validacion.h"
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

class Ingreso {

public:
	string leer(string, int);
	string leerString(string, int);
	char* ingresaNumericos(const char*);
};