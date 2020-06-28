#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
//#define E 5
//typedef int entero;
using namespace std;
template<typename T>class Arreglo;
template<typename T> ostream &operator<< (ostream& salida, Arreglo<T>& z);
template<class T>
class Arreglo {
public:
T *v;

public:
Arreglo();
void encerar();
void ingresar();
void proceso();
void impresion();
};
template<typename T>
Arreglo<T>::Arreglo (){
	v=(T*)malloc(4*sizeof(T));
}

//desarrollo de la funsión encerar
template<typename T>
void Arreglo<T>::ingresar(){
	//cout << "Hola" << endl;
	for(int i=0;i<10;i++){
		cout<<"Valor "<<i+1<<endl;
		//scanf("%d",*(&v)+i);
		cin>>*(v+i);
	}
}
template<typename T>
void Arreglo<T>::encerar(){
	for(int i=0;i<10;*(v+i)=0,i++);
}
template<typename T>
void Arreglo<T>::proceso(){
	for(int i=0;i<10;i++){
  		*(v+i)=*(v+i)*2;
  		
		//v[i]=v[i]*E;
	}
}
template<typename T>
void Arreglo<T>::impresion(){
	for(int i=0;i<10;i++){
		printf("%d, ",*(v+i));
	}
	cout<< endl;
	//cout<<v[i]<<", ";
}	

