#include "AVL.h"

template<class T>
void AVL<T>::mostrarArbol(Nodo<T>* p, int espacios)
{
    if (p != NULL) {
        if (p->derecho) {
            mostrarArbol(p->derecho, espacios + 4);
        }
        if (espacios) {
            cout << setw(espacios) << ' ';
        }
        if (p->derecho) cout << " /\n" << setw(espacios) << ' ';
        cout << p->dato << "\n ";
        if (p->izquierdo) {
            cout << std::setw(espacios) << ' ' << " \\\n";
            mostrarArbol(p->izquierdo, espacios + 4);
        }
    }
}


template<class T>
void AVL<T>::eliminarArbol(Nodo<T>* nodo)
{
 
    if (nodo) {
        eliminarArbol(nodo->izquierdo);
        eliminarArbol(nodo->derecho); 
        delete nodo;           
        nodo = NULL;
    }
}

template<class T>
Nodo<T>* AVL<T>::getRaiz()
{
    return this->raiz;
}


template<class T>
void AVL<T>::Insertar(const T dat)
{
    Nodo<T>* padre = NULL;

    cout << "Insertar: " << dat << endl;
    actual = raiz;
    
    while (!Vacio(actual)) {
        padre = actual;
        if (dat >= actual->dato) actual = actual->derecho;
        else if (dat < actual->dato) actual = actual->izquierdo;
    }


    if (Vacio(padre)) raiz = new Nodo<T>(dat);
  
    else if (dat < padre->dato) {
        padre->izquierdo = new Nodo<T>(dat, padre);
        Equilibrar(padre, IZQUIERDO, true);
    }
  
    else if (dat >= padre->dato) {
        padre->derecho = new Nodo<T>(dat, padre);
        Equilibrar(padre, DERECHO, true);
    }
}


template<class T>
void AVL<T>::Equilibrar(Nodo<T>* nodo, int rama, bool nuevo)
{
    bool salir = false;

    
    while (nodo && !salir) {
        if (nuevo)
            if (rama == IZQUIERDO) nodo->factorE--; 
            else                  nodo->factorE++;
        else
            if (rama == IZQUIERDO) nodo->factorE++; 
            else                  nodo->factorE--;
        if (nodo->factorE == 0) salir = true; 
                                        
        else if (nodo->factorE == -2) {
            if (nodo->izquierdo->factorE == 1) rotacionDobleDerecha(nodo); 
            else rotacionSimpleDerecha(nodo);                       
            salir = true;
        }
        else if (nodo->factorE == 2) { 
            if (nodo->derecho->factorE == -1) rotacionDobleIzquierda(nodo); 
            else rotacionSimpleIzquierda(nodo);                       
            salir = true;
        }
        if (nodo->padre)
            if (nodo->padre->derecho == nodo) rama = DERECHO; else rama = IZQUIERDO;
        nodo = nodo->padre; 
    }
}

template<class T>
void AVL<T>::rotacionDobleDerecha(Nodo<T>* nodo)
{
    cout << "rotacionDobleDerecha" << endl;
    Nodo<T>* Padre = nodo->padre;
    Nodo<T>* nodoActual = nodo;
    Nodo<T>* izquierdoA = nodoActual->izquierdo;
    Nodo<T>* derechoI = izquierdoA->derecho;
    Nodo<T>* izquierdoDIz = derechoI->izquierdo;
    Nodo<T>* derechoDIz = derechoI->derecho;

    if (Padre)
        if (Padre->derecho == nodo) Padre->derecho = derechoI;
        else Padre->izquierdo = derechoI;
    else raiz = derechoI;

    
    izquierdoA->derecho = izquierdoDIz;
    nodoActual->izquierdo = derechoDIz;
    derechoI->izquierdo = izquierdoA;
    derechoI->derecho = nodoActual;

    // Reasignar padres:
    derechoI->padre = Padre;
    nodoActual->padre = izquierdoA->padre = derechoI;
    if (izquierdoDIz) izquierdoDIz->padre = izquierdoA;
    if (derechoDIz) derechoDIz->padre = nodoActual;

    // Ajustar valores de factorE:
    switch (derechoI->factorE) {
    case -1: izquierdoA->factorE = 0; nodoActual->factorE = 1; break;
    case 0:  izquierdoA->factorE = 0; nodoActual->factorE = 0; break;
    case 1:  izquierdoA->factorE = -1; nodoActual->factorE = 0; break;
    }
    derechoI->factorE = 0;
}

