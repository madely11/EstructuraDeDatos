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

    deposito = atof(valorDeposito.c_str());
    while (deposito < 0) {
        valorDeposito = ingreso.leer("Ingrese la cantidad de dinero a depositar: ", 2);
        deposito = atof(valorDeposito.c_str());

    deposito = atoi(valorDeposito.c_str());
    while (deposito < 0) {
        valorDeposito = ingreso.leer("Ingrese la cantidad de dinero a depositar: ", 2);
        deposito = atoi(valorDeposito.c_str());

    }
    monto += deposito;
    tipoTransaccion = "Deposito";
    guardarTransaccion(numCuenta, monto, deposito);
    stringConsola(dato);
    cout << endl;
    //system("pause");
    return monto;
}

/**
    @brief Funcion para realizar un retiro de una cuenta
    @param monto tipo float, numCuenta tipo int
    @returns float monto de la cuenta
*/

float Transacciones::retirar(float monto, int numCuenta){
    float retiro;
    string valorRetiro;
    Ingreso ingreso;
    valorRetiro= ingreso.leer("Ingrese la cantidad de dinero a retirar: ", 2);

    retiro = atof(valorRetiro.c_str());
    while (retiro < 0) {//aqui hacer validacion
        valorRetiro = ingreso.leer("Monto invalido. Ingrese de nuevo: ", 2);
        retiro = atof(valorRetiro.c_str());

    retiro = atoi(valorRetiro.c_str());
    while (retiro < 0) {//aqui hacer validacion
        valorRetiro = ingreso.leer("Monto invalido. Ingrese de nuevo: ", 2);
        retiro = atoi(valorRetiro.c_str());

    }
    if (monto > retiro) {
        monto -= retiro;
        tipoTransaccion = "Retiro";
        guardarTransaccion(numCuenta, monto, retiro);
        stringConsola(dato);
        cout << endl;
    }
    else {
        cout << "Saldo insuficiente" << endl;
    }
    return monto;
}

/**
    @brief Funcion para registrar las transacciones realizadas
    @param numCuenta tipo int, monto tipo float, numCuenta tipo int, ingreso tipo int
    @returns void
*/

void Transacciones::guardarTransaccion(int numeroCuenta, float monto, int ingreso)
{
    ManejoArchivo am("transacciones.txt");
    stringstream montoString;
    montoString << fixed << setprecision(2) << monto;
    dato = to_string(numeroCuenta) + "," + tipoTransaccion + "," + to_string(ingreso) + "," +
            montoString.str() + "," + fecha.getFecha() + "," + fecha.getHora() + "," + "f";
    am.agregarLinea(dato);
}


/**
    @brief Funcion para revisar los datos de una transaccion por cuenta
    @param num tipo int
    @returns void
*/

Transacciones::Transacciones()
{
    this->dato = "";
    this->tipoTransaccion = "";
}

void Transacciones::setFecha(Fecha f)
{
    this->fecha = f;
}

void Transacciones::setTipoTrans(string tipoT)
{
    this->tipoTransaccion = tipoT;
}

void Transacciones::setDato(string dato)
{
    this->dato = dato;
}

Fecha Transacciones::getFecha()
{
    return fecha;
}

string Transacciones::getTipoTrans()
{
    return tipoTransaccion;
}

string Transacciones::getDato()
{
    return dato;
}

void Transacciones::imprimirCartola(int numC)
{
    int i = 1;
   
    ManejoArchivo maT("transacciones.txt");
    maT.buscarRegistroCartola(numC);
    //cartola.agregarLinea("      Fecha         Hora           Monto          Saldo");
    // while (!maT.buscarRegistroCartola(numC)._Equal("salir")) {
        //stringConsola(maT.buscarRegistroCartola(numC));
        //cartola.agregarLinea(stringConsola(maT.buscarRegistroCartola(numC), 1));
        //maT.actualizarTransacciones(maT.buscarRegistroCartola(numC));
        //i++;
       // cout << endl;
    //}
}



void Transacciones::datosTransaccion(int numC, int num)
{
    string f;
    int i = 1;
    ManejoArchivo maT("transacciones.txt");
    system("cls");
  
    if (num == 1) {
        while (!maT.buscarRegistro(numC, i)._Equal("salir")) {
            stringConsola(maT.buscarRegistro(numC, i));
            i++;
            cout << endl;
        }
        system("pause");
    }
    else {
        f = ingresarFecha();
        while (!maT.buscarRegistro(f, numC, i)._Equal("salir")) {
            stringConsola(maT.buscarRegistro(f, numC,i));
            i++;
            cout << endl;
        }
    
        if(i == 1)
            cout << "\n\t\t\t\t\No se han realizado transacciones con esa fecha!" << endl;
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
    o << "\n\tFecha" << "\t\tHora" << "\t\tMonto" << "\t\tSaldo" << "\n" << "\t" << f.obtenerFecha() << "\t" << f.obtenerHora();
    return o;
}
/**
    @brief Funcion para imprimir en consola
    @param Entrada mensaje tipo string
    @returns void
*/

void Transacciones::stringConsola(string mensaje)
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
    cout << "\t";
    cout << "\t" << saldo;
    cout << endl;
}

string Transacciones::stringConsola(string mensaje, int num) {
    Fecha _fecha;
    int i = 0;
    string salida = "";
    string saldo = "";
    string fechaT = "";
    string horaT = "";
    string valorT = "";
    string dato = "";

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
    _fecha.setFecha(fechaT);
    i++;
    while (i < mensaje.length() && mensaje.at(i) != ',') {
        horaT += mensaje.at(i);
        i++;
    }
    _fecha.setHora(horaT);

    if (salida._Equal("Deposito")) {
        salida = "";
        salida = '+';
    }
    else {
        salida = "";
        salida = '-';
    }
    salida += valorT;
    dato = "\n" + _fecha.getFecha() + "\t\t" + _fecha.getHora() + "\t" + salida + "\t" + saldo;
    return dato;
}
void Transacciones::generarPdf() {
    string f;
    int numeroCuenta;
    int i = 1;
    string numCuenta, dato, primera;
    Ingreso ingreso;
    ManejoArchivo amC("cuenta.txt");
    ManejoArchivo maT("transacciones.txt");
    ManejoArchivo pdf("pdfDocumento.txt");
    system("cls");
    numCuenta = ingreso.leer("Ingrese el numero de cuenta: ", 1);
    numeroCuenta = atoi(numCuenta.c_str());
    if (amC.buscarCuenta(numeroCuenta)._Equal("salir")) {
        cout << "Cuenta no existente" << endl;
        system("pause");
        return;
    }
    primera += "\nFecha";
    primera += "\t\t\tHora";
    primera += "\t\tMonto";
    primera += "\t\tSaldo";
    //cout << primera << endl;
    pdf.agregarLinea(primera);
    while (!maT.buscarRegistro(numeroCuenta, i)._Equal("salir")) {
        dato = stringConsola(maT.buscarRegistro(numeroCuenta, i),1);
        //cout << dato << endl;
        pdf.agregarLinea(dato);
        i++;
        cout << endl;
    }
    system("txt2pdf.exe pdfDocumento.txt documentoPDF.pdf");
    remove("pdfDocumento.txt");
}