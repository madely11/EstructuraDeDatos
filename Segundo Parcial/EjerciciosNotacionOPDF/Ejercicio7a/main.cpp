#include <iostream>
#include <ctime>
using namespace std;

int sumar(int, int);

int main(int argc, char** argv) {
	unsigned t1=0, t2=0;
	double time;
	int num1, num2, suma;
	cout << "Ingrese el numero 1:" ;
	cin >> num1;
	cout << "Ingrese el numero 2:" ;
	cin >> num2;
	t1 = clock();
	suma = sumar(num1, num2);
	t2 = clock();
	time = (double(t2 - t1) / CLOCKS_PER_SEC);
	cout << "Suma: " << suma << endl;
	cout << time << " segundos" << endl;
	cout << endl;
	return 0;
}

int sumar(int num1, int num2){
	return num1+num2;
}
