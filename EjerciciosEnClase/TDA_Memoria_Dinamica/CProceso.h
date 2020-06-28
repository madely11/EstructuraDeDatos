#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
template<typename T>class CProceso;
template<typename T> ostream &operator<< (ostream& salida, CProceso<T>& z);
template<class T>
class CProceso{
private:
	T num,den;

public:
	void _setnum(T);	
	void _setden(T);
	T _getnum();
	T _getden();
	CProceso(T nume, T deno);

	CProceso racional(CProceso obj1, CProceso obj2);
	void imprimeObj(CProceso Obj);
	
};
