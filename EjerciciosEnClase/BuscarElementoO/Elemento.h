#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define TAM 10
using namespace std;
template<typename T>class Elemento;
template<typename T> ostream &operator<< (ostream& salida, Elemento<T>& z);
template<class T>
class Elemento{
	public:
	T A[TAM];
	int i;
	public:
	void leer();
	float buscarElemento(T);
};
template<typename T>
void Elemento<T> ::leer(){
	for(i=0;i< TAM;i++){
		std::cout<<"Ingrese el valor "<<i+1<<std::endl;
		std::cin>>A[i];
	}
}
template<typename T>
float Elemento<T> ::buscarElemento(T x){
	int i, p=0,sw=0;
	float n;
	n=(float)TAM;
	for(i=0;i< TAM;i++){
		if(A[i]==x){
			p=i;
			sw=1;
			break;
		}
	}
	if(sw==0){
		cout<<"dato no encontrado"<<endl;
		p=TAM;
	}
	n=(float)p*(p+1)/(2*p);
	return n;
}

