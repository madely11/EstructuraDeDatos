#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
class Hanoi{
	public:
		int n;
    	char A = 'A';
		char B = 'B';
		char C = 'C';
	public:
		int hanoi (int n);
		void hanoi (int num, char A, char C, char B);
	
	
};

int Hanoi :: hanoi(int n)
{
    if(n == 1)
        return 1;
    else
        return 2 * hanoi(n-1) + 1;
}

void Hanoi :: hanoi(int num,char A,char C,char B)
{
    if(num==1)
    {
            cout<<"Mover el disco "<<num<<" desde el poste "<<A<<" hasta el poste "<<C<<endl;

    }
    else
    {
        hanoi(num-1,A,B,C);
        cout<<"Mover el disco "<<num<<" desde el poste "<<A<<" hasta el poste "<<C<<endl;
        hanoi(num-1,B,C,A);
    }
}
