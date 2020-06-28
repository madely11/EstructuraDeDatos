#include "Transacciones.h"
#include "ManejoArchivo.h"
#include <iostream>

using namespace std;

int Transacciones::depositar(int monto, int numCuenta) {
    int deposito;
    cout << "Ingrese la cantidad de dinero a depositar: " << endl;
    cin >> deposito;
    while (deposito <= 0) {
        cout << "Monto invalido. Ingrese de nuevo:" << endl;
        cin >> deposito;
    }
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
    while (retiro <= 0) {
        cout << "Monto invalido. Ingrese de nuevo:" << endl;
        cin >> retiro;
    }
    if (monto > retiro) {
        monto -= retiro;
        tipoTransaccion = "Retiro";
        guardarTransaccion(numCuenta, monto, retiro);
        cout << stringConsola(dato) << endl;
        system("pause");
    }
    else {
        cout << "Saldo insuficiente" << endl;
        system("pause");
    }
    return monto;
}

inline void Transacciones::guardarTransaccion(int numeroCuenta, int monto, int ingreso)
{
    ManejoArchivo am("registroTransaciones.txt");
    dato = to_string(numeroCuenta) + "," + tipoTransaccion + "," + to_string(ingreso) + "," +
        to_string(monto) + "," + fecha.getFecha() + "," + fecha.getHora();
    am.agregarLinea(dato);
}

void Transacciones::datosTransaccion()
{
    int numeroCuenta;
    int i = 1;
    ManejoArchivo amc("cuenta.txt");
    ManejoArchivo am("registroTransaciones.txt");
    system("cls");
    cout << "Ingrese el numero de cuenta: ";
    cin >> numeroCuenta;
    if (amc.buscarCuenta(numeroCuenta)._Equal("salir")) {
        cout << "Cuenta no existente" << endl;
        system("pause");
        return;
    }

    if (am.buscarRegistro(numeroCuenta, i)._Equal("salir")) {
        cout << "La cuenta no ha realizado ninguna transaccion" << endl;
        system("pause");
        return;
    }

    while (!am.buscarRegistro(numeroCuenta, i)._Equal("salir")) {
        cout << stringConsola(am.buscarRegistro(numeroCuenta, i)) << endl << endl;
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
