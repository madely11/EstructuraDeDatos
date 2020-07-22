#include <iostream>
#include<stdio.h>
#include "Objeto.h"

using namespace std;

void main() {
	int pMochila=0, cObjetos=0, posicion = 0, i =0;
	float s=0;
	cout << "Ingrese el peso de la mochila: " << endl;
	cin >> pMochila;
	fflush(stdin);
	Objeto obj(pMochila);
	obj.calcularPeso();
	obj.valorOptimo(posicion, s);
	obj.imprimir();
	//free(obj.nombre);

	free(obj.peso);
	free(obj.valor);
	free(obj.valorPorGramo);
	free(obj.cantidad);
}
