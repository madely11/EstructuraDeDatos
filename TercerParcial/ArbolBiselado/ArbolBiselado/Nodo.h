#pragma once
#include<iostream>
class Nodo
{
public:
	Nodo* izquierdo;
	Nodo* derecho;
	Nodo* padre;
	int v;
	friend class Biselado;
};

