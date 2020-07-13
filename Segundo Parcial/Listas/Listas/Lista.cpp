#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include "Lista.h"
#include "Nodo.h"
void Lista::InsertarInicio(int numero)
{
	if (vacio()) {
		siguiente = new Nodo(numero, NULL);
	}
	else {
		Nodo* aux = new Nodo();
		aux->setNumero(numero);
		aux->setSiguiente(siguiente);
		siguiente = aux;
	}
}
void Lista::InsertarFinal(int numero)
{
	if (vacio()) {
		siguiente = new Nodo(numero, NULL);
	}
	else {
		Nodo* aux1 = new Nodo();
		aux1 = siguiente;
		Nodo* aux2 = new Nodo();
		while ((aux1) != NULL) {
			aux2 = aux1;
			aux1 = aux1->getSiguiente();
		}
		Nodo* aux3 = new Nodo(numero, NULL);
		aux2->setSiguiente(aux3);

	}
}
void Lista::Imprimir(void)
{
	Nodo* aux = new Nodo();
	aux = siguiente;
	int cont = 1;
	//int salto = 10;
	if (!vacio()) {

		while (aux != NULL) {
			std::cout << aux->getNumero() << "\n";
			aux = aux->getSiguiente();
			cont++;
		}
	}
	else {
		std::cout << "Lista vacia" << std::endl;
	}
}
int Lista::vacio(void)
{
	if (siguiente == NULL)
		return true;
	else
		return false;
}
