#pragma once

#include "Menu.h"
#include "Mongo_DB_Thread.h"
#include <locale.h>


int main()
{
	setlocale(LC_ALL, "");
	Menu menu;
	int cont = 1;

	Mongo_DB_Instance::GetInstance()->createPool("mongodb://localhost:27017");

	auto dbClient_A =
		Mongo_DB_Instance::GetInstance()->getClientFromPool();

	/*std::thread thread_A{
	  Mongo_DB_Thread(*dbClient_A, "Translate", "word", menu._data, menu._tree)
	};*/

	std::thread thread_A{
	  Mongo_DB_Thread(*dbClient_A, "Translate", "word", menu._data)
	};

	thread_A.join();

	menu._tree.showTree(menu._tree.get_root(), cont);

	//Conection_DB conection;
	//Conection_DB* conection = Conection_DB::getInstance();
	/*mongocxx::instance instance{};
	mongocxx::uri uri("mongodb://localhost:27017");
	mongocxx::client client(uri);
	mongocxx::database db = client["Translate"];
	mongocxx::collection coll = db["word"];*/
	//conection.read_DB(&menu._tree);

	menu.menuTeclas();
	return 0;
}