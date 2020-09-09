/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE PARA FUNCIONES DE ARBOL                                   *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 04/07/20									  *
* FECHA DE MODIFICACIÓN: 09/07/20								  *
******************************************************************/

#include "Biselado.h"

void Biselado::rotacionDerecha(Nodo* nodo)
{
	Nodo* auxIzquierdo = nodo->izq;
	Nodo* auxDerecho = auxIzquierdo->der;
	Nodo* auxPadre = nodo->padre;
	if (auxPadre)
	{
		if (auxPadre->der == nodo) auxPadre->der = auxIzquierdo;
		else auxPadre->izq = auxIzquierdo;
	}
	if (auxDerecho)
		auxDerecho->padre = nodo;
	auxIzquierdo->padre = auxPadre;
	auxIzquierdo->der = nodo;

	nodo->padre = auxIzquierdo;
	nodo->izq = auxDerecho;
}

void Biselado::rotacionIzquierda(Nodo* nodo)
{
	Nodo* auxDerecho = nodo->der;
	Nodo* auxIzquierdo = auxDerecho->izq;
	Nodo* auxPadre = nodo->padre;
	if (auxPadre)
	{
		if (auxPadre->der == nodo) auxPadre->der = auxDerecho;
		else auxPadre->izq = auxDerecho;
	}
	if (auxIzquierdo)
		auxIzquierdo->padre = nodo;
	auxDerecho->padre = auxPadre;
	auxDerecho->izq = nodo;

	nodo->padre = auxDerecho;
	nodo->der = auxIzquierdo;
}

void Biselado::mostrar(Nodo* nodo, int cont)
{
	if (nodo == NULL) {
		return;
	}
	else {
		mostrar(nodo->der, cont + 1);
		for (int i = 0; i < cont; i++) {
			std::cout << "   ";
		}
		std::cout << nodo->valor << std::endl;
		mostrar(nodo->izq, cont + 1);
		return;
	}

}

void Biselado::biselado(Nodo* nodo)
{
	while (true)
	{
		Nodo* padre = nodo->padre;
		if (!padre) break;
		Nodo* abuelo = padre->padre;
		if (!abuelo)//Zig
		{
			if (padre->izq == nodo)
				rotacionDerecha(padre);
			else
				rotacionIzquierda(padre);
			break;
		}
		if (abuelo->izq == padre)
		{
			if (padre->izq == nodo)
			{//ZigZig
				rotacionDerecha(abuelo);
				rotacionDerecha(padre);
			}
			else
			{//ZigZag
				rotacionIzquierda(padre);
				rotacionDerecha(abuelo);
			}
		}
		else
		{
			if (padre->izq == nodo)
			{//ZigZag
				rotacionDerecha(padre);
				rotacionIzquierda(abuelo);
			}
			else
			{//ZigZig
				rotacionIzquierda(abuelo);
				rotacionIzquierda(padre);
			}
		}
	}
	raiz = nodo;
}

void Biselado::insertar(int valor)
{
	if (!raiz)
	{
		raiz = (Nodo*)malloc(sizeof(Nodo));
		raiz->izq = NULL;
		raiz->der = NULL;
		raiz->padre = NULL;
		raiz->valor = valor;
		return;
	}
	Nodo* nodo = raiz;
	while (true)
	{
		//if (nodo->valor == valor) break; // not multiset
		if (valor < (nodo->valor))
		{
			if (nodo->izq) nodo = nodo->izq;
			else
			{
				nodo->izq = (Nodo*)malloc(sizeof(Nodo));
				nodo->izq->padre = nodo;
				nodo->izq->der = NULL;
				nodo->izq->izq = NULL;
				nodo->izq->valor = valor;
				nodo = nodo->izq;
				break;
			}
		}
		else
		{
			if (nodo->der) nodo = nodo->der;
			else
			{
				nodo->der = (Nodo*)malloc(sizeof(Nodo));
				nodo->der->padre = nodo;
				nodo->der->der = NULL;
				nodo->der->izq = NULL;
				nodo->der->valor = valor;
				nodo = nodo->der;
				break;
			}
		}
	}
	biselado(nodo);
}

void Biselado::Inorder(Nodo* nodo)
{
	if (!nodo) return;
	Inorder(nodo->izq);
	printf("valor: %d ", nodo->valor);
	if (nodo->izq) printf("izq: %d ", nodo->izq->valor);
	if (nodo->der) printf("der: %d ", nodo->der->valor);
	puts("");
	Inorder(nodo->der);
}
bool Biselado::borrar(int dato)
{
	Nodo* nodo = buscar(dato);
	if (!nodo) return false;
	biselado(nodo); //check once more;
	Nodo* auxNodo = raiz->izq;
	if (!auxNodo) {

		raiz = raiz->der;
		raiz->padre = NULL;
	}
	else {
		if (auxNodo->der) {
			while (auxNodo->der) auxNodo = auxNodo->der;
			raiz->valor = auxNodo->valor;
			if (auxNodo->izq)
			{
				auxNodo->padre->der = auxNodo->izq;
				auxNodo->izq->padre = auxNodo->padre;
				//free(nodo);
			}
			else {
				auxNodo->padre->der = NULL;
				//free(nodo);
			}
		}
		else {
			auxNodo->padre = NULL;
			auxNodo->der=raiz->der;
			raiz->der->padre = auxNodo;
			raiz = auxNodo;
		}	
	}
	//free(nodo);
	return true;
}

Nodo* Biselado::buscar(int dato)
{
	if (!raiz) return NULL;
	Nodo* nodo = raiz;
	while (nodo)
	{
		if (nodo->valor == dato)
			break;
		if (dato < (nodo->valor))
		{
			if (nodo->izq)
				nodo = nodo->izq;
			else
				break;
		}
		else
		{
			if (nodo->der)
				nodo = nodo->der;
			else
				break;
		}
	}
	biselado(nodo);
	if (nodo->valor == dato) return nodo;
	else return NULL;
}

void Biselado::showTreeGraph(Nodo* tree, int x, int y, int cont) {
	if (tree) {
		dibujar.dibujarNodo(x, y, to_string(tree->valor));
		if (tree->izq) {
			if (cont == 1) {
				showTreeGraph(tree->izq, x / 2, y + 75, cont + 1); //450
			}
			else {
				if (x > 900) {
					showTreeGraph(tree->izq, x - x / 10, y + 75, cont); ///jh
				}
				else {
					showTreeGraph(tree->izq, x - x / 8, y + 75, cont);
				}
			}

		}
		if (tree->der) {
			if (cont == 1) {
				showTreeGraph(tree->der, x + x / 2, y + 75, cont + 1); //
			}
			else {
				if (x > 900) {
					showTreeGraph(tree->der, x + x / 10, y + 75, cont);
				}
				else {
					showTreeGraph(tree->der, x + x / 8, y + 75, cont); //mnhjk
				}

			}

		}
	}
}