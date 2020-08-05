#pragma once

#include <iostream>
#include "Persona.h"
#include "Ingreso.h"
#include "Validacion.h"
using namespace std;

class IngresoPersona
{
public:
	void imprimirDatos();
	void ingresoDatos();
	Persona persona;
	Ingreso ingreso;
	Validacion validar;
};

