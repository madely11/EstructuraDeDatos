#include "Lista.h"

bool Lista::listaVacia()
{
	return lista==NULL;
}
Lista::Lista()
{
}
void Lista::insertarInicio(Persona dato)
{
	Nodo* nuevo = new Nodo(dato, NULL, NULL);
	if (listaVacia()) {
		lista = nuevo;
		listaFinal = nuevo;
		lista->setSiguiente(lista);
		lista->setAnterior(listaFinal);
		listaFinal->setSiguiente(lista);
		listaFinal->setAnterior(lista);
	}
	Nodo* aux = lista;
	nuevo->setSiguiente(aux);
	nuevo->setAnterior(listaFinal);
	lista = nuevo;
}

void Lista::insertarEntre(Persona dato, int pos)
{
}

void Lista::insertarFinal(Persona dato)
{
}

void Lista::borrar(string cedula)
{
}

void Lista::mostrar()
{

}
