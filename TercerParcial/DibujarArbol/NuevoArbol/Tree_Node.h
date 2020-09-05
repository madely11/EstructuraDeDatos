#pragma once
#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>

using namespace std;

template<class T>
class Tree_Node
{
public:
    Tree_Node();
    Tree_Node(T _data, Tree_Node<T>* _left, Tree_Node<T>* _right);
    void set_data(T _data);
    void set_left_node(Tree_Node<T>* _left);
    void set_right_node(Tree_Node<T>* _right);
    T get_data();
    Tree_Node<T>* get_right_node();
    Tree_Node<T>* get_left_node();

    virtual ~Tree_Node();
protected:
private:
    Tree_Node<T>* _left;
    Tree_Node<T>* _right;
    T _data;
};

#endif


