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
    @file Cuenta.cpp
    @brief Clase que contiene metodos para crear los objetos cuenta
    @author Madely Betancourt y Kevin Caicedo
    @date 6/2020
*/

#include "Cuenta.h"
#include "Ingreso.h"
/**
    @brief Constructor clase Cuenta
    @param num cuenta tipo int, id string;
    @returns Cuenta
*/
Cuenta::Cuenta(int num, string id) {
    tipo = new TipoCuenta(num);
    this->idCliente = id;
    ManejoArchivo archivoM("cliente.txt");
    this->numeroCuenta = archivoM.contarLineas();
    this->monto = 5;
    hacerString();
    ManejoArchivo a("cuenta.txt");
    a.agregarLinea(dato);
}
/**
    @brief Constructor clase Cuenta
    @param void
    @returns Cuenta
*/
Cuenta::Cuenta() {
    monto = 0;
    numeroCuenta = 0;
    idCliente = "";
    dato = "";
}/**
    @brief Funcion para validar si existe una cuenta
    @param num cuenta int
    @returns bool
*/
bool Cuenta::verificarCuenta(int num) {
    int id;
    Ingreso ingreso;
    string mensaje, cuenta;
    ManejoArchivo archivoM("cuenta.txt");
    cuenta = ingreso.leer("Ingrese el numero de cuenta: ", 1);
    id = atoi(cuenta.c_str());
    mensaje = archivoM.buscarCuenta(id);
    if (mensaje._Equal("salir")) {
        cout << "Cuenta no existente" << endl;
        system("pause");
        return false;
    }

    guardarDatos(mensaje);

    if (num == 1) {
        monto = t.depositar(monto, id);
        hacerString();
        archivoM.actualizar(id, dato);
    }
    if (num == 2) {
        monto = t.retirar(monto, id);
        hacerString();
        archivoM.actualizar(id, dato);
    }
}
/**
    @brief Funcion para guardar datos
    @param entrada mensaje string;
    @returns void
*/
void Cuenta::guardarDatos(string mensaje) {
    int i = 0;
    string auxString;
    idCliente = "";
    while (mensaje.at(i) != ',' && i < mensaje.length()) {
        idCliente += mensaje.at(i);
        i++;
    }
    //idcliente tiene cedula
    i++;
    while (mensaje.at(i) != ',' && i < mensaje.length()) {
        auxString += mensaje.at(i);
        i++;
    }
    numeroCuenta = atoi(auxString.c_str()); //tiene numero cuenta
    i++;
    auxString = "";
    while (mensaje.at(i) != ',' && i < mensaje.length()) {
        auxString += mensaje.at(i);
        i++;
    }
    monto = atof(auxString.c_str());//monto
    i++;
    auxString = "";
    while (i < mensaje.length() && mensaje.at(i) != ',') {
        auxString += mensaje.at(i);
        i++;
    }
    i = atoi(auxString.c_str());//numero identificador de tipo de cuenta
    tipo = new TipoCuenta(i);
}
/**
    @brief Funcion para generar un atrind de los datos
    @param void
    @returns datos tipo string
    */
void Cuenta::hacerString() {
    dato = idCliente + "," + to_string(numeroCuenta) + "," + to_string(monto) + "," + to_string(tipo->getId());
}

int Cuenta::getNumc(void)
{
    return numeroCuenta;
}

int Cuenta::getMonto(void)
{
    return monto;
}

void Cuenta::setNumc(int numC)
{
    this->numeroCuenta = numC;

}

void Cuenta::setMonto(int monto)
{
    this->monto = monto;
}
