#include <iostream>
#include <stdlib.h>
#define dim 5
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int* arr;
	int num;
	bool verificar=false;
	arr = (int*) malloc(dim*sizeof(int));
	for(int i = 0; i<dim; i++){
		cout << "Ingrese el numero " << i+1 <<" :" ;
		cin >> *(arr+i);
	}
	cout << endl;
	cout <<"Ingrese el numero a buscar: ";
	cin >> num;
	for(int i = 0; i<dim; i++){
		if(*(arr+i) == num){
			cout << "Existe un numero igual en el arreglo";
			verificar = true;
			i = dim;
		}
	}
	
	if(!verificar){
		cout << "No existe un numero igual en el arreglo";
	}
	
	return 0;
}
