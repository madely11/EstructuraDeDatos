#pragma once
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include "Dibujar.h"
#include<math.h>
#include "Tree.cpp"

using namespace std;

template<class T>
class Binary_Tree : public Tree<T>
{
public:
    Binary_Tree() : Tree<T>() {};
    void _add(T, Tree_Node<T>*, Tree_Node<T>*);
    template<typename R>
    void _delete(R _data, Tree_Node<T>*, Tree_Node<T>*);
    template<typename R>
    T _look(R _data, Tree_Node<T>*);
    void imprimir(Tree_Node<T>*);
    void imprimirPosorden();
    void showTree(Tree_Node<T>*, int );
    void showTreeGraph(Tree_Node<T>*, int, int, int);
    void _delete_leaf(Tree_Node<T>*, Tree_Node<T>*);
    int cont_prime(Tree_Node<T>*);
    void _delete_leaf_left(Tree_Node<T>*, Tree_Node<T>*);
    void _delete_leaf_right(Tree_Node<T>*, Tree_Node<T>*);
    void _delete_branch(Tree_Node<T>*, Tree_Node<T>*);
    int get_lvl(T _data, Tree_Node<T>*);
    int get_height_tree(Tree_Node<T>*);
    bool is_prime(T);
public:
    Dibujar dibujar;
};

#endif

