#include "Nodo.h"


Nodo::Nodo() {
	this->siguiente = NULL;
	this->anterior = NULL;
}

Nodo::Nodo(Cliente _dato, Nodo* _anterior, Nodo* _siguiente) {
	this->dato = _dato;
	this->siguiente = _siguiente;
	this->anterior = _anterior;
}

Nodo::Nodo(Cuenta _dato, Nodo* _anterior, Nodo* _siguiente)
{
	this->datoCuenta = _dato;
	this->siguiente = _siguiente;
	this->anterior = _anterior;
}

Nodo::Nodo(Transacciones _dato, Nodo* _anterior, Nodo* _siguiente)
{
	this->datoTrans = _dato;
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

Cliente Nodo::getValor() {
	return this->dato;
}

Cuenta Nodo::getValorCuenta()
{
	return this->datoCuenta;
}

Transacciones Nodo::getValorTrans()
{
	return this->datoTrans;
}
