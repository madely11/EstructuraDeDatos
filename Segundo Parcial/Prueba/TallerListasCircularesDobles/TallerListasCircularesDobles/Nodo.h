#include<iostream>
#include"Persona.h"
using namespace std;

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

