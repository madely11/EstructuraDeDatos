#include "Nodo.h"
template <typename tipo>
inline Nodo<tipo>::Nodo()
{
}


template <typename tipo>
Nodo* Nodo <tipo>::getSiguiente()
{
	return siguiente;
}

template <typename tipo>
void Nodo <tipo> ::setSiguiente(Nodo* newSiguiente)
{
	siguiente = newSiguiente;
}

template <typename tipo>
inline Nodo <tipo> ::Nodo(tipo newDato, Nodo* newSiguiente)
{
	dato = newDato;
	siguiente = newSiguiente;
}

template <typename tipo>
tipo Nodo<tipo>::getDato(void)
{
	return dato;
}

template <typename tipo>
void Nodo <tipo>::setDato(tipo newDato)
{
	dato = newDato;
}