// Rotación doble a izquierdas
template<class T>
void AVL<T>::rotacionDobleIzquierda(Nodo<T>* nodo)
{
    cout << "rotacionDobleIzquierda" << endl;
    Nodo<T>* Padre = nodo->padre;
    Nodo<T>* nodoActual = nodo;
    Nodo<T>* derechoA = nodoActual->derecho;
    Nodo<T>* izquierdoD = derechoA->izquierdo;
    Nodo<T>* izquierdoIz = izquierdoD->izquierdo;
    Nodo<T>* derechoIz = izquierdoD->derecho;

    if (Padre)
        if (Padre->derecho == nodo) Padre->derecho = izquierdoD;
        else Padre->izquierdo = izquierdoD;
    else raiz = izquierdoD;

    // Reconstruir árbol:
    nodoActual->derecho = izquierdoIz;
    derechoA->izquierdo = derechoIz;
    izquierdoD->izquierdo = nodoActual;
    izquierdoD->derecho = derechoA;

    // Reasignar padres:
    izquierdoD->padre = Padre;
    nodoActual->padre = derechoA->padre = izquierdoD;
    if (izquierdoIz) izquierdoIz->padre = nodoActual;
    if (derechoIz) derechoIz->padre = derechoA;

    // Ajustar valores de factorE:
    switch (izquierdoD->factorE) {
    case -1: nodoActual->factorE = 0; derechoA->factorE = 1; break;
    case 0:  nodoActual->factorE = 0; derechoA->factorE = 0; break;
    case 1:  nodoActual->factorE = -1; derechoA->factorE = 0; break;
    }
    izquierdoD->factorE = 0;
}

// Rotación simple a derechas
template<class T>
void AVL<T>::rotacionSimpleDerecha(Nodo<T>* nodo)
{
    cout << "rotacionSimpleDerecha" << endl;
    Nodo<T>* Padre = nodo->padre;
    Nodo<T>* nodoActual = nodo;
    Nodo<T>* izquierdoA = nodoActual->izquierdo;
    Nodo<T>* derechoIz = izquierdoA->derecho;

    if (Padre)
        if (Padre->derecho == nodoActual) Padre->derecho = izquierdoA;
        else Padre->izquierdo = izquierdoA;
    else raiz = izquierdoA;

    // Reconstruir árbol:
    nodoActual->izquierdo = derechoIz;
    izquierdoA->derecho = nodoActual;

    // Reasignar padres:
    nodoActual->padre = izquierdoA;
    if (derechoIz) derechoIz->padre = nodoActual;
    izquierdoA->padre = Padre;

    // Ajustar valores de factorE:
    nodoActual->factorE = 0;
    izquierdoA->factorE = 0;
}

// Rotación simple a izquierdas
template<class T>
void AVL<T>::rotacionSimpleIzquierda(Nodo<T>* nodo)
{
    cout << "rotacionSimpleIzquierda" << endl;
    Nodo<T>* Padre = nodo->padre;
    Nodo<T>* nodoActual = nodo;
    Nodo<T>* derecho = nodoActual->derecho;
    Nodo<T>* izquierdoD = derecho->izquierdo;

    if (Padre)
        if (Padre->derecho == nodoActual) Padre->derecho = derecho;
        else Padre->izquierdo = derecho;
    else raiz = derecho;

    // Reconstruir árbol:
    nodoActual->derecho = izquierdoD;
    derecho->izquierdo = nodoActual;

    // Reasignar padres:
    nodoActual->padre = derecho;
    if (izquierdoD) izquierdoD->padre = nodoActual;
    derecho->padre = Padre;

    // Ajustar valores de factorE:
    nodoActual->factorE = 0;
    derecho->factorE = 0;
}

// Eliminar un elemento de un árbol AVL
template<class T>
void AVL<T>::Borrar(const T dat)
{
    Nodo<T>* padre = NULL;
    Nodo<T>* nodo;
    T aux;

    actual = raiz;
   
    while (!Vacio(actual)) {
        if (dat == actual->dato) { 
            if (EsHoja(actual)) { 
                if (padre) 
                    if (padre->derecho == actual) padre->derecho = NULL;
                    else if (padre->izquierdo == actual) padre->izquierdo = NULL;
                delete actual; // Borrar el nodo
                actual = NULL;
                if ((padre->derecho == actual && padre->factorE == 1) ||
                    (padre->izquierdo == actual && padre->factorE == -1)) {
                    padre->factorE = 0;
                    actual = padre;
                    padre = actual->padre;
                }
                if (padre)
                    if (padre->derecho == actual) Equilibrar(padre, DERECHO, false);
                    else                         Equilibrar(padre, IZQUIERDO, false);
                return;
            }
            else { 
                padre = actual;
               
                if (actual->izquierdo) {
                    nodo = actual->izquierdo;
                    while (nodo->derecho) {
                        padre = nodo;
                        nodo = nodo->derecho;
                    }
                }
               
                else {
                    nodo = actual->derecho;
                    while (nodo->izquierdo) {
                        padre = nodo;
                        nodo = nodo->izquierdo;
                    }
                }
               
                aux = actual->dato;
                actual->dato = nodo->dato;
                nodo->dato = aux;
                actual = nodo;
            }
        }
        else { 
            padre = actual;
            if (dat > actual->dato) actual = actual->derecho;
            else if (dat < actual->dato) actual = actual->izquierdo;
        }
    }
}

