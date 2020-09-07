#include<cstdio>
#include<cstdlib>
#include"Biselado.h"

int main()
{
	Biselado arbol;
	int cont = 1;
	while (true)
	{
		int t;
		scanf_s("%d", &t);
		if (t != 0 && t != -1) arbol.insertar(t);
		else if (t == 0)
		{
			scanf_s("%d", &t);
			if (!arbol.buscar(t))
				printf("Couldn't buscar %d!\n", t);
			else
				printf("Found %d!\n", t);
		}
		else
		{
			scanf_s("%d", &t);
			if (arbol.borrar(t))
				printf("Deleted %d!\n", t);
			else
				printf("Couldn't buscar %d!\n", t);
		}
		if (arbol.raiz) printf("raiz: %d\n", arbol.raiz->v);
		//Inorder(raiz);
		arbol.mostrar(arbol.raiz, cont);
	}
}