#pragma once
#define NOMINMAX
#include "Menu.h"
#include "Mongo_DB_Instance.h"
#include "Mongo_DB_Access.h"
#include "Validacion.h"
#include <locale.h>
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL,"");
	Mongo_DB_Instance::GetInstance()->createPool("mongodb://localhost:27017");
	auto dbClient_A = Mongo_DB_Instance::GetInstance()->getClientFromPool();
	Mongo_DB_Access access(*dbClient_A, "Translate", "word");
	Menu menu;
	access.get_Word(&menu._tree);
	//access.get_all_documents();
	menu.menuTeclas();
	return 0;
}