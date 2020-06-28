#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#define E 5
typedef int entero;
using namespace std;
template<typename T>class Arreglo;
template<typename T> ostream &operator<< (ostream& salida, Arreglo<T>& z);
template<class T>
class Arreglo{
	public: 
	T v[10];
	public:
	void encerar();
	void ingresar();
	void procesar();
	void imprimir();
};

//desarrollo de la funsión encerar
template<typename T>
void Arreglo<T> :: ingresar(){
	entero val;
	for(entero i=0;i<10;i++){
		cout<<"Valor "<<i+1<<endl;
		cin>>v[i];
	}
}
template<typename T>
void Arreglo<T> :: encerar(){
	for(entero i=0;i<10;v[i]=0,i++);
}
template<typename T>
void Arreglo<T> :: procesar(){
	for(entero i=0;i<10;i++){
  		v[i]*=E;
		//v[i]=v[i]*E;
	}
}
template<typename T>
void Arreglo<T>:: imprimir(){
	for(entero i=0;i<10;i++)
	cout<<v[i]<<", ";
}