template<class T>
void AVL<T>::InOrden(void (*func)(T&, int), Nodo<T>* nodo, bool r)
{
    if (r) nodo = raiz;
    if (nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
    func(nodo->dato, nodo->factorE);
    if (nodo->derecho) InOrden(func, nodo->derecho, false);
}


template<class T>
void AVL<T>::PreOrden(void (*func)(T&, int), Nodo<T>* nodo, bool r)
{
    if (r) nodo = raiz;
    func(nodo->dato, nodo->factorE);
    if (nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
    if (nodo->derecho) PreOrden(func, nodo->derecho, false);
}

template<class T>
void AVL<T>::PostOrden(void (*func)(T&, int), Nodo<T>* nodo, bool r)
{
    if (r) nodo = raiz;
    if (nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
    if (nodo->derecho) PostOrden(func, nodo->derecho, false);
    func(nodo->dato, nodo->factorE);
}

template<class T>
bool AVL<T>::Buscar(const T dat)
{
    actual = raiz;

    while (!Vacio(actual)) {
        if (dat == actual->dato) return true; // dato encontrado
        else if (dat > actual->dato) actual = actual->derecho; // Seguir
        else if (dat < actual->dato) actual = actual->izquierdo;
    }
    return false; // No está en árbol
}

template<class T>
int AVL<T>::Altura(const T dat)
{
    int altura = 0;
    actual = raiz;

    while (!Vacio(actual)) {
        if (dat == actual->dato) return altura; // dato encontrado
        else {
            altura++; // Incrementamos la altura, seguimos buscando
            if (dat > actual->dato) actual = actual->derecho;
            else if (dat < actual->dato) actual = actual->izquierdo;
        }
    }
    return -1; // No está en árbol
}

// Contar el número de nodos
template<class T>
const int AVL<T>::NumeroNodos()
{
    contador = 0;

    auxContador(raiz); // FUnción auxiliar
    return contador;
}

template<class T>
void AVL<T>::auxContador(Nodo<T>* nodo)
{
    contador++;  // Otro nodo
    // Continuar recorrido
    if (nodo->izquierdo) auxContador(nodo->izquierdo);
    if (nodo->derecho)   auxContador(nodo->derecho);
}

template<class T>
const int AVL<T>::AlturaArbol()
{
    altura = 0;

    auxAltura(raiz, 0); // Función auxiliar
    return altura;
}

template<class T>
void AVL<T>::auxAltura(Nodo<T>* nodo, int a)
{
    // Recorrido postorden
    if (nodo->izquierdo) auxAltura(nodo->izquierdo, a + 1);
    if (nodo->derecho)   auxAltura(nodo->derecho, a + 1);
    if (EsHoja(nodo) && a > altura) altura = a;
}


template <class T>
void AVL<T>::showTreeGraph(Nodo<T>* tree, int x, int y, int cont) {
    if (tree) {
        dibujar.dibujarNodo(x, y, to_string(tree->dato));
        if (tree->izquierdo) {
            if (cont == 1) {
                showTreeGraph(tree->izquierdo, x / 2, y + 75, cont + 1); //450
            }
            else {
                if (x > 900) {
                    showTreeGraph(tree->izquierdo, x - x / 10, y + 75, cont); ///jh
                }
                else {
                    showTreeGraph(tree->izquierdo, x - x / 8, y + 75, cont);
                }
            }

        }
        if (tree->derecho) {
            if (cont == 1) {
                showTreeGraph(tree->derecho, x + x / 2, y + 75, cont + 1); //
            }
            else {
                if (x > 900) {
                    showTreeGraph(tree->derecho, x + x / 10, y + 75, cont);
                }
                else {
                    showTreeGraph(tree->derecho, x + x / 8, y + 75, cont); //mnhjk
                }

            }

        }
    }
}
// Función de prueba para recorridos del árbol
template <class T>
void Mostrar(T& d, int factorE)
{
    cout << d << "(" << factorE << "),";
}