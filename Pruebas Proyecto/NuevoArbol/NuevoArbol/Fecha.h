#pragma once
#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;

class Fecha
{
public:
	void setFecha(string);
	void setHora(string);
	string fechaUnida();
	string horaUnida();
	string getFecha();
	string getHora();
	string obtenerHora();
	string obtenerFecha();

private:
	string hora;
	string fecha;
};

