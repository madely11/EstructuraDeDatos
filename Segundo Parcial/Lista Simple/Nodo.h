#include<iostream>
using namespace std;
template<class T>
class Nodo{
	public:
		Nodo();
		Nodo(T _dato, Nodo<T>* _siguiente);
		Nodo<T>* getSiguiente();
		T getValor();
		void setSiguiente(Nodo<T>* _siguiente);
	private:
	T dato;
	Nodo<T>* siguiente;	
	};
template<class T>
Nodo<T>::Nodo(){
	this->dato=0;
	this->siguiente=NULL;
}
template<class T>
Nodo<T>::Nodo(T _dato, Nodo<T>* _siguiente){
	this->dato=_dato;
	this->siguiente=_siguiente;
}

template<class T>
void Nodo<T>::setSiguiente(Nodo<T>* _siguiente){
	this->siguiente=_siguiente;
}
template<class T>
Nodo<T>* Nodo<T>::getSiguiente(){
	return this->siguiente;
}
template<class T>
T Nodo<T>::getValor(){
	return this->dato;
}
