#include "Cuenta.h"
#include "Ingreso.h"

Cuenta::Cuenta(int num, string id) {
    tipo = new TipoCuenta(num);
    this->idCliente = id;
    ManejoArchivo archivoM("cliente.txt");
    this->numeroCuenta = archivoM.contarLineas();
    this->monto = 5;
    hacerString();
    cout << dato << endl;
    ManejoArchivo a("cuenta.txt");
    a.agregarLinea(dato);
}

Cuenta::Cuenta() {
    monto = 0;
    numeroCuenta = 0;
    idCliente = "";
    dato = "";
}

bool Cuenta::verificarCuenta(int num) {
    int id;
    Ingreso ingreso;
    string mensaje, cuenta;
    ManejoArchivo archivoM("cuenta.txt");
    cuenta = ingreso.leer("Ingrese el numero de cuenta: ", 1);
    id = atoi(cuenta.c_str());
    mensaje = archivoM.buscarCuenta(id);
    if (mensaje._Equal("salir")) {
        cout << "Cuenta no existente" << endl;
        system("pause");
        return false;
    }

    guardarDatos(mensaje);

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
    monto = atof(auxString.c_str());//monto
    i++;
    auxString = "";
    while (i < mensaje.length() && mensaje.at(i) != ',') {
        auxString += mensaje.at(i);
        i++;
    }
    i = atoi(auxString.c_str());//numero identificador de tipo de cuenta
    tipo = new TipoCuenta(i);
}

void Cuenta::hacerString() {
    dato = idCliente + "," + to_string(numeroCuenta) + "," + to_string(monto) + "," + to_string(tipo->getId());
}

int Cuenta::getNumc(void)
{
    return numeroCuenta;
}

float Cuenta::getMonto(void)
{
    return monto;
}

void Cuenta::setNumc(int numC)
{
    this->numeroCuenta = numC;

}

void Cuenta::setMonto(float monto)
{
    this->monto = monto;
}
