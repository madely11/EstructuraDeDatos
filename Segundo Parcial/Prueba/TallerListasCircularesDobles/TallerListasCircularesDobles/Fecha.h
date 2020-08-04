#pragma once
#include <iostream>
#include <string>
using namespace std;

class Fecha
{
private:
	int mes;
	int dia;
	int anio;
public:
	Fecha();
	Fecha(int, int, int);
	void setDia(int dia);
	void setMes(int mes);
	void setAnio(int anio);
	int getDia();
	int getMes();
	int getAnio();
	string toString();
};

