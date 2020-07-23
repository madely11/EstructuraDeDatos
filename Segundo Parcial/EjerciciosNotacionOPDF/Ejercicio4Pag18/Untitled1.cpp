#include <iostream>
#include <stdlib.h>
#define dim 5
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int busquedaInterpolada(int*, int);

int main(int argc, char** argv) {
	int* arr;
	int num, resultado;
	bool verificar=false;
	arr = (int*) malloc(dim*sizeof(int));
	for(int i = 0; i<dim; i++){
		cout << "Ingrese el numero " << i+1 <<" :" ;
		cin >> *(arr+i);
	}
	cout << endl;
	cout <<"Ingrese el numero a buscar: ";
	cin >> num;
	
	resultado = busquedaInterpolada(arr, num);
	cout << endl;
	if(resultado != -1){
		cout << "El resultado es: " << *(arr+resultado) << " y se encuentra en la posicion: " << resultado+1;
	}
	else{
		cout << "No se han encontrado resultados!";
	}
	return 0;
}

int busquedaInterpolada(int* arr, int num){
	int min=0, max = dim-1, medio;
	while(*(arr+min) < num && *(arr+max) >= num){
		medio = min + ((num - *(arr+min)) * (max-min) ) / (*(arr+max) - *(arr+min));
		if(*(arr+medio) < num)
			min = medio+1;
		else if(*(arr+medio) > num)
			max = medio-1;
		else 
			return medio;
	}
	
	if(*(arr+min) == num)
		return min;
	else 
		return -1;
}
