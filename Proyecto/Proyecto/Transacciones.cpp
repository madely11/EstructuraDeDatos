#include "Transacciones.h"
#include "ManejoArchivo.h"
#include "Ingreso.h"
#include <iostream>

using namespace std;

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

inline void Transacciones::guardarTransaccion(int numeroCuenta, int monto, int ingreso)
{
    ManejoArchivo am("transacciones.txt");
    dato = to_string(numeroCuenta) + "," + tipoTransaccion + "," + to_string(ingreso) + "," +
        to_string(monto) + "," + fecha.getFecha() + "," + fecha.getHora();
    am.agregarLinea(dato);
}

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
    salida += valorT;
    cout << fecha;
    cout << "\t\t" << salida;
    cout << "\t\t" << saldo;
    cout << endl;
}
