 #include "Validacion.h"

bool Validacion::cedula(string cedula) {
	char* aux;
	int aux_int;
	int aux_int2;
	int verificador;
	int suma = 0;

	if (cedula.length() != 10) {
		return false;
	}

	aux = (char*)malloc(sizeof(char) * 2);
	*(aux + 0) = cedula.at(0);
	*(aux + 1) = cedula.at(1);
	aux_int = atoi(aux);

	if (aux_int > 25) {
		return false;
	}

	aux = (char*)realloc(aux, sizeof(char) * 1);
	*(aux + 0) = cedula.at(2);
	aux_int = atoi(aux);
	if (aux_int > 5) {
		return false;
	}
	for (int i = 0; i < 9; i++)
	{
		*(aux + 0) = cedula.at(i);
		aux_int = atoi(aux);
		if (i % 2 == 0) {
			aux_int *= 2;
		}
		if (aux_int > 9) {
			aux_int -= 9;
		}
		suma += aux_int;
	}

	aux_int2 = suma / 10;
	aux_int2 = (aux_int2 + 1) * 10;
	verificador = aux_int2 - suma;

	*(aux + 0) = cedula.at(9);
	aux_int = atoi(aux);
	if (aux_int != verificador) {
		return false;
	}

	return true;
}