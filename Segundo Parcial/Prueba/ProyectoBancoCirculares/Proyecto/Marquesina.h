#pragma once

#include <iostream>
#include<Windows.h>


using namespace std;

class Marquesina {
public:
    string realizarMarquezina(string cadena);
};
string Marquesina::realizarMarquezina(string cadena)
{

    char a = cadena[0];
    for (int i = 0; i < cadena.length(); i++)
    {

        if (i == cadena.length() - 1) {
            cadena[i] = a;
        }
        else {
            cadena[i] = cadena[i + 1];
        }


    }
    Sleep(150);

    return cadena;


}