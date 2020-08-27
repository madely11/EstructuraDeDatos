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
					  "Mostrar profundidad        ",
					  "Mostrar altura             ",
	                  "Buscar Nivel               ",
					  "Contar numeros primos      ",
					  "Salir                     " };
	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 60);
		cout << "                SELECCIONE UNA OPCION         " << endl;
		for (int i = 0; i < 9; i++)
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
				if (cursor == 9)
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
					cursor = 8;
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
							datoS = ingreso.leer("Ingrese un dato: ", 1);
							dato = atoi(datoS.c_str());
							_tree._add(dato, _tree.get_root(), NULL);
							cout << "Desea ingresar otro dato (S/N): ";
							cin >> opt;
							cout << endl;
							cin.ignore();
						}
						menuTeclas();
					}
					break;
				case 1:
					if (true) {
						system("cls");
						int dato;
						datoS = ingreso.leer("Ingrese el dato que desea eliminar: ", 1);
						dato = atoi(datoS.c_str());
						_tree._delete(dato, _tree.get_root(), NULL);
						system("pause"); 

					}
					menuTeclas();
					break;
				case 2:
					if (true) {
						system("cls");
						int dato;
						datoS = ingreso.leer("Ingrese el dato que desea buscar: ", 1);
						dato = atoi(datoS.c_str());
						if (_tree._look(dato, _tree.get_root()) != NULL) {
							cout << "Elmento encontrado: "<< dato  << endl;
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
						int dato;
						datoS = ingreso.leer("Ingrese el dato del desea saber la profundidad: ", 1);
						dato = atoi(datoS.c_str());
						dato = _tree.get_lvl(dato, _tree.get_root());
						if ( dato!= 0) {
							cout << "La profundidad del elemento es: " <<dato<< endl;
						}
						system("pause");
						//Sleep(3000);
					}
					menuTeclas();
					break;
				case 5:

					if (true) {
						system("cls");
						int altura = _tree.get_height_tree(this->_tree.get_root())-1;
						cout << "La altura del arbol es: " << altura<<endl;
						system("pause");
						//Sleep(3000);
					}
					menuTeclas();
					break;
				case 6:

					if (true) {
						system("cls");
						int dato;
						datoS = ingreso.leer("Ingrese el dato del desea saber el nivel: ", 1);
						dato = atoi(datoS.c_str());
						dato = _tree.get_lvl(dato, _tree.get_root());
						if (dato != 0) {
							cout << "El nivel del elemento es: " << dato << endl;
						}
						system("pause");
						//Sleep(3000);
					}
					menuTeclas();
					break;
				case 7:
					if (true) {
						system("cls");
						int dato = _tree.cont_prime(_tree.get_root());
						cout << "La cantidad de numeros primos es: " <<dato<< endl;
						system("pause");
					}
					menuTeclas();
					break;
				case 8:
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

