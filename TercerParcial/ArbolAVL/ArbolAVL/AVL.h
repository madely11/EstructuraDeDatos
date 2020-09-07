#pragma once
#include"Nodo.h" 
#include"Dibujar.h"
template<class T>
class AVL {
private:
    enum { IZQUIERDO, DERECHO };
    // Punteros de la lista, para cabeza y nodo actual:
    
    Nodo<T>* actual;
    int contador;
    int altura;

public:
    Nodo<T>* raiz;
    // Constructor y destructor b�sicos:
    AVL() : raiz(NULL), actual(NULL) {}
    ~AVL() { eliminarArbol(this->raiz); }
    // Insertar en �rbol ordenado:
    void Insertar(const T dat);
    // Borrar un elemento del �rbol:
    void Borrar(const T dat);
    // Funci�n de b�squeda:
    bool Buscar(const T dat);
    Nodo<T>* getRaiz();
    // Comprobar si el �rbol est� vac�o:
    bool Vacio(Nodo<T>* r) { return r == NULL; }
    // Comprobar si es un nodo hoja:
    bool EsHoja(Nodo<T>* r) { return !r->derecho && !r->izquierdo; }
    // Contar n�mero de nodos:
    const int NumeroNodos();
    const int AlturaArbol();
    // Calcular altura de un dato:
    int Altura(const T dat);
    // Devolver referencia al dato del nodo actual:
    T& ValorActual() { return actual->dato; }
    // Moverse al nodo raiz:
    void Raiz() { actual = raiz; }
    void showTreeGraph(Nodo<T>* tree, int x, int y, int cont);
    // Aplicar una funci�n a cada elemento del �rbol
    void InOrden(void (*func)(T&, int), Nodo<T>* nodo = NULL, bool r = true);
    void PreOrden(void (*func)(T&, int), Nodo<T>* nodo = NULL, bool r = true);
    void PostOrden(void (*func)(T&, int), Nodo<T>* nodo = NULL, bool r = true);
    void mostrarArbol(Nodo<T>*, int espacios);
    // Funciones de equilibrado:
    void Equilibrar(Nodo<T>* nodo, int, bool);
    void rotacionSimpleIzquierda(Nodo<T>* nodo);
    void rotacionSimpleDerecha(Nodo<T>* nodo);
    void rotacionDobleIzquierda(Nodo<T>* nodo);
    void rotacionDobleDerecha(Nodo<T>* nodo);
    // Funciones auxiliares
    void eliminarArbol(Nodo<T>*);
    void auxContador(Nodo<T>*);
    void auxAltura(Nodo<T>*, int);
    Dibujar dibujar;
};

