/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE INGRESO                                                   *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 1/09/20									  *
* FECHA DE MODIFICACIÓN: 13/09/20								  *
******************************************************************/

/**
    @file Tree.h
    @brief Clase que contiene metodos virtuales para un arbol
    @author Madely Betancourt y Kevin Caicedo
    @date 9/2020
*/

#pragma once
#ifndef TREE_H
#define TREE_H

#include <iostream>

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

