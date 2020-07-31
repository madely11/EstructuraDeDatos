#include<iostream>
using namespace std;
template<class T>
class Nodo{
	public:
		Nodo();
		Nodo(T _dato,Nodo<T>* _anterior, Nodo<T>* _siguiente);
		Nodo<T>* getAnterior();
		Nodo<T>* getSiguiente();
		T getValor();
		void setAnterior(Nodo<T>* );
		void setSiguiente(Nodo<T>* );
	private:
	T dato;
	Nodo<T>* anterior;
	Nodo<T>* siguiente;	
	};
template<class T>
Nodo<T>::Nodo(){
	this->dato=0;
	this->siguiente=NULL;
	this->anterior=NULL;
}
template<class T>
Nodo<T>::Nodo(T _dato,Nodo<T>* _anterior, Nodo<T>* _siguiente){
	this->dato=_dato;
	this->siguiente=_siguiente;
	this->anterior=_anterior;
}
template<class T>
void Nodo<T>::setAnterior(Nodo<T>* _anterior){
    this->anterior=_anterior;	
    
}
template<class T>
void Nodo<T>::setSiguiente(Nodo<T>* _siguiente){
	this->siguiente=_siguiente;
}
template<class T>
Nodo<T>* Nodo<T>::getAnterior(){
	return this->anterior;
}
template<class T>
Nodo<T>* Nodo<T>::getSiguiente(){
	return this->siguiente;
}
template<class T>
T Nodo<T>::getValor(){
	return this->dato;
}
