#pragma once
#define NOMINMAX
#include "Menu.h"
#include "Mongo_DB_Instance.h"
#include "Mongo_DB_Access.h"
#include <locale.h>


int main()
{
	setlocale(LC_ALL,"");
	int cont = 1;

	Mongo_DB_Instance::GetInstance()->createPool("mongodb://localhost:27017");
	auto dbClient_A = Mongo_DB_Instance::GetInstance()->getClientFromPool();
	Mongo_DB_Access access(*dbClient_A, "Translate", "word");
	Menu menu;
	access.get_Word(&menu._tree);
	menu.menuTeclas();

	
	


	//_tree.showTree(_tree.get_root(), cont);

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