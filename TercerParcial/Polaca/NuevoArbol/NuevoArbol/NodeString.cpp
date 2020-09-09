#include "NodeString.h"
/**@brief  Constructor
@param void
@returns void
*/
NodeString::NodeString() { this->next = NULL; }
/**@brief  Constructor
@param  T d
@param  Node* n
@returns void
*/

NodeString::NodeString(string d, NodeString* n) {
	this->data = d;
	this->next = n;
}
/**@brief  Constructor
@param  T d
@param  Node* n
@returns void
*/
NodeString::NodeString(string d, NodeString* n, NodeString* p) {
	this->data = d;
	this->next = n;
	this->previous = p;
}
/**@brief  Destructor
@param  void
@returns void
*/