#include "Fecha.h"

Fecha::Fecha()
{
}

Fecha::Fecha(int dDia, int dMes, int dAnio)
{
	dia = dDia;
	mes = dMes;
	anio = dAnio;
}

void Fecha::setDia(int dia)
{
}

void Fecha::setMes(int mes)
{
}

void Fecha::setAnio(int anio)
{
}

int Fecha::getDia()
{
	return dia;
}

int Fecha::getMes()
{
	return mes;
}

int Fecha::getAnio()
{
	return anio;
}

string Fecha::toString()
{
	return to_string(getDia()) + "/" + to_string(getMes()) + "/" + to_string(getAnio());
}
