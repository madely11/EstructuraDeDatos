#include <iostream>
#include <sstream>

#include "Binary_Tree.h"

#include "Tree_Node.cpp"

#pragma once

using namespace std;

void Binary_Tree::_add(string _data, Tree_Node* _parent, Tree_Node* _node) {
	if (_data.compare("(")) {
		_node = _parent->get_left_node();
		return;
	}
	else if (isdigit(_data.at(0)) == 0) {
		_parent->set_data(_data);
		_node = _parent->get_right_node();
		return;
	}
	else if (isdigit(_data.at(0)) != 0) {
		_node->set_data(_data);
		_node = _parent;
		return;
	}
	else if (_data.compare(")")) {
		_node = _parent;
		return;
	}
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
