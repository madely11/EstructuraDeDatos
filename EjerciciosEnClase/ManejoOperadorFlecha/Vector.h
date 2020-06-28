#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
template<typename T>class Arreglo;
template<typename T> ostream &operator<< (ostream& salida, Arreglo<T>& z);
template<class T>
class Vector
{

	private:
	T *vector;
	public:
		T* getVector();
		Vector();
		void ingresarV(T *, int);
		void imprimirV( T  *, int );
		void procesar(Vector , int);
		Vector(T *ptr);
};
template<typename T>
T* Vector<T>::getVector(){
	return vector;
}
template<typename T>
void Vector<T>::procesar(Vector vec, int dim){
	for(int i=0; i<dim; i++)
	{
		*(vector+i)= *(vec.vector+i) *5;
	}
}
template<typename T>
void Vector<T>::ingresarV(T *vector, int dim)
{
	for(int i=0; i<dim; i++)
	{
		printf("\nINGRESE UN DATO:\t");
		scanf("%d",(vector+i));
		//cin>>*(vector+i);
	}
	this->vector=vector;
}
template<typename T>
void Vector<T>::imprimirV(  T *vector, int dim)
{
	printf("\nDATOS GUARDADOS:\n");
	for(int i=0; i<dim; i++)
	{
	
		printf("%d,",*(vector+i));
	}
}
template<typename T>
Vector<T>::Vector(){

	
}


