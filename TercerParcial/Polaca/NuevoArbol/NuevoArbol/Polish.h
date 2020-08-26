#pragma once
#include"Pila.h"
#include"Binary_Tree.h"
class Polish
{ 
public:
	bool jerarquia(char,char);
	string stringPost(string[], int);
	Pila pil1;
	Binary_Tree _tree;
};

