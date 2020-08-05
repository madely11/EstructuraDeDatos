#include "Lista.h"

bool Lista::listaVacia()
{
	return lista==NULL;
}
Lista::Lista()
{
}

string Lista::buscarEmail(string iniciales)
{
	if (listaVacia()) {
		return iniciales + "@espe.edu.ec";
	}
	else {
		int cont = 0;
		Nodo* aux = lista;
		string auxIni;
		auxIni = listaFinal->getValor().getNombre().at(0) + listaFinal->getValor().getApellido();
		if (auxIni._Equal(iniciales))
			cont += 1;

		while (aux != listaFinal)
		{
			auxIni = aux->getValor().getNombre().at(0) + aux->getValor().getApellido();
			if (auxIni._Equal(iniciales))
				cont += 1;
			aux = aux->getSiguiente();
		}

		if (cont != 0) {
			//cont -= 1;
			return iniciales + to_string(cont) + "@espe.edu.ec";
		}
		else {
			return iniciales + "@espe.edu.ec";
		}
	}
}

bool Lista::verificarCedula(string cedula)
{
	Nodo* aux = lista;
	if (listaVacia())
		return false;

	if ((listaFinal->getValor().getCedula())._Equal(cedula))
		return true;

	while (aux != listaFinal) {
		if ((aux->getValor().getCedula())._Equal(cedula))
			return true;
		aux = aux->getSiguiente();
	}	
	return false;
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
	int cont=1;
	if (listaVacia()) {
		cout << "La lista esta vacia" << endl;
		exit(1);
	}
	if (pos == 1) {
		insertarInicio(dato);
	}
	else {
		Nodo* nuevo = new Nodo(dato, NULL, NULL);
		Nodo* aux = lista;
		Nodo* aux2;

		while (aux != listaFinal && cont != pos) {
			cont += 1;
			aux = aux->getSiguiente();
		}

		if (cont==pos) {
			aux2 = aux->getAnterior();
			nuevo->setAnterior(aux2);
			aux2->setSiguiente(nuevo);
			nuevo->setSiguiente(aux);
			aux->setAnterior(nuevo);
		}
		else {
			cout << "No existe esa posicion" << endl;
		}
	}
	
}


void Lista::borrar(string cedula)
{
	if (listaVacia()) {
		cout << "La lista esta vacia" << endl;
	}
	else {
		Nodo* aux = lista;
		while (!aux->getValor().getCedula()._Equal(cedula) && aux != listaFinal) {
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
}

void Lista::mostrar()
{
	Nodo* aux = lista;
	while (aux != listaFinal) {
		cout << aux->getValor().getNombre() << " ";
		cout << aux->getValor().getApellido() << endl;
		cout << aux->getValor().getCedula() << endl;
		cout << aux->getValor().getEdad() << endl;
		cout << aux->getValor().getFecha().toString() << endl;
		cout << aux->getValor().getCorreo() << endl;
		aux = aux->getSiguiente();
		cout << endl;
		cout << endl;
	}
	cout << endl;
	cout << endl;
	cout << aux->getValor().getNombre() << endl;
	cout << aux->getValor().getApellido() << endl;
	cout << aux->getValor().getCedula() << endl;
	cout << aux->getValor().getEdad() << endl;
	cout << aux->getValor().getFecha().toString() << endl;
	cout << aux->getValor().getCorreo() << endl;
}

