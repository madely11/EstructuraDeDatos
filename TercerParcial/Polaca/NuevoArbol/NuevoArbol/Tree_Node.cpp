#include <iostream>
#include <sstream>

#include "Tree_Node.h"

using namespace std;

/**
 * @brief Tree_Node
 * @tparam T
 * @return
*/

Tree_Node::Tree_Node() {
	this->_left = NULL;
	this->_right = NULL;
}

/**
 * @brief Tree_Node
 * @tparam T
 * @param _data
 * @param _left
 * @param _right
 * @return
*/

Tree_Node::Tree_Node(string _data, Tree_Node* _left, Tree_Node* _right) {
	this->_left = _left;
	this->_right = _right;
	this->_data = _data;
}

/**
 * @brief set_data
 * @tparam T
 * @param _data
*/
void Tree_Node::set_data(string _data) {
	this->_data = _data;
}

/**
 * @brief set_left_node
 * @tparam T
 * @param _left
*/
void Tree_Node::set_left_node(Tree_Node* _left) {
	this->_left = _left;
}

/**
 * @brief set_right_node
 * @tparam T
 * @param _right
*/
void Tree_Node::set_right_node(Tree_Node* _right) {
	this->_right = _right;
}

/**
 * @brief get_data
 * @tparam T
 * @return T
*/
string Tree_Node ::get_data() {
	return this->_data;
}

/**
 * @brief get_right_node
 * @tparam T
 * @return Tree_Node<T>*
*/
Tree_Node* Tree_Node::get_right_node() {
	return this->_right;

}

/**
 * @brief get_left_node
 * @tparam T
 * @return Tree_Node<T>*
*/
Tree_Node* Tree_Node::get_left_node() {
	return this->_left;
}

/**
 * @brief to_string
 * @tparam T
 * @return string
*/

string Tree_Node::to_string() {
	ostringstream oss;
	oss << this->get_data();
	return oss.str();
}

/**
 * @brief ~Tree_Node
 * @tparam T
 * @return
*/
Tree_Node::~Tree_Node() {}
