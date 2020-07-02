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
	crearLectura();
	int cuentaLinea = 0;
	string texto;
	//if (!crearLectura()) {
	//	//cerrarLectura();
	//	return -1;
	//}
	while (!archivoLectura.eof())
	{
		getline(archivoLectura, texto);
		cuentaLinea++;
	}
	cout << " Lineas: " << cuentaLinea << endl;
	cerrarLectura();
	return cuentaLinea;
}

string ManejoArchivo::leerArchivo() {
	string texto ;
	string linea;
	int i = 0;

	crearLectura();

	/*if (!crearLectura()) {
		texto = "salir";
		return texto;
	}*/
	while (!archivoLectura.eof())
	{
		getline(archivoLectura, linea);
		while (i < linea.length() && linea.at(i) != ',') {
			texto += linea.at(i);
			i++;
		}
		i = 0;
		texto += "\n\t";
	}
	cerrarLectura();
	return texto;
}

string ManejoArchivo::buscarRespaldo(string ingresado) {
	crearLectura();
	string linea;
	string dato;
	string texto = "salir";
	int i;
	while (!archivoLectura.eof())
	{
		i = 0;
		dato = "";
		getline(archivoLectura, linea);
		while (i < linea.length() && linea.at(i) != ',') {
			dato += linea.at(i);
			i++;
		}
		if (dato._Equal(ingresado)) {
			dato += ",";
			i++;
			while (i < linea.length() && linea.at(i) != ',') {
				dato += linea.at(i);
				i++;
			}
			dato += ",";
			i++;
			while (i < linea.length() && linea.at(i) != ',') {
				dato += linea.at(i);
				i++;
			}
			dato += ",";
			i++;
			while (i < linea.length() && linea.at(i) != ',') {
				dato += linea.at(i);
				i++;
			}
			cerrarLectura();
			return dato;
		}
	}
	cerrarLectura();
	return texto;
}

void ManejoArchivo::actualizarRespaldo(string linea) {
	crearLectura();
	string rCuenta, rCliente, rTransacciones;
	int i=0;

	while (i < linea.length() && linea.at(i) != ',') {
		i++;
	}
	i++;
	while (i < linea.length() && linea.at(i) != ',') {
		rCliente += linea.at(i);
		i++;
	}
	i++;
	while (i < linea.length() && linea.at(i) != ',') {
		rCuenta += linea.at(i);
		i++;
	}
	i++;
	while (i < linea.length() && linea.at(i) != ',') {
		rTransacciones += linea.at(i);
		i++;
	}

	remove("cliente.txt");
	rename(rCliente.c_str(), "cliente.txt");

	remove("cuenta.txt");
	rename(rCuenta.c_str(), "cuenta.txt");

	remove("Transacciones.txt");
	rename(rTransacciones.c_str(), "Transacciones.txt");
	
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
	crearLectura();
	ofstream archivoAux;
	string dato;

	archivoAux.open("cuentaAux.txt", ios::out | ios::app);


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
	string idFecha;

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

	if (f._Equal(idFecha)) {
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

