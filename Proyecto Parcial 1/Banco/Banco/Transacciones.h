/***********************************************************************
 * Module:  Transacciones.h
 * Author:  Madely Betancourt, Kevin Caicedo
 * Modified: martes, junio 16, 2020 7:17:41 PM
 * Purpose: Declaration of the class Transacciones
 ***********************************************************************/

#if !defined(__Banco_Transacciones_h)
#define __Banco_Transacciones_h

#include "Fecha.h"

class Transacciones
{
public:
    void datosTransaccion();
    int depositar(int, int);
    int retirar(int, int);
    string stringConsola(string);
    void guardarTransaccion(int, int, int);

private:
    Fecha fecha;
    string tipoTransaccion;
    string dato;
};


int Transacciones::depositar(int monto, int numCuenta) {
    int deposito;
    cout << "Ingrese la cantidad de dinero a depositar: " << endl;
    cin >> deposito;
    monto += deposito;
    tipoTransaccion = "Deposito";
    guardarTransaccion(numCuenta, monto, deposito);
    cout << stringConsola(dato) << endl;
    system("pause");
    return monto;
}

int Transacciones::retirar(int monto, int numCuenta) {
    int retiro;
    cout << "Ingrese la cantidad de dinero a retirar: " << endl;
    cin >> retiro;
    if (monto > retiro) {
        monto -= retiro;
        tipoTransaccion = "Retiro";
        guardarTransaccion(numCuenta, monto, retiro);
        cout << stringConsola(dato) << endl;
        system("pause");
    }
    else {
        cout << "Saldo insuficiente" << endl;
        Sleep(1000);
    }
    return monto;
}

inline void Transacciones::guardarTransaccion(int numeroCuenta, int monto, int ingreso)
{
    FileManager fm("registroTransaciones.txt");
    dato = to_string(numeroCuenta) + "," + tipoTransaccion + "," + to_string(ingreso) + "," +
        to_string(monto) + "," + fecha.getFecha() + "," + fecha.getHora();
    fm.agregarLinea(dato);
}

void Transacciones::datosTransaccion()
{
    int numeroCuenta;
    int i = 1;
    FileManager fmc("cuenta.txt");
    FileManager fm("registroTransaciones.txt");
    system("cls");
    cout << "Ingrese el numero de cuenta: ";
    cin >> numeroCuenta;
    if (fmc.buscarCuenta(numeroCuenta)._Equal("salir")) {
        cout << "Cuenta no existente" << endl;
        Sleep(1000);
        return;
    }

    if (fm.buscarRegistro(numeroCuenta, i)._Equal("salir")) {
        cout << "La cuenta no ha realizado ninguna transaccion" << endl;
        Sleep(1000);
        return;
    }

    while (!fm.buscarRegistro(numeroCuenta, i)._Equal("salir")) {
        cout << stringConsola(fm.buscarRegistro(numeroCuenta, i)) << endl << endl;
        system("pause");
        i++;
    }
}

inline string Transacciones::stringConsola(string mensaje)
{
    int i = 0;
    string salida = "";

    while (mensaje.at(i) != ',' && i < mensaje.length()) {
        i++;
    }
    salida += "Transaccion realizada: ";
    i++;
    while (mensaje.at(i) != ',' && i < mensaje.length()) {
        salida += mensaje.at(i);
        i++;
    }
    salida += "\nMonto de tansaccion: ";
    i++;
    while (mensaje.at(i) != ',' && i < mensaje.length()) {
        salida += mensaje.at(i);
        i++;
    }
    salida += "\nSaldo actual: ";
    i++;
    while (i < mensaje.length() && mensaje.at(i) != ',') {
        salida += mensaje.at(i);
        i++;
    }
    salida += "\nFecha: ";
    i++;
    while (i < mensaje.length() && mensaje.at(i) != ',') {
        salida += mensaje.at(i);
        i++;
    }
    salida += "\nHora: ";
    i++;
    while (i < mensaje.length() && mensaje.at(i) != ',') {
        salida += mensaje.at(i);
        i++;
    }
    return salida;
}
#endif