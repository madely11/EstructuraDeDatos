#include <iostream>
#include <stdlib.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int* arr;
	int num, dim, cont=0;
	bool verificar = false;
	cout << "Ingrese la dimension del arreglo: ";
	cin >> dim;
	arr = (int*) malloc(dim*sizeof(int));
	for(int i = 0; i<dim; i++){
		cout << "Ingrese el numero " << i+1 <<" :" ;
		cin >> *(arr+i);
	}
	cout << endl;
	cout <<"Ingrese el numero a buscar: ";
	cin >> num;
	for(int i = 0; i<dim; i++){
		cont+=1;
		if(*(arr+i) == num){
			cout << "Numero: " << *(arr+i) << " k: " << cont;
			verificar = true;
			i = dim;
		}
	}
	
	if(!verificar){
		cout << "No existe un numero igual en el arreglo";
	}
	
	return 0;
}
