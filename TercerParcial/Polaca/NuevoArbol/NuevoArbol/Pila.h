#if !defined(__Pila_h)
#define __Pila_h
#include "Node.h"

class Pila {
public:
    Pila();
    //Metodos para agregar
    void push(char);
    //Metodos para eleiminar
    char pop();
    char getFirst();
    //Longitud de lista
    int size();
    //Lista vacia
    bool isEmpty();
    char toEmpty();
    //Metodo de impresion
    void print();
private:
    Node* next;
};
#endif