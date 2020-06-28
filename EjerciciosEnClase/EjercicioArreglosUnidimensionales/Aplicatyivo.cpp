#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include "Arreglo.h"

int main(int argc, char *argv[])
{
	Arreglo<int> a;
	a.encerar();
	a.imprimir();
	system("pause");
	a.ingresar();
	a.imprimir();
	system("pause");
	a.procesar();
	a.imprimir();
	system("pause");
	return 0;
}
