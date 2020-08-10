
/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE PARA DEFINIR FUNCIONES DE NODO                            *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/06/20									  *
* FECHA DE MODIFICACIÓN: 02/07/20								  *
******************************************************************/


#include "Nodo.h"

/**
	@brief Constructor Nodo
	@param void
	@returns void
*/
Nodo::Nodo() {
	this->siguiente = NULL;
	this->anterior = NULL;
}
/**
	@brief Constructor Nodo Cliente
	@param Cliente, Nodo
	@returns void
*/

Nodo::Nodo(Cliente _dato, Nodo* _anterior, Nodo* _siguiente) {
	this->dato = _dato;
	this->siguiente = _siguiente;
	this->anterior = _anterior;
}
/**
	@brief Constructor Nodo Cuenta
	@param Cuenta , Nodo
	@returns void
*/
Nodo::Nodo(Cuenta _dato, Nodo* _anterior, Nodo* _siguiente)
{
	this->datoCuenta = _dato;
	this->siguiente = _siguiente;
	this->anterior = _anterior;
}
/**
	@brief Constructor Nodo Transacciones
	@param Transacciones, Nodo
	@returns void
*/
Nodo::Nodo(Transacciones _dato, Nodo* _anterior, Nodo* _siguiente)
{
	this->datoTrans = _dato;
	this->siguiente = _siguiente;
	this->anterior = _anterior;
}
/**
	@brief Funcion set Nodo anterior
	@param Nodo
	@returns void
*/
void Nodo::setAnterior(Nodo* _anterior) {
	this->anterior = _anterior;

}
/**
	@brief Funcion set Nodo siguiente
	@param Nodo
	@returns void
*/
void Nodo::setSiguiente(Nodo* _siguiente) {
	this->siguiente = _siguiente;
}
/**
	@brief Funcion get Nodo anterior
	@param void
	@returns Nodo
*/
Nodo* Nodo::getAnterior() {
	return this->anterior;
}
/**
	@brief Funcion get Nodo siguiente
	@param void
	@returns Nodo
*/
Nodo* Nodo::getSiguiente() {
	return this->siguiente;
}
/**
	@brief Funcion get Valor
	@param void
	@returns Cliente
*/
Cliente Nodo::getValor() {
	return this->dato;
}

/**
	@brief Funcion get ValorCuenta
	@param void
	@returns Cuenta
*/
Cuenta Nodo::getValorCuenta()
{
	return this->datoCuenta;
}

/**
	@brief Funcion get Transacciones
	@param void
	@returns Transacciones
*/
Transacciones Nodo::getValorTrans()
{
	return this->datoTrans;
}
