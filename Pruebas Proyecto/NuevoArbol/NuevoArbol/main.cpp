#pragma once

#include "Menu.h"
#include <locale.h>


int main()
{
	setlocale(LC_ALL, "");
	Menu menu;
	//File_Manager file("words.txt");
	//file.load_file(&menu._tree);
	Conection_DB conection;
	conection.read_DB(&menu._tree);
	menu.menuTeclas();
	return 0;
}