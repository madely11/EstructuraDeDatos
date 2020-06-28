#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Elemento.h"

int main(int argc, char** argv) {
	Elemento<int> e;
	e.leer();
	std::cout<<"Tiempo en encontrar el elemento: "<<e.buscarElemento(5)<<std::endl;
	return 0;
}
