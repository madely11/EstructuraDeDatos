
#include <iostream>
#include "Operacion.h"

using namespace std;

int main() {
	Operacion op;
	op.ejecutar(2);
	op.ejecutar(4);
	op.ejecutar(8);
	op.ejecutar(16);
	system("pause");
}