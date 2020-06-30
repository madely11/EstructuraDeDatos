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
    stringConsola(dato);
    cout << endl;
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
        stringConsola(dato);
        cout << endl;
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
        stringConsola(am.buscarRegistro(numeroCuenta, i));
        i++;
        cout << endl;
    }
    system("pause");
}

ostream& operator<<(ostream& o, Fecha& f) {
    o << "\n\tFecha" << "\t\tHora" << "\t\tMonto" << "\t\tSaldo" << "\n" << "\t" << f.getFecha() << "\t" << f.getHora();
    return o;
}

inline void Transacciones::stringConsola(string mensaje)
{
    Fecha fecha;
    int i = 0;
    string salida = "";
    string saldo = "";
    string fechaT = "";
    string horaT = "";
    string valorT = "";

    while (mensaje.at(i) != ',' && i < mensaje.length()) {
        i++;
    }
    i++;
    while (mensaje.at(i) != ',' && i < mensaje.length()) {
        salida += mensaje.at(i);//tiene el tipo de transaccion
        i++;
    }
    i++;
    while (mensaje.at(i) != ',' && i < mensaje.length()) {
        valorT += mensaje.at(i);
        i++;
    }
    i++;
    while (i < mensaje.length() && mensaje.at(i) != ',') {
        saldo += mensaje.at(i);
        i++;
    }
    i++;
    while (i < mensaje.length() && mensaje.at(i) != ',') {
        fechaT += mensaje.at(i);
        i++;
    }
    fecha.setFecha(fechaT);
    i++;
    while (i < mensaje.length() && mensaje.at(i) != ',') {
        horaT += mensaje.at(i);
        i++;
    }
    fecha.setHora(horaT);

    if (salida._Equal("Deposito")) {
        salida = "";
        salida = '+';
    }
    else {
        salida = "";
        salida = '-';
    }
    //cout << "Tipo de transaccion: " << salida << endl;
    salida += valorT;
    cout << fecha;
    cout << "\t" << salida;
    cout << "\t\t" << saldo;
    cout << endl;
}
