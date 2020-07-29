
/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* PROGRAMA PARA CONVERTIR EN MAYUSCULAS O MINUSCULAS              *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/07/20									  *
* FECHA DE MODIFICACIÓN: 28/07/20								  *
******************************************************************/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;


/**
	@file Letras.h
	@brief Clase que contiene metodos para convertir de minusculas a mayusculas y viceversa
	@author Madely Betancourt y Kevin Caicedo
	@date 7/2020
*/

class Letras{
	public:
		void convertirMinus();
		void convertirMayus();
};
/**
	@brief Funcion para convertir a mayusculas
	@param void
	@returns void
*/
void Letras::convertirMayus(){
		char caracter;
	cout<<"Convertir a mayusculas ingrese: "<<endl;
	int i = 0;
	char* valor;
	valor = (char*)calloc(30, sizeof(char));
	while ((caracter = getch()) != 13) {
		if (caracter==' ') {
			*(valor + i) = caracter;
			printf("%c", caracter);
			i++;			
		}
		else if(caracter >= 97 && caracter <= 122){
			caracter=caracter^32;
			*(valor + i) =caracter;
			printf("%c", caracter);
			i++;		
		}
		else{
			
			*(valor + i) = caracter;
			printf("%c", caracter);
			i++;			
		}
		
	}
}

/**
	@brief Funcion para convertir a minusculas
	@param void
	@returns void
*/

void Letras::convertirMinus(){
		char caracter;
	cout<<endl<<"Convertir a minusculas ingrese: "<<endl;
	int i = 0;
	char* valor;
	valor = (char*)calloc(30, sizeof(char));
	while ((caracter = getch()) != 13) {
		if (caracter==' ') {
			*(valor + i) = caracter;
			printf("%c", caracter);
			i++;			
		}
		else if(caracter >= 65 && caracter <= 90){
			caracter=caracter|32;
			*(valor + i) =caracter;
			printf("%c", caracter);
			i++;
		}
		else{
			
			*(valor + i) = caracter;
			printf("%c", caracter);
			i++;					
		}
		
	}
}
