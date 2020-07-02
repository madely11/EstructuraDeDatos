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
    @file Transacciones.cpp
    @brief Clase que contiene metodos para realizar las Transacciones del sistema
    @author Madely Betancourt y Kevin Caicedo
    @date 6/2020
*/
#include "Transacciones.h"
#include "ManejoArchivo.h"
#include "Ingreso.h"
#include <iostream>

using namespace std;
/**
    @brief Funcion para realizar un deposito 
    @param monto tipo float, numCuenta tipo int
    @returns float monto de la cuenta
*/
float Transacciones::depositar(float monto, int numCuenta) {
    float deposito;
    string valorDeposito;
    Ingreso ingreso;
    valorDeposito = ingreso.leer("Ingrese la cantidad de dinero a depositar: ", 2);
    deposito = atoi(valorDeposito.c_str());
    while (deposito < 0) {
        cout << "Monto invalido. Ingrese de nuevo:" << endl;
        cin >> deposito;
        cin.clear();
        cin.sync();
    }
    monto += deposito;
    tipoTransaccion = "Deposito";
    guardarTransaccion(numCuenta, monto, deposito);
    stringConsola(dato);
    cout << endl;
    system("pause");
    return monto;
}

/**
    @brief Funcion para realizar un retiro de una cuenta
    @param monto tipo float, numCuenta tipo int
    @returns float monto de la cuenta
*/
float Transacciones::retirar(float monto, int numCuenta) {
    float retiro;
    string valorRetiro;
    Ingreso ingreso;
    valorRetiro= ingreso.leer("Ingrese la cantidad de dinero a retirar: ", 2);
    retiro = atoi(valorRetiro.c_str());
    while (retiro < 0) {//aqui hacer validacion
        cout << "Monto invalido. Ingrese de nuevo:" << endl;
        cin >> retiro;
        cin.clear();
        cin.sync();
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

/**
    @brief Funcion para registrar las transacciones realizadas
    @param numCuenta tipo int, monto tipo float, numCuenta tipo int, ingreso tipo int
    @returns void
*/
inline void Transacciones::guardarTransaccion(int numeroCuenta, float monto, int ingreso)
{
    ManejoArchivo am("transacciones.txt");
    dato = to_string(numeroCuenta) + "," + tipoTransaccion + "," + to_string(ingreso) + "," +
        to_string(monto) + "," + fecha.getFecha() + "," + fecha.getHora();
    am.agregarLinea(dato);
}


/**
    @brief Funcion para revisar los datos de una transaccion por cuenta
    @param num tipo int
    @returns void
*/
void Transacciones::datosTransaccion(int num)
{
    string f;
    int numeroCuenta;
    int i = 1;
    string numCuenta;
    Ingreso ingreso;
    ManejoArchivo amC("cuenta.txt");
    ManejoArchivo maT("transacciones.txt");
    system("cls");
    numCuenta = ingreso.leer("Ingrese el numero de cuenta: ", 1);
    numeroCuenta = atoi(numCuenta.c_str());
    if (amC.buscarCuenta(numeroCuenta)._Equal("salir")) {
        cout << "Cuenta no existente" << endl;
        system("pause");
        return;
    }

    if (maT.buscarRegistro(numeroCuenta, i)._Equal("salir")) {
        cout << "La cuenta no ha realizado ninguna transaccion" << endl;
        system("pause");
        return;
    }

    if (num == 1) {
        while (!maT.buscarRegistro(numeroCuenta, i)._Equal("salir")) {
            stringConsola(maT.buscarRegistro(numeroCuenta, i));
            i++;
            cout << endl;
        }
        //system("txt2pdf.exe transacciones.txt transacciones.pdf");
        system("pause");
    }
    else {
        f = ingresarFecha();
        while (!maT.buscarRegistro(f, numeroCuenta, i)._Equal("salir")) {
            stringConsola(maT.buscarRegistro(f, numeroCuenta,i));
            i++;
            cout << endl;
        }
        //cout << maT.buscarRegistro(f, numeroCuenta, i) << endl;
        system("pause");
    }
   
}
/**
    @brief Funcion para ingresar una fecha
    @param void
    @returns fecha tipo string
*/
string Transacciones::ingresarFecha() {
    Ingreso ingreso;
    string f;
    cout << "Ingrese la fecha" << endl;
    getline(cin, f);
    while (!ingreso.leerFecha(f))
    {
        cout << "\nDato incorrecto, ingrese de nuevo" << endl;
        getline(cin, f);
    }
    return f;
}
/**
    @brief Sobrecarga del operador imprimir 
    @param Fecha tipo Fecha
    @returns void
*/
ostream& operator<<(ostream& o, Fecha& f) {
    o << "\n\tFecha" << "\t\tHora" << "\t\tMonto" << "\t\tSaldo" << "\n" << "\t" << f.getFecha() << "\t" << f.getHora();
    return o;
}
/**
    @brief Funcion para imprimir en consola
    @param Entrada mensaje tipo string
    @returns void
*/
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
    salida += valorT;
    cout << fecha;
    cout << "\t\t" << salida;
    cout << "\t\t" << saldo;
    cout << endl;
}
