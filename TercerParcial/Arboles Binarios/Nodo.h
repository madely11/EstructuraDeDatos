/***********************************************************************
 * Module:  Nodo.h
 * Author:  Kevin Caicedo
 * Modified: martes, agosto 18, 2020 10:23:08 PM
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Nodo_h)
#define __Class_Diagram_1_Nodo_h

class Nodo
{
public:
   int getDato(void);
   void setDato(int newDato);
   Nodo* getIzquierda(void);
   void setIzquierda(Nodo* newIzquierda);
   Nodo* getDerecha(void);
   void setDerecha(Nodo* newDerecha);
   Nodo();
   ~Nodo();

protected:
private:
   int dato;
   Nodo* izquierda;
   Nodo* derecha;


};

#endif
