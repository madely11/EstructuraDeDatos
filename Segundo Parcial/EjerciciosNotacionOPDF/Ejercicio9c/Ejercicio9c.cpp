#include <iostream>
#include <math.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	long int cantidad;
	int cont=1;
	cout << "Ingrese la cantidad de soporte del recipiente:" << endl;
	cin >> cantidad;
	for(long int i = 3; i<=cantidad;){
		i = pow(i, 3);
		cont+=1;
	}
	cout << "Los segundos que haran falta para que se desborde son: " << cont << endl;
}
