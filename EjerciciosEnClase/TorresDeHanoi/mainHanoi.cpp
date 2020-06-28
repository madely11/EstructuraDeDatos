#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include "Hanoi.h"
using namespace std;

int main(int argc, char *argv[])
{
	int n;
	Hanoi h;		
    cout<<"Los postes son A B C\n";
    cout<<"Ingrese el numero de discos: ";
    cin>>n;
    h.n = n;
    h.hanoi(h.n,h.A, h.B, h.C);
    cout<<"los movimientos son "<<h.hanoi(h.n)<<endl;
	system("pause");
	return 0;
}
