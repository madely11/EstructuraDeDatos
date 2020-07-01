#include "ManejoArchivo.h"

ManejoArchivo::ManejoArchivo(string archivo)
{
	nombreArchivo = archivo;
	crearEscritura();
	cerrarEscritura();
}

ManejoArchivo::ManejoArchivo()
{
	nombreArchivo = "";
}

bool ManejoArchivo::crearEscritura()
{
	archivoEscritura.open(nombreArchivo, ios::out | ios::app);

	if (archivoEscritura.fail()) {
		cout << "Imposible abrir el archivo: " << nombreArchivo << endl;
		return false;
	}
	else {
		return true;
	}
}

void ManejoArchivo::cerrarEscritura()
{
	archivoEscritura.flush();
	archivoEscritura.close();
}

bool ManejoArchivo::crearLectura()
{
	archivoLectura.open(nombreArchivo, ios::in);

	if (archivoLectura.fail()) {
		cout << "Imposible abrir el archivo: " << nombreArchivo << endl;
		return false;
	}
	else {
		return true;
	}
}

void ManejoArchivo::cerrarLectura()
{
	archivoLectura.close();
}

void ManejoArchivo::agregarLinea(string linea)
{
	crearEscritura();
	archivoEscritura << linea << endl;
	cerrarEscritura();
}

int ManejoArchivo::contarLineas()
{
	int cuentaLinea = 0;
	string texto;
	if (!crearLectura()) {
		//cerrarLectura();
		return -1;
	}
	while (!archivoLectura.eof())
	{
		getline(archivoLectura, texto);
		cuentaLinea++;
	}
	if (cuentaLinea > 1)
		cuentaLinea -= 1;
	cerrarLectura();
	return cuentaLinea;
}

string ManejoArchivo::leerArchivo(string archivo) {
	string texto, linea;
	nombreArchivo = archivo;

	if (!crearLectura()) {
		texto = "salir";
		return texto;
	}
	while (!archivoLectura.eof())
	{
		getline(archivoLectura, linea);
		texto += linea;
		texto += "\n";
	}
	cerrarLectura();
	return texto;
}

string ManejoArchivo::buscarRespaldo(string nombreRespaldo) {
	crearLectura();
	string linea;
	string texto = "salir";
	while (!archivoLectura.eof())
	{
		getline(archivoLectura, linea);
		if (linea._Equal(nombreRespaldo)) {
			texto = "";
			texto += linea;
			cerrarLectura();
			return texto;
		}
	}
	cerrarLectura();
	return texto;

}

void ManejoArchivo::actualizarRespaldo(string respaldo, int idRespaldo) {
	if (idRespaldo == 1) {
		remove("cliente.txt");
		rename(respaldo.c_str(), "cliente.txt");
	}

	if (idRespaldo == 2) {
		remove("cuenta.txt");
		rename(respaldo.c_str(), "cuenta.txt");
	}

	if (idRespaldo == 1) {
		remove("Transacciones.txt");
		rename(respaldo.c_str(), "Transacciones.txt");
	}
	
}

string ManejoArchivo::buscarCuenta(int numCuenta)
{
	crearLectura();
	string texto;
	string texto2 = "salir";
	string id_string;
	while (!archivoLectura.eof())
	{
		getline(archivoLectura, texto);
		texto = comparar(numCuenta, texto);
		if (!texto._Equal("salir")) {
			cerrarLectura();
			return texto;
		}
	}
	cerrarLectura();
	return texto2;
}

void ManejoArchivo::actualizar(int numCuenta, string datoNuevo)
{
	ofstream archivoAux;
	string dato;

	archivoAux.open("cuentaAux.txt", ios::out | ios::app);
	if (!crearLectura()) {
		return;
	}

	if (archivoAux.fail()) {
		cout << "No se abre el aux" << endl;
		return;
	}

	while (!archivoLectura.eof()) {

		getline(archivoLectura, dato);
		if (comparar(numCuenta, dato)._Equal("salir")) {
			archivoAux << dato << endl;
		}
		else {
			archivoAux << datoNuevo << endl;
		}
	}
	archivoAux.close();
	cerrarLectura();
	remove("cuenta.txt");
	rename("cuentaAux.txt", "cuenta.txt");

}

string ManejoArchivo::comparar(int numCuenta, string dato)
{
	int i = 0;
	int id = 0;
	string texto2 = "salir";
	string id_string;
	id_string = "";
	while (i < dato.length() && dato.at(i) != ',') {
		i++;
	}
	i++;
	while (i < dato.length() && dato.at(i) != ',') {
		id_string += dato.at(i);
		i++;
	}
	id = atoi(id_string.c_str());
	if (id == numCuenta) {
		return dato;
	}
	return texto2;
}

string ManejoArchivo::buscarRegistro(int numCuenta, int coincidencia)
{
	crearLectura();
	string texto;
	string texto2 = "salir";
	string idString;
	int i = 0;
	while (!archivoLectura.eof())
	{
		getline(archivoLectura, texto);
		texto = compararRegistro(numCuenta, texto);

		if (!texto._Equal("salir")) {
			i++;
		}
		if (!texto._Equal("salir") && i == coincidencia) {
			//i++;
			cerrarLectura();
			return texto;
		}
	}
	cerrarLectura();
	return texto2;
}

string ManejoArchivo::buscarRegistro(string f, int numCuenta, int coincidencia)
{
	crearLectura();
	string texto;
	string texto2 = "salir";
	string idString;
	int i = 0;
	while (!archivoLectura.eof())
	{
		getline(archivoLectura, texto);
		texto = compararRegistro(numCuenta, texto);
		texto = compararRegistro(f, texto);
		if (!texto._Equal("salir")) {
			i++;
		}
		if (!texto._Equal("salir") && i == coincidencia) {
			//i++;
			cerrarLectura();
			return texto;
		}
	}
	cerrarLectura();
	return texto2;
}

string ManejoArchivo::compararRegistro(string f, string dato)
{
	int i = 0;
	string texto2 = "salir";
	string idFecha = "";

	while (i < dato.length() && dato.at(i) != ',') {
		i++;
	}
	i++;
	while (i < dato.length() && dato.at(i) != ',') {
		i++;
	}
	i++;
	while (i < dato.length() && dato.at(i) != ',') {
		i++;
	}
	i++;
	while (i < dato.length() && dato.at(i) != ',') {
		i++;
	}
	i++;
	while (i < dato.length() && dato.at(i) != ',') {
		idFecha += dato.at(i);
		i++;
	}

	if (idFecha._Equal(f)) {
		return dato;
	}
	return texto2;
}

string ManejoArchivo::compararRegistro(int numCuenta, string dato)
{
	int i = 0;
	int id = 0;
	string texto2 = "salir";
	string idString;
	idString = "";
	while (i < dato.length() && dato.at(i) != ',') {
		idString += dato.at(i);
		i++;
	}
	id = atoi(idString.c_str());
	if (id == numCuenta) {
		return dato;
	}
	return texto2;
}

