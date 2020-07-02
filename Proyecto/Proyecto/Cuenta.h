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
#include <iostream>

using namespace std;

class Cuenta
{
public:
    int getNumc(void);
    float getMonto(void);
    void setNumc(int);
    void setMonto(float);
    bool verificarCuenta(int);

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

