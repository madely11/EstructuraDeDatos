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

void Lista::insertarFinal(Persona dato) {
	Nodo* nodo = new Nodo(dato, NULL, NULL);
	if (listaVacia()) {
		lista = nodo;
		listaFinal = nodo;
		lista->setSiguiente(lista);
		lista->setAnterior(listaFinal);
		listaFinal->setSiguiente(lista);

	}
	else {
		listaFinal->setSiguiente(nodo);
		Nodo* aux = listaFinal;
		nodo->setAnterior(aux);
		nodo->setSiguiente(lista);
		listaFinal = nodo;
		lista->setAnterior(listaFinal);
	}
}

void Lista::insertarEntre(Persona dato, int pos)
{
	if (listaVacia()) {
		cout << "La lista esta vacia";
		exit(1);
	}
	else {

	}
}


void Lista::borrar(string cedula)
{
	if (listaVacia()) {
		cout << "La lista esta vacia";
		exit(1);
	}
	Nodo* aux = lista;
	while (aux->getValor().getCedula()._Equal(cedula) && aux != listaFinal) {
		aux = aux->getSiguiente();
	}
	if (aux->getValor().getCedula()._Equal(cedula)) {
		if (aux == lista) {
			aux->getAnterior()->setSiguiente(aux->getSiguiente());
			aux->getSiguiente()->setAnterior(aux->getAnterior());
			lista = aux->getSiguiente();
			aux = NULL;
		}
		else if (aux == listaFinal) {
			aux->getAnterior()->setSiguiente(aux->getSiguiente());
			aux->getSiguiente()->setAnterior(aux->getAnterior());
			listaFinal = aux->getAnterior();
			aux = NULL;
		}
		else {
			aux->getAnterior()->setSiguiente(aux->getSiguiente());
			aux->getSiguiente()->setAnterior(aux->getAnterior());
			aux = NULL;
		}
	}
	else {
		cout << "La persona no se encuentra registrada" << endl;
	}
}

void Lista::mostrar()
{
	Nodo* aux = lista;
	while (aux != listaFinal) {
		cout << aux->getValor().getNombre() << endl;
		cout << aux->getValor().getApellido() << endl;
		cout << aux->getValor().getCedula() << endl;
		cout << aux->getValor().getEdad() << endl;
		cout << aux->getValor().getFecha().toString() << endl;
		aux = aux->getSiguiente();
		cout << endl;
		cout << endl;
	}
	cout << aux->getValor().getNombre() << endl;
	cout << aux->getValor().getApellido() << endl;
	cout << aux->getValor().getCedula() << endl;
	cout << aux->getValor().getEdad() << endl;
	cout << aux->getValor().getFecha().toString() << endl;
}
