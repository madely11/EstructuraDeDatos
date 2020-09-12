#include "Validar.h"



bool Validar::validarExpresion(string exp)
{
    if (validarParentesis(exp) && validarCaracteres(exp))
        return true;
    else
        return false;
}

//validar numero de parentesis y que no haya (5+3)(5^2)
bool Validar::validarParentesis(string exp)
{
    int cont1 = 0, cont2 = 0;

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp.at(i) == '(') {
            if (i != 0) {
                if (isdigit(exp.at(i - 1)) != 0 || exp.at(i - 1) == ')' || ((isdigit(exp.at(i + 1)) == 0 && exp.at(i + 1) != '('))) {
                    cout << i << endl;
                    cout << "hay un numero y paretnesis unidos " << endl;
                    return false;
                }
            }
            else { //(6-(5*4))
                if (isdigit(exp.at(i + 1) == 0 && exp.at(i + 1) != '(')) {
                    return false;
                }
            }
            cont1 += 1;
        }
        //(6-(5*4))
        else if (exp.at(i) == ')') {
            if (i != exp.length() - 1) {
                if (isdigit(exp.at(i + 1)) != 0 || exp.at(i + 1) == '(' || (isdigit(exp.at(i - 1)) == 0) && exp.at(i - 1) != ')') {
                    cout << "hay un numero o operadore" << endl;
                    return false;
                }
            }
            else { //(6-(5*4))
                if (isdigit(exp.at(i - 1)) == 0 && exp.at(i - 1) != ')') {
                    cout << i << endl;
                    cout << "no sabemos" << endl;
                    return false;
                }

            }
            cont2 += 1;
        }
    }
    return cont1 == cont2;
}

//validar que no sean letras, que no haya caraceres unidos, que no empiece o termine con caracter 
bool Validar::validarCaracteres(string exp)
{
    bool verificar = false;
    int l = exp.length() - 1, pos = 100;
    for (int i = 0; i < exp.length(); i++)
    {
        if (isdigit(exp.at(i)) == 0 && (exp.at(i) != '(' && exp.at(i) != ')')) {
            if (exp.at(i) == '+' || exp.at(i) == '-' || exp.at(i) == '*' || exp.at(i) == '/' || exp.at(i) == '^') {
                if (pos == i - 1) {
                    cout << "caracteres unidos posicion " << i << endl;
                    return false;
                }
                pos = i;
                verificar = true;
            }
            else {
                cout << "letras" << endl;
                return false;
            }
        }
    }
    if (exp.at(l) == '+' || exp.at(l) == '-' || exp.at(l) == '*' || exp.at(l) == '/' || exp.at(l) == '^') {
        cout << "termina caracter" << endl;
        return false;
    }
    else if (exp.at(0) == '+' || exp.at(0) == '-' || exp.at(0) == '*' || exp.at(0) == '/' || exp.at(0) == '^') {
        cout << "dmpieza caracter " << endl;
        return false;
    }
    return verificar;
}

void Validar::separarExpresion(string exp)
{
    string* arr = new string[exp.length()];
    string dato;
    int cont = 0;
    for (int i = 0; i < exp.length(); i++)
    {
        if (isdigit(exp.at(i))) {
            if (i < exp.length() - 1) {
                if (isdigit(exp.at(i + 1))) {
                    dato += exp.at(i);
                }
                else {
                    dato += exp.at(i);
                    arr[cont] = dato;
                    dato = "";
                    cont += 1;
                }
            }
            else {
                dato += exp.at(i);
                arr[cont] = dato;
                dato = "";
                cont += 1;
            }
        }
        else {
            arr[cont] = exp.at(i);
            cont += 1;
        }
    }
    Polish p1;
    cout << endl;
    cout<< p1.stringPost(arr, cont)<<endl;
}


