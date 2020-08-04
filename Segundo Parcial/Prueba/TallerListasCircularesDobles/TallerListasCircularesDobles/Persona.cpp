#include "Persona.h"


Persona::Persona(int edad, string cedula, string nombre, string apellido, string correo, Fecha fecha)
{
	this->edad = edad;
	this->nombre = nombre;
	this->apellido = apellido;
	this->correo = correo;
	this->fecha = fecha;
}

Persona::Persona()
{
}

void Persona::setFecha(Fecha fecha)
{
}

void Persona::setEdad(int edad)
{
}

void Persona::setCedula(string cedula)
{
}

void Persona::setNombre(string nombre)
{
}

void Persona::setApellido(string apellido)
{
}

void Persona::setCorreo(string correo)
{
}

int Persona::getEdad()
{
	return edad;
}

Fecha Persona::getFecha()
{
	return fecha;
}

string Persona::getCedula()
{
	return cedula;
}

string Persona::getNombre()
{
	return nombre;
}

string Persona::getApellido()
{
	return apellido;
}

string Persona::getCorreo()
{
	return correo;
}

string Persona::toString()
{
	return nombre + apellido + to_string(edad) + cedula + correo;
}
