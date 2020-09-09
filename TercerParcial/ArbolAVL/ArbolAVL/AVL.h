/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* iNGRESO, BORRADO, GRAFICO ARBOL AVL                *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 04/07/20									  *
* FECHA DE MODIFICACIÓN: 09/07/20								  *
******************************************************************/
#pragma once
#include"Nodo.h" 
#include"Dibujar.h"
template<class T>
class AVL {
private:
    enum { IZQUIERDO, DERECHO };
   
    
    Nodo<T>* actual;
    int contador;
    int altura;

public:
    Nodo<T>* raiz;
   
    AVL() : raiz(NULL), actual(NULL) {}
    ~AVL() { eliminarArbol(this->raiz); }
  
    void Insertar(const T dat);
  
    void Borrar(const T dat);

    bool Buscar(const T dat);
    Nodo<T>* getRaiz();
    // Comprobar si el árbol está vacío:
    bool Vacio(Nodo<T>* r) { return r == NULL; }
    // Comprobar si es un nodo hoja:
    bool EsHoja(Nodo<T>* r) { return !r->derecho && !r->izquierdo; }
    // Contar número de nodos:
    const int NumeroNodos();
    const int AlturaArbol();
    // Calcular altura de un dato:
    int Altura(const T dat);
    // Devolver referencia al dato del nodo actual:
    T& ValorActual() { return actual->dato; }
    // Moverse al nodo raiz:
    void Raiz() { actual = raiz; }
    void showTreeGraph(Nodo<T>* tree, int x, int y, int cont);
    // Aplicar una función a cada elemento del árbol
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

