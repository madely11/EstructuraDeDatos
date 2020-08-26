#include <iostream>
#include <sstream>

#include "Binary_Tree.h"


#pragma once

using namespace std;

void Binary_Tree::_add(string _data) {
	Pila_Tree pila_tree;
	string input;
	int cont = 0;
	Tree_Node *t,*t1, *t2;
	for (int i = 0; i < _data.length(); i++)
	{
		if (_data.at(i)!=' ') {
			input += _data.at(i);
		}
		else{
			if (isdigit(input.at(i))) {
				t = new Tree_Node(input,NULL,NULL);
				pila_tree.push(t);
				input ="";
			}
			else {
				t = new Tree_Node(input, NULL, NULL);
				t1 = pila_tree.pop();
				t2 = pila_tree.pop();
				t->set_right_node(t1);
				t->set_left_node(t2);
				pila_tree.push(t);

			}
		}
	}
	t = pila_tree.getFirst();
	this->set_root(t);
	pila_tree.clean_pila();
}


void Binary_Tree::showTree(Tree_Node* tree, int cont) {
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




string Binary_Tree::to_string() {
	return " ";
}


Binary_Tree::~Binary_Tree() {}
