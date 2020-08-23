/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE PARA REALIZAR LAS TRANSACCIONES EN EL PROGRAMA            *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACI�N: 20/06/20									  *
* FECHA DE MODIFICACI�N: 02/07/20								  *
******************************************************************/

/**
    @file Transacciones.h
    @brief Clase que contiene declaracion de metodos para realizar las Transacciones del sistema
    @author Madely Betancourt y Kevin Caicedo
    @date 6/2020
*/
#pragma once
#include "Fecha.h"
#include <sstream>
#include <iomanip> 


class Transacciones
{
public:
    Transacciones();
    void setFecha(Fecha);
    void setTipoTrans(string);
    void setDato(string);
    Fecha getFecha();
    string getTipoTrans();
    string getDato();
    void imprimirCartola(int);
    void datosTransaccion(int, int);
    void generarPdf();
    float depositar(float, int);
    float retirar(int, int);
    void stringConsola(string);
    string stringConsola(string, int);
    void guardarTransaccion(int, int, int);
    string ingresarFecha();
    friend ostream& operator<<(ostream& o, Fecha& f);

private:
    Fecha fecha;
    string tipoTransaccion;
    string dato;
};
