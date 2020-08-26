#include"Node.h"
/**@brief  Constructor
@param void
@returns void
*/
template<class T>
Node<T>::Node() { this->next = NULL; }
/**@brief  Constructor
@param  T d
@param  Node* n
@returns void
*/
template<class T>
Node<T>::Node(T d, Node<T>* n) {
	this->data = d;
	this->next = n;
}
/**@brief  Constructor
@param  T d
@param  Node* n
@returns void
*/
template<class T>
Node<T>::Node(T d, Node<T>* n, Node<T>* p) {
	this->data = d;
	this->next = n;
	this->previous = p;
}
/**@brief  Destructor
@param  void
@returns void
*/
