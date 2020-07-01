#include "Fecha.h"
#include <string>
#include <iostream>
using namespace std;


void Fecha::setFecha(string newFecha) {
    fecha = newFecha;
}

void Fecha::setHora(string newHora) {
    hora = newHora;
}

string Fecha::getFecha()
{
    struct tm pt1;
    int m;
    __time64_t tSac = time(NULL);
    errno_t err;
    _time64(&tSac);
    err = _localtime64_s(&pt1, &tSac);
    m = pt1.tm_mon + 1;
    if(m < 10)
        fecha = to_string(pt1.tm_mday) + "/" + '0'+ to_string(pt1.tm_mon + 1) + "/" + to_string(pt1.tm_year + 1900);
    else
        fecha = to_string(pt1.tm_mday) + "/" + to_string(pt1.tm_mon + 1) + "/" + to_string(pt1.tm_year + 1900);
    return fecha;
}

string Fecha::fechaUnida() {
    string f;
    int m;
    struct tm pt1;
    __time64_t tSac = time(NULL);
    errno_t err;
    _time64(&tSac);
    err = _localtime64_s(&pt1, &tSac);
    m = pt1.tm_mon + 1;
    if (m < 10)
        f = "_" + to_string(pt1.tm_mday) + '0' + to_string(pt1.tm_mon + 1) + to_string(pt1.tm_year + 1900);
    else
        f = "_" + to_string(pt1.tm_mday) + to_string(pt1.tm_mon + 1) + to_string(pt1.tm_year + 1900) + "_";
    return f;
}

string Fecha::getHora()
{
    struct tm pt1;
    __time64_t tSac = time(NULL);
    errno_t err;
    _time64(&tSac);
    err = _localtime64_s(&pt1, &tSac);
    hora = to_string(pt1.tm_hour) + ":" + to_string(pt1.tm_min) + ":" + to_string(pt1.tm_sec);
    return hora;
}

string Fecha::horaUnida() {
    string h;

    struct tm pt1;
    __time64_t tSac = time(NULL);
    errno_t err;
    _time64(&tSac);
    err = _localtime64_s(&pt1, &tSac);
    h = "_" + to_string(pt1.tm_hour) + to_string(pt1.tm_min) + to_string(pt1.tm_sec);
    return h;
}
