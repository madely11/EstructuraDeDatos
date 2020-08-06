#pragma once
#include<iostream>
#include"Cliente.h"
#include"Cuenta.h"
using namespace std;

#ifndef Nodo_H
#define Nodo_H
class Nodo {
public:
	Nodo();
	Nodo(Cliente _dato, Nodo* _anterior, Nodo* _siguiente);
	Nodo(Cuenta _dato, Nodo* _anterior, Nodo* _siguiente);
	Nodo(Transacciones _dato, Nodo* _anterior, Nodo* _siguiente);
	Nodo* getAnterior();
	Nodo* getSiguiente();
	Cliente getValor();
	Cuenta getValorCuenta();
	Transacciones getValorTrans();
	void setAnterior(Nodo*);
	void setSiguiente(Nodo*);
private:
	Cliente dato;
	Cuenta datoCuenta;
	Transacciones datoTrans;
	Nodo* anterior;
	Nodo* siguiente;
};
#endif 
