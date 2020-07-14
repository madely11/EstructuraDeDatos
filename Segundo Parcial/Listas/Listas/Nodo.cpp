#include "Nodo.h"
template <typename tipo, typename tipo2>
inline Nodo<tipo, tipo2>::Nodo()
{
}


template <typename tipo, typename tipo2>
tipo2* Nodo <tipo, tipo2>::getSiguiente()
{
	return siguiente;
}

template <typename tipo, typename tipo2>
void Nodo <tipo, tipo2> ::setSiguiente(tipo2* newSiguiente)
{
	siguiente = newSiguiente;
}

template <typename tipo, typename tipo2, tipo2>
inline Nodo <tipo, tipo2> ::Nodo(tipo newDato, tipo2* newSiguiente)
{
	dato = newDato;
	siguiente = newSiguiente;
}

template <typename tipo, typename tipo2>
tipo Nodo<tipo, tipo2>::getDato(void)
{
	return dato;
}

template <typename tipo, typename tipo2>
void Nodo <tipo, tipo2>::setDato(tipo newDato)
{
	dato = newDato;
}