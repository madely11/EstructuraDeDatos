/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE PARA DEFINIR LA LISTA                                     *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/06/20									  *
* FECHA DE MODIFICACIÓN: 02/07/20								  *
******************************************************************/

#pragma once

#include"Nodo.h"
#include "ManejoArchivo.h"
#include <iostream>
using namespace std;


#ifndef Lista_H
#define Lista_H
/**
    @file Lista.h
    @brief Prototipo para la lista
    @author Madely Betancourt y Kevin Caicedo
    @date 7/2020
*/
class Lista {
public:
    Lista();
    bool verificarCedula(string cedula);
    void insertarInicio(Cliente dato);
    void insertarEntre(Cliente dato, int pos);
    void insertarFinal(Cliente dato);
    void insertarFinal(Cuenta dato);
    void insertarFinal(Transacciones dato);
    bool verificarCuenta(int);
    bool verificarTransaccion(string);
    void borrar(string cedula);
    bool listaVacia();
    void mostrar();
    void llenarLista(string);
    void llenarCuenta(string);
    void mostrarCuenta();
    void llenarTrans(string);
    void mostrarTrans();
private:
    Nodo* lista;
    Nodo* listaFinal;
};
#endif 