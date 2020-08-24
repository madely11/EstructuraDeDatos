#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <iostream>
#include "Menu.h"

using namespace std;
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
	string menu[] = { "Agregar dato              ",
					  "Eliminar Dato             ",
					  "Buscar Dato              ",
					  "Imprimir Arbol           ",
					  //"Restaurar archivo         ",
					 // "Generar PDF               ",
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
						char opt = 's';
						int dato;
						while (opt == 's' || opt == 'S') {
							cout << "Ingrese un dato:";
							cin >> dato;
							_tree._add(dato);
							cout << "Desea ingresar otro dato (S/N): ";
							cin >> opt;
						}
						menuTeclas();
					}
					break;
				case 1:
					if (true) {
						system("cls");
						int dato;
						cout << "Ingrese el dato que desea eliminar: " << endl;
						cin >> dato;
						_tree._delete(dato);
						system("pause");

					}

					menuTeclas();
					break;
				case 2:
					if (true) {
						system("cls");
						int dato;
						cout << "Ingrese el dato que desea buscar: " << endl;
						cin >> dato;
						if (_tree._look(dato) != NULL) {
							cout << "Elmento: " << _tree._look(dato) << endl;
						}
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

