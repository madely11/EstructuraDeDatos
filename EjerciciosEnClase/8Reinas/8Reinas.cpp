#include <iostream>
#include <fstream>  
#include "Reina.h"
using namespace std;


int main() {
	int n;
	cout<<"\tCuantas reinas "<<endl;
	cin>>n;
	Reina *obj= new Reina(n);
	obj->solucionReinas();
	cout << "Procesos para llegar a la solucion: "<< obj->contador << endl;
	cout<<"Se creo el archivo solucion.txt"<<endl;	
	return 0;
}













