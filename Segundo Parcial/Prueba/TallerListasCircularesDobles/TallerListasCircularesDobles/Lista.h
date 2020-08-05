#pragma once
#include"Nodo.h"
#include"Persona.h"
#include <iostream>
using namespace std;

class Lista {
public:
    Lista();
    string buscarEmail(string iniciales);
    bool verificarCedula(string cedula);
    void insertarInicio(Persona dato);
    void insertarEntre(Persona dato, int pos);
    void insertarFinal(Persona dato);
    void borrar(string cedula);
    bool listaVacia();
    void mostrar();
    int contarNodos();
    
private:
    Nodo* lista;
    Nodo* listaFinal;
};
