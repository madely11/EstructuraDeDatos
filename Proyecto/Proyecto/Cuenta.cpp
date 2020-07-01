#include "Cuenta.h"

Cuenta::Cuenta(int num, string id) {
    tipo = new TipoCuenta(num);
    this->idCliente = id;
    ManejoArchivo archivoM("cuenta.txt");
    this->numeroCuenta = archivoM.contarLineas();
    this->monto = 5;
    hacerString();
    cout << dato << endl;
    archivoM.agregarLinea(dato);
    //archivoM.crearRespaldo();
}

Cuenta::Cuenta() {
    monto = 0;
    numeroCuenta = 0;
    idCliente = "";
    dato = "";
}

bool Cuenta::verificarCuenta(int num) {
    int id;
    string mensaje;
    ManejoArchivo archivoM("cuenta.txt");

    cout << "Ingrese el numero de cuenta: " << endl;
    cin >> id;

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
    dato = idCliente + "," + to_string(numeroCuenta) + "," + to_string(monto) + "," + to_string(tipo->getId());
}

int Cuenta::getNumc(void)
{
    return numeroCuenta;
}

double Cuenta::getMonto(void)
{
    return monto;
}

void Cuenta::setNumc(int numC)
{
    this->numeroCuenta = numC;

}

void Cuenta::setMonto(int monto)
{
    this->monto = monto;
}
