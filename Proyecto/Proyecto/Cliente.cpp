


#include <string.h>
#include "Cliente.h"
#include <iostream>

using namespace std;


void Cliente::pedirDatos(int num) {
    nombre = ingreso.leerString("Ingrese el nombre del titular : ", 1);
    cedula = cedula.assign(ingreso.ingresaNumericos("Ingrese la cedula del titular:"), 10);
    while (!validar.cedula(cedula)) {
        cedula.assign(ingreso.ingresaNumericos("\nIngrese la cedula del titular:"), 10);
    }
    cout << "\nIngrese el email del titular: "<<endl;
    getline(cin,email);
    while (validar.validarEmail(email)) {
        cout << "Reingrese el email del titular: "<<endl;
        getline(cin, email);
    }

    cout<<"Ingrese la direccion del titular : "<<endl;
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
