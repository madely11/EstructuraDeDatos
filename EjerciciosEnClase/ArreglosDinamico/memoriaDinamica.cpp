
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include "Arreglo.h"

int main(int argc, char *argv[])
{
	//int v[10];
	//int *v=new int[10];
	Arreglo<int> v;
	v.encerar();
	//v.impresion();
	
	v.ingresar();
	v.impresion();
	//system("pause");
	v.proceso();
	v.impresion();
	//system("pause");
	//delete(v);
	//free(v);
	return 0;
}
