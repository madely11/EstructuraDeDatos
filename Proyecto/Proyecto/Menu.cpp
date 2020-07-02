/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE PARA DEFINIR EL MENU DEL PROGRAMA                         *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/06/20									  *
* FECHA DE MODIFICACIÓN: 02/07/20								  *
******************************************************************/

/**
	@file Menu.cpp
	@brief Clase que contiene metodos para presentar el menu en la consola
	@author Madely Betancourt y Kevin Caicedo
	@date 6/2020
*/
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
	string menu[] = { "Crear Cuenta              ",
					  "Realizar Transaccion      ",
					  "Registro de transacciones ",
					  "Crear Respaldo            ",
		              "Restaurar archivo         ",
					  "Salir                     "};
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

		ocultarCursor();

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
				switch (cursor)
				{
				case 0:
					if (true) {
						//crar cuenta
						submenu1();
					}
					break;
				case 1:
					if (true) {
						//realizar transaccion
						submenu2();
					}
					break;
				case 2:
					if (true) {
						//registro de transacciones
						submenu3();
					}
					break;
				case 3:
					if (true) {
						system("cls");
						cout << "\n\t\t\t\t Creando respaldo..." << endl;
						Sleep(2000);
						string linea;
						Respaldo archivo("respaldo.txt");
						linea+=archivo.nombreRespaldo();
						linea += ",";
						archivo.nombreArchivo = "cliente.txt";
						linea+=archivo.crearRespaldo();
						linea += ",";
						archivo.nombreArchivo = "cuenta.txt";
						linea+=archivo.crearRespaldo();
						linea += ",";
						archivo.nombreArchivo = "transacciones.txt";
						linea+=archivo.crearRespaldo();
						archivo.guardarRespaldo(linea);
						system("cls");
						cout << "\n\t\t\t\tRespaldo creado exitosamente!" << endl;
						Sleep(2000);
						menuTeclas();
					}
					break;
				case 4:
					if (true) {
						system("cls");
						cout << "\t\n" << "Respaldos: " << endl << endl;
						Respaldo respaldo("respaldos.txt");
						respaldo.imprimirNombreRespaldo();
						respaldo.ingresarRespaldo();
						system("cls");
						cout << "\n\t\t\t\t Documentos restaurados exitosamente!" << endl;
						Sleep(2000);
						menuTeclas();
					} 
					break;
				case 5:
					if (true) {
						system("cls");
						cout << endl << "<<<<<<<<<Gracias por usar nuestro programa>>>>>>>>>" << endl;
						Sleep(2000);
						exit(1);
						break;
					}
				}
			}
		}
	}
}

/**
	@brief Funcion para mostrar un submenu con otras opciones
	@param void
	@returns void
*/
void Menu::submenu1()
{
	int cursor = 0;
	char tecla;
	//int opcion;
	int cont = 1;
	system("cls");
	string menu[] = { "Ahorros      ",
					  "Credito      ",
					  "Cancelar     " };

	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 60);
		cout << "                SELECCIONE UNA OPCION         " << endl;
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

		ocultarCursor();

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
				switch (cursor)
				{
				case 0:
					if (true) {
						system("cls");
						Cliente cliente;
						cliente.pedirDatos(1);
						cout << endl << "<<<<<<<<<Cuenta creada exitosamente>>>>>>>>>" << endl;
						cout << cliente.stringConsola();
						cout << endl;
						//Sleep(1000);
						system("pause");
						menuTeclas();

						//TipoCuenta tipo1(1);
					}
					break;
				case 1:
					if (true) {
						system("cls");
						Cliente cliente;
						cliente.pedirDatos(2);
						cout << endl << "<<<<<<<<<Cuenta creada exitosamente>>>>>>>>>" << endl;
						cout << cliente.stringConsola();
						cout << endl;
						//Sleep(1000);
						system("pause");
						menuTeclas();
					}
					break;
				case 2:
					if (true) {
						system("cls");
						cout << endl << "<<<<<<<<<Proceso Cancelado>>>>>>>>>" << endl;
						Sleep(1000);
						menuTeclas();
					} 
					break;
				}
			}

		}
	}
}

