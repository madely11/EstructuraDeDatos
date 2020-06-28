#include "CProceso.h"
template<typename T>
CProceso<T>::CProceso(T nume,T deno)
{
	this->num=nume;
	this->den=deno;
}
template<typename T>
void CProceso<T>::_setnum(T nume)
{
	num=nume;
}
template<typename T>
T CProceso<T>::_getnum()
{
	return num;
}
template<typename T>
void CProceso<T>::_setden(T deno)
{
	den=deno;
}
template<typename T>
T CProceso<T>::_getden()
{
	return den;
}
template<typename T>
CProceso<T> CProceso<T>::racional(CProceso obj1, CProceso obj2)
{
	T a,b,c,d;
	a=obj1._getnum();
	b=obj1._getden();
	c=obj2._getnum();
	d=obj2._getden();
	this->_setnum((a*d)+(b*c));
	this->_setden(b*d);
	return *this;
}
template<typename T>
void CProceso<T>::imprimeObj(CProceso Obj)
{
	cout<<Obj._getnum()<<"/"<<Obj._getden()<<endl;
}
int main(void)
{
	int a=18,b=3;
	CProceso<int> *obj1 = new CProceso<int>(a,b);
	CProceso<int> *obj2 = new CProceso<int>(15,5);
	CProceso<int> *obj3 = new CProceso<int>(0,0);
	obj3->racional(*obj1,*obj2);
	obj1->imprimeObj(*obj1);
	obj2->imprimeObj(*obj2);
	obj3->imprimeObj(*obj3);
	system("pause");
	return 0;
}
