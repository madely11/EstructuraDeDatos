#include "Biselado.h"

void Biselado::rotacionDerecha(Nodo* P)
{
	Nodo* T = P->izquierdo;
	Nodo* B = T->derecho;
	Nodo* D = P->padre;
	if (D)
	{
		if (D->derecho == P) D->derecho = T;
		else D->izquierdo = T;
	}
	if (B)
		B->padre = P;
	T->padre = D;
	T->derecho = P;

	P->padre = T;
	P->izquierdo = B;
}

void Biselado::rotacionIzquierda(Nodo* P)
{
	Nodo* T = P->derecho;
	Nodo* B = T->izquierdo;
	Nodo* D = P->padre;
	if (D)
	{
		if (D->derecho == P) D->derecho = T;
		else D->izquierdo = T;
	}
	if (B)
		B->padre = P;
	T->padre = D;
	T->izquierdo = P;

	P->padre = T;
	P->derecho = B;
}

void Biselado::mostrar(Nodo* node, int cont)
{
	if (node == NULL) {
		return;
	}
	else {
		mostrar(node->derecho, cont + 1);
		for (int i = 0; i < cont; i++) {
			std::cout << "   ";
		}
		std::cout << node->v << std::endl;
		mostrar(node->izquierdo, cont + 1);
		return;
	}

}

void Biselado::biselado(Nodo* T)
{
	while (true)
	{
		Nodo* padre = T->padre;
		if (!padre) break;
		Nodo* pp = padre->padre;
		if (!pp)//Zig
		{
			if (padre->izquierdo == T)
				rotacionDerecha(padre);
			else
				rotacionIzquierda(padre);
			break;
		}
		if (pp->izquierdo == padre)
		{
			if (padre->izquierdo == T)
			{//ZigZig
				rotacionDerecha(pp);
				rotacionDerecha(padre);
			}
			else
			{//ZigZag
				rotacionIzquierda(padre);
				rotacionDerecha(pp);
			}
		}
		else
		{
			if (padre->izquierdo == T)
			{//ZigZag
				rotacionDerecha(padre);
				rotacionIzquierda(pp);
			}
			else
			{//ZigZig
				rotacionIzquierda(pp);
				rotacionIzquierda(padre);
			}
		}
	}
	raiz = T;
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
	Nodo* P = raiz;
	while (true)
	{
		if (P->v == valor) break; // not multiset
		if (valor < (P->v))
		{
			if (P->izquierdo) P = P->izquierdo;
			else
			{
				P->izquierdo = (Nodo*)malloc(sizeof(Nodo));
				P->izquierdo->padre = P;
				P->izquierdo->derecho = NULL;
				P->izquierdo->izquierdo = NULL;
				P->izquierdo->v = valor;
				P = P->izquierdo;
				break;
			}
		}
		else
		{
			if (P->derecho) P = P->derecho;
			else
			{
				P->derecho = (Nodo*)malloc(sizeof(Nodo));
				P->derecho->padre = P;
				P->derecho->derecho = NULL;
				P->derecho->izquierdo = NULL;
				P->derecho->v = valor;
				P = P->derecho;
				break;
			}
		}
	}
	biselado(P);
}

void Biselado::Inorder(Nodo* R)
{
	if (!R) return;
	Inorder(R->izquierdo);
	printf("valor: %d ", R->v);
	if (R->izquierdo) printf("izquierdo: %d ", R->izquierdo->v);
	if (R->derecho) printf("derecho: %d ", R->derecho->v);
	puts("");
	Inorder(R->derecho);
}
bool Biselado::borrar(int v)
{
	Nodo* N = buscar(v);
	if (!N) return false;
	biselado(N); //check once more;
	Nodo* P = raiz->izquierdo;
	if (!P) {

		raiz = raiz->derecho;
		raiz->padre = NULL;
	}
	else {
		if (P->derecho) {
			while (P->derecho) P = P->derecho;
			raiz->v = P->v;
			if (P->izquierdo)
			{
				P->padre->derecho = P->izquierdo;
				P->izquierdo->padre = P->padre;
				//free(P);
			}
			else {
				P->padre->derecho = NULL;
				//free(P);
			}
		}
		else {
			P->padre = NULL;
			P->derecho=raiz->derecho;
			raiz->derecho->padre = P;
			raiz = P;

		}
		
	}
	//free(N);
	return true;
}

Nodo* Biselado::buscar(int v)
{
	if (!raiz) return NULL;
	Nodo* P = raiz;
	while (P)
	{
		if (P->v == v)
			break;
		if (v < (P->v))
		{
			if (P->izquierdo)
				P = P->izquierdo;
			else
				break;
		}
		else
		{
			if (P->derecho)
				P = P->derecho;
			else
				break;
		}
	}
	biselado(P);
	if (P->v == v) return P;
	else return NULL;
}
