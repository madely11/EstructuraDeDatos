// ArbolAVL.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include"Ingreso.h"
#include"AVL.cpp"


void nuevomenu();
int main()
{
	AVL<int> _tree;
	Ingreso ingreso;
	string datoS;
	char opt = 's';
	int dato=1;
	while (dato != 4) {
		system("cls");
		nuevomenu();
		cout << "Que opcion desea realizar" << endl;
		cin >> dato;
		switch (dato)
		{
			case 1:
				while (opt == 's' || opt == 'S') {
					system("cls");
					datoS = ingreso.leer("Ingrese un dato: ", 1);
					dato = atoi(datoS.c_str());
					_tree.Insertar(dato);
					cout << "Desea ingresar otro dato (S/N): ";
					cin >> opt;
					cout << endl;
					cin.ignore();
				}
				break;

			case 2:
				system("cls");
				int dato;
				datoS = ingreso.leer("Ingrese el dato que desea eliminar: ", 1);
				dato = atoi(datoS.c_str());
				_tree.Borrar(dato);
				system("pause");
				break;
			case 3:
				_tree.dibujar.ventana->clear();
				_tree.showTreeGraph(_tree.getRaiz(), 900, 10, 1);
				_tree.dibujar.ventana->setVisible(true);
				_tree.dibujar.ventana->display();
				break;
		}
	}
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

void nuevomenu()
{
	cout << "1.Agregar dato" << endl;
	cout << "2.Eliminar dato" << endl;
	cout << "3.Mostrar arbol" << endl;
	cout << "4.Salir" << endl;
}
