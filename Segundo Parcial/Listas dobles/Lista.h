#include"Nodo.h"
using namespace std;
template<class T>
class Lista {
public:
    Lista();
    void nodoPosicion(int pos);
    void insertarEntre(T dato, int pos);
    void insertarInicio(T dato);
    void insertarFinal(T dato);
    void borrar(T dato);
    bool listaVacia();
    void mostrar();
    void nodoSiguiente();
    void nodoAnterior();
    void primerNodo();
    void ultimoNodo();
    //bool Actual() { return lista != NULL; }
    //int ValorActual() { return lista->valor; }

private:
    Nodo<T>* lista;
};
template<class T>
Lista<T>::Lista(){
	this->lista=NULL;
}
template<class T>
void Lista<T>::insertarEntre(T dato, int pos){
	Nodo<T>* nodo=new Nodo<T>(dato,NULL,NULL); 
	if(listaVacia()){
		cout<<"No existen elementos en la lista"<<endl;
	}else{
		if(pos==1){
			insertarInicio(dato);
		}
		else{
		Nodo<T>* aux;
		nodoPosicion(pos);
		aux=lista->getSiguiente();
		nodo->setAnterior(lista);
		nodo->setSiguiente(aux);
		lista->setSiguiente(nodo);
		nodo->getSiguiente()->setAnterior(nodo);
		}
		
		
	}
	
	
}
template<class T>
void Lista<T>::insertarFinal(T dato){
	Nodo<T>* nodo=new Nodo<T>(dato,NULL,NULL);
	if(listaVacia()){
		lista=nodo;
	}
	else{
		ultimoNodo();
		lista->setSiguiente(nodo);
		nodo->setAnterior(lista);
		
			}
}
template<class T>
void Lista<T>::insertarInicio(T dato){
	Nodo<T>* nodo= new Nodo<T>(dato,NULL,NULL);
	if(listaVacia()){
		lista=nodo;
	}
	else {
		primerNodo();
		nodo->setSiguiente(lista);
	   lista->setAnterior(nodo);
	}
		 
}
template<class T>
void Lista<T>::borrar(T dato){
	primerNodo();
	while(lista->getSiguiente()!=NULL&&lista->getSiguiente()->getValor()!=dato&&lista->getValor()!=dato){
		lista=lista->getSiguiente();
	}
	if(lista->getSiguiente()->getValor()==dato){
		Nodo<T>* aux=lista->getSiguiente();
		if(aux->getSiguiente()==NULL){
			aux=NULL;
			lista->setSiguiente(aux);
		}
		else{
			lista->setSiguiente(aux->getSiguiente());
			aux->getSiguiente()->setAnterior(lista);
			aux=NULL;
		}
		
		
	}else if(lista->getValor()==dato){
		Nodo<T>* aux=lista;
		lista=lista->getSiguiente();
		lista->setAnterior(NULL);
		aux=NULL;
	}
	else{cout<<"El elemento no existe"<<endl;
	}
}
template<class T>
void Lista<T>::nodoAnterior(){
	Nodo<T>* aux=lista->getAnterior();
	lista=aux;
}
template<class T>
void Lista<T>::nodoSiguiente(){
	Nodo<T>* aux=lista->getSiguiente();
	lista=aux;
}
template<class T>
void Lista<T>::primerNodo(){
	Nodo<T>* aux;
	while(lista->getAnterior()!=NULL){
		aux=lista->getAnterior();
		lista=aux;
	}
}
template<class T>
void Lista<T>::ultimoNodo(){
	Nodo<T>* aux;
	while(lista->getSiguiente()!=NULL){
		aux=lista->getSiguiente();
		lista=aux;
	}
}
template<class T>
void Lista<T>::nodoPosicion(int pos){

	int cont=1;
	primerNodo();
	Nodo<T>* aux;
	while(cont<pos-1){
		aux=lista->getSiguiente();
		cont++;
		lista=aux;
	}
}
template<class T>
void Lista<T>::mostrar(){
	primerNodo();
	Nodo<T>* aux;
	cout<<"NULL";
	while(lista->getSiguiente()!=NULL){
		aux=lista->getSiguiente();
		cout<<"<-"<<lista->getValor()<<"->";
		lista=aux;
	}
	cout<<"<-"<<lista->getValor()<<"->";
	cout<<"NULL"<<endl;
}
template<class T>
bool Lista<T>::listaVacia(){
	return lista==NULL;
}
