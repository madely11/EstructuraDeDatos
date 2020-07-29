#include <stdio.h>
#include <stdlib.h>
#include "Random.h"
#include <iostream>
#define longitud 10
using namespace std;

template <typename tipo, typename tipo2> class Objeto
{
public: 
	tipo* peso;
	tipo* valor;
	tipo2* valorPorGramo;
	tipo* cantidad;
	tipo dimension=0;
	tipo pesoT=0;
	tipo cObjetos=0;

public:
	Objeto(int);
	void llenar(Random);
	void calcularPeso();
	void ordenarPeso(tipo);
	int moverDato(tipo, tipo2);
	void valorOptimo(tipo, tipo2);
	void encerar();
	void imprimir();
};

template <typename tipo, typename tipo2>
inline Objeto<tipo, tipo2>::Objeto(int pMochila) {
	srand(time(NULL));
	Random rand(pMochila); //Se define el valor límite para hacer el random de peso y valor 
	pesoT = pMochila;
	cObjetos = rand.cantidadObjetos();
	dimension = cObjetos;
	peso = (tipo*)malloc(dimension * sizeof(tipo));
	valor = (tipo*)malloc(dimension * sizeof(tipo));
	valorPorGramo = (tipo2*)malloc(dimension * sizeof(tipo2));
	cantidad = (tipo*)malloc(dimension * sizeof(tipo));
	encerar();
	llenar(rand);
}

template <typename tipo, typename tipo2>
void Objeto<tipo, tipo2>::encerar()
{
	for (int i = 0; i < dimension; i++)
	{
		*(cantidad + i) = 0;
	}
}

template <typename tipo, typename tipo2>
void Objeto<tipo, tipo2>::llenar(Random rand) {

	for (int i = 0; i < dimension; i++)
	{
		*(peso + i) = rand.obtenerNumero();
		*(valor + i) = rand.obtenerNumero();
	}
}

template <typename tipo, typename tipo2>
void Objeto<tipo, tipo2>::calcularPeso() {
	for (int i = 0; i < dimension; i++)
	{
		*(valorPorGramo + i) = (float)*(valor + i) / (float)*(peso + i);
	}
	int i = 1;
	ordenarPeso(i);
}

template <typename tipo, typename tipo2>
void Objeto<tipo, tipo2>::ordenarPeso(tipo i) {
	int j = 0, auxP = 0, auxV = 0;
	float aux = 0;
	if (i < dimension) {
		aux = *(valorPorGramo + i);
		auxP = *(peso + i);
		auxV = *(valor + i);

		j = moverDato(i, aux);

		*(valorPorGramo + j) = aux;
		*(peso + j) = auxP;
		*(valor + j) = auxV;
		i++;
		ordenarPeso(i);
	}
}

template <typename tipo, typename tipo2>
int Objeto<tipo, tipo2>::moverDato(tipo j, tipo2 aux)
{
	while (j > 0 && aux > * (valorPorGramo + (j - 1)))
	{
		*(valorPorGramo + j) = *(valorPorGramo + (j - 1));
		*(peso + j) = *(peso + (j - 1));
		*(valor + j) = *(valor + (j - 1));
		j--;
	}
	return j;
}

template <typename tipo, typename tipo2>
void Objeto<tipo, tipo2>::valorOptimo(tipo posicion, tipo2 s) {
	//cout << "hola" << endl;
	if (posicion < dimension) {
		for (int i = 1; s < pesoT; i++)
		{
			s += (*(peso + posicion));
			if (s <= pesoT) {
				*(cantidad + posicion) = i;
			}
			else {
				valorOptimo(posicion + 1, s - *(peso + posicion));
			}
		}
	}
}


template <typename tipo, typename tipo2>
void Objeto<tipo, tipo2>::imprimir() {
	float suma = 0;
	for (int i = 0; i < dimension; i++)
	{
		cout << endl;
		//cout << "Objeto numero: " << i + 1 << "     peso: " << *(peso + i) << "      valor: " << *(valor + i) << "      valor/gramo: " << *(valorPorGramo + i);
		cout << "Se necesita " << *(cantidad + i) << " objetos de valor " << *(valor + i) << " con peso " << *(peso + i) << endl;
		suma += *(cantidad + i) * *(peso + i);
	}
	cout << endl;
	cout << "Valor optimizado: " << suma << endl;
	cout << endl;
}







