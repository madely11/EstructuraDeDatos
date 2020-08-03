#include "Random.h"

Random::Random() {

}

Random::Random(int pMochila) {
	Fecha f;
	if (f.getSegundos() == 1 ) {
		limite = pMochila;
		
	}

	if (f.getSegundos() > pMochila) {
		int valor;
		
		valor = f.getSegundos() - pMochila;
		valor += 1;
		limite = pMochila - (int)((1 + rand() % (valor - 1))/2);
		
	}
	else {
		limite = f.getSegundos();
		
	}
}

int Random::cantidadObjetos() {
	cObjetos = 5 + rand() % (11 - 5);
	
	return cObjetos;
}


int Random::obtenerNumero() {
	int valor = 0;
	//srand(time(NULL));
	valor = 1 + rand() % (limite - 1);
	//cout << "Valor: " << valor + 1 << endl;
	return valor + 1;
}