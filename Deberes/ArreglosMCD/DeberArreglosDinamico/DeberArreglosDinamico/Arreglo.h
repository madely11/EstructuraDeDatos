/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* PROGRAMA PARA CALCULAR EL MCM Y MCD DE UN ARREGLO DINÁMICO      *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 01/06/20									  *
* FECHA DE MODIFICACIÓN: 03/06/20								  *
******************************************************************/

#if !defined(__UML_Class_Diagram_3_Arreglo_h)
#define __UML_Class_Diagram_3_Arreglo_h

#include<iostream>
using namespace std;

template <typename tipo> class Arreglo
{
public:
	tipo* getArreglo(void);
	void setArreglo(tipo* newArreglo);
	int getLongitud(void);
	void setLongitud(int newLongitud);
	void encerar();
	void ingresar(int valor);
	void imprimir();
	Arreglo();

private:
	tipo* arreglo;
	int longitud;

};


/**
	@brief Funcion get del Arreglo
	@param void
	@returns arreglo
*/

template <typename tipo>
tipo* Arreglo <tipo> ::getArreglo(void)
{
	return arreglo;
}

/**
	@brief Funcion ser de arreglo
	@param entero puntero arreglo
	@returns arreglo que contiene el nuevo arreglo
*/

template <typename tipo>
void Arreglo<tipo>::setArreglo(tipo* newArreglo)
{
	arreglo = newArreglo;
}

/**
	@brief Funcion encerar
*/
template <typename tipo>
void Arreglo <tipo> ::encerar()
{
	for (int i = 0; i < longitud; i++)
	{
		*(arreglo + i) = 0;
	}
	
}

/**
	@brief Funcion ingresar
	@param valor que representa la cantidad de memoria sseparada para el arreglo
*/
template <typename tipo>
void Arreglo <tipo> :: ingresar(int valor)
{
	longitud++;
	arreglo = (tipo*)realloc(arreglo, longitud * sizeof(tipo));
	*(arreglo + (longitud-1)) = valor;
}

/**
	@brief Funcion imprimir
*/
template <typename tipo>
void Arreglo <tipo> :: imprimir()
{
	for (int i = 0; i < longitud; i++)
	{
		cout << *(arreglo + i) << " ";
	}
	cout << endl;
}


/**
	@brief Funcion get de longitud
	@returns longitud
*/
template <typename tipo>
int Arreglo <tipo> ::getLongitud(void)
{
	return longitud;
}

/**
	@brief Funcion ser para longitud
	@param entero longitud
*/
template <typename tipo>
void Arreglo <tipo> :: setLongitud(int newLongitud)
{
	longitud = newLongitud;
}

/**
	@brief Funcion constrcutor de arreglo
*/

template <typename tipo>
inline Arreglo <tipo>  ::Arreglo()
{
	longitud = 0;
	arreglo = (tipo*) malloc(longitud * sizeof(tipo));
}

#endif
