#pragma once
#include<iostream>
#include"Persona.h"
using namespace std;
#ifndef Nodo_H
#define Nodo_H
class Nodo {
public:
	Nodo();
	Nodo(Persona _dato, Nodo* _anterior, Nodo* _siguiente);
	Nodo* getAnterior();
	Nodo* getSiguiente();
	Persona getValor();
	void setAnterior(Nodo*);
	void setSiguiente(Nodo*);
private:
	Persona dato;
	Nodo* anterior;
	Nodo* siguiente;
};
#endif 
