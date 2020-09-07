#pragma once
#include"Nodo.h"
class Biselado
{
public:
	Nodo* raiz=NULL;
	void rotacionDerecha(Nodo* P);
	void rotacionIzquierda(Nodo* P);
	void mostrar(Nodo* node, int cont);
	void biselado(Nodo* T);
	void insertar(int v);
	Nodo* buscar(int v);
	void Inorder(Nodo* R);
	bool borrar(int v);
};

