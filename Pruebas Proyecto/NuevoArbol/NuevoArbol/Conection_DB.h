#pragma once
#include "Binary_Tree.cpp"
#include"Translate.h"



class Conection_DB
{
public:
	Translate new_word;
	void insert_data_DB(Translate word);
	void read_DB(Binary_Tree<Translate>*);
};

