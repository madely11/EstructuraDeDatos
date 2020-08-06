#pragma once
#include"Nodo.h"
#include "ManejoArchivo.h"
#include <iostream>
using namespace std;

#ifndef Lista_H
#define Lista_H
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