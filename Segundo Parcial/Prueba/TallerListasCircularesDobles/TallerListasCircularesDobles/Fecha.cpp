#include "Fecha.h"

bool Fecha::validarFecha()
{
	try {

		if ((getDia() < 0 || getDia() > 31)) {
			throw 1;
		}

		if ((getMes()< 0 || getMes() > 12)) {
			throw 1;
		}

		if ((getAnio() < 1920 || getAnio() > 2020)) {
			throw 1;
		}
	}
	catch (int e) {
		return false;
	}
	return true;
}

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
	this->dia = dia;
}

void Fecha::setMes(int mes)
{
	this->mes = mes;
}

void Fecha::setAnio(int anio)
{
	this->anio = anio;
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

int Fecha::obtenerAnio()
{
	struct tm pt1;
	__time64_t tSac = time(NULL);
	errno_t err;
	_time64(&tSac);
	err = _localtime64_s(&pt1, &tSac);
	anio = pt1.tm_year + 1900;
	return anio;
}

string Fecha::toString()
{
	return to_string(getDia()) + "/" + to_string(getMes()) + "/" + to_string(getAnio());
}
