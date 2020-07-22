#include <stdio.h>
#include <stdlib.h>
#include "Random.h"
#include <iostream>
using namespace std;

class Objeto
{
public: 
	//char** nombre;
	int* peso;
	int* valor;
	float* valorPorGramo;
	int* cantidad;
	int dimension=0;
	int pesoT=0;
	int cObjetos=0;

public:
	Objeto(int);
	void llenar(Random);
	void calcularPeso();
	void ordenarPeso(int);
	int moverDato(int, float);
	void valorOptimo(int, float);
	void encerar();
	void imprimir();
};



