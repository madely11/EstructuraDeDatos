#include <iostream>
#include "Operaciones.h"

using namespace std;

int main() {
	Operaciones op;
	op.ejecutar(10);
	op.ejecutar(1000);
	op.ejecutar(100000);
	op.ejecutar(10000000);
	system("pause");
}