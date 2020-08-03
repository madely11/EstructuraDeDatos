/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE PARA DETERMINAR TIPO DE CUENTA                            *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 20/06/20									  *
* FECHA DE MODIFICACIÓN: 02/07/20								  *
******************************************************************/

/**
    @file TipoCuenta.cpp
    @brief Clase que contiene los nombre de los tipos de cuenta
    @author Madely Betancourt y Kevin Caicedo
    @date 6/2020
*/
#include "TipoCuenta.h"

/**
    @brief Funcion para obtener el nombre del tipo de Cuenta
    @param void
    @returns nombre Ahorro o Credito tipo string 
*/
string TipoCuenta::getNombre()
{
    return nombre;
}
/**
    @brief Funcion para cambiar el nombre del tipo de Cuenta
    @param nombre de tipo string
    @returns void
*/
void TipoCuenta::setNombre(string newNombre)
{
    this->nombre = newNombre;
}
/**
    @brief  Constructor clase Tipo Cuenta
    @param numero tipo int
    @returns TipoCuenta
*/
TipoCuenta::TipoCuenta(int num) {
    if (num == 1) {
        this->nombre = "Ahorros";
        this->id = 1;
    }
    else {
        this->nombre = "Credito";
        this->id = 2;
    }
}
/**
    @brief  Obtener id de Tipo Cuento
    @param void
    @returns entero id de cuent
*/
int TipoCuenta::getId()
{
    return id;
}
/**
    @brief Funcion Cambiar id de Tipo Cuenta
    @param entero Id
    @returns void
*/
void TipoCuenta::setId(int newId)
{
    id = newId;
}
