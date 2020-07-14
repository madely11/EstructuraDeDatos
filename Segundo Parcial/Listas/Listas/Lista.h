#include "Nodo.h"

class Lista
{
public:
	void InsertarInicio(int numero);
	void InsertarFinal(int numero);
	void Imprimir(void);
	int vacio(void);
protected:
private:
	Nodo<int, Nodo> siguiente;
};

