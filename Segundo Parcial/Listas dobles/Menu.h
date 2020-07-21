#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <math.h>
#include"Lista.h"
using namespace std;

class Menu{
	public:
	void MenuTeclas();
	Lista<int>* lista=new Lista<int>();
};



void Menu :: MenuTeclas()
{
	int cursor = 0;
	char tecla;
	int opcion;
	int cont = 1;
	system("cls");
	string menu[] = { "Ingresar al inicio          ",
					  "Ingresar al final           ",
					  "Ingresar entre              ",
					  "Eliminar Dato               ",
					  "Mostrar Lista               ",
					  "Salir                       "
					   };
	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 60);
		cout << "                SELECCIONE UNA OPCION         " << endl;
		for (int i = 0; i < 6; i++)
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
				if (cursor == 6)
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
					cursor = 5;
				}
				break;
			}
			if (tecla == 13)
			{   int dato=0;
				int pos=0;
				system("cls");
				switch (cursor)
				{
				case 0:
					
					cout<<"Ingrese el dato que desea ingresar:  ";
					cin>>dato;
					lista->insertarInicio(dato);
					system("pause");
					system("cls");
					MenuTeclas();
					break;
				case 1:
					//int dato=0;
					cout<<"Ingrese el dato que desea ingresar:  ";
					cin>>dato;
					lista->insertarFinal(dato);
					system("pause");
					system("cls");
					MenuTeclas();
					break;
				case 2:
					
					cout<<"Ingrese el dato que desea ingresar:  ";
					cin>>dato;
					cout<<endl<<"En que posicion desea ingresar el dato: ";
					cin>>pos;
					lista->insertarEntre(dato,pos);
					system("pause");
					system("cls");
					MenuTeclas();
					break;
				case 3:
					//int dato=0;
					cout<<"Ingrese el dato que desea eliminar:  ";
					cin>>dato;
					lista->borrar(dato);
					system("pause");
					system("cls");
					MenuTeclas();
					break;
				case 4:
					lista->mostrar();
					system("pause");
					system("cls");
					MenuTeclas();
					break;
				
				case 5:
					system("cls");
					cout << endl << "<<<<<<<<<Gracias por usar nuestro programa>>>>>>>>>" << endl;
					exit(1);
					break;
				}
			}
		}
	}
}
