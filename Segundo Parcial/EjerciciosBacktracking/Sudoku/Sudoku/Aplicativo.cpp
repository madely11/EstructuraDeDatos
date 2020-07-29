#include <iostream>
#include "Tablero.h"
using namespace std;

void main() {
	Tablero tab;
	tab.imprimirTablero();
	free(tab.matriz);
}