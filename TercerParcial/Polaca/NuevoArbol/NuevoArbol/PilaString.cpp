#include "PilaString.h"

PilaString::PilaString()
{
    this->next = NULL;
}

void PilaString::push(string d)
{
    if (this->isEmpty()) {
        this->next = new NodeString(d, NULL);
    }
    else {
        NodeString* aux = new NodeString(d, this->next);
        this->next = aux;
    }
}

string PilaString::pop()
{
    if (!isEmpty()) {
        NodeString* aux = this->next->getNext();
        string d = this->next->getData();
        delete this->next;
        this->next = aux;
        return  d;
    }
    else {
        cout << "Pila vacia" << endl;
        return 0;
    }
}

string PilaString::getFirst()
{
    if (!isEmpty()) {
        string d = this->next->getData();
        return  d;
    }
    else {
        cout << "Pila vacia" << endl;
        return 0;
    }
}

bool PilaString::isEmpty()
{
    return (this->next == NULL) ? true : false;
}

void PilaString::print()
{
    NodeString* aux = new NodeString();
    aux = this->next;
    while (aux != NULL) {
        cout << aux->getData() << "  ";
        aux = aux->getNext();
    }
}

