#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
class Orden
{
public:
	void retraso();
	void ejecutar(int);
};


using namespace std;

void Orden::retraso() {
    int* arr;
	arr = (int*)malloc(999999 * sizeof(int));
	for (int i = 0; i < 999999; i++)
	{
		*(arr + i) = i;
	}
    
}

void Orden::ejecutar(int n) {
	clock_t tmI=0, tmF=0;
	double tiempo;
	tmI = clock();
	 int* arr;
	arr = (int*)malloc(999999 * sizeof(int));
	
	for (int i = 0; i < n; i++)
	{
		retraso();
		*(arr + i) = i;
	}
	cout << n << endl;
    tmF = clock();
	tiempo = (double)((double)(tmF - tmI) / CLOCKS_PER_SEC);
	cout << tiempo << " segundos" << endl;
	cout << endl;
}

