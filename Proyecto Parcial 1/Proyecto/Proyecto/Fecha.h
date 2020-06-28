#pragma once
#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;


class Fecha
{
public:
    string getFecha();
    string getHora();

private:
    string hora;
    string fecha;
};

