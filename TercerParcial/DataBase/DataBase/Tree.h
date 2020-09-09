#pragma once
#ifndef TREE_H
#define TREE_H
#include "Tree_Node.h"

using namespace std;

template<class T>
class Tree
{
public:
    Tree();
    void set_root(Tree_Node<T>* _root);
    Tree_Node<T>* get_root();
    virtual void _add(T, Tree_Node<T>*, Tree_Node<T>*) = 0;
    bool _is_empty();
    virtual string to_string() = 0;
    virtual ~Tree();
protected:
    Tree_Node<T>* _root;
private:
};

#endif

