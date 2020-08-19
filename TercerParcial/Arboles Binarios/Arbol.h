/***********************************************************************
 * Module:  Arbol.h
 * Author:  Kevin Caicedo
 * Modified: martes, agosto 18, 2020 10:21:41 PM
 * Purpose: Declaration of the class Arbol
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Arbol_h)
#define __Class_Diagram_1_Arbol_h

#include <Nodo.h>

class Arbol
{
public:
   void insertar(Nodo* elemento);
   void eliminar(int dato);
   bool buscar(int dato);
   Nodo* getArbol(void);
   void setArbol(Nodo* newArbol);
   Arbol();
   ~Arbol();

protected:
private:
   Nodo* arbol;


};

#endif
