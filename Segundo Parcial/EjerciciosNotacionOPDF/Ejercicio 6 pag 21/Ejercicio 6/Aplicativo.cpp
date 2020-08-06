#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 99999
using namespace std;
int c[10000][10000];
int a[10000][10000];
void fun_Ex(int N){
int cuenta=0;
int i=3;
while (i<N)
{ cuenta=cuenta+10;
 int j=2;
 while (j<N)
 { cuenta=cuenta+100;
 j=j+1;
 }
 i=i+1;
}
}
void prod_mat(int N) {
	for (int i=1; i<=N; i++)  {
		for (int j=1; j <= N; j++){
			c[i][j] = 0;   
  			for (int k=1; k<=N; k++){
		 	c[i][j] += a[i][k];  
			  }      	   
		} 
	} 
		
}
void misterio(int N){
	int a=0;
	for (int i=1; i<N; i++){
		for (int j=i+1; j <= N; j++){ 
	     a+=1;
		}  
	}
}
bool impar(int N){
		return N%2;
}
void muy_impar(int N){
	int x=0,y=0; 
	for (int i=1; i<=N; i++){
		if (impar(i)){
			for (int j=i; j<N; j++){
			x++;     
				for (int j=1; j<=i; j++) y++;
			}      
		}
	
	}   
}	
int recursiva(int N){
	if (N < 1) return 1; 
	return recursiva(N-1)+recursiva(N-1); 
}		
int main(){
	clock_t tmI=0, tmF=0;
	int n=20;
	double tiempo;
	tmI = clock();
	recursiva(n);
	cout << n << endl;
    tmF = clock();
	tiempo = (double)((double)(tmF - tmI) / CLOCKS_PER_SEC);
	cout << tiempo << " segundos" << endl;
	cout << endl;
	system("pause");
	return 0;
}
