#pragma once
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>

#include "Tree.cpp"

using namespace std;

template<class T>
class Binary_Tree : public Tree<T>
{
public:
    Binary_Tree() : Tree<T>() {};
    void _add(T _data);
    template<typename R>
    void _delete(R _data);
    template<typename R>
    T _look(R _data);
    void imprimir(Tree_Node<T>* node);
    void imprimirPosorden();
    void showTree(Tree_Node<T>* tree, int cont);
    string to_string();
    virtual ~Binary_Tree();
protected:
private:
};

#endif

