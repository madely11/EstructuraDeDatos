#pragma once
#include <string>
#include<iostream>
#include <stdlib.h>
#include "Binary_Tree.h"
#define longitud2 3
using namespace std;


class Validar
{
public:
	bool validarExpresion(string);
	bool validarParentesis(string);
	bool validarCaracteres(string);
	void separarExpresion(string);
public:
	Binary_Tree _tree;
};
