#include <iostream>
#include <ctime>
using namespace std;

int multiplicar(int, int);

int main(int argc, char** argv) {
	unsigned t1=0, t2=0;
	double time;
	int num1, num2, multi;
	cout << "Ingrese el numero 1:" ;
	cin >> num1;
	cout << "Ingrese el numero 2:" ;
	cin >> num2;
	t1 = clock();
	multi = multiplicar(num1, num2);
	t2 = clock();
	time = (double(t2 - t1) / CLOCKS_PER_SEC);
	cout << "Multiplicacion: " << multi << endl;
	cout << time << " segundos" << endl;
	cout << endl;
	system("pause");
	return 0;
	
}

int multiplicar(int num1, int num2){
	return num1*num2;
}
