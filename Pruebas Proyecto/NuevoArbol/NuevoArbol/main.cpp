#pragma once

#include "Menu.h"
#include <locale.h>


int main()
{
	setlocale(LC_ALL, "");
	Menu menu;
	Conection_DB conection;
	//Conection_DB* conection = Conection_DB::getInstance();
	mongocxx::instance instance{};
	mongocxx::uri uri("mongodb://localhost:27017");
	mongocxx::client client(uri);
	mongocxx::database db = client["Translate"];
	mongocxx::collection coll = db["word"];
	conection.read_DB(&menu._tree);
	menu.menuTeclas();
	return 0;
}