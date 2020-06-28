#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include <cstdlib>
#include <iostream>

using namespace std;
template<typename T>class Matriz;
template<typename T> ostream &operator<< (ostream& salida, Matriz<T>& z);
template<class T>
class Matriz{
public:
void ingreso(T **mat, int t);
void imprime(T **mat, int t);
void proceso(T **mat1, T **mat2,T **matr, int t);	
void encerar(T ** m,int d);

T **nmatriz(int d);
};



//FUNCION PARA INGRESAR LOS DATOS DE LA MATRIZ
template<typename T>
void Matriz<T>::ingreso(T **mat, int t)
{
	for(int i=0;i<t;i++)
		for(int j=0;j<t;j++)
			scanf("%d",&(*(*(mat+i)+j)));
}

//FUNCION PARA CALCULAR MULTIPLICACION DE MATRICES
template<typename T>
void Matriz<T>::proceso(T **mat1, T **mat2,T **matr, int t)
{
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++){
			for(int h=0;h<t;h++){
				*(*(matr+i)+j)=*(*(matr+i)+j)+(*(*(mat1+i)+h))*(*(*(mat2+h)+j));
			}

		}
	}
}

//FUNCION IMPRESION DATOS DE LA MATRIZ
template<typename T>
void Matriz<T>::imprime(T **mat, int t)
{
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++)
		{
			printf("%d",*(*(mat+i)+j));
			printf("%*s",j+5,"");
		}
	printf("\n");
	}
}
template<typename T>
T** Matriz<T>::nmatriz(int d)
{
    int **m , j;
    m =(int **)malloc(d*sizeof(int *));
    for(j=0;j<d;j++)
        *(m+j)=(int *)malloc(d*sizeof(int));
    return m;
}
template<typename T>
void Matriz<T>::encerar(T ** m,int d)
{
    int i, j;
    for(i=0;i<d;i++)
        for(j=0;j<d;j++)
            *(*(m+i)+j)=0;
    
}



