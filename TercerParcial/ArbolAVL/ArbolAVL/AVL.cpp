#include "AVL.h"
//#include"SFML/Graphics.hpp"
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

// Poda: borrar todos los nodos a partir de uno, incluido
template<class T>
void AVL<T>::eliminarArbol(Nodo<T>* nodo)
{
    // Algoritmo recursivo, recorrido en postorden
    if (nodo) {
        eliminarArbol(nodo->izquierdo); // eliminarArbol izquierdo
        eliminarArbol(nodo->derecho);   // eliminarArbol derecho
        delete nodo;            // Eliminar nodo
        nodo = NULL;
    }
}

template<class T>
Nodo<T>* AVL<T>::getRaiz()
{
    return this->raiz;
}

// Insertar un dato en el árbol AVL
template<class T>
void AVL<T>::Insertar(const T dat)
{
    Nodo<T>* padre = NULL;

    cout << "Insertar: " << dat << endl;
    actual = raiz;
    // Buscar el dato en el árbol, manteniendo un puntero al nodo padre
    while (!Vacio(actual)) {
        padre = actual;
        if (dat >= actual->dato) actual = actual->derecho;
        else if (dat < actual->dato) actual = actual->izquierdo;
    }

    // Si se ha encontrado el elemento, regresar sin insertar
    // Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
    // el nodo raiz
    if (Vacio(padre)) raiz = new Nodo<T>(dat);
    // Si el dato es menor que el que contiene el nodo padre, lo insertamos
    // en la rama izquierda
    else if (dat < padre->dato) {
        padre->izquierdo = new Nodo<T>(dat, padre);
        Equilibrar(padre, IZQUIERDO, true);
    }
    // Si el dato es mayor que el que contiene el nodo padre, lo insertamos
    // en la rama derecha
    else if (dat >= padre->dato) {
        padre->derecho = new Nodo<T>(dat, padre);
        Equilibrar(padre, DERECHO, true);
    }
}

// Equilibrar árbol AVL partiendo del nodo nuevo
template<class T>
void AVL<T>::Equilibrar(Nodo<T>* nodo, int rama, bool nuevo)
{
    bool salir = false;

    // Recorrer camino inverso actualizando valores de factorE:
    while (nodo && !salir) {
        if (nuevo)
            if (rama == IZQUIERDO) nodo->factorE--; // Depende de si añadimos ...
            else                  nodo->factorE++;
        else
            if (rama == IZQUIERDO) nodo->factorE++; // ... o borramos
            else                  nodo->factorE--;
        if (nodo->factorE == 0) salir = true; // La altura de las rama que
                                        // empieza en nodo no ha variado,
                                        // salir de Equilibrar
        else if (nodo->factorE == -2) { // Rotar a derechas y salir:
            if (nodo->izquierdo->factorE == 1) rotacionDobleDerecha(nodo); // Rotación doble
            else rotacionSimpleDerecha(nodo);                         // Rotación simple
            salir = true;
        }
        else if (nodo->factorE == 2) {  // Rotar a izquierdas y salir:
            if (nodo->derecho->factorE == -1) rotacionDobleIzquierda(nodo); // Rotación doble
            else rotacionSimpleIzquierda(nodo);                        // Rotación simple
            salir = true;
        }
        if (nodo->padre)
            if (nodo->padre->derecho == nodo) rama = DERECHO; else rama = IZQUIERDO;
        nodo = nodo->padre; // Calcular factorE, siguiente nodo del camino.
    }
}

