#pragma once
#include <iostream>
#include <string>
#include "Fecha.h"


using namespace std;

#ifndef Persona_H
#define Persona_H
class Persona
{
private:
	Fecha fecha;
	int edad;
	string cedula;
	string nombre;
	string apellido;
	string correo;

public:
	Persona(int, string, string, string, string, Fecha);
	Persona();
	void setFecha(Fecha fecha);
	void setEdad(int edad);
	void setCedula(string cedula);
	void setNombre(string nombre);
	void setApellido(string apellido);
	void setCorreo(string correo);
	int getEdad();
	Fecha getFecha();
	string getCedula();
	string getNombre();
	string getApellido();
	string getCorreo();
	string toString();
};
#endif 

