#include "Node_Tree.h"
/**@brief  Constructor
@param void
@returns void
*/
Node_Tree::Node_Tree() { this->next = NULL; }
/**@brief  Constructor
@param  T d
@param  Node* n
@returns void
*/

Node_Tree::Node_Tree(Tree_Node* d, Node_Tree* n) {
	this->data = d;
	this->next = n;
}
/**@brief  Constructor
@param  T d
@param  Node* n
@returns void
*/
Node_Tree::Node_Tree(Tree_Node* d, Node_Tree* n, Node_Tree* p) {
	this->data = d;
	this->next = n;
	this->previous = p;
}
/**@brief  Destructor
@param  void
@returns void
*/
