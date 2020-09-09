#pragma once
#include <iostream>
using namespace std;
class NodeString
{
public:
	NodeString();
	NodeString(string d, NodeString* n);
	NodeString(string d, NodeString* n, NodeString* p);


	void setData(string d) { this->data = d; };
	void setNext(NodeString* n) { this->next = n; };
	void setPrevious(NodeString* p) { this->previous = p; };

	string getData() { return this->data; };
	NodeString* getNext() { return this->next; };
	NodeString* getPrevious() { return this->previous; };
private:
	string data;
	NodeString* next;
	NodeString* previous;
};

