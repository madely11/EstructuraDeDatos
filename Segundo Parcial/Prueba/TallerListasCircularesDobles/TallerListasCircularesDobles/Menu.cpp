#include"Menu.h"

void Menu::MenuTeclas()
{
	int cursor = 0;
	char tecla;
	int opcion;
	int cont = 1;
	IngresoPersona nuevaPersona;
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
			{
				string dato;
				int pos = 0;
				system("cls");
				switch (cursor)
				{
				case 0:

					cout << "Ingrese el dato que desea ingresar:  ";
					nuevaPersona.ingresoDatos();
					lista->insertarInicio(nuevaPersona.persona);
					system("pause");
					system("cls");
					MenuTeclas();
					break;
				case 1:
					//	int dato=0;
					cout << "Ingrese el dato que desea ingresar:  ";
					nuevaPersona.ingresoDatos();
					lista->insertarFinal(nuevaPersona.persona);
					system("pause");
					system("cls");
					MenuTeclas();
					break;
				case 2:

					cout << "Ingrese el dato que desea ingresar:  ";
					nuevaPersona.ingresoDatos();
					cout << endl << "En que posicion desea ingresar el dato: ";
					cin >> pos;
					lista->insertarEntre(nuevaPersona.persona, pos);
					system("pause");
					system("cls");
					MenuTeclas();
					break;
				case 3:
					//int dato=0;

					cout << "Ingrese el dato que desea eliminar:  ";
					cin >> dato;
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