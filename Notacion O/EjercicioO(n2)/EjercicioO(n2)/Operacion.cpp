#include "Operacion.h"
#include <iostream>
#include <ctime>

using namespace std;

void Operacion::retraso() {
	int* arr;
	arr = (int*)malloc(999999 * sizeof(int));
	for (int i = 0; i < 999999; i++)
	{
		*(arr + i) = i;
	}
}

void Operacion::ejecutar(int n) {
	unsigned t1 = 0, t2 = 0;
	double time;
	int* arr;
	int longitud = 0;
	t1 = clock();
	arr = (int*)malloc(longitud * sizeof(int));

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			retraso();
			longitud++;
			arr = (int*)realloc(arr, longitud * sizeof(int));
			*(arr + (longitud - 1)) = i*j;
		}
	}
	t2 = clock();
	cout << n << endl;
	time = (double(t2 - t1) / CLOCKS_PER_SEC);
	cout << time << " segundos" << endl;
	cout << endl;
}
