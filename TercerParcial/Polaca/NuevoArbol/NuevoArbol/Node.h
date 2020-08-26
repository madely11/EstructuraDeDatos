#if !defined(__Node_h)

#include <iostream>
using namespace std;
template <class T>
class Node {
public:
	Node();
	Node(T d, Node<T>* n);
	Node(T d, Node<T>* n, Node<T>* p);


	void setData(T d) { this->data = d; };
	void setNext(Node<T>* n) { this->next = n; };
	void setPrevious(Node<T>* p) { this->previous = p; };

	T getData() { return this->data; };
	Node<T>* getNext() { return this->next; };
	Node<T>* getPrevious() { return this->previous; };
private:
	T data;
	Node<T>* next;
	Node<T>* previous;
};
#endif