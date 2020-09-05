#include <iostream>
#include "Binary_Tree.cpp"
#include "Ingreso.h"


using namespace std;


int main()
{
	Binary_Tree<int> _tree;
	Ingreso ingreso;
	string datoS;
	char opt = 's';
	int dato, cont=1;
	while (opt == 's' || opt == 'S') {
		datoS = ingreso.leer("Ingrese un dato: ", 1);
		dato = atoi(datoS.c_str());
		_tree._add(dato, _tree.get_root(), NULL);
		cout << "Desea ingresar otro dato (S/N): ";
		cin >> opt;
		cout << endl;
		cin.ignore();
	}
	_tree.showTreeGraph(_tree.get_root(), 900, 10, cont);
	_tree.dibujar.ventana->setVisible(true);
	_tree.dibujar.ventana->display();
	system("pause");
	//_tree.dibujar.mostrar();
	return 0;
}