#include "Pila.h"
/**@brief  Constructor
@param  void
@returns void
*/
template <class T>
Pila<T>::Pila()
{
    this->next = NULL;
}
/**@brief  agregar al inicio
@param  T d
@returns void
*/
template<class T>
void Pila<T>::push(T d) {
    if (this->isEmpty()) {
        this->next = new Node<T>(d, NULL);
    }
    else {
        Node<T>* aux = new Node<T>(d, this->next);
        this->next = aux;
    }
}

/**@brief  Verifica que la pila esta este vacia
@param  void
@returns void
*/
template<class T>
bool Pila<T>::isEmpty() {
    return (this->next == NULL) ? true : false;
}
/**@brief  imprimir lista
@param  void
@returns void
*/
template<class T>
void Pila<T>::print() {
    Node<T>* aux = new Node<T>();
    aux = this->next;
    while (aux != NULL) {
        cout << aux->getData() << "  ";
        aux = aux->getNext();
    }
}
/**@brief  vaciar pila
@param  void
@returns void
*/
template<class T>
T Pila<T>::toEmpty() {
    Node<T>* aux = new Node<T>();
    while (!this->isEmpty()) {
        aux = this->next;
        this->next = this->next->getNext();
        return aux->getData();
    }
}

/**@brief  eliminar al incio
@param  void
@returns void
*/
template<class T>
T Pila<T>::pop() {
    if (!isEmpty()) {
        Node<T>* aux = this->next->getNext();
        T d = this->next->getData();
        delete this->next;
        this->next = aux;
        return  d;
    }
    else {
        cout << "Pila vacia" << endl;
        return 0;
    }
}
/**@brief  recuperar primer Dato
@param  void
@returns void
*/
template<class T>
T Pila<T>::getFirst() {
    if (!isEmpty()) {
        T d = this->next->getData();
        return  d;
    }
    else {
        cout << "Pila vacia" << endl;
        return 0;
    }
}
/**@brief  Numero de datos de la lista
@param  void
@returns void
*/
template<class T>
int Pila<T>::size() {
    int contador = 0;
    Node<T>* aux = new Node<T>();
    aux = this->next;
    while (aux != NULL) {
        contador++;
        aux = aux->getNext();
    }
    return contador;
}
/**@brief  Destructor
@param  void
@returns void
*/
