#include <string.h>
#include "Cliente.h"
#include <iostream>

using namespace std;


void Cliente::pedirDatos(int num) {
    cout << "Ingrese el nombre del titular: " << endl;
    getline(cin, nombre);
    cout << "Ingrese la cedula del titular: " << endl;
    getline(cin, cedula);
    while (!validar.cedula(cedula)) {
        cout << "Ingrese la cedula del titular: " << endl;
        getline(cin, cedula);
    }
    cout << "Ingrese el e-mail del titular: " << endl;
    getline(cin, email);
    cout << "Ingrese la direccion del titular: " << endl;
    getline(cin, direccion);
    cuenta = new Cuenta(num, cedula);
    hacerString();
    ManejoArchivo archivoM("cliente.txt");
    archivoM.agregarLinea(dato);
}

string Cliente::stringConsola() {
    string salida;
    salida = "Nombre: " + nombre +
        "\nCedula: " + cedula +
        "\nEmail: " + email +
        "\nDireccion: " + direccion +
        "\nNumero de cuenta: " + to_string(cuenta->getNumc()) +
        "\nMonto: " + to_string(cuenta->getMonto()) +
        "\nTipo de cuenta: " + cuenta->tipo->getNombre();
    return salida;
}


void Cliente::hacerString() {
    dato = nombre + "," + cedula + "," + email + "," + direccion;
}
