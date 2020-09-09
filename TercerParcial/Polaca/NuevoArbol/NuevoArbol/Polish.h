#pragma once
#include"Pila.h"
#include "PilaString.h"
#include"Binary_Tree.h"
#include <string>
#include <iostream>

class Polish
{ 
public:
	bool jerarquia(char,char);
	void resolverEcuacion(string[], int);
	void separar(string);
	string doOperation(string, string, string);
	string stringPost(string[], int);
	Pila pil1;
	Binary_Tree _tree;
	string respuesta;
};

