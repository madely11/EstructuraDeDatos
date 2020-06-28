#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "Matriz.h"
int main()
{
	int d;
	int **mat1, **mat2, **matr;
	Matriz<int> matriz;
	printf("\nIngrese la dimension de la matriz: ");
	scanf("%d",&d);
	

	mat1=matriz.nmatriz(d);
	mat2=matriz.nmatriz(d);
	matr=matriz.nmatriz(d);
	matriz.encerar(matr,d);
	printf("\nIngrese los datos de la matriz 1: ");
	matriz.ingreso(mat1, d);
	printf("\nIngrese los datos de la matriz 2: ");
	matriz.ingreso(mat2, d);
	
	matriz.imprime(mat1, d);
	printf("\n");
	matriz.imprime(mat2, d);
	printf("\n");

	matriz.proceso(mat1,mat2,matr,d);
	matriz.imprime(matr,d);
	system("pause");
   return 0;
}
