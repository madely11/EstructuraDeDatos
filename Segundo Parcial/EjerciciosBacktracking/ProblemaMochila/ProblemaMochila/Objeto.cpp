#include "Objeto.h"

#define longitud 10

Objeto::Objeto(int pMochila) {
	srand(time(NULL));
	Random rand(pMochila); //Se define el valor límite para hacer el random de peso y valor 
	pesoT = pMochila;
	cObjetos = rand.cantidadObjetos();
	dimension = cObjetos;
	peso = (int*)malloc(dimension * sizeof(int));
	valor = (int*)malloc(dimension * sizeof(int));
	valorPorGramo = (float*)malloc(dimension * sizeof(float));
	cantidad = (int*)malloc(dimension * sizeof(int));
	encerar();
	llenar(rand);
}

void Objeto::encerar()
{
	for (int i = 0; i < dimension; i++)
	{
		*(cantidad + i) = 0;
	}
}

void Objeto::llenar(Random rand) {
	
	for (int i = 0; i < dimension; i++)
	{
		*(peso + i) = rand.obtenerNumero();
		*(valor + i) = rand.obtenerNumero();
	}
	cout << "LLENO " << endl;
	imprimir();
	//calcularPeso();
}

void Objeto::calcularPeso() {
	for (int i = 0; i < dimension; i++)
	{
		*(valorPorGramo + i) = (float)*(valor + i) / (float)*(peso + i);
	}
	int i = 1;
	ordenarPeso(i);
}

void Objeto::ordenarPeso(int i) {
	int j = 0, auxP=0, auxV=0;
	float aux=0;
	if (i < dimension) {
		aux = *(valorPorGramo + i);
		auxP = *(peso + i);
		auxV = *(valor + i);

		j = moverDato(i, aux);
		
		*(valorPorGramo + j) = aux;
		*(peso+ j) = auxP;
		*(valor + j) = auxV;
		i++;
		ordenarPeso(i);
	}
}

int Objeto::moverDato(int j, float aux)
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

 
void Objeto::valorOptimo(int posicion, float s) {
	if (posicion < dimension) {
		for (int i = 1; s < pesoT; i++)
		{
			s += (*(peso + posicion));
			//cout << "Suma: " << s << endl;
			if (s <= pesoT) {
				*(cantidad + posicion) = i;
			}
			else {
				s -= *(peso + posicion);
				posicion += 1;
				valorOptimo(posicion, s);
			}
		}
	}
}


	


void Objeto::imprimir() {
	float suma=0;
	for (int i = 0; i < dimension; i++)
	{
		cout << endl;
		//cout << "Objeto numero: " << i + 1 << "     peso: " << *(peso + i) << "      valor: " << *(valor + i) << "      valor/gramo: " << *(valorPorGramo + i);
		cout << "Se necesita "<< *(cantidad + i) << " objetos de valor " << *(valor+i ) << " con peso " << *(peso + i) << endl;
		suma += *(cantidad + i) * *(peso + i);
	}
	cout << "Suma " << suma << endl;
	cout << endl;
}


	