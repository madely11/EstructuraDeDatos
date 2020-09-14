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
    @file Binary_Tree.h
    @brief Clase que contiene metodos para manejar un arbol
    @author Madely Betancourt y Kevin Caicedo
    @date 9/2020
*/
#pragma once
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include<math.h>
#include "Tree.cpp"

using namespace std;

template<class T>
class Binary_Tree : public Tree<T>
{
public:
    Binary_Tree() : Tree<T>() {};
    void _add(T, Tree_Node<T>*, Tree_Node<T>*);
    T _look(T _data, Tree_Node<T>*);
    void _look_english(T* _data, Tree_Node<T>*);
    void delete_Tree();
    string to_string();
protected:
private:
};

#endif

