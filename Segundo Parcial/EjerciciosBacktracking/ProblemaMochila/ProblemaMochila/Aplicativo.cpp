#include <iostream>
#include <sstream>
#include<stdio.h>
#include "Objeto.h"
#include "Ingreso.h"

using namespace std;

void main() {
	Ingreso ingreso;
	string dim;
	int pMochila=0, cObjetos=0, posicion = 0, i =0;
	float s=0;
	dim = ingreso.leer("Ingrese el peso de la mochila: ", 1);
	istringstream(dim) >> pMochila;
	fflush(stdin);
	Objeto <int, float> obj(pMochila);
	obj.calcularPeso();
	obj.valorOptimo(posicion, s);
	obj.imprimir();
	

	free(obj.peso);
	free(obj.valor);
	free(obj.valorPorGramo);
	free(obj.cantidad);
}
