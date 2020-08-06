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
					  "Mostrar Pila                ",
					  "Mostrar Datos               ",
					  "Salir                       "
	};
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
				system("cls");
				switch (cursor)
				{
				case 0:
					if (true) {
						nuevaPersona.ingresoDatos();
						if (lista->verificarCedula(nuevaPersona.persona.getCedula())) {
							cout << "Esta cedula ya existe" << endl;
							system("pause");
							system("cls");
							MenuTeclas();
						}
						string ini = nuevaPersona.persona.getNombre().at(0) + nuevaPersona.persona.getApellido();
						nuevaPersona.persona.setCorreo(lista->buscarEmail(ini));
						lista->insertarInicio(nuevaPersona.persona);
						p.insertar(nuevaPersona.persona.getCorreo());
						system("pause");
						system("cls");
						MenuTeclas();
					}
					break;
				case 1:
					if (true) {
						nuevaPersona.ingresoDatos();
						if (lista->verificarCedula(nuevaPersona.persona.getCedula())) {
							cout << "Esta cedula ya existe" << endl;
							system("pause");
							system("cls");
							MenuTeclas();
						}
						string ini = nuevaPersona.persona.getNombre().at(0) + nuevaPersona.persona.getApellido();
						nuevaPersona.persona.setCorreo(lista->buscarEmail(ini));
						lista->insertarFinal(nuevaPersona.persona);
						p.insertar(nuevaPersona.persona.getCorreo());
						system("pause");
						system("cls");
						MenuTeclas();
					}
					break;
				case 2:
					if (true) {
						Ingreso ingreso;
						Validacion validar;
						string dato;
						int pos;
						dato = ingreso.leer("En que posicion desea ingresar el dato: ", 1);
						pos=atoi(dato.c_str());
						nuevaPersona.ingresoDatos();
						if (lista->verificarCedula(nuevaPersona.persona.getCedula())) {
							cout << "Esta cedula ya existe" << endl;
							system("pause");
							system("cls");
							MenuTeclas();
						}
						string ini = nuevaPersona.persona.getNombre().at(0) + nuevaPersona.persona.getApellido();
						nuevaPersona.persona.setCorreo(lista->buscarEmail(ini));
						if (lista->insertarEntre(nuevaPersona.persona, pos)) {
							p.insertar(nuevaPersona.persona.getCorreo());
							system("pause");
							system("cls");
							MenuTeclas();
						}
						else {
							system("pause");
							system("cls");
							MenuTeclas();
						}
						
					}
					break;
				case 3:
					if (true) {
						Ingreso ingreso;
						Validacion validar;
						string dato;
						dato = dato.assign(ingreso.ingresaNumericos("Ingrese la cedula: "), 10);
						while (!validar.cedula(dato)) {
							dato = dato.assign(ingreso.ingresaNumericos("\nIngrese la cedula: "), 10);
						}
						lista->borrar(dato);
						system("pause");
						system("cls");
						MenuTeclas();
					}
					break;
					
				case 4:
					lista->mostrar();
					system("pause");
					system("cls");
					MenuTeclas();
					break;

				case 5:
					cout << "La pila es: " << endl;
					p.imprimir();
					system("pause");
					system("cls");
					MenuTeclas();
					break;

				case 6:
					cout << "La lista es: " << endl;
					lista->mostrar();
					cout << endl;
					cout << endl;
					cout << "La pila es: " << endl;
					p.imprimir();
					system("pause");
					system("cls");
					MenuTeclas();
					break;

				case 7:
					free(lista);
					system("cls");
					cout << endl << "<<<<<<<<<Gracias por usar nuestro programa>>>>>>>>>" << endl;
					exit(1);
					break;
				}
			}
		}
	}
}