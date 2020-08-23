#pragma once
#ifndef TREE_H
#define TREE_H

#include <iostream>

#include "Tree_Node.h"

using namespace std;


class Tree
{
public:
    Tree();
    void set_root(Tree_Node* _root);
    Tree_Node* get_root();
    virtual void _add(string, Tree_Node*, Tree_Node*) = 0;
    bool _is_empty();
    virtual string to_string() = 0;
    virtual ~Tree();
protected:
    Tree_Node* _root;
private:
};

#endif

