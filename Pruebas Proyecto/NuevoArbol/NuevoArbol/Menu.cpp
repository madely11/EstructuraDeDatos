
#include "Menu.h"
#include <conio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//#include <math.h>
/**
	@brief Funcion para oculta Cursor en la consola
	@param void
	@returns void
*/
void Menu::ocultarCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
/**
	@brief Funcion para manejar el menu con las teclas desde la consola
	@param void
	@returns void
*/
void Menu::menuTeclas()
{
	int cursor = 0;
	char tecla;
	//int opcion;
	int cont = 1;
	system("cls");
	string menu[] = { "Traducir de Español a Ingles              ",
					  "Traducir de Ingles a Español            ",
					  "Agregar palabra              ",
					  "Imprimir Arbol           ",
					  "Salir                     " };
	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 60);
		cout << "                SELECCIONE UNA OPCION         " << endl;
		for (int i = 0; i < 5; i++)
		{
			if (cursor == i)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout << menu[i] << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << menu[i] << endl;
			}
		}

		ocultarCursor();

		for (;;)
		{
			tecla = _getch();
			if (tecla == 80)
			{
				cursor++;
				if (cursor == 5)
				{
					cursor = 0;
				}
				break;
			}
			if (tecla == 72)
			{
				cursor--;
				if (cursor == -1)
				{
					cursor = 4;
				}
				break;
			}
			if (tecla == 13)
			{
				switch (cursor)
				{
				case 0:
					if (true) {
						system("cls");
						_data.set_spanish(ingreso.leerString("Ingrese la palabra en español que desea traducir: ", 1));
						_data.set_english("");
						_data = _tree._look(_data, _tree.get_root());
						//cout << _data.get_spanish() << ", " << _data.get_english() << endl;
						if (_data.get_english()._Equal("")) {
							cout << "Esta palabra no se cuentra en nuestro diccionario" << endl;
						}
						else {
							cout << "Traducción: " << _data.get_english()<<endl;
							_data.hablar(1);
						}
						system("pause");
						menuTeclas();
					}
					break;
				case 1:
					if (true) {
						system("cls");
						_data.set_english(ingreso.leerString("Ingrese la palabra en ingles que desea traducir: ", 1));
						_data.set_spanish("");
						 _tree._look_english(&_data, _tree.get_root());
						//cout << _data.get_spanish() << ", " << _data.get_english() << endl;
						if (_data.get_spanish()._Equal("")) {
							cout << "Esta palaabra no se cuentra en nuestro diccionario" << endl;
						}
						else {
							cout << "Traducción: " << _data.get_spanish()<<endl;
							_data.hablar(2);
						}
						system("pause");
						menuTeclas();
					}

					break;
				case 2:
					if (true) {
						system("cls");
						Conection_DB conection;
						_data.set_spanish(ingreso.leerString("Ingrese la palabra en español: ", 1));
						if (_data == _tree._look(_data, _tree.get_root())) {

							_data.set_english(ingreso.leerString("Ingrese la palabra en ingles: ", 1));
							_tree._add(_data, _tree.get_root(), NULL);
							conection.insert_data_DB(_data);
							cout << "Palabra ingresada exitosamente!" << endl;
						}
						else cout << "La palabra ya existe!" << endl;
						system("pause");
					}
					menuTeclas();
					break;
				case 3:
				
					if (true) {
						system("cls");
						int cont=1;
						_tree.showTree(_tree.get_root(), cont);
						system("pause");
						//Sleep(3000);
					}
					menuTeclas();
					break;
				case 4:
					if (true) {
						system("cls");
						cout << endl << "\n\t\t\t\t\t\t\t\t Gracias!" << endl;
						Sleep(3000);
						exit(1);
					}
					break;
				}
			}
		}
	}
}

