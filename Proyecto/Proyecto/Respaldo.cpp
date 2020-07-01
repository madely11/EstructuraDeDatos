#include "Respaldo.h"

Respaldo::Respaldo(string nombre) {
	nombreArchivo = nombre;
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

void Respaldo::crearRespaldo() {
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
	guardarRespaldo(nombreArchivo, respaldo);
}

void Respaldo::guardarRespaldo(string tipoArchivo, string respaldo) {
	if (tipoArchivo._Equal("cliente.txt")) {
		ManejoArchivo archivo("respaldoClientes.txt");
		archivo.agregarLinea(respaldo);
	}

	if (tipoArchivo._Equal("cuenta.txt")) {
		ManejoArchivo archivo("respaldoCuentas.txt");
		archivo.agregarLinea(respaldo);
	}

	if (tipoArchivo._Equal("transacciones.txt")) {
		ManejoArchivo archivo("respaldoTransacciones.txt");
		archivo.agregarLinea(respaldo);
	}
}

void Respaldo::obtenerNombreRespaldo(int idRespaldo) {
	string mensaje;
	ManejoArchivo archivo;
	mensaje = archivo.leerArchivo(nombreArchivo);
	if (mensaje._Equal("salir")) {
		cout << "\nEl archivo " + nombreArchivo + " no existe" << endl;
	}
	else {
		cout << "\n\t" << mensaje << endl;
		ingresarRespaldo(idRespaldo);
	}
}

void Respaldo::ingresarRespaldo(int idRespaldo) {
	string respaldoSeleccionado, texto;
	cout << "\n\t" << "Ingrese el respaldo que desea restaurar: " << endl;
	getline(cin, respaldoSeleccionado);
	ManejoArchivo archivo(nombreArchivo);
	texto = archivo.buscarRespaldo(respaldoSeleccionado);
	while (texto._Equal("salir"))
	{
		cout << "\n\t" << "Reingrese el respaldo que desea restaurar: " << endl;
		getline(cin, respaldoSeleccionado);
		texto = archivo.buscarRespaldo(respaldoSeleccionado);
	}

	archivo.actualizarRespaldo(texto, idRespaldo);

}