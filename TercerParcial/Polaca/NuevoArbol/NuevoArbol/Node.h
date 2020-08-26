#if !defined(__Node_h)

#include <iostream>
using namespace std;
class Node {
public:
	Node();
	Node(char d, Node* n);
	Node(char d, Node* n, Node* p);


	void setData(char d) { this->data = d; };
	void setNext(Node* n) { this->next = n; };
	void setPrevious(Node* p) { this->previous = p; };

	char getData() { return this->data; };
	Node* getNext() { return this->next; };
	Node* getPrevious() { return this->previous; };
private:
	char data;
	Node* next;
	Node* previous;
};
#endif