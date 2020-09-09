#pragma once

//#include "Menu.h"
#include "Mongo_DB_Instance.h"
#include "Mongo_DB_Access.h"
#include <locale.h>


int main()
{
	setlocale(LC_ALL, "");
	//Menu menu;
	Translate _data;
	Binary_Tree<Translate> _tree;
	int cont = 1;

	Mongo_DB_Instance::GetInstance()->createPool("mongodb://localhost:27017");

	auto dbClient_A = Mongo_DB_Instance::GetInstance()->getClientFromPool();

	Mongo_DB_Access access(*dbClient_A, "Translate", "word");
	_data.set_english("water");
	_data.set_spanish("agua");
	access.insert(_data);
	access.get_Word(&_tree);


	_tree.showTree(_tree.get_root(), cont);

	//Conection_DB conection;
	//Conection_DB* conection = Conection_DB::getInstance();
	/*mongocxx::instance instance{};
	mongocxx::uri uri("mongodb://localhost:27017");
	mongocxx::client client(uri);
	mongocxx::database db = client["Translate"];
	mongocxx::collection coll = db["word"];*/
	//conection.read_DB(&menu._tree);

	//menu.menuTeclas();
	return 0;
}