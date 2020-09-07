#include "Biselado.h"

void Biselado::rotacionDerecha(Nodo* nodo)
{
	Nodo* auxIzquierdo = nodo->izquierdo;
	Nodo* auxDerecho = auxIzquierdo->derecho;
	Nodo* auxPadre = nodo->padre;
	if (auxPadre)
	{
		if (auxPadre->derecho == nodo) auxPadre->derecho = auxIzquierdo;
		else auxPadre->izquierdo = auxIzquierdo;
	}
	if (auxDerecho)
		auxDerecho->padre = nodo;
	auxIzquierdo->padre = auxPadre;
	auxIzquierdo->derecho = nodo;

	nodo->padre = auxIzquierdo;
	nodo->izquierdo = auxDerecho;
}

void Biselado::rotacionIzquierda(Nodo* nodo)
{
	Nodo* auxDerecho = nodo->derecho;
	Nodo* auxIzquierdo = auxDerecho->izquierdo;
	Nodo* auxPadre = nodo->padre;
	if (auxPadre)
	{
		if (auxPadre->derecho == nodo) auxPadre->derecho = auxDerecho;
		else auxPadre->izquierdo = auxDerecho;
	}
	if (auxIzquierdo)
		auxIzquierdo->padre = nodo;
	auxDerecho->padre = auxPadre;
	auxDerecho->izquierdo = nodo;

	nodo->padre = auxDerecho;
	nodo->derecho = auxIzquierdo;
}

void Biselado::mostrar(Nodo* nodo, int cont)
{
	if (nodo == NULL) {
		return;
	}
	else {
		mostrar(nodo->derecho, cont + 1);
		for (int i = 0; i < cont; i++) {
			std::cout << "   ";
		}
		std::cout << nodo->v << std::endl;
		mostrar(nodo->izquierdo, cont + 1);
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
			if (padre->izquierdo == nodo)
				rotacionDerecha(padre);
			else
				rotacionIzquierda(padre);
			break;
		}
		if (abuelo->izquierdo == padre)
		{
			if (padre->izquierdo == nodo)
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
			if (padre->izquierdo == nodo)
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
		raiz->izquierdo = NULL;
		raiz->derecho = NULL;
		raiz->padre = NULL;
		raiz->v = valor;
		return;
	}
	Nodo* nodo = raiz;
	while (true)
	{
		if (nodo->v == valor) break; // not multiset
		if (valor < (nodo->v))
		{
			if (nodo->izquierdo) nodo = nodo->izquierdo;
			else
			{
				nodo->izquierdo = (Nodo*)malloc(sizeof(Nodo));
				nodo->izquierdo->padre = nodo;
				nodo->izquierdo->derecho = NULL;
				nodo->izquierdo->izquierdo = NULL;
				nodo->izquierdo->v = valor;
				nodo = nodo->izquierdo;
				break;
			}
		}
		else
		{
			if (nodo->derecho) nodo = nodo->derecho;
			else
			{
				nodo->derecho = (Nodo*)malloc(sizeof(Nodo));
				nodo->derecho->padre = nodo;
				nodo->derecho->derecho = NULL;
				nodo->derecho->izquierdo = NULL;
				nodo->derecho->v = valor;
				nodo = nodo->derecho;
				break;
			}
		}
	}
	biselado(nodo);
}

void Biselado::Inorder(Nodo* nodo)
{
	if (!nodo) return;
	Inorder(nodo->izquierdo);
	printf("valor: %d ", nodo->v);
	if (nodo->izquierdo) printf("izquierdo: %d ", nodo->izquierdo->v);
	if (nodo->derecho) printf("derecho: %d ", nodo->derecho->v);
	puts("");
	Inorder(nodo->derecho);
}
bool Biselado::borrar(int dato)
{
	Nodo* nodo = buscar(dato);
	if (!nodo) return false;
	biselado(nodo); //check once more;
	Nodo* auxNodo = raiz->izquierdo;
	if (!auxNodo) {

		raiz = raiz->derecho;
		raiz->padre = NULL;
	}
	else {
		if (auxNodo->derecho) {
			while (auxNodo->derecho) auxNodo = auxNodo->derecho;
			raiz->v = auxNodo->v;
			if (auxNodo->izquierdo)
			{
				auxNodo->padre->derecho = auxNodo->izquierdo;
				auxNodo->izquierdo->padre = auxNodo->padre;
				//free(nodo);
			}
			else {
				auxNodo->padre->derecho = NULL;
				//free(nodo);
			}
		}
		else {
			auxNodo->padre = NULL;
			auxNodo->derecho=raiz->derecho;
			raiz->derecho->padre = auxNodo;
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
		if (nodo->v == dato)
			break;
		if (dato < (nodo->v))
		{
			if (nodo->izquierdo)
				nodo = nodo->izquierdo;
			else
				break;
		}
		else
		{
			if (nodo->derecho)
				nodo = nodo->derecho;
			else
				break;
		}
	}
	biselado(nodo);
	if (nodo->v == dato) return nodo;
	else return NULL;
}
