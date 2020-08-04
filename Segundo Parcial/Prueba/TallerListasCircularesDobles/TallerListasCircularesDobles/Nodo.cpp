#include "Nodo.h"


Nodo::Nodo() {

	this->siguiente = NULL;
	this->anterior = NULL;
}

Nodo::Nodo(Persona _dato, Nodo* _anterior, Nodo* _siguiente) {
	this->dato = _dato;
	this->siguiente = _siguiente;
	this->anterior = _anterior;
}

void Nodo::setAnterior(Nodo* _anterior) {
	this->anterior = _anterior;

}

void Nodo::setSiguiente(Nodo* _siguiente) {
	this->siguiente = _siguiente;
}

Nodo* Nodo::getAnterior() {
	return this->anterior;
}

Nodo* Nodo::getSiguiente() {
	return this->siguiente;
}

Persona Nodo::getValor() {
	return this->dato;
}