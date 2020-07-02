/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE PARA REALIZAR LAS TRANSACCIONES EN EL PROGRAMA            *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/06/20									  *
* FECHA DE MODIFICACIÓN: 02/07/20								  *
******************************************************************/

/**
    @file Transacciones.h
    @brief Clase que contiene declaracion de metodos para realizar las Transacciones del sistema
    @author Madely Betancourt y Kevin Caicedo
    @date 6/2020
*/
#pragma once
#include "Fecha.h"

class Transacciones
{
public:
    void datosTransaccion(int);
    void generarPdf();
    float depositar(float, int);
    float retirar(float, int);
    void stringConsola(string);
    string stringConsola(string, int);
    void guardarTransaccion(int, float, int);
    string ingresarFecha();
    friend ostream& operator<<(ostream& o, Fecha& f);

private:
    Fecha fecha;
    string tipoTransaccion;
    string dato;
};

