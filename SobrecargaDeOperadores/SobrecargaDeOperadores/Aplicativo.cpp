#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include "Sobrecarga.h"
using namespace std;


int main(int argc, char** argv) {
    Pareja A(150, 75);
    Pareja B(100, 15);
    Pareja C;
    cout << "........................." << endl;
    cout << "........................." << endl;
    cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";
    cout << "........................." << endl;
    cout << "........................." << endl;
    C = C + A;
    C = C + B;
    cout << "Suma C = " << C << endl;
    cout << "........................." << endl;
    cout << "........................." << endl;
    C = A ;
    C = C - B;
    cout << "Resta C = " << C << endl;
    cout << "........................." << endl;
    cout << "........................." << endl;
    C = A;
    C = C * B;
    cout << "Multiplicacion C = " << C << endl;
    cout << "........................." << endl;
    cout << "........................." << endl;
    C = A;
    C = C / B;
    cout << "Division C = " << C << endl;
    cout << "........................." << endl;
    cout << "........................." << endl;
    cout << "Sobrecarga de operador (): " << endl;
    A();
    B();
    cout << "........................." << endl;
    cout << "........................." << endl;
    ++C;
    cout << "Mas Mas C = " << C << endl;
    cout << "........................." << endl;
    cout << "........................." << endl;
    --C;
    cout << "Menos Menos C = " << C << endl;
    cout << "........................." << endl;
    cout << "........................." << endl;
    cout << "A == B " << ((A == B) ? "  True \n" : "  False  \n");
    cout << "........................." << endl;
    cout << "........................." << endl;
    A ^= B;
    cout << "A ^= B " <<A<< endl;
    cout << "........................." << endl;
    cout << "........................." << endl;
    C = A;
    cout << "A > B " << ((A > B) ? "  True \n" : "  False  \n");
    cout << "........................." << endl;
    cout << "........................." << endl;
    cout << "A < B " << ((A < B) ? "  True \n" : "  False  \n");
    cout << "........................." << endl;
    cout << "A es divisible para B -->" << ((A % B) ? "  True \n" : "  False  \n");
    cout << "........................." << endl;
    cout << "........................." << endl;
    cout << "A != B " << ((A != B) ? "  True \n" : "  False  \n");
    cout << "........................." << endl;
    cout << "........................." << endl;
    cout << "A >= B " << ((A >= B) ? "  True \n" : "  False  \n");
    cout << "........................." << endl;
    cout << "........................." << endl;
    cout << "A <= B " << ((A <= B) ? "  True \n" : "  False  \n");
    cout << "........................." << endl;
    cout << "........................." << endl;
   
    A %= B;
    cout << "A %=B:" << A << endl;
    cout << "........................." << endl;
    cout << "........................." << endl;
    C = A = B = ++C;
    cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";
    cout << "C = " << C << endl;
    cout << "........................." << endl;
    cout << "........................." << endl;
    return 0;
}
