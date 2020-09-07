#include <iostream>
#include "Menu.h"

using namespace std;
/**
	@brief Funcion para oculta Cursor en la consola
	@param void
	@returns void
*/

void nuevomenu()
{
	cout << "1.Agregar dato" << endl;
	cout << "2.Eliminar dato" << endl;
	cout << "3.Buscar Dato  " << endl;
	cout << "4.Imprimir Arbol " << endl;
	cout << "5.Mostrar profundidad  " << endl;
	cout << "6.Mostrar altura  " << endl;
	cout << "7.Buscar Nivel  " << endl;
	cout << "8.Contar numeros primos   " << endl;
	cout << "9.Salir   " << endl;
}
void Menu::menuTeclas() {
	int dato = 0;
	int cont = 1;
	while (dato != 9) {
		system("cls");
		nuevomenu();
		cout << "Que opcion desea realizar" << endl;
		cin >> dato;
		switch (dato)
		{
		case 1:
			if (true) {
				while (opt == 's' || opt == 'S') {
					datoS = ingreso.leer("Ingrese un dato: ", 1);
					dato = atoi(datoS.c_str());
					_tree._add(dato, _tree.get_root(), NULL);
					cout << "Desea ingresar otro dato (S/N): ";
					cin >> opt;
					cout << endl;
					cin.ignore();
				}
			}
			break;
		case 2:
			if (true) {
				//int dato;
				datoS = ingreso.leer("Ingrese el dato que desea eliminar: ", 1);
				dato = atoi(datoS.c_str());
				_tree._delete(dato, _tree.get_root(), NULL);
				system("pause");
			}
			break;
		case 3:
			if (true) {
				//int dato;
				datoS = ingreso.leer("Ingrese el dato que desea buscar: ", 1);
				dato = atoi(datoS.c_str());
				if (_tree._look(dato, _tree.get_root()) != NULL) {
					cout << "Elmento encontrado: " << dato << endl;
				}
				system("pause");
			}
			break;
		case 4:
			if (true) {
				//_tree.showTree(_tree.get_root(), cont);
				_tree.graphConsole(_tree.get_root(), 900, 10, cont);
				system("pause");
			}
			break;
		case 5:
			if (true) {
				//int dato;
				datoS = ingreso.leer("Ingrese el dato del desea saber la profundidad: ", 1);
				dato = atoi(datoS.c_str());
				dato = _tree.get_lvl(dato, _tree.get_root());
				if (dato != 0) {
					cout << "La profundidad del elemento es: " << dato << endl;
				}
				system("pause");
			}
			break;
		case 6:
			if (true) {
				int altura = _tree.get_height_tree(this->_tree.get_root(), 0, 0);
				cout << "La altura del arbol es: " << altura << endl;
				system("pause");
			}
			break;
		case 7:
			if (true) {
				//int dato;
				datoS = ingreso.leer("Ingrese el dato del desea saber el nivel: ", 1);
				dato = atoi(datoS.c_str());
				dato = _tree.get_lvl(dato, _tree.get_root());
				if (dato != 0) {
					cout << "El nivel del elemento es: " << dato << endl;
				}
				system("pause");
			}
			break;
		case 8:
			if (true) {
				system("cls");
				int dato = _tree.cont_prime(_tree.get_root(), 0);
				cout << "La cantidad de numeros primos es: " << dato << endl;
				system("pause");
			}
			break;
		case 9:
			exit(0);
			break;
		}
	}
}

