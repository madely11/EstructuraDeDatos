#include <stdlib.h>
#include <time.h>
#include "Fecha.h"
#include <iostream>
using namespace std;

class Random
{
private:
	int cObjetos=0;
	int limite=0;
public:
	Random(int);
	Random();
	int cantidadObjetos();
	int obtenerNumero();
};

