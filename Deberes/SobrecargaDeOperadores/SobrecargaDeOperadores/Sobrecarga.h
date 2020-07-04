#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
using namespace std;


class Pareja {

public:
    int a, b;

public:
    // constructor base
    Pareja() : a(0), b(0) {}

    // constructor parametrizado
    Pareja(const int a, const int b) {
        this->a = a;
        this->b = b;
    }

    // constructor de copia
    Pareja(const Pareja&);

    // operadores miembros
    Pareja& operator + (const Pareja& p);
    Pareja& operator - (const Pareja& p);
    Pareja& operator * (const Pareja& p);
    Pareja& operator / (const Pareja& p);
    Pareja& operator = (const Pareja& p);
    Pareja& operator ++();
    bool    operator ==(const Pareja& p) const;
    bool operator > (const Pareja& p) const;
    bool operator < (const Pareja& p)const;
    bool operator % (const Pareja& p)const;
    Pareja& operator ^=(const Pareja& p);
    bool operator !=  (const Pareja& p)const;
    bool operator >=  (const Pareja& p)const;
    bool operator <=  (const Pareja& p)const;
    void operator () ();
    Pareja& operator --();
    Pareja& operator %=(const Pareja& p);
    // operadores no miembros
    friend ostream& operator << (ostream& o, const Pareja& p);
    friend istream& operator >> (istream& o, const Pareja& p);
};

// implementacion de los operadores para la clase Pareja
//....................................
Pareja::Pareja(const Pareja& p)
{
    *this = p;
}
//....................................
Pareja& Pareja::operator + (const Pareja& p)
{
    this->a += p.a;
    this->b += p.b;
    return *this;
}
//....................................
Pareja& Pareja::operator - (const Pareja& p)
{
    this->a -= p.a;
    this->b -= p.b;
    return *this;
}
//....................................
Pareja& Pareja::operator * (const Pareja& p)
{
    this->a *= p.a;
    this->b *= p.b;
    return *this;
}
//....................................
Pareja& Pareja::operator / (const Pareja& p)
{
    if (p.a != 0) this->a /= p.a;
    if (p.b != 0) this->b /= p.b;
    return *this;
}
//....................................
Pareja& Pareja::operator = (const Pareja& p)
{
    if (this != &p) { //Comprueba que no se esté intentanod igualar un objeto a sí mismo
        if (p.a != 0) this->a = p.a;
        if (p.b != 0) this->b = p.b;
    }
    return *this;
}

//Sobrecarga de operador aumento
Pareja& Pareja::operator ++ ()
{
    this->a++;
    this->b++;
    return *this;
}

//Sobrecarga de operador igualdad
bool Pareja::operator == (const Pareja& p) const
{
    return this->a == p.a && this->b == p.b;
}

// sobrecarga de operados mayor que
bool Pareja::operator > (const Pareja& p) const {    // sobrecarga operador >
    return this->a > p.a && this->b > p.b;
}

// sobrecarga de operados menor que
bool Pareja::operator < (const Pareja& p) const {
    return this->a<p.a&& this->b>p.b;
}

// sobrecarga de operados menor que
bool Pareja::operator % (const Pareja& p) const {
    if (((this->a % p.a) == 0) && ((this->b % p.b) == 0))
        return 1;
    else
        return 0;
}

inline Pareja& Pareja::operator ^= (const Pareja& p)
{
    this->a ^= p.a;
    this->b ^= p.b;
    return *this;
}

// Sobrecarga del operador diferente de
bool Pareja::operator!=(const Pareja& p) const
{
    return this->a != p.a && this->b != p.b;
}

//Sobrecarga del operador mayor o igual que
bool Pareja::operator>=(const Pareja& p) const
{
    return this->a >= p.a && this->b >= p.b;
}

//Sobrecarga del operador menor o igual que
bool Pareja::operator<=(const Pareja& p) const
{
    return this->a <= p.a && this->b <= p.b;
}

//Sobrecarga del operador decremento
Pareja& Pareja::operator -- ()
{
    this->a--;
    this->b--;
    return *this;
}

//Sobrecarga del operador %=
Pareja& Pareja::operator%=(const Pareja& p)
{
    this->a %= p.a;
    this->b %= p.b;
    return *this;
}

//Sobrecarga del operador ()
void Pareja::operator () () {
    cout << " Primer termino: " << this->a << endl;
    cout << " Segundo termino: " << this->b << endl;
}

// implemetaci¢n de operadores no miembros
ostream& operator << (ostream& o, const Pareja& p)
{
    o << "(" << p.a << ", " << p.b << ")";
    return o;
}

istream& operator >> (istream& i, Pareja& p)
{
    cout << "Introducir valores para ( a, b) :";
    i >> p.a >> p.b;
    i.ignore();
    return i;
}

