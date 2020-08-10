
/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE PARA DEFINIR EL NODO DE LA LISTA                          *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/06/20									  *
* FECHA DE MODIFICACIÓN: 02/07/20								  *
******************************************************************/


#pragma once
#include<iostream>
#include"Cliente.h"
#include"Cuenta.h"
using namespace std;

#ifndef Nodo_H
#define Nodo_H


/**
	@file Nodo.h
	@brief Prototipo para la lista
	@author Madely Betancourt y Kevin Caicedo
	@date 7/2020
*/

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
