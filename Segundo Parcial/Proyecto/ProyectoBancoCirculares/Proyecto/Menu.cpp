/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE PARA DEFINIR EL MENU DEL PROGRAMA                         *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
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
					  "Actualizar Cartola        ",
					  "Crear Respaldo            ",
		              "Restaurar archivo         ",
					  "Generar PDF               ",
					  "Salir                     "};
	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 60);
		cout << "                SELECCIONE UNA OPCION         " << endl;
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

		ocultarCursor();

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
					//actualizar cartola 
					if(true){
						system("cls");
						string cuenta;
						int id;
						cuenta = ingreso.leer("Ingrese el numero de cuenta: ", 1);
						id = atoi(cuenta.c_str()); // numero de cuenta
						listaCuentas->llenarCuenta("cuentas.txt");
						if (!listaCuentas->verificarCuenta(id)) {
							cout << "No se encontro la cuenta" << endl;
							system("pause");
							system("cls");
							menuTeclas();
						}
						else {
							system("cls");
							Transacciones t;
							t.imprimirCartola(id);
							system("pause");
						}
						Sleep(2500);
						menuTeclas();
					}
					break;
				case 4:
					//crear respaldo
					if (true) {
						
						system("cls");
						cout << "\n\t\t\t\t Creando respaldo..." << endl;
						Sleep(2000);
						string linea;
						Respaldo archivo("respaldo.txt");
						linea += archivo.nombreRespaldo();
						linea += ",";
						archivo.nombreArchivo = "cliente.txt";
						linea += archivo.crearRespaldo();
						linea += ",";
						archivo.nombreArchivo = "cuentas.txt";
						linea += archivo.crearRespaldo();
						linea += ",";
						archivo.nombreArchivo = "transacciones.txt";
						linea += archivo.crearRespaldo();
						archivo.guardarRespaldo(linea);
						system("cls");
						cout << "\n\t\t\t\tRespaldo creado exitosamente!" << endl;
						Sleep(2500);
						menuTeclas();
					} 
					break;
				case 5:
					//restaurar respaldo
					if (true) {
						
						system("cls");
						cout << "\t\n" << "Respaldos: " << endl << endl;
						Respaldo respaldo("respaldos.txt");
						respaldo.imprimirNombreRespaldo();
						respaldo.ingresarRespaldo();
						system("cls");
						cout << "\n\t\t\t\t Documentos restaurados exitosamente!" << endl;
						Sleep(2500);
						menuTeclas();
					}
					break;
				case 6:
					//generar pdf
					if (true) {
						
						remove("documentoPDF.pdf");
						system("cls");
						Transacciones t;
						t.generarPdf();
						cout << endl << "\t\t\t Documento PDF creado exitosamente!" << endl;
						Sleep(2500);
						menuTeclas();
					}
						break;
				case 7:
					if (true) {
						
						delete(listaCliente);
						delete(listaCuentas);
						delete(listaTrans);
						system("cls");
						cout << endl << "\n\t\t\t\t\t\t\t\t Gracias!" << endl;
						Sleep(2500);
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
						system("cls");
						cout << cliente.stringConsola();
						cout << endl;
						listaCliente->llenarLista("cliente.txt");
						Sleep(2500);
						system("pause");
						menuTeclas();
					}
					break;
				case 1:
					if (true) {
						system("cls");
						Cliente cliente;
						cliente.pedirDatos(2);
						system("cls");
						cout << endl << "\n\t\t\t\t\Cuenta creada exitosamente!" << endl;
						cout << cliente.stringConsola();
						cout << endl;
						listaCliente->llenarLista("cliente.txt");
						listaCliente->mostrar();
						Sleep(2500);
						system("pause");
						menuTeclas();
					}
					break;
				case 2:
					if (true) {
						system("cls");
						cout << endl << "\n\t\t\t\t\Proceso Cancelado!" << endl;
						Sleep(2500);
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
						string cuenta;
						int id;
						cuenta = ingreso.leer("Ingrese el numero de cuenta: ", 1);
						id = atoi(cuenta.c_str()); // numero de cuenta
						listaCuentas->llenarCuenta("cuenta.txt");
						if (!listaCuentas->verificarCuenta(id)) {
							cout << "No se encontro la cuenta" << endl;
							Sleep(2500);
							menuTeclas();
						}
						else {
							Cuenta cuenta;
							cuenta.realizarTransaccion(1, id);
							delete(listaCuentas);
							listaCuentas = new Lista();
							cout << "Transacción realizada con éxito!" << endl;
							listaCuentas->llenarCuenta("cuenta.txt");
						}
						Sleep(2500);
						menuTeclas();
					}
					break;
				case 1:
					if (true) {
						system("cls");
						string cuenta;
						int id;
						cuenta = ingreso.leer("Ingrese el numero de cuenta: ", 1);
						id = atoi(cuenta.c_str());
						listaCuentas->llenarCuenta("cuenta.txt");
						if (!listaCuentas->verificarCuenta(id)) {
							cout << "No se encontro la cuenta" << endl;
							system("pause");
							menuTeclas();
						}
						else {
							Cuenta cuenta;
							cuenta.realizarTransaccion(2, id);
							delete(listaCuentas);
							listaCuentas = new Lista();
							listaCuentas->llenarCuenta("cuenta.txt");
						}
						Sleep(2500);
						menuTeclas();
					}
					break;
				case 2:
					if (true) {
						system("cls");
						cout << endl << "\n\t\t\t\t\Proceso Cancelado!" << endl;
						Sleep(2500);
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
	system("cls");
	string cuenta;
	int id;
	cuenta = ingreso.leer("Ingrese el numero de cuenta: ", 1);
	id = atoi(cuenta.c_str()); // numero de cuenta
	int cursor = 0;
	char tecla;
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
						listaCuentas->llenarCuenta("cuenta.txt");
						if (!listaCuentas->verificarCuenta(id)) {
							cout << "No se encontro la cuenta" << endl;
							system("pause");
							menuTeclas();
						}
						listaTrans->llenarTrans("transacciones.txt");
						if (!listaTrans->verificarTransaccion(cuenta)) {
							cout << "La cuenta no ha realizado ninguna transaccion" << endl;
							system("pause");
							menuTeclas();
						}
						else {
							Transacciones t;
							t.datosTransaccion(id, 1);
							system("pause");
						}
						Sleep(2500);
						menuTeclas();
					}
					break;
				case 1:
					if (true) {
						system("cls");
						Transacciones t;
						t.datosTransaccion(id, 2);
						Sleep(2500);
						menuTeclas();
					}
					break;
				case 2:
					if (true) {
						system("cls");
						cout << endl << "\n\t\t\t\t\Proceso Cancelado!"  << endl;
						Sleep(2500);
						menuTeclas();
					} 
					break;
				}
			}
		}
	}
}
