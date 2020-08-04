#include"Lista.h"
#include"IngresoPersona.h"
void main()
{
	Lista* lista = new Lista();
	IngresoPersona p1;
	p1.ingresoDatos();
	lista->insertarInicio(p1.persona);
	
}
	