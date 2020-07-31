#include"Nodo.h"
using namespace std;
template<class T>
class Lista {
public:
    Lista();
    //void nodoPosicion(int pos);
    //void insertarEntre(T dato, int pos);
    void insertarInicio(T dato);
    void insertarFinal(T dato);
    void borrar(T dato);
    bool listaVacia();
    void mostrar();
    //bool Actual() { return lista != NULL; }
    //int ValorActual() { return lista->valor; }

private:
    Nodo<T>* lista;
    Nodo<T>* listaFinal;
};
template<class T>
Lista<T>::Lista(){
	this->lista=NULL;
	this->listaFinal=NULL;
}
template<class T>
void Lista<T>::insertarFinal(T dato){
	Nodo<T>* nodo=new Nodo<T>(dato,NULL,NULL);
	cout<<"valor"<<nodo->getValor();
	if(listaVacia()){
		lista=nodo;
		listaFinal=nodo;
		lista->setSiguiente(lista);
		lista->setAnterior(listaFinal);
		listaFinal->setSiguiente(lista);
	
	}
	else{
		
		listaFinal->setSiguiente(nodo);
		Nodo<T>* aux=listaFinal;
		nodo->setAnterior(aux);
		nodo->setSiguiente(lista);
		listaFinal=nodo;
		lista->setAnterior(listaFinal);
		}
}
template<class T>
void Lista<T>::insertarInicio(T dato){
	Nodo<T>* nodo= new Nodo<T>(dato,NULL,NULL);
	if(listaVacia()){
		lista=nodo;
	}
	else {
		//primerNodo();
		nodo->setSiguiente(lista);
	   lista->setAnterior(nodo);
	}
		 
}
template<class T>
void Lista<T>::borrar(T dato){
//	primerNodo();
	Nodo<T>* aux=lista;
	while(aux->getValor()!=dato&&aux!=listaFinal){
		aux=aux->getSiguiente();
	}
	if(aux->getValor()==dato){
		if(aux==lista){
		aux->getAnterior()->setSiguiente(aux->getSiguiente());
		aux->getSiguiente()->setAnterior(aux->getAnterior());
		lista=aux->getSiguiente();
		aux=NULL;
		}
		else if(aux==listaFinal){
		aux->getAnterior()->setSiguiente(aux->getSiguiente());
		aux->getSiguiente()->setAnterior(aux->getAnterior());
		listaFinal=aux->getAnterior();
		aux=NULL;
		}
		else{
		aux->getAnterior()->setSiguiente(aux->getSiguiente());
		aux->getSiguiente()->setAnterior(aux->getAnterior());
		aux=NULL;
		}
	
	}	
	
	
	
	else{cout<<"El elemento no existe"<<endl;
	}
}
template<class T>
void Lista<T>::mostrar(){
	//primerNodo();
	Nodo<T>* aux=lista;
	
    //cout<<lista->getValor();
    //cout<<listaFinal->getValor();
	while(aux != listaFinal){
		cout<<"<-"<<aux->getValor()<<"->";
		aux=aux->getSiguiente();	
	}
    cout<<"<-"<<aux->getValor()<<"->";
    //	cout<<"<-"<<aux->getSiguiente()->getValor()<<"->";
	//cout<<"   "<< lista->getAnterior()->getValor();
	
}
template<class T>
bool Lista<T>::listaVacia(){
	return lista==NULL;
}
