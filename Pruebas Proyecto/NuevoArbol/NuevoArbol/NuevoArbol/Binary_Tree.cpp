#include <iostream>
#include <sstream>

#include "Binary_Tree.h"

#include "Tree_Node.cpp"

#pragma once

using namespace std;

template<typename T>
void Binary_Tree<T>::_add(T _data) {

	Tree_Node<T>* _data_node = new Tree_Node<T>(_data, NULL, NULL);
	if (this->_is_empty()) {
		this->_root = _data_node;
	}
	else {
		Tree_Node<T>* _aux = this->_root;
		Tree_Node<T>* _aux_1 = this->_root;
		while (_aux != NULL) {
			_aux_1 = _aux;
			if (_data < _aux->get_data()) {
				_aux = _aux->get_left_node();
			}
			else {
				_aux = _aux->get_right_node();
			}
		}

		if (_data < _aux_1->get_data()) {
			_aux_1->set_left_node(_data_node);
		}
		else {
			_aux_1->set_right_node(_data_node);
		}
	}
}

template<typename T>
template<typename R>
T Binary_Tree<T>::_look(R _data) {
	if (this->_is_empty()) {
		cout << "Nodo Vacio" << endl;
		return NULL;
	}
	else {
		Tree_Node<T>* _aux = this->_root;
		while (_aux != NULL && _data != _aux->get_data()) {
			if (_data < _aux->get_data()) {
				_aux = _aux->get_left_node();
			}
			else {
				_aux = _aux->get_right_node();
			}
		}

		if (_aux == NULL) {
			cout << "No existe" << endl;
			return NULL;
		}
		else {
			return _aux->get_data();
		}
	}
}

template<typename T>
template<typename R>
void Binary_Tree<T>::_delete(R _data) {
	/*if (this->_is_empty()) {
		cout << "Nodo Vacio" << endl;
	}
	else {
		Tree_Node<T>* _aux = this->_root;
		Tree_Node<T>* _parent = this->_root;
		while (_aux != NULL && _data != _aux->get_data()) {
			_parent = _aux;
			if (_data < _aux->get_data()) {
				_aux = _aux->get_left_node();
			}
			else {
				_aux = _aux->get_right_node();
			}
		}

		if (_aux == NULL) {
			cout << "No existe" << endl;
		}
		else {
				bool _left_or_right = true;
				if (_parent->get_left_node() == _aux) 
					_left_or_right = false;

				if (_aux->get_left_node() != NULL && _aux->get_right_node() != NULL) {
					Tree_Node<T>* _aux_1 = _aux->get_left_node();
					Tree_Node<T>* _aux_2 = _aux_1;
					while (_aux_1 != NULL) {
						_aux_2 = _aux_1;
						_aux_1 = _aux_1->get_right_node();
					}

					if (_left_or_right) {
						_parent->set_right_node(_aux_2);
					}
					else {
						_parent->set_right_node(_aux_2);
					}
					delete _aux;
				}
				else if (_aux->get_left_node() != NULL && _aux->get_right_node() == NULL) {
					Tree_Node<T>* _aux_1 = _aux->get_left_node();
					if (_left_or_right) {
						_parent->set_right_node(_aux_1);
					}
					else {
						_parent->set_right_node(_aux_1);
					}
					delete _aux;
				}
				else if (_aux->get_left_node() == NULL && _aux->get_right_node() != NULL) {
					Tree_Node<T>* _aux_1 = _aux->get_right_node();
					if (_left_or_right) {
						_parent->set_right_node(_aux_1);
					}
					else {
						_parent->set_right_node(_aux_1);
					}
					delete _aux;
				}
				else {
					delete _aux;
				}
			}
		}*/
	
	if (this->_is_empty()) {
		cout << "Arbol Vacio" << endl;
	}
	else {
		Tree_Node<T>* _aux = this->_root;
		Tree_Node<T>* padre;
		while (_aux != NULL && _data != _aux->get_data()) {
			if (_data < _aux->get_data()) {
				padre = _aux;
				_aux = _aux->get_left_node();
			}
			else {
				padre = _aux;
				_aux = _aux->get_right_node();
			}
		}

		if (_aux == NULL) {
			cout << "No existe el dato" << endl;
		}
		else {
			cout << "padre " <<padre->get_data() << endl;
			cout << "hoja " << _aux->get_data() << endl;
			//Cuando es hoja
			if (_aux->get_left_node() == NULL && _aux->get_right_node() == NULL) {
				if (_aux == this->get_root()) {
					this->set_root(NULL);
					_aux = NULL;
				}
				else {
					if (padre->get_right_node() == _aux) {
						padre->set_right_node(NULL);
						_aux = NULL;
					}
					else {
						padre->set_left_node(NULL);
						_aux = NULL;
					}
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

template<typename T>
string Binary_Tree<T>::to_string() {
	return " ";
}

template<typename T>
Binary_Tree<T>::~Binary_Tree() {}
