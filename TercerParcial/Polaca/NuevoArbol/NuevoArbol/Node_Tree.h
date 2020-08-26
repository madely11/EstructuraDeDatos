#pragma once
#include <iostream>
#include"Binary_Tree.h"
using namespace std;
class Node_Tree
{
public:
	Node_Tree();
	Node_Tree(Tree_Node* d, Node_Tree* n);
	Node_Tree(Tree_Node* d, Node_Tree* n, Node_Tree* p);


	void setData(Tree_Node* d) { this->data = d; };
	void setNext(Node_Tree* n) { this->next = n; };
	void setPrevious(Node_Tree* p) { this->previous = p; };

	Tree_Node* getData() { return this->data; };
	Node_Tree* getNext() { return this->next; };
	Node_Tree* getPrevious() { return this->previous; };
private:
	Tree_Node* data;
	Node_Tree* next;
	Node_Tree* previous;
};

