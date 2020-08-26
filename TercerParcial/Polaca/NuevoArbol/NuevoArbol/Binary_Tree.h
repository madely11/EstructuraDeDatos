#pragma once
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include "Tree.h"

using namespace std;

class Binary_Tree : public Tree
{
public:
    Binary_Tree() : Tree() {};
    void _add(string, Tree_Node*, Tree_Node*);
    void showTree(Tree_Node*, int );
    string to_string();
    virtual ~Binary_Tree();
protected:
private:
};

#endif

