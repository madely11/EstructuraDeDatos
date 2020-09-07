/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* APLICATIVO DEL PROGRAMA                                         *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 04/07/20									  *
* FECHA DE MODIFICACIÓN: 09/07/20								  *
******************************************************************/
#include<cstdio>
#include<cstdlib>
#include"Biselado.h"
#include "Ingreso.h"
using namespace std;

int main()
{
	Biselado arbol;
	int cont = 1;
	Ingreso ingreso;
	string datoS;
	char opt = 's';
	int dato = 0;
	while (dato != 4) {
		system("cls");
		cout << "1.Agregar dato" << endl;
		cout << "2.Eliminar dato" << endl;
		cout << "3.Mostrar arbol" << endl;
		cout << "4.Salir" << endl;
		cout << "Que opcion desea realizar" << endl;
		cin >> dato;
		switch (dato)
		{
		case 1:
			while (opt == 's' || opt == 'S') {
				//system("cls");
				//cin.ignore();
				datoS = ingreso.leer("Ingrese un dato: ", 1);
				dato = atoi(datoS.c_str());
				arbol.insertar(dato);
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
			arbol.borrar(dato);
			system("pause");
			break;
		case 3:
			arbol.dibujar.ventana->clear();
			arbol.showTreeGraph(arbol.raiz, 900, 10, 1);
			arbol.dibujar.ventana->setVisible(true);
			arbol.dibujar.ventana->display();
			break;
		}
	}
	//while (true)
	//{
	//	int t;
	//	scanf_s("%d", &t);
	//	if (t != 0 && t != -1) arbol.insertar(t);
	//	else if (t == 0)
	//	{
	//		scanf_s("%d", &t);
	//		if (!arbol.buscar(t))
	//			printf("Couldn't buscar %d!\n", t);
	//		else
	//			printf("Found %d!\n", t);
	//	}
	//	else
	//	{
	//		scanf_s("%d", &t);
	//		if (arbol.borrar(t))
	//			printf("Deleted %d!\n", t);
	//		else
	//			printf("Couldn't buscar %d!\n", t);
	//	}
	//	if (arbol.raiz) printf("raiz: %d\n", arbol.raiz->valor);
	//	//Inorder(raiz);
	//	arbol.mostrar(arbol.raiz, cont);
	//}
}

