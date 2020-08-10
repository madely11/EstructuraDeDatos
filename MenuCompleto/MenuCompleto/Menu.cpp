#include"Menu.h"

void Menu::ocultarCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
void Menu::gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void Menu::MenuTeclas()
{
	int cursor = 0;
	char tecla;
	int opcion;
	int cont = 1;
	system("cls");
	ocultarCursor();
	string menu[] = { "Primer Parcial      ", "Segundo Parcial      ", "Extras I      ", "Salir      "};
	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 70);
		cout << "\t\t\t\t\t\t   SELECCIONE UNA OPCION   " << endl;
		for (int i = 0; i < 4; i++)
		{
			if (cursor == i)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 70);
				cout << menu[i] << "\t\t";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << menu[i] << "\t\t";
			}
		}
		for (;;)
		{
			tecla = _getch();
			if (tecla == 77)
			{
				cursor++;
				if (cursor == 4)
				{
					cursor = 0;
				}
				break;
			}
			if (tecla == 75)
			{
				cursor--;
				if (cursor == -1)
				{
					cursor = 3;
				}
				break;
			}
			if (tecla == 13)
			{
				string dato;
				int pos = 0;
				//system("cls");
				switch (cursor)
				{
				case 0:
					if (true) {
						subParcialUno();
					}
					break;
				case 1:
					if (true) {
						subParcialDos();
					}
					break;
				case 2:
					if (true) {
						subParcialTres();
					}
					break;

				case 3:
					if (true) {
						exit(0);
					}
					break;
				}
			}
		}
	}
}

void Menu::subParcialUno()
{
	int cursor = 0;
	char tecla;
	int opcion;
	int cont = 1;
	//system("cls");
	ocultarCursor();
	string menu[] = { " Suma de fracciones        ",
					  " MCM y MCM                 ",
					  " Elevar Matriz             ",
					  " Funciones Trigonómetricas ",
					  " Ordenamiento String       ",
					  " Sobrecarga de Operadores  ",
					  " Ejercicios de Notacion O  ",
					  " Volver                    "
	};
	for (;;) {
		//system("cls");
		gotoxy(0, 3);
		for (int i = 0; i < 8; i++)
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
				if (cursor == 8)
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
					cursor = 7;
				}
				break;
			}
			if (tecla == 13)
			{
				string dato;
				int pos = 0;
				//system("cls");
				switch (cursor)
				{
				case 0:
					if (true) {
						system("cls");
						system("C:\\Programas\\SumaDeFracciones.exe");
						system("pause");
						system("cls");
						MenuTeclas();
					}
					break;
				case 1:
					if (true) {
						system("cls");
						system("C:\\Programas\\DeberArreglosDinamico.exe");
						system("pause");
						system("cls");
						MenuTeclas();
					}
					break;
				case 2:
					if (true) {
						system("cls");
						system("C:\\Programas\\ElevaMatriz.exe");
						system("pause");
						system("cls");
						MenuTeclas();
					}
					break;
				case 3:
					if (true) {
						system("cls");
						system("C:\\Programas\\FuncionesTrigonometricas.exe");
						system("pause");
						system("cls");
						MenuTeclas();
						
					}
					break;
				case 4:
					if (true) {
						system("cls");
						system("C:\\Programas\\ArregloStrings.exe");
						system("pause");
						system("cls");
						MenuTeclas();
					}
					break;
				case 5:
					if (true) {
						system("cls");
						system("C:\\Programas\\SobrecargaDeOperadores.exe");
						system("pause");
						system("cls");
						MenuTeclas();
					}
					break;
				case 6:
					if (true) {
						system("cls");
						system("C:\\Programas\\EjercicioP(n2).exe");
						system("pause");
						system("cls");
						MenuTeclas();
					}
					break;
				case 7:
					if (true) {
						MenuTeclas();
					}
					break;
				}
			}
		}
	}
}

void Menu::subParcialDos()
{int cursor = 0;
	char tecla;
	int opcion;
	int cont = 1;
	
	//system("cls");
	ocultarCursor();
	string menu[] = { "\t\t\t\t Mayusculas y minusculas   ",
					  "\t\t\t\t NReinas                   ",
					  "\t\t\t\t Problema de la mochila    ",
					  "\t\t\t\t Lista Simples             ",
					  "\t\t\t\t Listas Dobles             ",
					  "\t\t\t\t Listas Circulares Dobles  ",
					  "\t\t\t\t Volver                    "
	};
	for (;;) {
		//system("cls");
		gotoxy(0, 3);
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
				string dato;
				int pos = 0;
				//system("cls");
				switch (cursor)
				{
				case 0:
					if (true) {
						system("cls");
						system("C:\\Programas\\SegundoParcial\\MayusAndMinus.exe");
						system("pause");
						system("cls");
						MenuTeclas();
					}
					break;
				case 1:
					if (true) {
						system("cls");
						system("C:\\Programas\\SegundoParcial\\NReinas.exe");
						system("pause");
						system("cls");
						MenuTeclas();
					}
					break;
				case 2:
					if (true) {
						system("cls");
						system("C:\\Programas\\SegundoParcial\\ProblemaMochila.exe");
						system("pause");
						system("cls");
						MenuTeclas();
					}
					
					break;
				case 3:
					if (true) {
						system("cls");
						system("C:\\Programas\\SegundoParcial\\ListaSimple.exe");
						system("pause");
						system("cls");
						MenuTeclas();
					}

					break;
				case 4:
					if (true) {
						system("cls");
						system("C:\\Programas\\SegundoParcial\\ListaDobles.exe");
						system("pause");
						system("cls");
						MenuTeclas();
					}

					break;
				case 5:
					if (true) {
						system("cls");
						system("C:\\Programas\\SegundoParcial\\ListasCircularesDobles.exe");
						system("pause");
						system("cls");
						MenuTeclas();
					}

					break;
				case 6:
					if (true) {
						MenuTeclas();
					}
					break;
				}
			}
		}
	}
}

void Menu::subParcialTres()
{
	int cursor = 0;
	char tecla;
	int opcion;
	int cont = 1;

	//system("cls");
	ocultarCursor();
	string menu[] = { "\t\t\t\t\t\t\t\t Generar QR              ",
					  "\t\t\t\t\t\t\t\t Mostrar Imagen          ",
					  "\t\t\t\t\t\t\t\t Volver                  "
	};
	for (;;) {
		//system("cls");
		gotoxy(0, 3);
		for (int i = 0; i < 3; i++)
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
				if (cursor == 3)
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
					cursor = 2;
				}
				break;
			}
			if (tecla == 13)
			{
				string dato;
				int pos = 0;
				//system("cls");
				switch (cursor)
				{
				case 0:
					if (true) {
						system("cls");
						system("C:\\Programas\\QR.exe");
						system("pause");
						system("cls");
						MenuTeclas();
					}
					break;
				case 1:
					if (true) {
						system("cls");
						system("C:\\Programas\\MuestraImagen.exe");
						system("pause");
						system("cls");
						MenuTeclas();
					}
					break;
				case 2:
					if (true) {
						//system("pause");
						//system("cls");
						MenuTeclas();
					}
					break;
				}
			}
		}
	}
}