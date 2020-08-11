/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE CUENTA                                                    *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/06/20									  *
* FECHA DE MODIFICACIÓN: 02/07/20								  *
******************************************************************/

/**
    @file Cuenta.h
    @brief Clase que contiene metodos para crear los objetos cuenta
    @author Madely Betancourt y Kevin Caicedo
    @date 6/2020
*/
#pragma once
#include "TipoCuenta.h"
#include "ManejoArchivo.h"
#include "Transacciones.h"
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <iomanip> 
#include <iostream>

using namespace std;

class Cuenta
{
public:
    int getNumc(void);
    TipoCuenta getTipo(void);
    float getMonto(void);
    string getId(void);
    string getDato(void);
    void setTipo(int);
    void setNumc(int);
    void setId(string);
    void setDato(string);
    void setMonto(float);
    int generarCuenta(string, int);
    void realizarTransaccion(int, int);
    void hacerString();
    void guardarDatos(string);
    Cuenta();
    Cuenta(int, string);
    TipoCuenta* tipo;
    Transacciones t;
protected:
private:
    float monto;
    int numeroCuenta;
    string idCliente;
    string dato;
};

