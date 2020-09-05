#pragma once

#include <iostream>
#include <iomanip>  
using namespace std;
template<class T> class AVL;
template<class T>
class Nodo
{
public:
    // Constructor:
    Nodo(const T dat, Nodo<T>* pad = NULL,
        Nodo<T>* izq = NULL, Nodo<T>* der = NULL) :
        dato(dat), padre(pad), izquierdo(izq), derecho(der), factorE(0) {}
    // Miembros:
    T dato;
    int factorE;
    Nodo<T>* izquierdo;
    Nodo<T>* derecho;
    Nodo<T>* padre;
    friend class AVL<T>;
};

