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
#pragma once
#include"Nodo.h"
#include "Dibujar.h"
class Biselado
{
public:
	Nodo* raiz=NULL;
	void rotacionDerecha(Nodo* P);
	void rotacionIzquierda(Nodo* P);
	void mostrar(Nodo* node, int cont);
	void biselado(Nodo* T);
	void insertar(int valor);
	Nodo* buscar(int valor);
	void Inorder(Nodo* R);
	bool borrar(int valor);
	void showTreeGraph(Nodo* tree, int x, int y, int cont);
public:
	Dibujar dibujar;
};

