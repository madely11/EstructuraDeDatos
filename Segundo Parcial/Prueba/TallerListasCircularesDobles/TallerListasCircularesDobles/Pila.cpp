#include"Pila.h"
int Pila::pilaVacia() {
	return cima == NULL;
}

string Pila::separarDato(string dato) {
	string d;
	for (int i = 0; i < dato.length(); i++)
	{
		if (dato.at(i) == '@') {
			return d;
		}	
		d += dato.at(i);
	}
}

string Pila::encriptar(string dato)
{
	string encrip;
	int car;
	cout << "Ingrese el caracter con el que desea encriptar: ";
	cin >> car;
	for (int i = 0; i < dato.length(); i++)
	{
		encrip += dato.at(i) ^ car;
	}
	cout << "El dato encriptado es: " << encrip << endl;

	/*string desencrip;
	for (int i = 0; i < dato.length(); i++)
	{
		desencrip += encrip.at(i) ^ car;
	}

	cout << "El dato desencriptado es: " << desencrip << endl;*/
	return encrip;
}



void Pila::insertar(string dato) {
	dato = separarDato(dato);
	dato = encriptar(dato);
	dato += "@espe.edu.ec";
	Nodo* nuevo;
	nuevo = new Nodo(dato);
	nuevo->siguiente = cima;
	cima = nuevo;
}

/*string Pila::quitar() {
	string aux = cima->dato;
	if (pilaVacia())
		cout << "Pila Vacia no existe datos "<< endl;
	cima = cima->siguiente;
	return aux;
}*/

/*string Pila::cimaPila() {
	if (pilaVacia())
		cout << "Pila Vacia" << endl;
	return cima->dato;
}*/

void Pila::imprimir() {
	Nodo* valor;
	while (!pilaVacia()) {
		valor = cima;
		cout << cima->dato << endl;
		cima = cima->siguiente;
	}
}

/*void Pila::limpiarPila() {
	Nodo* valor;
	while (!pilaVacia()) {
		valor = cima;
		cima = cima->siguiente;
		delete valor;
	}
}*/

