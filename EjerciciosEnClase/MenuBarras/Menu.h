#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <math.h>
using namespace std;

class Menu{
	public:
	void MenuTeclas();
	int suma(int a, int b);
};

int Menu :: suma(int a, int b){
	return a+b;
}

void Menu :: MenuTeclas()
{
	int cursor = 0;
	char tecla;
	int opcion;
	int cont = 1;
	system("cls");
	string menu[] = { "Suma          ",
					  "Resta         ",
					  "Multiplicación",
					  "Division      ",
					  "Factorial     ",
					  "Potencia      ",
					  "Salir         " };
	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 60);
		cout << "                SELECCIONE UNA OPCION         " << endl;
		for (int i = 0; i < 7; i++)
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
		for (;;)
		{
			tecla = _getch();
			if (tecla == 80)
			{
				cursor++;
				if (cursor == 7)
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
					cursor = 6;
				}
				break;
			}
			if (tecla == 13)
			{
				switch (cursor)
				{
				case 0:
					printf("\nResultado suma = %d\n", suma(5,8));
					system("pause");
					system("cls");
					MenuTeclas();
					break;
				case 1:
					MenuTeclas();
					break;
				case 2:
					MenuTeclas();
					break;
				case 3:
					MenuTeclas();
					break;
				case 4:
					MenuTeclas();
					break;
				case 5:
					MenuTeclas();
					break;
				case 6:
					system("cls");
					cout << endl << "<<<<<<<<<Gracias por usar nuestro programa>>>>>>>>>" << endl;
					exit(1);
					break;
				}
			}
		}
	}
}
