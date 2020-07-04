#include "Operaciones.h"
#include <iostream>
#include <ctime>

using namespace std;

void Operaciones::retraso() {
	int* arr;
	arr = (int*)malloc(999999 * sizeof(int));
	for (int i = 0; i < 999999; i++)
	{
		*(arr + i) = i;
	}
}

void Operaciones::ejecutar(int n) {
	unsigned t1=0, t2=0;
	double time;
	t1 = clock();
	retraso();
	cout << n << endl;
	t2 = clock();
	time = (double(t2 - t1) / CLOCKS_PER_SEC);
	cout << time << " segundos" << endl;
	cout << endl;
}
