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
    srand(time(NULL));
    tipo = new TipoCuenta(num);
    this->idCliente = id;
    this->numeroCuenta = generarCuenta(id, tipo->getId());
    this->monto = 5;
    hacerString();
    ManejoArchivo a("cuenta.txt");
    a.cerrarLectura();
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
    tipo = new TipoCuenta();
}
/**
    @brief Funcion para validar si existe una cuenta
    @param num cuenta int
    @returns bool
*/
void Cuenta::realizarTransaccion(int num, int id) {
    string mensaje;
    ManejoArchivo archivoM("cuenta.txt");
    archivoM.cerrarLectura();
    mensaje = archivoM.buscarCuenta(id); //linea que tiene ese num cuenta
    archivoM.cerrarLectura();
    guardarDatos(mensaje); //setear el objeto 

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
    monto = stof(auxString);//monto
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
    string auxMonto;
    stringstream montoString;
    montoString << fixed << setprecision(2) << monto;
    dato = idCliente + "," + to_string(numeroCuenta) + "," + montoString.str() + "," + to_string(tipo->getId());
}

int Cuenta::getNumc(void)
{
    return numeroCuenta;
}

TipoCuenta Cuenta::getTipo(void)
{
    return *tipo;
}
float Cuenta::getMonto(void)
{
    return monto;
}

string Cuenta::getId(void)
{
    return idCliente;
}

string Cuenta::getDato(void)
{
    return dato;
}

void Cuenta::setTipo(int tipo)
{
    this->tipo = new TipoCuenta(tipo);
}

void Cuenta::setNumc(int numC)
{
    this->numeroCuenta = numC;

}

void Cuenta::setId(string id)
{
    this->idCliente = id;
}

void Cuenta::setDato(string dato)
{
    this->dato = dato;
}

void Cuenta::setMonto(float monto)
{
    this->monto = monto;
}

int Cuenta::generarCuenta(string cedula, int tipo)
{
    int num=0, pos=0;
    string numC = to_string(tipo) + "0";
    pos = 10 + rand() % (100 - 10);
    numC += to_string(pos);
    while (numC.length() <= 6) {
        num = 1 + rand() % (10 - 1);
        numC += cedula.at(num);
    }
    return atoi(numC.c_str());
}


