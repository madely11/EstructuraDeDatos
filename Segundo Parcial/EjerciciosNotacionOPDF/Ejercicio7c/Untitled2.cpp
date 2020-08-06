#include <iostream>
#include <ctime>
using namespace std;

float dividir(float, float);

int main(int argc, char** argv) {
	unsigned t1=0, t2=0;
	double time;
	float num1, num2, div;
	cout << "Ingrese el numero 1:" ;
	cin >> num1;
	cout << "Ingrese el numero 2:" ;
	cin >> num2;
	t1 = clock();
	div = dividir(num1, num2);
	t2 = clock();
	time = (double(t2 - t1) / CLOCKS_PER_SEC);
	cout << "Suma: " << div << endl;
	cout << time << " segundos" << endl;
	cout << endl;
	system("pause");
	return 0;
}

float dividir(float num1, float num2){
	return num1/num2;
}
