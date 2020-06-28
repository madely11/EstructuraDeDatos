/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC:                                                            *
******************************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include "conio.h"
#include <sstream>
using namespace std;
template<class T>
class CuboMagico{
private:
  T** cuadrado;
public:
    CuboMagico(T**);
    CuboMagico();
    void llenar(int,int);
    void mostrar(int, int);
    T** getCuboMagicoCuadrado();
    void setCuboMagicoCuadrado(T**);

};
template<class T>
inline CuboMagico<T>::CuboMagico(T **_cuadrado){
    CuboMagico::cuadrado=_cuadrado;
}
template<class T>
inline CuboMagico<T>::CuboMagico(){
    
}
template<class T>
T** CuboMagico<T>::getCuboMagicoCuadrado(){
    return cuadrado;
}
template<class T>
void CuboMagico<T>::setCuboMagicoCuadrado(T **_cuadrado){
    cuadrado=_cuadrado;
}

template<class T>
void CuboMagico<T>::llenar(int a,int b){
    int x=0,k=0,p=1,j=0,t=0,s=0,d=0;
        x=(b-1)/2;
        t=((a+1)/2);
        s=(a-x-1)/2;
        d=x;
         for(int g=0; g<((a+1)/2);g++){
            j=g;
            k=g;
        for( int i=x;i>=j;i--){
            *(*(cuadrado+i)+k)=p;
             if( k<(d-s) ){
                *(*(cuadrado+i)+(k+t))=p;
			}
            if(k>(d+s)){
                *(*(cuadrado+i)+(k-t))=p;
            }
            if(i>(d+s)){
                *(*(cuadrado+(i-t))+k)=p;
            }
            if(i<(d-s)){
                *(*(cuadrado+(i+t))+k)=p;
            }

            k++;
            p++;
        }
        x++;
    }
}
template<class T>
void CuboMagico<T>::mostrar(int a,int b){
   system("cls");
    int x=0,t=0,s=0;
        t=((a+1)/2);
        x=(b-1)/2;
        s=(a-x-1)/2;

        for(int l=0;l<a;l++){
                cout<<"\n\t";
            for(int h=0;h<b;h++){
                if(h>=(x-s) && h<=(x+s) && l<=(x+s) && l>=(x-s)){
                    cout<<"\t"<<*(*(cuadrado+l)+h);
                }
        	}
		}
}

