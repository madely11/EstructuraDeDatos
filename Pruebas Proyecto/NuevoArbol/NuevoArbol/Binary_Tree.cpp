#pragma once
#include <sstream>
#include "Binary_Tree.h"
#include "Tree_Node.cpp"


/**
	@brief Funcion para insertar un dato al arbo
	@tparam T dato
	@param Tree_Node* node
	@param Tree_Node* parent
	@returns void
*/
template<typename T>
void Binary_Tree<T>::_add(T _data, Tree_Node<T>* node, Tree_Node<T>* parent) {
	Tree_Node<T>* _aux = new Tree_Node<T>(_data, NULL, NULL);
	if (this->_is_empty()) {
		this->_root = _aux;
		return;
	}
	else {
		if (node != NULL) {
			if (_data < node->get_data()) {
				parent = node;
				node = node->get_left_node();
				_add(_data, node, parent);
			}
			else {
				parent = node;
				node = node->get_right_node();
				_add(_data, node, parent);
			}
		}
		else {
			if (_data < parent->get_data()) {
				parent->set_left_node(_aux);
				return;
			}
			else {
				parent->set_right_node(_aux);
				return;
			}
		}
	}

		
}
/**
	@brief Funcion para buscar un elemento en el arbol
	@tparam T dato
	@param Tree_Node* node
	@returns void
*/
template<typename T>
T Binary_Tree<T>::_look(T _data, Tree_Node<T>* node) {
	if (this->_is_empty()) {
		//cout << "Nodo Vacio" << endl;
		return _data;
	}
	else {
		if (node != NULL && _data != node->get_data()) {
			if (_data < node->get_data()) {
				node = node->get_left_node();
				return _look(_data, node);
			}
			else {
				node = node->get_right_node();
				return _look(_data, node);
			}
		}
		else {
			if (node == NULL) {
				return _data;
			}
			else {
				return node->get_data();
			}
		}
	}
}
/**
	@brief Funcion para buscar un elemento 
	@tparam T dato
	@param Tree_Node* node
	@returns void
*/
template<class T>
void Binary_Tree<T>::_look_english(T* _data, Tree_Node<T>* _node)
{
	if (_node!=NULL&& *_data != _node->get_data()) {
		_look_english(_data, _node->get_left_node());
		_look_english(_data, _node->get_right_node());
	}
	else if (_node == NULL) {
		return;
	}else *_data=_node->get_data();
}
/**
	@brief Funcion para limpiar el arbol
	@param void
	@returns void
*/
template<class T>
void Binary_Tree<T>::delete_Tree()
{
	Tree_Node<T>* _node = this->get_root();
	if (this->get_root() != NULL) {
		this->set_root(_node->get_left_node());
		delete_Tree();
		this->set_root(_node->get_right_node());
		delete_Tree();
		this->set_root(NULL);
	}
}


template<class T>
string Binary_Tree<T>::to_string()
{
	return string();
}

