/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE PARA DEFINIR LA FECHA DE LAS TRANSACCIONES                *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/06/20									  *
* FECHA DE MODIFICACIÓN: 02/07/20								  *
******************************************************************/

/**
    @file Fecha.cpp
    @brief Clase que contiene metodos para tomar la fecha del sistema 
    @author Madely Betancourt y Kevin Caicedo
    @date 6/2020
*/


#include "Fecha.h"
#include <string>
#include <iostream>
using namespace std;

/**
    @brief Funcion para cambiar fecha
    @param Entrada fecha de tipo string
    @returns void
*/
void Fecha::setFecha(string newFecha) {
    fecha = newFecha;
    //cout << "New fecha " << fecha << endl;
}
/**
    @brief Funcion para cambiar la hora
    @param Entrada hora de tipo string
    @returns void
*/
void Fecha::setHora(string newHora) {
    hora = newHora;
    //cout << "New hora " << hora << endl;
}
/**
    @brief Funcion para obtener la fecha del  sistema
    @param void
    @returns salida fecha del sistema tipo string
*/
string Fecha::getFecha()
{
    struct tm pt1;
    int m,d;
    __time64_t tSac = time(NULL);
    errno_t err;
    _time64(&tSac);
    err = _localtime64_s(&pt1, &tSac);
    d = pt1.tm_mday;
    m = pt1.tm_mon + 1;

    if (d < 10 && m < 10)
        fecha = '0' + to_string(pt1.tm_mday) + "/" + '0' + to_string(pt1.tm_mon + 1) + "/" + to_string(pt1.tm_year + 1900);
    
    else if (d >= 10 && m < 10)
        fecha = to_string(pt1.tm_mday) + "/" + '0' + to_string(pt1.tm_mon + 1) + "/" + to_string(pt1.tm_year + 1900);
    
    else if (d < 10 && m >= 10)
        fecha = '0' + to_string(pt1.tm_mday) + "/" + to_string(pt1.tm_mon + 1) + "/" + to_string(pt1.tm_year + 1900);
    
    else if(d>=10 && m>=10)
        fecha = to_string(pt1.tm_mday) + "/" + to_string(pt1.tm_mon + 1) + "/" + to_string(pt1.tm_year + 1900);
    return fecha;
}
/**
    @brief Funcion para obtener la fecha completa del sistema
    @param void
    @returns salida fecha completa del sistema tipo string
*/
string Fecha::fechaUnida() {
    string f;
    int m;
    struct tm pt1;
    __time64_t tSac = time(NULL);
    errno_t err;
    _time64(&tSac);
    err = _localtime64_s(&pt1, &tSac);
    m = pt1.tm_mon + 1;
    if (m < 10)
        f = "_" + to_string(pt1.tm_mday) + '0' + to_string(pt1.tm_mon + 1) + to_string(pt1.tm_year + 1900);
    else
        f = "_" + to_string(pt1.tm_mday) + to_string(pt1.tm_mon + 1) + to_string(pt1.tm_year + 1900) + "_";
    return f;
}
/**
    @brief Funcion para obtener la hora del  sistema
    @param void
    @returns salida hora del sistema tipo string
*/
string Fecha::getHora()
{
    struct tm pt1;
    __time64_t tSac = time(NULL);
    errno_t err;
    _time64(&tSac);
    err = _localtime64_s(&pt1, &tSac);
    hora = to_string(pt1.tm_hour) + ":" + to_string(pt1.tm_min) + ":" + to_string(pt1.tm_sec);
    return hora;
}
/**
    @brief Funcion para obtener la hora completa del  sistema
    @param void
    @returns salida hora completa del sistema tipo string
*/
string Fecha::horaUnida() {
    string h;

    struct tm pt1;
    __time64_t tSac = time(NULL);
    errno_t err;
    _time64(&tSac);
    err = _localtime64_s(&pt1, &tSac);
    h = "_" + to_string(pt1.tm_hour) + to_string(pt1.tm_min) + to_string(pt1.tm_sec);
    return h;
}

string Fecha::obtenerFecha() {
    return fecha;
}

string Fecha::obtenerHora() {
    return hora;
}