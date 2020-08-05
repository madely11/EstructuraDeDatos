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

void Fecha::diferencia()
{
	time_t now;
	struct tm newyear;
	double seconds;

	time(&now);  /* get current time; same as: now = time(NULL)  */

	__time64_t tSac = time(NULL);
	_time64(&tSac);
	newyear = *_localtime64_s(&now, &tSac);

	newyear.tm_hour = 9; newyear.tm_min = 26; newyear.tm_sec = 0;
	newyear.tm_mon = getMes();  newyear.tm_mday = getDia();

	seconds = difftime(now, mktime(&newyear));

	cout << "seconds since new year in the current timezone: "<<  seconds;
}

string Fecha::toString()
{
	return to_string(getDia()) + "/" + to_string(getMes()) + "/" + to_string(getAnio());
}