/**
	@brief Funcion de submenu para mostrar otras opciones del programa
	@param void
	@returns void
*/
void Menu::submenu2()
{
	int cursor = 0;
	char tecla;
	//int opcion;
	int cont = 1;
	system("cls");
	string menu[] = { "Deposito      ",
					  "Retiro        ",
					  "Cancelar      " };

	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 60);
		cout << "                SELECCIONE UNA OPCION         " << endl;
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

		ocultarCursor();

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
				switch (cursor)
				{
				case 0:
					if (true) {
						system("cls");
						Cuenta cuenta;
						if (!cuenta.verificarCuenta(1)) {
							menuTeclas();
						}
						Sleep(1000);
						menuTeclas();
					}
					break;
				case 1:
					if (true) {
						system("cls");
						Cuenta cuenta;
						if (!cuenta.verificarCuenta(2)) {
							menuTeclas();
						}
						Sleep(1000);
						menuTeclas();
					}
					break;
				case 2:
					if (true) {
						system("cls");
						cout << endl << "<<<<<<<<<Proceso Cancelado>>>>>>>>>" << endl;
						Sleep(1000);
						menuTeclas();
					} 
					break;
				}
			}
		}
	}
}
/**
	@brief Funcion de submenu para mostrar otras opciones del programa
	@param void
	@returns void
*/
void Menu::submenu3()
{
	int cursor = 0;
	char tecla;
	//int opcion;
	int cont = 1;
	system("cls");
	string menu[] = { "Buscar por cuenta      ",
					  "Buscar por fecha       ",
					  "Cancelar               "};

	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 60);
		cout << "                SELECCIONE UNA OPCION         " << endl;
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

		ocultarCursor();

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
				switch (cursor)
				{
				case 0:
					if (true) {
						system("cls");
						Transacciones t;
						t.datosTransaccion(1);
						Sleep(1000);
						menuTeclas();
						//TipoCuenta tipo1(1);
					}
					break;
				case 1:
					if (true) {
						system("cls");
						Transacciones t;
						t.datosTransaccion(2);
						Sleep(1000);
						menuTeclas();
					}
					break;
				case 2:
					if (true) {
						system("cls");
						cout << endl << "<<<<<<<<<Proceso Cancelado>>>>>>>>>" << endl;
						Sleep(1000);
						menuTeclas();
					} 
					break;
				}
			}
		}
	}
}

//void Menu::submenu4()
//{
//	int cursor = 0;
//	char tecla;
//	//int opcion;
//	int cont = 1;
//	system("cls");
//	string menu[] = { "Respaldo de clientes          ",
//					  "Respaldo de cuentas           ",
//					  "Respaldo de transacciones     ",
//					  "Sallir                        " };
//
//	for (;;) {
//		system("cls");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 60);
//		cout << "                SELECCIONE UNA OPCION         " << endl;
//		for (int i = 0; i < 4; i++)
//		{
//			if (cursor == i)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
//				cout << menu[i] << endl;
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//			}
//			else
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//				cout << menu[i] << endl;
//			}
//		}
//
//		ocultarCursor();
//
//		for (;;)
//		{
//			tecla = _getch();
//			if (tecla == 80)
//			{
//				cursor++;
//				if (cursor == 4)
//				{
//					cursor = 0;
//				}
//				break;
//			}
//			if (tecla == 72)
//			{
//				cursor--;
//				if (cursor == -1)
//				{
//					cursor = 3;
//				}
//				break;
//			}
//			if (tecla == 13)
//			{
//				switch (cursor)
//				{
//				case 0:
//					if (true) {
//						system("cls");
//						
//						system("pause");
//						menuTeclas();
//					}
//					break;
//				case 1:
//					if (true) {
//						system("cls");
//						
//						system("pause");
//						menuTeclas();
//					}
//					break;
//				case 2:
//					if (true) {
//						system("cls");
//						
//						system("pause");
//						menuTeclas();
//					}
//					break;
//				case 3:
//					if (true) {
//						system("cls");
//						cout << endl << "<<<<<<<<<Proceso Cancelado>>>>>>>>>" << endl;
//						Sleep(1000);
//						menuTeclas();
//					}
//					break;
//				}
//			}
//
//		}
//	}
//}

//void Menu::submenu5()
//{
//	int cursor = 0;
//	char tecla;
//	//int opcion;
//	int cont = 1;
//	system("cls");
//	string menu[] = { "Restaurar archivo de clientes          ",
//					  "Restaurar archivo de cuentas           ",
//					  "Restaurar archivo de transacciones     ",
//					  "Salir                                  "};
//
//	for (;;) {
//		system("cls");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 60);
//		cout << "                SELECCIONE UNA OPCION         " << endl;
//		for (int i = 0; i < 4; i++)
//		{
//			if (cursor == i)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
//				cout << menu[i] << endl;
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//			}
//			else
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//				cout << menu[i] << endl;
//			}
//		}
//
//		ocultarCursor();
//
//		for (;;)
//		{
//			tecla = _getch();
//			if (tecla == 80)
//			{
//				cursor++;
//				if (cursor == 4)
//				{
//					cursor = 0;
//				}
//				break;
//			}
//			if (tecla == 72)
//			{
//				cursor--;
//				if (cursor == -1)
//				{
//					cursor = 3;
//				}
//				break;
//			}
//			if (tecla == 13)
//			{
//				switch (cursor)
//				{
//				case 0:
//					if (true) {
//						system("cls");
//						Respaldo respaldo("respaldoClientes.txt");
//						respaldo.obtenerNombreRespaldo(1);
//						system("pause");
//						menuTeclas();
//
//						//TipoCuenta tipo1(1);
//					}
//					break;
//				case 1:
//					if (true) {
//						system("cls");
//						Respaldo respaldo("respaldoCuentas.txt");
//						respaldo.obtenerNombreRespaldo(2);
//						system("pause");
//						menuTeclas();
//					}
//					break;
//				case 2:
//					if (true) {
//						system("cls");
//						Respaldo respaldo("respaldoTransacciones.txt");
//						respaldo.obtenerNombreRespaldo(3);
//						system("pause");
//						menuTeclas();
//					}
//					break;
//				case 3:
//					system("cls");
//					cout << endl << "<<<<<<<<<Proceso Cancelado>>>>>>>>>" << endl;
//					Sleep(1000);
//					menuTeclas();
//					break;
//				}
//			}
//
//		}
//	}
//}