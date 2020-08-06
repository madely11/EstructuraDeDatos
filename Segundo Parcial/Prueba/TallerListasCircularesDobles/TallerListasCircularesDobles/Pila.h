#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pila {
	class Nodo {
	public:
		Nodo* siguiente;
		string dato;
		Nodo(string x) {
			dato = x;
			siguiente = NULL;
		}
	};
public:
	Nodo* cima;
	Pila() {
		cima = NULL;
	}
	void insertar(string dato);
	void imprimir();
	//string quitar();
	string separarDato(string);
	string encriptar(string);
	//string cimaPila();
	int pilaVacia();
	//void limpiarPila();
	/*~Pila() {
		limpiarPila();
	}*/

};

