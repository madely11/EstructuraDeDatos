#include"Node.h"
/**@brief  Constructor
@param void
@returns void
*/
Node::Node() { this->next = NULL; }
/**@brief  Constructor
@param  T d
@param  Node* n
@returns void
*/

Node::Node(char d, Node* n) {
	this->data = d;
	this->next = n;
}
/**@brief  Constructor
@param  T d
@param  Node* n
@returns void
*/
Node::Node(char d, Node* n, Node* p) {
	this->data = d;
	this->next = n;
	this->previous = p;
}
/**@brief  Destructor
@param  void
@returns void
*/
