#include "Pila_Tree.h"
/**@brief  Constructor
@param  void
@returns void
*/

Pila_Tree::Pila_Tree()
{
    this->next = NULL;
}
/**@brief  agregar al inicio
@param  T d
@returns void
*/

void Pila_Tree::push(Tree_Node* d) {
    if (this->isEmpty()) {
        this->next = new Node_Tree(d, NULL);
    }
    else {
        Node_Tree* aux = new Node_Tree(d, this->next);
        this->next = aux;
    }
}

/**@brief  Verifica que la pila esta este vacia
@param  void
@returns void
*/
bool Pila_Tree::isEmpty() {
    return (this->next == NULL) ? true : false;
}
/**@brief  imprimir lista
@param  void
@returns void
*/

/**@brief  vaciar pila
@param  void
@returns void
*/
Tree_Node* Pila_Tree::toEmpty() {
    Node_Tree* aux = new Node_Tree();
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
Tree_Node* Pila_Tree::pop() {
    if (!isEmpty()) {
        Node_Tree* aux = this->next->getNext();
        Tree_Node* d = this->next->getData();
        delete this->next;
        this->next = aux;
        return  d;
    }
    else {
        cout << "Pila vacia" << endl;
        return 0;
    }
}
void Pila_Tree::clean_pila()
{
    while (!isEmpty()) {
        pop();
    }
}
/**@brief  recuperar primer Dato
@param  void
@returns void
*/
Tree_Node* Pila_Tree::getFirst() {
    if (!isEmpty()) {
        Tree_Node* d = this->next->getData();
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
int Pila_Tree::size() {
    int contador = 0;
    Node_Tree* aux = new Node_Tree();
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
