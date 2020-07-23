#include <iostream>
#include <math.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int euros, cont;
	cout << "Ingrese la cantidad de euros:" << endl;
	cin >> euros;
	for(int i = 2; i<=euros;){
		i = pow(i, 2);
		cont+=1;
	}
	cout << "Se necesitaran " << cont << " dias" << endl;
}
