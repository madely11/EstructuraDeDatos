#include "Fecha.h"

/**
    @brief Funcion para obtener la hora del  sistema
    @param void
    @returns salida hora del sistema tipo string
*/
int Fecha::getSegundos()
{
    struct tm pt1;
    __time64_t tSac = time(NULL);
    errno_t err;
    _time64(&tSac);
    err = _localtime64_s(&pt1, &tSac);
    segundos = pt1.tm_sec;
    return segundos;
}

/**
    @brief Funcion para cambiar la hora
    @param Entrada hora de tipo string
    @returns void
*/
void Fecha::setSegundos(int nuevoSegundos) {
    segundos = nuevoSegundos;
    //cout << "New hora " << hora << endl;
}
