#include "Lista.h"

Lista::Lista(){
	primero=NULL;
}

void Lista::insertar(char parte){
	pnodo anterior;
   if(listaVacia()) {                
      primero = new Nodo(parte,primero);
   } else {
      anterior = primero;
	  primero = new Nodo(parte,primero);
      primero->siguiente =anterior;
	}
}

bool Lista::listaVacia(){
	 return primero == NULL; 
}

char* Lista::crearLinea(){
	string serpiente;
	char* temp;
	pnodo aux;
   	aux = primero;
   	while(aux) {
   		temp=(char*)malloc(1*sizeof(int));
   		sprintf(temp,"%c",aux->getParte());
   		serpiente.append(temp);
      	aux = aux->siguiente;
      	free(temp);
   	}
   	temp=(char*)malloc(serpiente.length()*sizeof(int));
   	sprintf(temp,"%s",serpiente.c_str());
   	return temp;
}