// Rotación doble a derechas
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

    // Reconstruir árbol:
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
    // Mientras sea posible que el valor esté en el árbol
    while (!Vacio(actual)) {
        if (dat == actual->dato) { // Si el valor está en el nodo actual
            if (EsHoja(actual)) { // Y si además es un nodo hoja: lo borramos
                if (padre) // Si tiene padre (no es el nodo raiz)
                   // Anulamos el puntero que le hace referencia
                    if (padre->derecho == actual) padre->derecho = NULL;
                    else if (padre->izquierdo == actual) padre->izquierdo = NULL;
                delete actual; // Borrar el nodo
                actual = NULL;
                // El nodo padre del actual puede ser ahora un nodo hoja, por lo tanto su
                // factorE es cero, pero debemos seguir el camino a partir de su padre, si existe.
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
            else { // Si el valor está en el nodo actual, pero no es hoja
               // Buscar nodo
                padre = actual;
                // Buscar nodo más izquierdo de rama derecha
                if (actual->izquierdo) {
                    nodo = actual->izquierdo;
                    while (nodo->derecho) {
                        padre = nodo;
                        nodo = nodo->derecho;
                    }
                }
                // O buscar nodo más derecho de rama izquierda
                else {
                    nodo = actual->derecho;
                    while (nodo->izquierdo) {
                        padre = nodo;
                        nodo = nodo->izquierdo;
                    }
                }
                // Intercambiar valores de no a borrar u nodo encontrado
                // y continuar, cerrando el bucle. El nodo encontrado no tiene
                // por qué ser un nodo hoja, cerrando el bucle nos aseguramos
                // de que sólo se eliminan nodos hoja.
                aux = actual->dato;
                actual->dato = nodo->dato;
                nodo->dato = aux;
                actual = nodo;
            }
        }
        else { // Todavía no hemos encontrado el valor, seguir buscándolo
            padre = actual;
            if (dat > actual->dato) actual = actual->derecho;
            else if (dat < actual->dato) actual = actual->izquierdo;
        }
    }
}

// Recorrido de árbol en inorden, aplicamos la función func, que tiene
// el prototipo:
// template<class DATO> void func(DATO&);
template<class T>
void AVL<T>::InOrden(void (*func)(T&, int), Nodo<T>* nodo, bool r)
{
    if (r) nodo = raiz;
    if (nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
    func(nodo->dato, nodo->factorE);
    if (nodo->derecho) InOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en preorden, aplicamos la función func, que tiene
// el prototipo:
// template<class DATO> void func(DATO&);
template<class T>
void AVL<T>::PreOrden(void (*func)(T&, int), Nodo<T>* nodo, bool r)
{
    if (r) nodo = raiz;
    func(nodo->dato, nodo->factorE);
    if (nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
    if (nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en postorden, aplicamos la función func, que tiene
// el prototipo:
// template<class DATO> void func(DATO&);
template<class T>
void AVL<T>::PostOrden(void (*func)(T&, int), Nodo<T>* nodo, bool r)
{
    if (r) nodo = raiz;
    if (nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
    if (nodo->derecho) PostOrden(func, nodo->derecho, false);
    func(nodo->dato, nodo->factorE);
}

// Buscar un valor en el árbol
template<class T>
bool AVL<T>::Buscar(const T dat)
{
    actual = raiz;

    // Todavía puede aparecer, ya que quedan nodos por mirar
    while (!Vacio(actual)) {
        if (dat == actual->dato) return true; // dato encontrado
        else if (dat > actual->dato) actual = actual->derecho; // Seguir
        else if (dat < actual->dato) actual = actual->izquierdo;
    }
    return false; // No está en árbol
}

// Calcular la altura del nodo que contiene el dato dat
template<class T>
int AVL<T>::Altura(const T dat)
{
    int altura = 0;
    actual = raiz;

    // Todavía puede aparecer, ya que quedan nodos por mirar
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

// Función auxiliar para contar nodos. Función recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
template<class T>
void AVL<T>::auxContador(Nodo<T>* nodo)
{
    contador++;  // Otro nodo
    // Continuar recorrido
    if (nodo->izquierdo) auxContador(nodo->izquierdo);
    if (nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del árbol, que es la altura del nodo de mayor altura.
template<class T>
const int AVL<T>::AlturaArbol()
{
    altura = 0;

    auxAltura(raiz, 0); // Función auxiliar
    return altura;
}

// Función auxiliar para calcular altura. Función recursiva de recorrido en
// postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
// altura de la máxima actual
template<class T>
void AVL<T>::auxAltura(Nodo<T>* nodo, int a)
{
    // Recorrido postorden
    if (nodo->izquierdo) auxAltura(nodo->izquierdo, a + 1);
    if (nodo->derecho)   auxAltura(nodo->derecho, a + 1);
    // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
    // árbol, actualizamos la altura actual del árbol
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