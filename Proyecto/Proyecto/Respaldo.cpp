#include "Respaldo.h"


Respaldo::Respaldo(string nombre) {
	nombreArchivo = nombre;
}

Respaldo::Respaldo() {
	nombreArchivo = "";
}

string Respaldo::nombreRespaldo() {
	string respaldo = "";
	int i = 0;
	while (i < nombreArchivo.length() && nombreArchivo.at(i) != '.') {
		respaldo += nombreArchivo.at(i);
		i++;
	}
	respaldo += fecha.fechaUnida();
	respaldo +=fecha.horaUnida();
	respaldo += ".txt";
	return respaldo;
}

string Respaldo::crearRespaldo() {
	string respaldo;
	int i = 0;
	respaldo = nombreRespaldo();

	ifstream a(nombreArchivo);
	ofstream aR(respaldo);

	filebuf* inbuf = a.rdbuf();
	filebuf* outbuf = aR.rdbuf();

	char c = inbuf->sbumpc();
	while (c != EOF)
	{
		outbuf->sputc(c);
		c = inbuf->sbumpc();
	}
	aR.close();
	a.close();
	return respaldo;
}


void Respaldo::guardarRespaldo(string linea) {
		ManejoArchivo archivo("respaldos.txt");
		archivo.agregarLinea(linea);
}

void Respaldo::imprimirNombreRespaldo() {
	string mensaje;
	ManejoArchivo archivo("respaldos.txt");
	mensaje = archivo.leerArchivo();
	if (!mensaje._Equal("salir")) {
		cout << "\t" << mensaje << endl;
	}
}

void Respaldo::ingresarRespaldo() {
	string respaldoSeleccionado, texto;
	cout << "\n" << "Ingrese el respaldo que desea restaurar: " << endl << "\t";
	getline(cin, respaldoSeleccionado);
	while (respaldoSeleccionado.length() == 0) {
		cout << "\n" << "Reingrese el respaldo que desea restaurar: " << endl << "\t";
		getline(cin, respaldoSeleccionado);
	}
	ManejoArchivo archivo(nombreArchivo);
	texto = archivo.buscarRespaldo(respaldoSeleccionado);
	while (texto._Equal("salir"))
	{ 
		cout << "\n" << "Reingrese el respaldo que desea restaurar: " << endl<< "\t";
		getline(cin, respaldoSeleccionado);
		texto = archivo.buscarRespaldo(respaldoSeleccionado);
	}
	archivo.actualizarRespaldo(texto);

}