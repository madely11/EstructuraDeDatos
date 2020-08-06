#include "Nodo.h"
template<class T>
Nodo<T>::Nodo() {
	this->dato = 0;
	this->siguiente = NULL;
	this->anterior = NULL;
}
template<class T>
Nodo<T>::Nodo(T _dato, Nodo<T>* _anterior, Nodo<T>* _siguiente) {
	this->dato = _dato;
	this->siguiente = _siguiente;
	this->anterior = _anterior;
}
template<class T>
void Nodo<T>::setAnterior(Nodo<T>* _anterior) {
	this->anterior = _anterior;

}
template<class T>
void Nodo<T>::setSiguiente(Nodo<T>* _siguiente) {
	this->siguiente = _siguiente;
}
template<class T>
Nodo<T>* Nodo<T>::getAnterior() {
	return this->anterior;
}
template<class T>
Nodo<T>* Nodo<T>::getSiguiente() {
	return this->siguiente;
}
template<class T>
T Nodo<T>::getValor() {
	return this->dato;
}
