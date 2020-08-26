#if !defined(__Pila_h)
#define __Pila_h
#include "Node.h"
template <class T>
class Pila {
public:
    Pila();
    //Metodos para agregar
    void push(T);
    //Metodos para eleiminar
    T pop();
    T getFirst();
    //Longitud de lista
    int size();
    //Lista vacia
    bool isEmpty();
    T toEmpty();
    //Metodo de impresion
    void print();
private:
    Node<T>* next;
};
#endif