/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* PROGRAMA QUE RELAIZA EL PROBLEMA DE LAS 8 REINAS                *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/07/20									  *
* FECHA DE MODIFICACIÓN: 28/07/20								  *
******************************************************************/



#include<iostream>
#include<stdio.h>
#include<conio.h>
#include <cstdlib>

/**
	@file Funciones.h
	@brief Clase que contiene metodos para resolver problema de las 8reinas
	@author Madely Betancourt y Kevin Caicedo
	@date 7/2020
*/

using namespace std;
class Reina{
	public:
		bool colocarReina( int,int);
	    bool validarPosicion(int,int ,int);
	    void mostrarReina(int);
	    Reina(int);
	private:
		int** tablero; 
};

/**
	@brief Constructor Clase Reina
	@param Dimension de tabla tipo int
	@returns void
*/
Reina::Reina(int dimension){
	tablero=(int**) calloc (dimension,sizeof(int*));
	for(int i=0;i<dimension;i++){
		*(tablero+i)=(int*) calloc (dimension,sizeof(int));
	}
	
}

/**
	@brief Funcion que coloc a las reina en la posicion correcta
	@param Dimension de tabla tipo int y posicion fila
	@returns bool
*/
bool Reina::colocarReina(int fila, int dimension){
	if(fila==dimension){
		cout<<"La solucion es: "<<endl;
		mostrarReina(dimension);
		return true;
	}
	for(int i=0;i<dimension;i++ ){
		if(!validarPosicion(fila,i,dimension)){
			*(*(tablero+fila)+i)=fila+1;
			//mostrarReina(dimension);
			
			if(colocarReina(fila+1,dimension)){
				return true;
			}
			 *(*(tablero+fila)+i)=0; 
		}
	}
	
	//cout<<"no existe solucion"<<endl;
	
	return false;
}
/**
	@brief Funcion que valida la posicipon donde se desea ubicar la Reina
	@param Dimension de tabla tipo int, posicion columna y posicion fila tipo int
	@returns bool
*/
bool Reina::validarPosicion(int fila , int columna, int dimension){
	
	for(int i=0;i<dimension;i++){
		if(*(*(tablero+fila)+i)!=0||*(*(tablero+i)+columna)!=0){
		return true;}
	}

	for(int c=columna,f=fila;(c>=0)&&(f>=0);c--,f--){
		//cout<<c<<f;
		if(*(*(tablero+f)+c)!=0||*(*(tablero+f)+c)!=0){
	return true;	}
	}
	for(int c=columna,f=fila;(c<dimension)&&(f>=0);c++,f--){
		if(*(*(tablero+f)+c)!=0||*(*(tablero+f)+c)!=0){
	return true;	}
	}
	for(int c=columna,f=fila;(f<dimension)&&(c>=0);f++,c--){
		if(*(*(tablero+f)+c)!=0||*(*(tablero+f)+c)!=0){
	return true;	}
	}
	for(int c=columna,f=fila;(f<dimension)&&(c<dimension);f++,c++){
		if(*(*(tablero+f)+c)!=0||*(*(tablero+f)+c)!=0){
	return true;	}
	}
	return false;
}
/**
	@brief Funcion para mostrar la solucion del problema
	@param Dimension de tabla tipo int
	@returns void
*/
void Reina::mostrarReina(int dimension){
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++)
		{
			printf("%d", *(*(tablero + i) + j));
		}
		printf("\n");
	}
}
