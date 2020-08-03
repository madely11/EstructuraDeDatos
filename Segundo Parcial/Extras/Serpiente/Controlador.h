/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* PROGRAMA DEL JUEGO DE SNAKE                                     *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 23/07/20									  *
* FECHA DE MODIFICACIÓN: 02/08/20								  *
******************************************************************/
#pragma once
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "Lista.h"

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
#define ESC 27

char tecla;
class Controlador{
	public:
		void gotoxy(int, int);
		void ocultar();
		void cuadrado();
		void guardarPosicion(int*, int*, int*, int*, int**);
		void dibujar(int*, int**, char*);
		void borrar(int**, int*);
		void teclas(int*);
		void comida(int*, int*, int*, int*, int*, Lista*, char*);
		bool finJuego(int*, int*, int*, int**);
};

 
void Controlador::gotoxy(int x, int y) { 
 HANDLE hCon; 
 COORD dwPos; 
 
 dwPos.X = x; 
 dwPos.Y = y; 
 hCon = GetStdHandle(STD_OUTPUT_HANDLE); 
 SetConsoleCursorPosition(hCon,dwPos); 
}

void Controlador::ocultar() {
 CONSOLE_CURSOR_INFO cci = {100, FALSE};
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void Controlador::cuadrado(){ 
 for(int i=2; i < 78; i++){
 	gotoxy (i, 3); printf ("%c", 205);
 	gotoxy(i, 23); printf ("%c", 205); 
 }
 for(int v=4; v < 23; v++){
 	gotoxy (2,v); printf ("%c", 186);
 	gotoxy(77,v); printf ("%c", 186); 
 }
 gotoxy (2,3); printf ("%c", 201);
 gotoxy (2,23); printf ("%c", 200);
 gotoxy (77,3); printf ("%c", 187);
 gotoxy(77,23); printf ("%c", 188); 
 }

void Controlador::guardarPosicion(int *n, int *tam, int *x, int *y, int **cuerpo ){
 *(*(cuerpo+*n)+0) = *x;
 *(*(cuerpo+*n)+1) = *y;
 *n+=1;
 if(*n == *tam) 
 	*n = 1;
}

void Controlador::dibujar(int *tam, int **cuerpo, char* line){	
 for(int i = 1; i < *tam-1; i++){
 	gotoxy(*(*(cuerpo+i)+0) , *(*(cuerpo+i)+1));
	printf("%c",line[i-1]);
 }
}

void Controlador::borrar(int **cuerpo, int *n){
 	gotoxy(*(*(cuerpo+*n)+0) , *(*(cuerpo+*n)+1)); 
 	printf(" ");
}

void Controlador::teclas(int *dir){
 if(kbhit()){
 	tecla = getch();
 	switch(tecla){
 		case ARRIBA : if(*dir != 2) *dir = 1; break;
 		case ABAJO : if(*dir != 1) *dir = 2; break;
 		case DERECHA : if(*dir != 4) *dir = 3; break;
 		case IZQUIERDA : if(*dir != 3) *dir = 4; break;
 	}
 }
}

void Controlador::comida(int *x, int *y, int *xc, int *yc, int *tam, Lista *listE, char *com){
 if(*x == *xc && *y == *yc){	
 	srand (time(NULL));
 	listE->insertar('#');
 	*xc = (rand() % 73) + 4;
 	*yc = (rand() % 19) + 4;
 	*com = '@';
 	*tam=*tam+1;
 	gotoxy(*xc, *yc); 
	printf("%c", *com);
 }
}

bool Controlador::finJuego(int *tam, int *x, int *y, int** cuerpo){
 if(*y == 3 || *y == 23 || *x == 2 || *x == 77) 
 	return false;
 for(int j = *tam - 1; j > 0; j--){
 	if(*(*(cuerpo+j)+0) == *x && *(*(cuerpo+j)+1) == *y)
 	return false;
 }
 return true;
}

 
