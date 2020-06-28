#pragma once
#include <string>
#include <iostream>

using namespace std;
class TipoCuenta
{
public:
    string getNombre();
    void setNombre(string);
    TipoCuenta(int);
    int getId();
    void setId(int);

private:
    string nombre;
    int id;
};

