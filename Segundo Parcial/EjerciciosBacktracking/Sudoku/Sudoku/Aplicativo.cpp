#include <iostream>
#include "Tablero.h"
using namespace std;

void main() {
	Tablero tab;
	tab.imprimirTablero();
	system("pause");
	free(tab.matriz);
}