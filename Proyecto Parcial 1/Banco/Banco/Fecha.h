/***********************************************************************
 * Module:  Fecha.h
 * Author: Madely Betancourt, Kevin Caicedo
 * Modified: martes, junio 16, 2020 7:16:22 PM
 * Purpose: Declaration of the class Fecha
 ***********************************************************************/

#if !defined(__Banco_Fecha_h)
#define __Banco_Fecha_h

#include <iostream>
#include <string.h>
using namespace std;
#include <ctime>

class Fecha
{
public:
    string getFecha();
    string getHora();

private:
    string hora;
    string fecha;
};


inline string Fecha::getFecha()
{
    struct tm pt1;
    __time64_t tSac = time(NULL);
    errno_t err;
    _time64(&tSac);
    err = _localtime64_s(&pt1, &tSac);
    fecha = to_string(pt1.tm_mday) + "/" + to_string(pt1.tm_mon + 1) + "/" + to_string(pt1.tm_year + 1900);
    return fecha;
}

inline string Fecha::getHora()
{
    struct tm pt1;
    __time64_t tSac = time(NULL);
    errno_t err;
    _time64(&tSac);
    err = _localtime64_s(&pt1, &tSac);
    hora = to_string(pt1.tm_hour) + ":" + to_string(pt1.tm_min) + ":" + to_string(pt1.tm_sec);
    return hora;
}


#endif
