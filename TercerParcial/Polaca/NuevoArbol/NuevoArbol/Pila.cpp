#include "Pila.h"
/**@brief  Constructor
@param  void
@returns void
*/

Pila::Pila()
{
    this->next = NULL;
}
/**@brief  agregar al inicio
@param  T d
@returns void
*/

void Pila::push(char d) {
    if (this->isEmpty()) {
        this->next = new Node(d, NULL);
    }
    else {
        Node* aux = new Node(d, this->next);
        this->next = aux;
    }
}

/**@brief  Verifica que la pila esta este vacia
@param  void
@returns void
*/
bool Pila::isEmpty() {
    return (this->next == NULL) ? true : false;
}
/**@brief  imprimir lista
@param  void
@returns void
*/
void Pila::print() {
    Node* aux = new Node();
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
char Pila::toEmpty() {
    Node* aux = new Node();
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
char Pila::pop() {
    if (!isEmpty()) {
        Node* aux = this->next->getNext();
        char d = this->next->getData();
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
char Pila::getFirst() {
    if (!isEmpty()) {
        char d = this->next->getData();
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
int Pila::size() {
    int contador = 0;
    Node* aux = new Node();
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
