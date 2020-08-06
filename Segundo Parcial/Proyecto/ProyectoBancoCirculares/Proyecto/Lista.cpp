#include "Lista.h"

bool Lista::listaVacia()
{
	return lista == NULL;
}
Lista::Lista()
{
	lista = NULL;
	listaFinal = NULL;
}

bool Lista::verificarCedula(string cedula)
{
	Nodo* aux = lista;
	if (listaVacia())
		return false;

	if ((listaFinal->getValor().getId())._Equal(cedula))
		return true;

	while (aux != listaFinal) {
		if ((aux->getValor().getId())._Equal(cedula))
			return true;
		aux = aux->getSiguiente();
	}
	return false;
}

void Lista::insertarInicio(Cliente dato)
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

void Lista::insertarFinal(Cliente dato) {
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

void Lista::insertarFinal(Cuenta dato)
{
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

void Lista::insertarFinal(Transacciones dato)
{
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

bool Lista::verificarCuenta(int numC)
{
	Nodo* aux = lista;
	if (listaVacia())
		return false;

	if ((listaFinal->getValorCuenta().getNumc() == numC))
		return true;

	while (aux != listaFinal) {
		if ((aux->getValorCuenta().getNumc() == numC))
			return true;
		aux = aux->getSiguiente();
	}
	return false;
}

bool Lista::verificarTransaccion(string numC)
{
	Nodo* aux = lista;
	if (listaVacia())
		return false;

	if ((listaFinal->getValorTrans().getDato()._Equal(numC)))
		return true;

	while (aux != listaFinal) {
		if ((aux->getValorTrans().getDato()._Equal(numC)))
			return true;
		aux = aux->getSiguiente();
	}
	return false;
}

void Lista::insertarEntre(Cliente dato, int pos)
{
	int cont = 1;
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

		if (cont == pos) {
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
		while (!aux->getValor().getId()._Equal(cedula) && aux != listaFinal) {
			aux = aux->getSiguiente();
		}
		if (aux->getValor().getId()._Equal(cedula)) {
			if (aux == lista) {
				aux->getAnterior()->setSiguiente(aux->getSiguiente());
				aux->getSiguiente()->setAnterior(aux->getAnterior());
				lista = aux->getSiguiente();
				if (aux == aux->getSiguiente()) {
					lista = NULL;
				}
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


void Lista::llenarLista(string archivo)
{
	ManejoArchivo archivoG(archivo);
	archivoG.cerrarLectura();
	int contLineas = 0;
	int numLineas = archivoG.contarLineas();
	cout << "numero lineas archivo " << numLineas << endl;
	if (numLineas != 0) {
		string linea;
		char** lineaAux=NULL;
		Cliente auxCliente;
		archivoG.crearLectura();

		while (!archivoG.archivoLectura.eof() && contLineas != numLineas)
		{
			getline(archivoG.archivoLectura, linea);
			lineaAux = archivoG.leerArchivo(linea,0);
			auxCliente.setNombre(*(lineaAux + 0));
			auxCliente.setId(*(lineaAux + 1));
			auxCliente.setEmail(*(lineaAux + 2));
			auxCliente.setDireccion(*(lineaAux + 3));
			if (!verificarCedula(auxCliente.getId())) {
				insertarFinal(auxCliente);
				cout << endl << "\n\t\t\t\t\Cuenta creada exitosamente!" << endl;
				cout << endl;
			}
				
			contLineas += 1;
		}
		archivoG.cerrarLectura();
		free(lineaAux);
	}	
}

void Lista::llenarCuenta(string archivo) {
	ManejoArchivo archivoG(archivo);
	archivoG.cerrarLectura();
	int contLineas = 0;
	int numLineas = archivoG.contarLineas();
	cout << "numero lineas archivo " << numLineas << endl;
	if (numLineas != 0) {
		string linea;
		char** lineaAux = NULL;
		Cuenta auxCuenta;
		archivoG.crearLectura();

		while (!archivoG.archivoLectura.eof() && contLineas != numLineas)
		{
			getline(archivoG.archivoLectura, linea);
			lineaAux = archivoG.leerArchivo(linea,0);
			auxCuenta.setId(*(lineaAux + 0));
			auxCuenta.setNumc(atoi(*(lineaAux + 1)));
			auxCuenta.setMonto(atoi(*(lineaAux + 2)));
			auxCuenta.setTipo((atoi(*(lineaAux + 3))));
			contLineas += 1;
			if(auxCuenta.getNumc()!=0 )
				insertarFinal(auxCuenta);
		}
		archivoG.cerrarLectura();
		free(lineaAux);
	}
}

void Lista::llenarTrans(string archivo)
{
	ManejoArchivo archivoG(archivo);
	archivoG.cerrarLectura();
	int contLineas = 0;
	int numLineas = archivoG.contarLineas();
	cout << "numero lineas archivo " << numLineas << endl;
	if (numLineas != 0) {
		string linea;
		char** lineaAux = NULL;
		Transacciones auxTrans;
		archivoG.crearLectura();

		while (!archivoG.archivoLectura.eof() && contLineas != numLineas)
		{
			getline(archivoG.archivoLectura, linea);
			lineaAux = archivoG.leerArchivo(linea, 1);
			auxTrans.setDato(*(lineaAux + 0)); //numero de cuenta
			auxTrans.setTipoTrans(*(lineaAux + 1)); // fecha
			contLineas += 1;
		    insertarFinal(auxTrans);
		}
		archivoG.cerrarLectura();
		free(lineaAux);
	}
}

void Lista::mostrarTrans()
{
	if (listaVacia()) {
		cout << "La lista esta vacia" << endl;
	}
	else {
		Nodo* aux = lista;
		while (aux != listaFinal) {
			cout << aux->getValorTrans().getDato() << endl;
			cout << aux->getValorTrans().getTipoTrans() << endl;
			aux = aux->getSiguiente();
			cout << endl;
		}
		cout << endl;
		cout << aux->getValorTrans().getDato() << endl;
		cout << aux->getValorTrans().getTipoTrans() << endl;
	}
}

void Lista::mostrarCuenta()
{
	if (listaVacia()) {
		cout << "La lista esta vacia" << endl;
	}
	else {
		Nodo* aux = lista;
		while (aux != listaFinal) {
			cout << aux->getValorCuenta().getNumc() << endl;
			cout << aux->getValorCuenta().getId() << endl;
			cout << aux->getValorCuenta().getMonto() << endl;
			cout << aux->getValorCuenta().tipo->getId() << endl;
			aux = aux->getSiguiente();
			cout << endl;
		}
		cout << endl;
		cout << aux->getValorCuenta().getNumc() << endl;
		cout << aux->getValorCuenta().getId() << endl;
		cout << aux->getValorCuenta().getMonto() << endl;
		cout << aux->getValorCuenta().tipo->getId() << endl;
	}
}

void Lista::mostrar()
{
	if (listaVacia()) {
		cout << "La lista esta vacia" << endl;
	}
	else {

		Nodo* aux = lista;
		while (aux != listaFinal) {
			cout << aux->getValor().getNombre() << " ";
			cout << aux->getValor().getId() << endl;
			cout << aux->getValor().getDireccion() << endl;
			cout << aux->getValor().getEmail() << endl;
			aux = aux->getSiguiente();
			cout << endl;
			cout << endl;
		}

		cout << aux->getValor().getNombre() << " ";
		cout << aux->getValor().getId() << endl;
		cout << aux->getValor().getDireccion() << endl;
		cout << aux->getValor().getEmail() << endl;
	}
}