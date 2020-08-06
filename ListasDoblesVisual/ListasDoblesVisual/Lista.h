#include"Nodo.h"
using namespace std;
template<class T>
class Lista {
public:
	Lista();
	void nodoPosicion(int pos);
	void insertarEntre(T dato, int pos);
	void insertarInicio(T dato);
	void insertarFinal(T dato);
	void borrar(T dato);
	bool listaVacia();
	void mostrar();
	void nodoSiguiente();
	void nodoAnterior();
	void primerNodo();
	void ultimoNodo();
	//bool Actual() { return lista != NULL; }
	//int ValorActual() { return lista->valor; }

private:
	Nodo<T>* lista;
};
