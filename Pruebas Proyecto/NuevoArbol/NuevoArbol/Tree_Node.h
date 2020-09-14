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
    @file Tree_Node.h
    @brief Clase para manejar los objetos Nodos del arbol
    @author Madely Betancourt y Kevin Caicedo
    @date 9/2020
*/

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
    Tree_Node(T _data, Tree_Node* _left, Tree_Node* _right);
    void set_data(T _data);
    void set_left_node(T _data);
    void set_right_node(T _data);
    void set_left_node(Tree_Node* _data);
    void set_right_node(Tree_Node* _data);
    T get_data();
    Tree_Node* get_right_node();
    Tree_Node* get_left_node();
    string to_string();
    virtual ~Tree_Node();
protected:
private:
    Tree_Node* _left;
    Tree_Node* _right;
    T _data;
};

#endif


