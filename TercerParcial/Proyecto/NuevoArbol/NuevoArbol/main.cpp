#include <iostream>
#include "Menu.h"
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	Menu menu;
	File_Manager file("words.txt");
	file.load_file(&menu._tree);
	menu.menuTeclas();
	return 0;
}