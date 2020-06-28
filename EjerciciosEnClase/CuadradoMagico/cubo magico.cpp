/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* AUTOR: Fernando Solis                                           *
* NRC: 6396                                                       *
******************************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sstream>
#include "CuboMagico.h"
#include "Ingreso.h"

using namespace std;

int main()
{
	
    int **_cuadrado;
    Ingreso ingreso;
    int num;
   
    string dim;
    do{
    	dim=ingreso.leer("Digite el tamanio del arreglo, solo numeros impares: ",2);
    	istringstream (dim) >> num;
    }while(num%2==0||num<0);
    num=2*num-1;

    _cuadrado=(int**)calloc(num,sizeof(int*));
    for(int i=0;i<num;i++){
        *(_cuadrado+i)=(int*)calloc(num,sizeof(int));
    }
    CuboMagico<int>* cubo= new CuboMagico<int>(_cuadrado);
    
    cubo->llenar(num,num);
    cubo->mostrar(num,num);
    
    system("pause");
    return 0;
}
