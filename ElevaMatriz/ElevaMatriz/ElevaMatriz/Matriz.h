/***********************************************************************
 * Module:  Matriz.h
 * Author:  Kevin Caicedo, Madely Betancourt
 * Modified: martes, junio 02, 2020 8:09:21 AM
 * Purpose: Declaration of the class Matriz
 ***********************************************************************/
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Ingreso.h"
#include <sstream>
using namespace std;

template<typename T> class Matriz;
template<typename T> ostream &operator<< (ostream& salida, Matriz<T>& z);
template<class T>
class Matriz
{
public:
	int getDimension(void);
	void setDimension(int nuevaDimension);
	T** getMatriz(void);
	void setMatriz(T** nuevaMatriz);
	void encerar(T** mat, int dimension);
	void igualar(T** mat1, T** mat2, int dimension);
	T** instanciar(int dimension);
	void imprimir(Matriz mat1);
	void ingresar(Matriz mat);
	Matriz(T** matriz, int dimension);
	Matriz();
	void elevar(Matriz mat1, Matriz mat2, int exponente);

protected:
private:	
	T** matriz;
	int dimension;


};
//Obten dimension
template<typename T>
int Matriz<T>::getDimension(void)
{
	return dimension;
}
//Cambia dimension
template<typename T>
void Matriz<T>::setDimension(int newDimension)
{
	dimension = newDimension;
}
//Obtener matriz 
template<typename T>
T** Matriz<T>::getMatriz(void)
{
	return matriz;
}
//Cambiar matriz
template<typename T>
void Matriz<T>::setMatriz(T** newMatriz)
{
	matriz = newMatriz;
}
// LLenar matriz
template<typename T>
void Matriz<T>::encerar(T** mat, int dimension)
{
	int i, j;
	for (i = 0; i < dimension; i++)
		for (j = 0; j < dimension; j++)
			*(*(mat + i) + j) = 0;
	return;
}
//Iguala matriz
template<typename T>
void Matriz<T>::igualar(T** mat1, T** mat2, int dimension)
{
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++)
		{
			*(*(mat1 + i) + j) = *(*(mat2 + i) + j);
		}

	}
}

// Instanciar matriz
template<typename T>
T** Matriz<T>::instanciar(int dimension)
{
	T** m;
	int j;
	m = (int**)malloc(dimension * sizeof(int*));
	for (j = 0; j < dimension; j++)
		*(m + j) = (int*)malloc(dimension * sizeof(int));
	return m;
}
//Imprimir la matriz
template<typename T>
void Matriz<T>::imprimir(Matriz mat1)
{
	for (int i = 0; i < mat1.dimension; i++) {
		for (int j = 0; j < mat1.dimension; j++)
		{
			printf("%d", *(*(mat1.matriz + i) + j));
			printf("%*s", j + 5, "");
		}
		printf("\n");
	}
}
//Ingrese los datos de la matriz 
template<typename T>
void Matriz<T>::ingresar(Matriz mat)
{
	Ingreso ingreso;
	int num;
	string dim;
	for (int i = 0; i < mat.dimension; i++) {
		for (int j = 0; j < mat.dimension; j++)
		{
			dim = ingreso.leer(" ", 1);
			istringstream(dim) >> num;
			*(*(mat.matriz + i) + j) = num;
		}
	}
}

//Constructor
template<typename T>
inline Matriz<T>::Matriz(T** _matriz, int _dimension)
{
	_matriz = instanciar(_dimension);
	Matriz::matriz = _matriz;
	Matriz::dimension = _dimension;

}
//Constructor
template<typename T>
inline Matriz<T>::Matriz()
{
}
//Funcion para elevar la matriz 
template<typename T>
void Matriz<T>::elevar(Matriz mat, Matriz matr, int exponente)
{

	T** mat2;
	mat2 = instanciar(mat.dimension);
	encerar(mat2, mat.dimension);
	igualar(mat2, mat.matriz, mat.dimension);
	if (exponente == 0) {
			for (int i = 0; i < mat.dimension; i++) {
				for (int j = 0; j < mat.dimension; j++) {
					*(*(matr.matriz + i) + j) = 1;	
				}
			}
	}
	else{
		for (int l = 0; l < exponente - 1; l++)
		{
			encerar(matr.matriz, mat.dimension);
			for (int i = 0; i < mat.dimension; i++) {
				for (int j = 0; j < mat.dimension; j++) {
					for (int h = 0; h < mat.dimension; h++) {
						*(*(matr.matriz + i) + j) = *(*(matr.matriz + i) + j) + (*(*(mat.matriz + i) + h)) * (*(*(mat2 + h) + j));
					}
				}
			}encerar(mat2, mat.dimension);
			igualar(mat2, matr.matriz, mat.dimension);

		}
	}
		
	
}

