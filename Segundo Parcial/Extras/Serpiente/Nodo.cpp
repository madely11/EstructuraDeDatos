#include "Nodo.h"

Nodo::Nodo(char parteS, Nodo *sig=NULL){
	parte=parteS;
	siguiente=sig;
}

char Nodo::getParte(){
	return parte;
}
