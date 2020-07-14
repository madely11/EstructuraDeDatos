#ifndef Nodo_H_
#define Nodo_H_
template <typename tipo, typename tipo2> 
class Nodo
{
public:
	//Nodo();
	Nodo(tipo newDato, tipo2* newSiguiente);
	Nodo();
	tipo2* getSiguiente();
	void setSiguiente(tipo2* newSiguiente);
	tipo getDato();
	void setDato(tipo newDato);
protected:
private:
	tipo dato;
	tipo2* siguiente;
};
#endif