#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;
#define TAM 9

class Tablero
{
public:
	int** matriz;
public:
	Tablero();
	bool verificarFila(int**, int, int, int);
	bool verificarColumna(int**, int, int, int);
	bool verificarCuadro(int**, int, int, int);
	bool validarInsertar(int**, int, int, int);
	void imprimirTablero();
	//void llamadaResolver();
	int generarDato();
	void llenarMatriz();
	void resolverTablero(int**, int, int, int, int);
	void encerarFila(int**, int);
};

