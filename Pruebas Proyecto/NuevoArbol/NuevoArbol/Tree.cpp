#include "Tree.h"

/**
 * @brief Tree
 * @tparam T
*/
template<typename T>
Tree<T>::Tree() {
	this->_root = NULL;
}
/**
   @brief Funcion set raiz del arbol
   @param Tree_Node* _root
   @returns void
*/
template<class T>
void Tree<T>::set_root(Tree_Node<T>* _root)
{
	this->_root = _root;
}
/**
   @brief Funcion obtener raiz del arbol
   @param void
   @returns Tree_Node*
*/
template<class T>
Tree_Node<T>* Tree<T>::get_root()
{
	return this->_root;
}

/**
 * @brief _is_empty
 * @tparam T
 * @return bool
*/
template<typename T>
bool Tree<T>::_is_empty() {
	return (this->_root == NULL) ? true : false;
}

/**
 * @brief ~Tree
 * @tparam T
*/
template<typename T>
Tree<T>::~Tree() {
	this->_root = NULL;
}
