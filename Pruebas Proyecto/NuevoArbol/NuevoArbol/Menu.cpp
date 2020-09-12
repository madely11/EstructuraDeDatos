#pragma once
#define NOMINMAX
#include "Menu.h"
#include <conio.h>
#include "Mongo_DB_Instance.h"
#include "Mongo_DB_Access.h"
//#include <string>
//#include <stdio.h>
//#include <stdlib.h>

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
					try {
						system("cls");
						_data.set_spanish(v.ingresaNumericos(" Ingrese la palabra en español que desea traducir:"));
						_data.set_english("");
						_data = _tree._look(_data, _tree.get_root());
						if (_data.get_english()._Equal("")) {
							cout<< endl << " Esta palabra no se cuentra en nuestro diccionario" << endl;
						}
						else {
							cout<< endl << " \t\t\t\tTraducción: " << _data.get_english() << endl;
							_data.hablar(1);
						}
						system("pause");
						menuTeclas();
					}
					catch (int e) {
						return;
					}
					break;
				case 1:
					try{
						system("cls");
						_data.set_english(v.ingresaNumericos(" Ingrese la palabra en ingles que desea traducir:"));
						_data.set_spanish("");
						 _tree._look_english(&_data, _tree.get_root());
						//cout << _data.get_spanish() << ", " << _data.get_english() << endl;
						if (_data.get_spanish()._Equal("")) {
							cout << endl <<"Esta palabra no se cuentra en nuestro diccionario" << endl;
						}
						else {
							cout << endl << "\t\t\t\tTraducción: " << _data.get_spanish()<<endl;
							_data.hablar(2);
						}
						system("pause");
						menuTeclas();
					}
					catch (int e) {
						return;
					}

					break;
				case 2:
					try {
						system("cls");
						_data.set_spanish(v.ingresaNumericos(" Ingrese la palabra en español:"));
						_data.set_english("");
						if (_data == _tree._look(_data, _tree.get_root())) {
							_data.set_english(v.ingresaNumericos(" \nIngrese la palabra en ingles:"));
							_tree._add(_data, _tree.get_root(), NULL);
							Mongo_DB_Instance::GetInstance()->createPool("mongodb://localhost:27017");
							auto dbClient_A = Mongo_DB_Instance::GetInstance()->getClientFromPool();
							Mongo_DB_Access access(*dbClient_A, "Translate", "word");
							access.insert(_data);
							cout << endl <<"\t\t\t\tPalabra ingresada exitosamente!" << endl;
						}
						else {
							cout << endl <<"\t\t\t\tLa palabra ya se encuentra en el diccionario!" << endl;
						}
						system("pause");
						menuTeclas();
					}
					catch (int e) {
						return;
					}
					break;
				case 3:
					try {
						system("cls");
						int cont=1;
						_tree.showTree(_tree.get_root(), cont);
						system("pause");
						//Sleep(3000);
						menuTeclas();
					}
					catch (int e) {
						return;
					}
					break;
				case 4:
					try {
						system("cls");
						cout << endl << "\n\t\t\t\t\t\t\t\t Gracias!" << endl;
						Sleep(3000);
						exit(1);
					}
					catch (int e) {
						return;
					}
					break;
				}
			}
		}
	}
}

