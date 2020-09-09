#pragma once
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include<math.h>
#include "Tree.cpp"

using namespace std;

template<class T>
class Binary_Tree : public Tree<T>
{
public:
    Binary_Tree() : Tree<T>() {};
    void _add(T, Tree_Node<T>*, Tree_Node<T>*);
    void _delete(T _data, Tree_Node<T>*, Tree_Node<T>*);
    T _look(T _data, Tree_Node<T>*);
    void _look_english(T* _data, Tree_Node<T>*);
    void imprimir(Tree_Node<T>*);
    void imprimirPosorden();
    void showTree(Tree_Node<T>*, int);
    string to_string();
protected:
private:
};

#endif
