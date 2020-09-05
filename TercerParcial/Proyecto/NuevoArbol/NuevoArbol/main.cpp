#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
	Menu menu;
	File_Manager file("words.txt");
	file.load_file(&menu._tree);
	menu.menuTeclas();
	return 0;
}