#include<iostream>
using namespace std;
template<class T>
class Nodo {
public:
	Nodo();
	Nodo(T _dato, Nodo<T>* _anterior, Nodo<T>* _siguiente);
	Nodo<T>* getAnterior();
	Nodo<T>* getSiguiente();
	T getValor();
	void setAnterior(Nodo<T>*);
	void setSiguiente(Nodo<T>*);
private:
	T dato;
	Nodo<T>* anterior;
	Nodo<T>* siguiente;
};
