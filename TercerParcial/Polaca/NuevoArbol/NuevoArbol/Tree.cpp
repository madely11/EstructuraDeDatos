#include "Tree.h"

/**
 * @brief Tree
 * @tparam T
*/

Tree::Tree() {
	this->_root = NULL;
}


void Tree::set_root(Tree_Node* _root)
{
	this->_root = _root;
}


Tree_Node* Tree::get_root()
{
	return this->_root;
}

/**
 * @brief _is_empty
 * @tparam T
 * @return bool
*/

bool Tree::_is_empty() {
	return (this->_root == NULL) ? true : false;
}

/**
 * @brief ~Tree
 * @tparam T
*/
Tree::~Tree() {
	this->_root = NULL;
}
