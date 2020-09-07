#include <iostream>
#include <sstream>

#include "Binary_Tree.h"

#include "Tree_Node.cpp"

#pragma once

using namespace std;

template<typename T>
void Binary_Tree<T>::_add(T _data, Tree_Node<T>* node, Tree_Node<T>* parent) {
	
	if (this->_is_empty()) {
		this->_root = new Tree_Node<T>(_data,NULL,NULL);
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
				parent->set_left_node(new Tree_Node<T>(_data, NULL, NULL));
				return;
			}
			else {
				parent->set_right_node(new Tree_Node<T>(_data, NULL, NULL));
				return;
			}
		}
	}

		
}

template<typename T>
template<typename R>
T Binary_Tree<T>::_look(R _data, Tree_Node<T>* node) {
	if (this->_is_empty()) {
		cout << "Nodo Vacio" << endl;
		return NULL;
	}
	else {
		if (node != NULL && _data != node->get_data()) {
			if (_data < node->get_data()) {
				node = node->get_left_node();
				_look(_data, node);
			}
			else {
				node = node->get_right_node();
				_look(_data, node);
			}
		}
		else {
			if (node == NULL) {
				cout << "No existe" << endl;
				return NULL;
			}
			else {
				return node->get_data();
			}
		}
	}
}

template<typename T>
template<typename R>
void Binary_Tree<T>::_delete(R _data, Tree_Node<T>* node, Tree_Node<T>* parent) {

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
void Binary_Tree<T>::_delete_leaf(Tree_Node<T>* _aux, Tree_Node<T>* _parent)
{
	if (_aux == this->get_root()) {
		this->set_root(NULL);
		_aux = NULL;
	}
	else {
		if (_parent->get_right_node() == _aux) {
			_parent->set_right_node(NULL);
			_aux = NULL;
		}
		else {
			_parent->set_left_node(NULL);
			_aux = NULL;
		}
	}
}

template<class T>
int Binary_Tree<T>::cont_prime(Tree_Node<T>* node)
{   
	int cont1 = 0;
	if (node != NULL)
	{
		//cont1++;
		if (node->get_left_node())

			cont1+=cont_prime(node->get_left_node());

		if (node->get_right_node())
			cont1+=cont_prime(node->get_right_node());

		if (is_prime(node->get_data())) {
		 return cont1+1;
		}else return cont1+0;
	}
	else return 0 ;
	
}

template<class T>
void Binary_Tree<T>::_delete_leaf_left(Tree_Node<T>* _aux, Tree_Node<T>* _parent)
{
	if (_aux == this->get_root()) {
		this->set_root(_aux->get_left_node());
		_aux = NULL;
	}

	else {

		if (_parent->get_right_node() == _aux) {
			_parent->set_right_node(_aux->get_left_node());
			_aux = NULL;
		}
		else {
			_parent->set_left_node(_aux->get_left_node());
			_aux = NULL;
		}
	}
}

template<class T>
void Binary_Tree<T>::_delete_leaf_right(Tree_Node<T>* _aux, Tree_Node<T>* _parent)
{
	if (_aux == this->get_root()) {
		this->set_root(_aux->get_right_node());
		_aux = NULL;
	}

	else {

		if (_parent->get_right_node() == _aux) {
			_parent->set_right_node(_aux->get_right_node());
			_aux = NULL;
		}
		else {
			_parent->set_left_node(_aux->get_right_node());
			_aux = NULL;
		}
	}
}

template<class T>
void Binary_Tree<T>::_delete_branch(Tree_Node<T>* _aux, Tree_Node<T>* _parent)
{
	Tree_Node<T>* _aux1 = _aux->get_left_node();
	Tree_Node<T>* _auxParent = NULL;

	if (_aux1->get_right_node() == NULL) {
		if (this->get_root() == _aux) {
			_aux1->set_right_node(_aux->get_right_node());
			this->set_root(_aux1);
		}
		else if (_parent->get_right_node() == _aux) {
			_parent->set_right_node(_aux1);
			_aux1->set_right_node(_aux->get_right_node());
			_aux = NULL;
		}
		else {
			_parent->set_left_node(_aux1);
			_aux1->set_right_node(_aux->get_right_node());
			_aux = NULL;
		}
	}
	else {
		while (_aux1->get_right_node() != NULL) {
			_auxParent = _aux1;
			_aux1 = _aux1->get_right_node();
		}

		if (_aux == this->get_root()) {
			_aux->set_data(_aux1->get_data());
			_auxParent->set_right_node(_aux1->get_left_node());
			this->set_root(_aux);
			_aux1 = NULL;
		}
		else {
			_aux->set_data(_aux1->get_data());
			_auxParent->set_right_node(_aux1->get_left_node());
			_aux1 = NULL;
		}
	}
}

template<class T>
int Binary_Tree<T>::get_lvl(T _data, Tree_Node<T>* node)
{
	if (this->_is_empty()|| _data!=_look(_data,this->get_root())) {
		cout << "El arbo esta vacio" << endl;
		return 0;
	}
	else {
		if (node != NULL && _data != node->get_data()) {
			if (_data < node->get_data()) {
				node = node->get_left_node();
				return 1+get_lvl(_data, node);
			}
			else {
				node = node->get_right_node();
				return 1+get_lvl(_data, node);
			}
		}
		else {
				return 1;
		}
	}
}

template<class T>
int Binary_Tree<T>::get_height_tree(Tree_Node<T>* _node) {
	int cont1 = 0;
	int cont2 = 0;
	if (this->_is_empty()) {
		cout << "El arbo esta vacio" << endl;
		return 0;

	}
	else {
		if(_node->get_left_node() != NULL|| _node->get_right_node() != NULL) {
			//cout << _node->get_data();
			cont1++;
			cont2++;
			if(_node->get_left_node() != NULL) {
				//cout << _node->get_data();
			cont1+= get_height_tree(_node->get_left_node());
			}
			if (_node->get_right_node() != NULL) {
			cont2+= get_height_tree(_node->get_right_node());
			}
		}
		else {
			return 1;
		}
		if (cont1 > cont2) {
			//cout << cont1<<endl;
			return cont1;
		}
		else {
			//cout << cont2 <<endl;
			return cont2;
		}

	}
}

template<typename T>
string Binary_Tree<T>::to_string() {
	return " ";
}

template<class T>
bool Binary_Tree<T>::is_prime(T num)
{
		int  raiz, contc, cont, res;
		raiz = sqrt(num);
		cont = 1;
		contc = 0;
		do {
			res = num % cont;
			if (res == 0)
				contc++;
			cont++;
		} while (cont <= raiz);

		if ((contc > 1) || (num == 1)) {
			return false;
		}
		else {
			return true;
		}
	
}

template<typename T>
Binary_Tree<T>::~Binary_Tree() {}
