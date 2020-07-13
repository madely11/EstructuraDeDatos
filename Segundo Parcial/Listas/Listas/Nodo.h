#ifndef Nodo_H_
#define Nodo_H_
template <typename tipo> 
class Nodo
{
public:
	//Nodo();
	Nodo(tipo newDato, Nodo* newSiguiente);
	Nodo();
	Nodo* getSiguiente();
	void setSiguiente(Nodo* newSiguiente);
	tipo getDato();
	void setDato(tipo newDato);
protected:
private:
	tipo dato;
	Nodo* siguiente;
};
#endif