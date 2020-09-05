#include <iostream>
#include <sstream>
#include "Binary_Tree.h"
#include "Tree_Node.cpp"

#pragma once

using namespace std;

template<typename T>
void Binary_Tree<T>::_add(T _data, Tree_Node<T>* node, Tree_Node<T>* parent) {
	//cout << "Ingreso add " << endl;
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

template<typename T>
T Binary_Tree<T>::_look(T _data, Tree_Node<T>* node) {
	if (this->_is_empty()) {
		cout << "Nodo Vacio" << endl;
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
				//cout << "No existe" << endl;
				return _data;
			}
			else {
				return node->get_data();
			}
		}
	}
}

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

template<typename T>
void Binary_Tree<T>::_delete(T _data, Tree_Node<T>* node, Tree_Node<T>* parent) {

	if (this->_is_empty()) {
		cout << "Arbol Vacio" << endl;
	}
	else {
		if (node != NULL && _data != node->get_data()) {
			if (_data < node->get_data()) {
				parent = node;
				node = node->get_left_node();
				_delete(_data, node, parent);
			}
			else {
				parent = node;
				node = node->get_right_node();
				_delete(_data, node, parent);
			}
		}
		else {
			if (node == NULL) {
				cout << "No existe el dato" << endl;
			}
			else {
				//Cuando es hoja
				if (node->get_left_node() == NULL && node->get_right_node() == NULL) {
					_delete_leaf(node, parent);
					return;
				}
				//cuando tiene un hijo a la izquierda
				else if (node->get_left_node() != NULL && node->get_right_node() == NULL) {
					_delete_leaf_left(node, parent);
					return;
				}
				//cuando tiene un hijo a la derecha
				else if (node->get_left_node() == NULL && node->get_right_node() != NULL) {
					_delete_leaf_right(node, parent);
					return;
				}
				//cuando tiene dos hijitos <3
				else if (node->get_left_node() != NULL && node->get_right_node() != NULL) {
					_delete_branch(node, parent);
					return;
				}
			}
		}
	}
}



template <typename T>
void Binary_Tree<T>::imprimirPosorden() {
	imprimir(this->_root);
}

template <typename T>
void Binary_Tree<T>::imprimir(Tree_Node<T>* node) {
	if (node != NULL)
	{
		if (node->get_left_node())
			imprimir(node->get_left_node());
		if (node->get_right_node())
			imprimir(node->get_right_node());

		cout << "     " << node->get_data() << "\n ";
	}
	else return;
}

template <class T>
void Binary_Tree<T>::showTree(Tree_Node<T>* tree, int cont) {
	if (this->_is_empty()) {
		cout << "Arbol vacio" << endl;
	}
	else {
		if (tree == NULL) {
			return;
		}
		else {
			showTree(tree->get_right_node(), cont + 1);
			for (int i = 0; i < cont; i++) {
				cout << "   ";
			}
			cout << tree->get_data() << endl;
			showTree(tree->get_left_node(), cont + 1);
			return;
		}
	}
}


template<class T>
string Binary_Tree<T>::to_string()
{
	return string();
}

