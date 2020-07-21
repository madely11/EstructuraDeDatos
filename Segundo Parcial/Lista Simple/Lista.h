#include"Nodo.h"
using namespace std;
template<class T>
class Lista {
public:
    Lista();
    void insertarInicio(T dato);
    void insertarFinal(T dato);
    void borrar(T dato);
    bool listaVacia();
    void mostrar();
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
void Lista<T>::insertarFinal(T dato){
	Nodo<T>* nodo=new Nodo<T>(dato,NULL);
	if(listaVacia()){
		lista=nodo;
	}
	else{
		Nodo<T>* aux=new Nodo<T>();
		aux=lista;
		while(aux->getSiguiente()!=NULL){
			aux=aux->getSiguiente();
		}
		aux->setSiguiente(nodo);
	}
	cout<<endl<<"El dato se ha ingresado correctamente"<<endl;
}
template<class T>
void Lista<T>::insertarInicio(T dato){
	Nodo<T>* nodo= new Nodo<T>(dato,NULL);
	if(listaVacia()){
		lista=nodo;
	}
	else {
		Nodo<T>* aux=lista;
		nodo->setSiguiente(aux);
		lista=nodo;
	}
	cout<<endl<<"El dato se ha ingresado correctamente"<<endl;
		 
}
template<class T>
void Lista<T>::borrar(T dato){
	Nodo<T>* aux=lista;
	
	while(aux->getSiguiente()!=NULL&&aux->getSiguiente()->getValor()!=dato&&aux->getValor()!=dato){
		
		aux=aux->getSiguiente();
	}
	
	if(aux->getSiguiente()->getValor()==dato){
		Nodo<T>* aux2=aux->getSiguiente();
		aux->setSiguiente(aux2->getSiguiente());
		aux2=NULL;
		cout<<endl<<"El elemento ha sido eliminado"<<endl;
	}else if(aux->getValor()==dato){
		Nodo<T>* aux2=aux->getSiguiente();
		lista=aux2;
		aux=NULL;
		cout<<endl<<"El elemento ha sido eliminado"<<endl;
	}
	else{
		cout<<"No existe el elemento"<<endl;
	}
	

}
template<class T>
void Lista<T>::mostrar(){
	Nodo<T>* aux=lista;
	cout<<aux->getValor()<<"->";
	while(aux->getSiguiente()!=NULL){
		aux=aux->getSiguiente();
		cout<<aux->getValor()<<"->";
	}
	cout<<"NULL"<<endl;

}
template<class T>
bool Lista<T>::listaVacia(){
	return lista==NULL;
}
