
#include <sstream>

#include "Tree_Node.h"

using namespace std;

/**
 * @brief Tree_Node
 * @tparam T
 * @return
*/
template<typename T>
Tree_Node<T>::Tree_Node() {
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
template<typename T>
Tree_Node<T>::Tree_Node(T _data, Tree_Node* _left, Tree_Node* _right) {
	this->_left = _left;
	this->_right = _right;
	this->_data = _data;
}

/**
 * @brief set_data
 * @tparam T
 * @param _data
*/
template<typename T>
void Tree_Node<T>::set_data(T _data) {
	this->_data = _data;
}

/**
 * @brief set_left_node
 * @tparam T
 * @param _left
*/
template<typename T>
void Tree_Node<T>::set_left_node(T _data) {
	this->_left->set_data(_data);
}

/**
 * @brief set_right_node
 * @tparam T
 * @param _right
*/
template<typename T>
void Tree_Node<T>::set_right_node(T _data) {
	this->_right->set_data(_data);
}

/**
 * @brief set_left_node
 * @tparam T
 * @param _left
*/
template<typename T>
void Tree_Node<T>::set_left_node(Tree_Node* _data) {
	this->_left = _data;
}

/**
 * @brief set_right_node
 * @tparam T
 * @param _right
*/
template<typename T>
void Tree_Node<T>::set_right_node(Tree_Node* _data) {
	this->_right = _data;
}
/**
 * @brief get_data
 * @tparam T
 * @return T
*/
template<typename T>
T Tree_Node<T>::get_data() {
	return this->_data;
}

/**
 * @brief get_right_node
 * @tparam T
 * @return Tree_Node<T>*
*/
template<typename T>
Tree_Node<T>* Tree_Node<T>::get_right_node() {
	return this->_right;

}

/**
 * @brief get_left_node
 * @tparam T
 * @return Tree_Node<T>*
*/
template<typename T>
Tree_Node<T>* Tree_Node<T>::get_left_node() {
	return this->_left;
}


/**
 * @brief to_string
 * @tparam T
 * @return string
*/
template<typename T>
string Tree_Node<T>::to_string() {
	ostringstream oss;
	oss << this->get_data();
	return oss.str();
}



/**
 * @brief ~Tree_Node
 * @tparam T
 * @return
*/
template<typename T>
Tree_Node<T>::~Tree_Node() {}
