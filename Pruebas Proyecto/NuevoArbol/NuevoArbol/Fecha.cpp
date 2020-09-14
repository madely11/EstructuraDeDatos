#include "Fecha.h"
#include <string>

/**
    @brief Funcion para cambiar fecha
    @param string entrada
    @returns void
*/
void Fecha::setFecha(string newFecha) {
    fecha = newFecha;
    //cout << "New fecha " << fecha << endl;
}
/**
    @brief Funcion para cambiar la hora
    @param string entrada
    @returns void
*/
void Fecha::setHora(string newHora) {
    hora = newHora;
    //cout << "New hora " << hora << endl;
}
/**
    @brief Funcion para obtener la fecha del  sistema
    @param void
    @returns string fecha
*/
string Fecha::getFecha()
{
    struct tm pt1;
    int m, d;
    __time64_t tSac = time(NULL);
    errno_t err;
    _time64(&tSac);
    err = _localtime64_s(&pt1, &tSac);
    d = pt1.tm_mday;
    m = pt1.tm_mon + 1;

    if (d < 10 && m < 10)
        fecha = '0' + to_string(pt1.tm_mday) + "/" + '0' + to_string(pt1.tm_mon + 1) + "/" + to_string(pt1.tm_year + 1900);

    else if (d >= 10 && m < 10)
        fecha = to_string(pt1.tm_mday) + "/" + '0' + to_string(pt1.tm_mon + 1) + "/" + to_string(pt1.tm_year + 1900);

    else if (d < 10 && m >= 10)
        fecha = '0' + to_string(pt1.tm_mday) + "/" + to_string(pt1.tm_mon + 1) + "/" + to_string(pt1.tm_year + 1900);

    else if (d >= 10 && m >= 10)
        fecha = to_string(pt1.tm_mday) + "/" + to_string(pt1.tm_mon + 1) + "/" + to_string(pt1.tm_year + 1900);
    return fecha;
}
/**
    @brief Funcion para obtener la fecha completa del sistema
    @param void
    @returns string fecha
*/
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
/**
    @brief Funcion para obtener la hora del  sistema
    @param void
    @returns salida hora del sistema tipo string
*/
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
/**
    @brief Funcion para obtener la hora completa del  sistema
    @param void
    @returns string hora
*/
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

string Fecha::obtenerFecha() {
    return fecha;
}

string Fecha::obtenerHora() {
    return hora;
}