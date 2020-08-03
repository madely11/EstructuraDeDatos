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
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "Lista.h"
#include "Controlador.h"
 /**
	@file Seriente.cpp
	@brief Programa Snake
	@author Madely Betancourt y Kevin Caicedo
	@date 8/2020
*/

int main()
{
	Lista listE;
	Lista *listEn=&listE;
	Controlador contr;
 	int **cuerpo;
 	char com = '@', *com1=&com;
	int n = 1, tam = 10, dir = 3, x = 10, y = 12, xc = 30, yc = 15;
	int *n1=&n, *tam1=&tam, *dir1=&dir, *x1=&x, *y1=&y, *xc1=&xc, *yc1=&yc;
	cuerpo =(int **)malloc(200*sizeof(int *));
    for(int j=0;j<200;j++)
        *(cuerpo+j)=(int *)malloc(2*sizeof(int));
        for(int i=0; i<10; i++){
        	listE.insertar('#'); //cuerpo serpiente
		}
		
 contr.ocultar();
 contr.cuadrado();
 contr.gotoxy(xc, yc); 
 printf("%c", com);
 
 while(tecla != ESC && contr.finJuego(tam1, x1, y1, cuerpo))
 {	
 	contr.borrar(cuerpo, n1);
 	contr.guardarPosicion(n1, tam1, x1, y1, cuerpo);
 	contr.dibujar(tam1, cuerpo, listE.crearLinea());
 	contr.comida(x1, y1, xc1, yc1, tam1, listEn, com1);
 	contr.teclas(dir1);
 	contr.teclas(dir1);
 
 	if(*dir1 == 1) 
	 *y1=*y1-1;
	 
 	if(*dir1 == 2) 
	 *y1=*y1+1;
	 
 	if(*dir1 == 3) 
	 *x1=*x1+1;
	 
 	if(*dir1 == 4) 
	 *x1=*x1-1;
 
 	Sleep(160);
 }
 	contr.cuadrado();
 return 0;
}
