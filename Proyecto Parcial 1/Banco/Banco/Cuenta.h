/***********************************************************************
 * Module:  Cuenta.h
 * Author:  Madely Betancourt, Kevin Caicedo
 * Modified: martes, junio 16, 2020 7:27:33 PM
 * Purpose: Declaration of the class Cuenta
 ***********************************************************************/

#if !defined(__Banco_Cuenta_h)
#define __Banco_Cuenta_h

#include <string>
#include "TipoCuenta.h"
#include "FileManager.h"
#include "Transacciones.h"

class Cuenta
{
public:
    int getNumc(void);
    double getMonto(void);
    void setNumc(int);
    int setMonto(int);
    bool verificarCuenta(int);
    
    void hacerString();
    void guardarDatos(string);
    Cuenta();
    Cuenta(int, string);
    TipoCuenta* tipo;
    Transacciones t;
protected:
private:
    int monto;
    int numeroCuenta;
    string idCliente;
    string dato;   
};


Cuenta::Cuenta(int num, string id) {
    tipo = new TipoCuenta(num);
    this->idCliente = id;
    FileManager fileM("cuenta.txt");
    this->numeroCuenta = fileM.contarLineas();
    this->monto = 5;
    hacerString();
   fileM.agregarLinea(dato);
}

Cuenta::Cuenta(){
    monto = 0;
    numeroCuenta = 0;
    idCliente = "";
    dato = "";
}

bool Cuenta :: verificarCuenta(int num) {
    int id;
    string mensaje;
    FileManager fileM("cuenta.txt");

    cout << "Ingrese el numero de cuenta: " << endl;
    cin >> id;

    mensaje = fileM.buscarCuenta(id);
    if (mensaje._Equal("salir")) {
        cout << "Cuenta no existente" << endl;
        Sleep(1000);
        return false;
    }
    guardarDatos(mensaje);

    if (num == 1) {
        monto = t.depositar(monto, id);
        hacerString();
        fileM.actualizar(id, dato);
     }
    if (num == 2) {
        monto = t.retirar(monto, id);
        hacerString();
        fileM.actualizar(id, dato);
     }
}

void Cuenta :: guardarDatos(string mensaje) { 
        int i = 0;
        string auxString;
        idCliente = "";
        while (mensaje.at(i) != ',' && i < mensaje.length()) {
            idCliente += mensaje.at(i);
            i++;
        }
        i++;
        while (mensaje.at(i) != ',' && i < mensaje.length()) {
            auxString += mensaje.at(i);
            i++;
        }
        numeroCuenta = atoi(auxString.c_str());
        i++;
        auxString = "";
        while (mensaje.at(i) != ',' && i < mensaje.length()) {
            auxString += mensaje.at(i);
            i++;
        }
        monto = atof(auxString.c_str());
        i++;
        auxString = "";
        while (i < mensaje.length() && mensaje.at(i) != ',') {
            auxString += mensaje.at(i);
            i++;
        }
        i = atoi(auxString.c_str());
        tipo = new TipoCuenta(i);
    }

void Cuenta::hacerString() {
    dato =idCliente + "," + to_string(numeroCuenta)+ "," + to_string(monto) + "," + to_string(tipo->getId());
}

int Cuenta::getNumc(void)
{
    return numeroCuenta;
}
inline double Cuenta::getMonto(void)
{
    return monto;
}
inline void Cuenta::setNumc(int numC)
{
    this->numeroCuenta = numC;
        
}
inline int Cuenta::setMonto(int monto)
{
    this->monto = monto;
}

#endif
