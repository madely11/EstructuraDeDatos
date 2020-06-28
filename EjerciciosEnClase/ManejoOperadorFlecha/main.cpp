#include <iostream>
#include "Vector.h"
#define dim 5

int main(int argc, char** argv) {
	int *ptr;
	ptr=(int*)malloc(dim*sizeof(int));
	//ptr=new int [dim];
	Vector<int> vector =Vector<int>();
	vector.ingresarV(ptr,dim);
	vector.imprimirV(ptr,dim);
	vector.procesar(vector,dim);
	vector.imprimirV(ptr,dim);
	system("pause");
	return 0;
}
